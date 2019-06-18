#include <iostream>
#include "Imagenex852.hpp"

void printUsage(){
	std::cerr << "Usage: dump852 filename.852" << std::endl;
	exit(1);
}

class Dumper852 : public Imagenex852{
	//TODO
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
