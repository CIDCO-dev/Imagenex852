#include <iostream>
#include "Imagenex852.hpp"

void printUsage(){
	std::cerr << "Usage: read852 filename" << std::endl;
	exit(1);
}

int main(int argc,char **argv){
	try{
		if(argc != 2){
			printUsage();
		}

		Imagenex852 sonar;
		std::string filename = argv[1]; //TODO get from argv

		std::cerr << "Reading " << filename << std::endl;

		sonar.read(filename);
	}
	catch(Exception * e){
		std::cerr << e->getMessage() << std::endl;
	}
}
