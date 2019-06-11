#ifndef IMAGENEX852_HPP
#define IMAGENEX852_HPP

#include <arpa/inet.h>
#include <string>
#include <fstream>
#include "util/Exception.hpp"

/**
 * File data is in bigendian 
 */

#pragma pack(1)
typedef struct{
	char 		magic[3];
	uint8_t 	nToReadIndex;
	uint16_t	totalBytes;
	char		todo[94]; //TODO: decortiquer selon la spec
} Imagenex852FileHeader;
#pragma pack()


class Imagenex852{
	public:
		void read(std::string & filename){
			std::ifstream in(filename,std::ios::binary);

			if(in){
				int bytesToRead = sizeof(Imagenex852FileHeader);

				do{
					Imagenex852FileHeader hdr;

					if(in.read((char*)&hdr,sizeof(Imagenex852FileHeader))){
						if(
							hdr.magic[0]=='8' &&
							hdr.magic[1]=='5' &&
							hdr.magic[2]=='2'
						){
							std::cerr << "Got file header. Payload is " << hdr.nToReadIndex << " bytes" << std::endl;
							
						}
						else{
							throw new Exception("Invalid 852 file header");
						}
					}
					else{
						throw new Exception("Error while reader file header");
					}
				} while(bytesToRead > 0);

				in.close();
			}
			else{
				throw new Exception("Cannot open file");
			}
		};

};

#endif
