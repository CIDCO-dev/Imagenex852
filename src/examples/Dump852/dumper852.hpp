#ifndef DUMPER852_HPP
#define DUMPER852_HPP
#include <iostream>
#include "Imagenex852.hpp"
class Dumper852 : public Imagenex852{

    std::ofstream out;

public:
    Dumper852(std::string filename){
        out = std::ofstream(filename);
        out << "#Date Time Mode StartGain PulseLength SoundSpeed OperatingFrequency HeadID Range profileRange RawData" << std::endl;
    }

    ~Dumper852(){
        out.close();
    }

    void processPing(Imagenex852FileHeader &hdr,Imagenex852ReturnDataHeader & returnDataHdr,uint8_t * echoData,unsigned int payloadBytes){
            uint8_t  profileRangeHi = (returnDataHdr.profileRange[1] & 0x7E) >> 1;
            uint8_t  profileRangeLo = ((returnDataHdr.profileRange[1] & 0x01) << 7)|(returnDataHdr.profileRange[0] & 0x7F);
            uint16_t profileRange  = (profileRangeHi << 8) | (profileRangeLo);

	    double soundSpeed = ( hdr.soundSpeed[0] & 0x80 )? 1500.0 : (double) ((((uint16_t)(hdr.soundSpeed[0] & 0x7F)) << 8) | hdr.soundSpeed[1]) / (double) 10.0 ;

                        out << hdr.date << " "
                            << hdr.time << hdr.timeHundredsSeconds << " "
                            << unsigned((uint8_t)hdr.mode) << " "
                            << unsigned((uint8_t)hdr.startGain) << " "
                            << unsigned((uint8_t)hdr.pulseLength) << " "
                            << soundSpeed << " "
                            << unsigned((uint8_t)hdr.operatingFrequency) << " "
                            << unsigned((uint8_t)hdr.headId) << " "
                            << unsigned((uint8_t)returnDataHdr.range) << " "
                            << unsigned((uint16_t)profileRange) << " ";

            for(unsigned int i=0;i<payloadBytes;i++){
                //printf("%.2X ",(uint8_t)echoData[i]);
                out << unsigned((uint8_t)echoData[i]) << " ";
            }

            out << std::endl;
        }
};
#endif // DUMPER852_HPP
