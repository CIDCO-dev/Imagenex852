#include <iostream>
#include "../Imagenex852.hpp"

void printUsage(){
	std::cerr << "Usage: dump852 filename.852 outputFilename" << std::endl;
	exit(1);
}

class Dumper852 : public Imagenex852{
    
    std::ofstream out;
    
public:
    Dumper852(std::string filename){
        out = std::ofstream(filename);
    }
    
    ~Dumper852(){
        out.close();
    }
    
	void processPing(Imagenex852FileHeader &hdr,Imagenex852ReturnDataHeader & returnDataHdr,uint8_t * echoData,unsigned int payloadBytes){
                        
                        out << hdr.date << " ";
                        out << hdr.time << " ";
                        out << hdr.timeHundredsSeconds << " ";
                        out << unsigned((uint8_t)hdr.mode) << " ";
                        out << unsigned((uint8_t)hdr.startGain) << " ";
                        out << unsigned((uint8_t)hdr.pulseLength) << " ";
                        out << unsigned((uint16_t)hdr.soundSpeed) << " ";
                        out << unsigned((uint8_t)hdr.operatingFrequency) << " ";
                        out << unsigned((uint8_t)hdr.headId) << " ";

			printf("Echo data:\n");
			for(unsigned int i=0;i<payloadBytes;i++){
				printf("%.2X ",(uint8_t)echoData[i]);
				out << unsigned((uint8_t)echoData[i]) << " ";
			}

                        out << std::endl;
			printf("\n");

        }
};

int main(int argc,char **argv){
	try{
		if(argc != 3){
			printUsage();
		}

		Dumper852 sonar(argv[2]);
		std::string filename = argv[1]; //TODO get from argv

		std::cerr << "Reading " << filename << std::endl;

		sonar.read(filename);
	}
	catch(Exception * e){
		std::cerr << e->getMessage() << std::endl;
	}
}
