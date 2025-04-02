//**********************************************************************************************************
//*    audioI2S-- I2S audiodecoder for ESP32,                                                              *
//**********************************************************************************************************


//#include "Arduino.h"
#include "Audio.h"
#include "SPI.h"
#include "SD.h"
#include "FS.h"

// Digital I/O used
#define SD_CS         48
#define SPI_SCK       21
#define SPI_MOSI      14
#define SPI_MISO      47


#define I2S_DOUT      7
#define I2S_BCLK      15
#define I2S_LRC       16







Audio audio;



void setup_SD() {
  
    pinMode(SD_CS, OUTPUT);      
    digitalWrite(SD_CS, HIGH);
    
    SPI.begin(SPI_SCK, SPI_MISO, SPI_MOSI);
    SPI.setFrequency(1000000);
    
    //Serial.begin(115200);
    SD.begin(SD_CS);
    
    audio.setPinout(I2S_BCLK, I2S_LRC, I2S_DOUT);
    audio.setVolume(12); // 0...21

    audio.connecttoFS(SD, "1.wav");
}

//void loop()
//{
//    audio.loop();
//}

// optional
void audio_info(const char *info){
    Serial.print("info        "); Serial.println(info);
}
void audio_id3data(const char *info){  //id3 metadata
    Serial.print("id3data     ");Serial.println(info);
}
void audio_eof_mp3(const char *info){  //end of file
    Serial.print("eof_mp3     ");Serial.println(info);
}
void audio_showstation(const char *info){
    Serial.print("station     ");Serial.println(info);
}
void audio_showstreamtitle(const char *info){
    Serial.print("streamtitle ");Serial.println(info);
}
void audio_bitrate(const char *info){
    Serial.print("bitrate     ");Serial.println(info);
}
void audio_commercial(const char *info){  //duration in sec
    Serial.print("commercial  ");Serial.println(info);
}
void audio_icyurl(const char *info){  //homepage
    Serial.print("icyurl      ");Serial.println(info);
}
void audio_lasthost(const char *info){  //stream URL played
    Serial.print("lasthost    ");Serial.println(info);
}


void send_SD_serial(String SD_command){       /* Função que envia os comandos seriais lidos da tela para o modulo Bluetooth/SD */

  Serial.print ( SD_command );
  
  }


  
