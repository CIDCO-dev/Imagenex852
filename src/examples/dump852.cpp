#include <iostream>
#include "../Imagenex852.hpp"
#include "dumper852.hpp"

void printUsage(){
	std::cerr << "Usage: dump852 filename.852 outputFilename" << std::endl;
	exit(1);
}


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
