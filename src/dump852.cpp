#include <iostream>
#include "Imagenex852.hpp"

void printUsage(){
	std::cerr << "Usage: dump852 filename.852" << std::endl;
	exit(1);
}

class Dumper852 : public Imagenex852{
	void processPing(Imagenex852FileHeader &hdr,Imagenex852ReturnDataHeader & returnDataHdr,uint8_t * echoData,unsigned int payloadBytes){
                        std::stringstream ss;

			ss << hdr.date << " " << hdr.time << hdr.timeHundredsSeconds << ".dat";

			std::ofstream out(ss.str());
                        
                        out << hdr.date << " ";
                        out << hdr.time;
                        out << hdr.timeHundredsSeconds << std::endl;
                        out << unsigned((uint8_t)hdr.mode) << std::endl;
                        out << unsigned((uint8_t)hdr.startGain) << std::endl;
                        out << unsigned((uint8_t)hdr.sectorSize) << std::endl;
                        out << unsigned((uint8_t)hdr.trainAngle) << std::endl;
                        out << unsigned((uint8_t)hdr.pulseLength) << std::endl;
                        out << unsigned((uint8_t)hdr.profile) << std::endl;
                        out << unsigned((uint16_t)hdr.soundSpeed) << std::endl;
                        out << hdr.userText << std::endl;
                        out << unsigned((uint8_t)hdr.operatingFrequency) << std::endl;
                        out << unsigned((uint8_t)hdr.headId) << std::endl;

			printf("Echo data:\n");
			for(unsigned int i=0;i<payloadBytes;i++){
				printf("%.2X ",(uint8_t)echoData[i]);
				out << unsigned((uint8_t)echoData[i]) << " ";
			}

                        out << std::endl;
			printf("\n");

			out.close();
        }
};

int main(int argc,char **argv){
	try{
		if(argc != 2){
			printUsage();
		}

		Dumper852 sonar;
		std::string filename = argv[1]; //TODO get from argv

		std::cerr << "Reading " << filename << std::endl;

		sonar.read(filename);
	}
	catch(Exception * e){
		std::cerr << e->getMessage() << std::endl;
	}
}
