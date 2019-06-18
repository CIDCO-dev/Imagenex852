#include <iostream>
#include "Imagenex852.hpp"

void printUsage(){
	std::cerr << "Usage: octave-dump filename.852" << std::endl;
	exit(1);
}

class OctaveDumper : public Imagenex852{
		void processPing(Imagenex852FileHeader &hdr,Imagenex852ReturnDataHeader & returnDataHdr,uint8_t * echoData,unsigned int payloadBytes){
			std::stringstream ss;

			ss << hdr.date << " " << hdr.time << hdr.timeHundredsSeconds << ".dat";

			std::ofstream out(ss.str());

			printf("Echo data:\n");
			for(unsigned int i=0;i<payloadBytes;i++){
				printf("%.2X ",(uint8_t)echoData[i]);
				out << unsigned((uint8_t)echoData[i]) << std::endl;
			}

			printf("\n");

			out.close();
		}
};

int main(int argc,char **argv){
	try{
		if(argc != 2){
			printUsage();
		}

		OctaveDumper dumper;
		std::string filename = argv[1];

		std::cerr << "Reading " << filename << std::endl;

		dumper.read(filename);
	}
	catch(Exception * e){
		std::cerr << e->getMessage() << std::endl;
	}
}
