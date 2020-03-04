#include <opencv2/opencv.hpp>
#include <opencv2/core/ocl.hpp>

#include <iostream>

using namespace std;
using namespace cv;

int main(){
	for(ulong i=0; i>=0; i++){
		UMat m(200,200, CV_8UC1, Scalar(1));
		stringstream ss; ss << sum(m).val[0] + i;
		auto mm = m.getMat(ACCESS_RW);
		putText(mm, ss.str(), Point(10, 30), FONT_HERSHEY_COMPLEX, 0.5, Scalar(100));
		imshow("w", mm);
		if(waitKey(100)==27){ break;}
	}
	//
	return 0;
}
