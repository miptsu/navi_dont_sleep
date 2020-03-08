#include <opencv2/opencv.hpp>
#include <opencv2/core/ocl.hpp>

#include <iostream>

using namespace std;
using namespace std::chrono;
using namespace cv;

int main(){
	const uint fps = 10; // approx frames per second, <=1000, better when 1000%fps=0
	auto t0 = system_clock::now();
	UMat img(512, 512, CV_8UC1, Scalar(1)); // UMat uses OpenCL
	for(ulong i=0; ; i++){
		Mat mm(img.rows, img.cols, img.type(), Scalar(0));
		// dd:hh:mm:ss converting
		auto s = duration_cast<seconds>(system_clock::now() - t0).count(); // long
		const auto d = s/(60*60*24);
		s -= d*60*60*24;
		const auto h = s/(60*60);
		s -= h*(60*60);
		const auto m = s/60;
		s -= m*60;
		//
		stringstream ss;
		ss<<d<<"d "<<h<<"h "<<m<<"m "<<s<<"s"<<(sum(img).val[0] > 1e6 ? "" : " "); // '?:' fools optimization pretending we need sum
		img.copyTo(mm); // device to host copy
		mm.colRange(0, img.cols-2).setTo(Scalar(0)); // colRange - obfuscating we dont need img data
		putText(mm, ss.str(), Point(10, 30), FONT_HERSHEY_SIMPLEX, .5, Scalar(150));
		mm.copyTo(img); // host to device copy (also sum will variate)
		imshow("uptime", mm);
		if(waitKey(1000/fps)==27){ break;}
	}
	//
	return 0;
}
