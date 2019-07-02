#include <iostream>
#include "../Imagenex852.hpp"
#include "opencv2/highgui/highgui.hpp"

void printUsage(){
	std::cerr << "Usage: imager.cpp filename.852 outputFilename" << std::endl;
	exit(1);
}

/**
 * Creates an image out of a series of pings
 */
class Imager852 : public Imagenex852{
private:
   std::vector<std::vector<uint8_t>> pingData;

public:
    Imager852(){

    }

    ~Imager852(){

    }

    void processPing(Imagenex852FileHeader &hdr,Imagenex852ReturnDataHeader & returnDataHdr,uint8_t * echoData,unsigned int payloadBytes){
	std::vector<uint8_t> verticalLine;

	for(unsigned int i=0;i<payloadBytes;i++){
		verticalLine.push_back((uint8_t)echoData[i]);
	}

	pingData.push_back(verticalLine);
    }

    void generateImage(std::string filename){
	if(pingData.size() > 0){

		cv::Mat img(pingData[0].size(),pingData.size(), CV_8UC1,cv::Scalar(70));

		//write a column for each ping
		for(unsigned int i=0;i<pingData.size();i++){
			for(unsigned int j=0;j<pingData[i].size();j++){
				img.at<uchar>(j, i, 0) = pingData[i][j];
			}
		}

		/*
		cv::namedWindow("Image", CV_WINDOW_AUTOSIZE);
		cv::imshow("Image",img);
		cv::waitKey(0);

		cv::destroyWindow("Image");
		*/

		imwrite(filename, img );
	}
    }
};

int main(int argc,char **argv){
	try{
		if(argc != 3){
			printUsage();
		}

		Imager852 sonar;
		std::string sonarFile = argv[1];
		std::string outputFile = argv[2];

		std::cerr << "Reading " << sonarFile << std::endl;

		sonar.read(sonarFile);

		std::cerr << "Writing " << outputFile << std::endl;

		sonar.generateImage(outputFile);
	}
	catch(Exception * e){
		std::cerr << e->getMessage() << std::endl;
	}
}
