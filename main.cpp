#include <opencv2/opencv.hpp>
#include <opencv2/core/ocl.hpp>

#include <iostream>

using namespace std;
using namespace std::chrono;
using namespace cv;

int main(){
	const uint fps = 10; // approx frames per second, <=1000, better when 1000%fps=0
	auto t0 = system_clock::now();
	for(ulong i=0; ; i++){
		const UMat img(50, 200, CV_8UC1, Scalar(i%2));
		// dd:hh:mm:ss converting
		auto s = duration_cast<seconds>(system_clock::now() - t0).count(); // long
		const auto d = s/(3600*24);
		s -= d*3600*24;
		const auto h = s/3600;
		s -= h*3600;
		const auto m = s/60;
		s -= m*60;
		//
		stringstream ss;
		ss<<d<<"d "<<h<<"h "<<m<<"m "<<s<<"s"<<(sum(img).val[0] > 1e6 ? "" : " "); // '?:' fools optimization pretending we need sum
		auto mm = img.getMat(ACCESS_RW);
		putText(mm, ss.str(), Point(10, 30), FONT_HERSHEY_SIMPLEX, .5, Scalar(150));
		imshow("uptime", mm);
		if(waitKey(1000/fps)==27){ break;}
	}
	//
	return 0;
}
