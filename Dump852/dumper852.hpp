#ifndef DUMPER852_HPP
#define DUMPER852_HPP
#include <iostream>
#include "Imagenex852.hpp"
#include <QProgressDialog>
#include <QObject>
class Dumper852 : public Imagenex852{

    std::ofstream out;
    QProgressDialog pd;

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
#endif // DUMPER852_HPP
