#ifndef IMAGENEX852_HPP
#define IMAGENEX852_HPP

#include <arpa/inet.h>
#include <string>
#include <sstream>
#include <fstream>
#include "../src/util/Exception.hpp"

/**
 * File data is in bigendian
 */

#pragma pack(1)
typedef struct{
    char 		magic[3];
    uint8_t 	nToReadIndex;
    uint16_t	totalBytes;
    uint16_t	nToRead;
    char		date[12];
    char		time[9];
    char		timeHundredsSeconds[4];
    uint8_t		reserved[4];
    uint8_t		mode;
    uint8_t		startGain;
    uint8_t		sectorSize; //   divided by 3
    uint8_t		trainAngle; // divided by 3
    uint8_t		reserved2;  //Always 0
    uint8_t		reserved3;  //Always 20
    uint8_t		reserved4;  //Always 9
    uint8_t		pulseLength; //in microSeconds
    uint8_t		profile; //0=off,1=points only,2=low mix,3=medium mix,4=high mix
    uint16_t	soundSpeed;
    char		userText[32];
    uint16_t	rovDepth;
    uint8_t		depthUnits;
    uint16_t	rovHeading;
    uint16_t	rovTurnsCounter;
    uint8_t		operatingFrequency;
    uint8_t		headId;
    char		reserved5[11]; //TODO: decortiquer selon la spec
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
            printf("Header size: %ld\n",sizeof(Imagenex852FileHeader));

            if(in){
                Imagenex852FileHeader hdr;

                //Read file header
                int incr = 100/sizeof(Imagenex852FileHeader);
                while(in.read((char*)&hdr,sizeof(Imagenex852FileHeader))){
                    if(
                        hdr.magic[0]=='8' &&
                        hdr.magic[1]=='5' &&
                        hdr.magic[2]=='2'
                    ){
                        printf("Got file header\n");

                        Imagenex852ReturnDataHeader returnDataHdr;

                        if(in.read((char*)&returnDataHdr,sizeof(Imagenex852ReturnDataHeader))){
                            unsigned int payloadBytes = (hdr.nToReadIndex==0)?0:((hdr.nToReadIndex==2)?252:500);
                            uint8_t	     echoData[501];

                            printf("Got return data header\n");

                            if(in.read((char*)&echoData,payloadBytes)){
                                uint8_t terminationByte;

                                printf("Got payload (%d bytes)\n",payloadBytes);

                                //read termination byte
                                if(in.read((char*)&terminationByte,1)){
                                    if(terminationByte == 0xFC){

                                        //Process received data
                                        processPing(hdr,returnDataHdr,echoData,payloadBytes);

                                        //Read zero-padded filler
                                        unsigned int paddingSize = ((hdr.nToReadIndex==0)?127:((hdr.nToReadIndex==2)?383:639)) - payloadBytes - sizeof(Imagenex852FileHeader) - sizeof(Imagenex852ReturnDataHeader);

                                        if(!in.read((char*)&echoData,paddingSize)){
                                            throw new Exception("Error while reading padding\n");
                                        }
                                    }
                                    else{
                                        printf("Termination byte: %.2X\n",terminationByte);
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

        virtual void processPing(Imagenex852FileHeader &hdr,Imagenex852ReturnDataHeader & returnDataHdr,uint8_t * echoData,unsigned int payloadBytes) = 0;
};

#endif
