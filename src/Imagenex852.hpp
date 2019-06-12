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

#pragma pack(1)
typedef struct{
        char            magic[3];
        uint8_t         headId;
        uint8_t         serialStatus;
	uint16_t	reserved1;
	uint8_t		range;
	uint16_t	profileRange;
	uint16_t	dataBytes;
} Imagenex852ReturnDataHeader;
#pragma pack()

class Imagenex852{
	public:
		void read(std::string & filename){
			std::ifstream in(filename,std::ios::binary);

			if(in){
				Imagenex852FileHeader hdr;

				//Read file header
				while(in.read((char*)&hdr,sizeof(Imagenex852FileHeader))){
					if(
						hdr.magic[0]=='8' &&
						hdr.magic[1]=='5' &&
						hdr.magic[2]=='2'
					){
						printf("Got file header\n");

						//TODO: process file header

						Imagenex852ReturnDataHeader returnDataHdr;

						if(in.read((char*)&returnDataHdr,sizeof(Imagenex852ReturnDataHeader))){
							unsigned int payloadBytes = (hdr.nToReadIndex==0)?0:((hdr.nToReadIndex==2)?252:500);
							uint8_t	     echoData[501];

							printf("Got return data header\n");

							if(in.read((char*)&echoData,payloadBytes)){
								//Todo: process payload bytes
								uint8_t terminationByte;

								printf("Got payload (%d bytes)\n",payloadBytes);

								//read termination byte
								if(in.read((char*)&terminationByte,1)){
									if(terminationByte == 0xFC){
										unsigned int paddingSize = ((hdr.nToReadIndex==0)?127:((hdr.nToReadIndex==2)?383:639)) - payloadBytes - sizeof(Imagenex852FileHeader) - sizeof(Imagenex852ReturnDataHeader)  ;

										if(!in.read((char*)&echoData,paddingSize)){
											throw new Exception("Error while reading padding\n");
										}
									}
									else{
										throw new Exception("Bad termination byte found at the end of packet");
									}
								}
								else{
									throw new Exception("No termination byte found at the end of packet");
								}
							}
						}
						else{
							throw new Exception("No return data header");
						}
					}
					else{
						throw new Exception("Invalid 852 file header");
					}
				}

				in.close();
			}
			else{
				throw new Exception("Cannot open file");
			}
		};

};

#endif
