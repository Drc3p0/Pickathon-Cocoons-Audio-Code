/*
teensy3.2 recieves data from teensy3.2 web server
1-5 serial1
data format is '[' start character, COCOON#, other data, other data, (up to 20 bytes), ']' end character
 
 */
#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>
#include "AudioSample1.h"
#include "AudioSample2.h"
#include "AudioSample3.h"
#include "AudioSample4.h"
#include "AudioSample5.h"
#include "AudioSample6.h"
#include "AudioSample7.h"
#include "AudioSample8.h"
#include "AudioSample9.h"
#include "AudioSample10.h"
#include "AudioSample11.h"
#include "AudioSample12.h"
#include "AudioSample13.h"
#include "AudioSample14.h"
#include "AudioSample15.h"
#include "AudioSample16.h"
#include "AudioSample17.h"
#include "AudioSample18.h"
#include "AudioSample19.h"
#include "AudioSample20.h"


// GUItool: begin automatically generated code
AudioPlayMemory          playMem3;       //xy=385.5555419921875,235.2222137451172
AudioPlayMemory          playMem2;       //xy=387.5555419921875,194.2222137451172
AudioPlayMemory          playMem4;       //xy=389.8888931274414,268.33335971832275
AudioPlayMemory          playMem1;       //xy=399.5555419921875,162.2222137451172
AudioPlayMemory          playMem5;       //xy=418.5555419921875,336.2222137451172
AudioPlayMemory          playMem6;       //xy=430.5555419921875,369.2222137451172
AudioPlayMemory          playMem9;       //xy=448.5555419921875,473.2222137451172
AudioPlayMemory          playMem8;       //xy=451.5555419921875,438.2222137451172
AudioPlayMemory          playMem10;      //xy=459.5555419921875,518.2222137451172
AudioPlayMemory          playMem7;       //xy=463.5555419921875,403.2222137451172
AudioPlayMemory          playMem11;      //xy=490.5555419921875,564.2222137451172
AudioPlayMemory          playMem13;      //xy=516.5555419921875,639.2222137451172
AudioPlayMemory          playMem17;      //xy=520.4444923400879,291.44454288482666
AudioPlayMemory          playMem12;      //xy=524.5555419921875,606.2222137451172
AudioPlayMemory          playMem14;      //xy=528.5555419921875,678.2222137451172
AudioPlayMemory          playMem15;      //xy=535.5555419921875,713.2222137451172
AudioPlayMemory          playMem16;      //xy=589.5555419921875,754.2222137451172
AudioPlayMemory          playMem18;      //xy=616.2221984863281,422.0000476837158
AudioMixer4              Mix1;           //xy=639.5555419921875,202.2222137451172
AudioPlayMemory          playMem19;      //xy=658.9999694824219,556.777811050415
AudioPlayMemory          playMem20;      //xy=695.1110916137695,681.0000400543213
AudioMixer4              Mix2;           //xy=773.6666564941406,332.66669845581055
AudioMixer4              Mix3;           //xy=788.666675567627,479.88889503479004
AudioMixer4              Mix4;           //xy=834.6666374206543,600.2223281860352
AudioMixer4              Mix5;           //xy=853.0000038146973,737.6667175292969
AudioMixer4              Mix6;           //xy=1052.4444732666016,516.1111259460449
AudioMixer4              Mix7;           //xy=1085.9999504089355,380.333402633667
AudioOutputI2S           i2s2;           //xy=1267.111125946045,441.7777900695801
AudioConnection          patchCord1(playMem3, 0, Mix1, 2);
AudioConnection          patchCord2(playMem2, 0, Mix1, 1);
AudioConnection          patchCord3(playMem4, 0, Mix1, 3);
AudioConnection          patchCord4(playMem1, 0, Mix1, 0);
AudioConnection          patchCord5(playMem5, 0, Mix2, 1);
AudioConnection          patchCord6(playMem6, 0, Mix2, 2);
AudioConnection          patchCord7(playMem9, 0, Mix3, 2);
AudioConnection          patchCord8(playMem8, 0, Mix3, 1);
AudioConnection          patchCord9(playMem10, 0, Mix3, 3);
AudioConnection          patchCord10(playMem7, 0, Mix2, 3);
AudioConnection          patchCord11(playMem11, 0, Mix4, 1);
AudioConnection          patchCord12(playMem13, 0, Mix4, 3);
AudioConnection          patchCord13(playMem17, 0, Mix2, 0);
AudioConnection          patchCord14(playMem12, 0, Mix4, 2);
AudioConnection          patchCord15(playMem14, 0, Mix5, 1);
AudioConnection          patchCord16(playMem15, 0, Mix5, 2);
AudioConnection          patchCord17(playMem16, 0, Mix5, 3);
AudioConnection          patchCord18(playMem18, 0, Mix3, 0);
AudioConnection          patchCord19(Mix1, 0, Mix7, 1);
AudioConnection          patchCord20(playMem19, 0, Mix4, 0);
AudioConnection          patchCord21(playMem20, 0, Mix5, 0);
AudioConnection          patchCord22(Mix2, 0, Mix6, 0);
AudioConnection          patchCord23(Mix3, 0, Mix6, 1);
AudioConnection          patchCord24(Mix4, 0, Mix6, 2);
AudioConnection          patchCord25(Mix5, 0, Mix6, 3);
AudioConnection          patchCord26(Mix6, 0, Mix7, 3);
AudioConnection          patchCord27(Mix7, 0, i2s2, 0);
AudioConnection          patchCord28(Mix7, 0, i2s2, 1);
AudioControlSGTL5000     sgtl5000_1;     //xy=891.5555419921875,210.2222137451172
// GUItool: end automatically generated code




long previousMillis = 0;
long interval = 1000;

int led = 13;

// Use these with the Teensy Audio Shield
  #define SDCARD_CS_PIN    10
  #define SDCARD_MOSI_PIN  7
  #define SDCARD_SCK_PIN   14

// Use these with the Teensy 3.5 & 3.6 SD card
//#define SDCARD_CS_PIN    BUILTIN_SDCARD
//#define SDCARD_MOSI_PIN  11  // not actually used
//#define SDCARD_SCK_PIN   13  // not actually used


byte logIncrement = 0;
const int sizeDataLog = 20;
byte dataLog[sizeDataLog] = {0};


void setup() {
  Serial4.begin(9600);
  Serial4.setTimeout(50);
  Serial.begin(9600);
  pinMode(led, OUTPUT);
  // Audio connections require memory to work.  For more
  // detailed information, see the MemoryAndCpuUsage example
  AudioMemory(50);

  // Comment these out if not using the audio adaptor board.
  // This may wait forever if the SDA & SCL pins lack
  // pullup resistors
  sgtl5000_1.enable();
  sgtl5000_1.volume(0.8);


  Mix1.gain(0, 0.80);
  Mix1.gain(1, 0.80);
  Mix1.gain(2, 0.80);
  Mix1.gain(3, 0.80);
  Mix2.gain(0, 0.80);
  Mix2.gain(1, 0.80);
  Mix2.gain(2, 0.80);
  Mix2.gain(3, 0.80);
  Mix3.gain(0, 0.80);
  Mix3.gain(1, 0.80);
  Mix3.gain(2, 0.80);
  Mix3.gain(3, 0.80);
  Mix4.gain(0, 0.80);
  Mix4.gain(1, 0.80);
  Mix4.gain(2, 0.80);
  Mix4.gain(3, 0.80);
  Mix5.gain(0, 0.80);
  Mix5.gain(1, 0.80);
  Mix5.gain(2, 0.80);
  Mix5.gain(3, 0.80);
  Mix6.gain(0, 0.80);
  Mix6.gain(1, 0.80);
  Mix6.gain(2, 0.80);
  Mix6.gain(3, 0.80);
  Mix7.gain(0, 0.80);
  Mix7.gain(1, 0.80);
  Mix7.gain(2, 0.80);
  Mix7.gain(3, 0.80);
  
    //  SPI.setMOSI(SDCARD_MOSI_PIN);
   //   SPI.setSCK(SDCARD_SCK_PIN);
  //if (!(SD.begin(SDCARD_CS_PIN))) {
    // stop here, but print a message repetitively
   // while (1) {
     // Serial.println("Unable to access the SD card");
   //   delay(500);
 //   }
 // }
  
}

void loop() {
  unsigned long currentMillis = millis();
digitalWrite(led, HIGH);


  if (Serial4.available()) {
    int foundInt = Serial4.parseInt();
    Serial.println(foundInt);
    if(foundInt == 91){ //new data
      //Serial.println("new data");
      logIncrement = 0;
    }
    dataLog[logIncrement] = foundInt;
    logIncrement++;
    if(foundInt == 93 ){ //got all the data.... added && logIncrement < 5
      Serial.println("got all the data");
      playSound();
    }
  }
}

void playSound(){
  //for(int i = 0; i<logIncrement; i++){
    //Serial.print(dataLog[i]);
    //Serial.print(",");
  //}
  //Serial.println();
//1-5
  if (dataLog[1] == 1 && playMem1.isPlaying() == 0) {
    playMem1.play(AudioSample1);
         Serial.println("we're playing #1");
  } 
  
  else if (dataLog[1] == 1 && playMem1.isPlaying() != 0) {
    playMem1.stop();
    playMem1.play(AudioSample1);
         Serial.println("we're re-playing #1");
  }

  
  if (dataLog[1] == 2 && playMem2.isPlaying() == 0) {
    playMem2.play(AudioSample2);
     Serial.println("we're playing #2");
  }
  else  if (dataLog[1] == 2 && playMem2.isPlaying() != 0) {
    playMem2.stop();
    playMem2.play(AudioSample2);
     Serial.println("we're re-playing #2");
  }

  
  if (dataLog[1] == 3 && playMem3.isPlaying() == 0) {
    playMem3.play(AudioSample3);
         Serial.println("we're playing #3");
  }
  else if (dataLog[1] == 3 && playMem3.isPlaying() != 0) {
    playMem3.stop();
    playMem3.play(AudioSample3);
         Serial.println("we're re-playing #3");
  }
  
  if (dataLog[1] == 4 && playMem4.isPlaying() == 0) {
    playMem4.play(AudioSample4);
     Serial.println("we're playing #4");
  }
  else  if (dataLog[1] == 4 && playMem4.isPlaying() != 0) {
    playMem4.stop();
    playMem4.play(AudioSample4);
     Serial.println("we're re-playing #4");
  }

  
  if (dataLog[1] == 5 && playMem5.isPlaying() == 0) {
    playMem5.play(AudioSample5);
         Serial.println("we're playing #5");
  }
  else  if (dataLog[1] == 5 && playMem5.isPlaying() != 0) {
    playMem5.stop();
    playMem5.play(AudioSample5);
         Serial.println("we're re-playing #5");
  }

    if (dataLog[1] == 6 && playMem6.isPlaying() == 0) {
    playMem6.play(AudioSample6);
         Serial.println("we're playing #6");
  }
  else if (dataLog[1] == 6 && playMem6.isPlaying() != 0) {
    playMem6.stop();
    playMem6.play(AudioSample6);
         Serial.println("we're re-playing #6");
  }

  
  if (dataLog[1] == 7 && playMem7.isPlaying() == 0) {
    playMem7.play(AudioSample7);
     Serial.println("we're playing #7");
  }
  else  if (dataLog[1] == 7 && playMem7.isPlaying() != 0) {
    playMem7.stop();
    playMem7.play(AudioSample7);
     Serial.println("we're re-playing #7");
  }

  
  if (dataLog[1] == 8 && playMem8.isPlaying() == 0) {
    playMem8.play(AudioSample8);
         Serial.println("we're playing #8");
  }
  else  if (dataLog[1] == 8 && playMem8.isPlaying() != 0) {
    playMem8.stop();
    playMem8.play(AudioSample8);
         Serial.println("we're re-playing #8");
  }
  
  if (dataLog[1] == 9 && playMem9.isPlaying() == 0) {
    playMem9.play(AudioSample9);
     Serial.println("we're playing #9");
  }
  else  if (dataLog[1] == 9 && playMem9.isPlaying() != 0) {
    playMem9.stop();
    playMem9.play(AudioSample9);
     Serial.println("we're re-playing #9");
  }

  
  if (dataLog[1] == 10 && playMem10.isPlaying() == 0) {
    playMem10.play(AudioSample10);
         Serial.println("we're playing #10");
  }
  else  if (dataLog[1] == 10 && playMem10.isPlaying() != 0) {
    playMem10.stop();
    playMem10.play(AudioSample10);
         Serial.println("we're re-playing #10");
  }
  
  if (dataLog[1] == 11 && playMem11.isPlaying() == 0) {
    playMem11.play(AudioSample11);
         Serial.println("we're playing #11");
  }
  else if (dataLog[1] == 11 && playMem11.isPlaying() != 0) {
    playMem11.stop();
    playMem11.play(AudioSample11);
         Serial.println("we're re-playing #11");
  }

  
  if (dataLog[1] == 12 && playMem12.isPlaying() == 0) {
    playMem12.play(AudioSample12);
     Serial.println("we're playing #12");
  }
  else  if (dataLog[1] == 12 && playMem12.isPlaying() != 0) {
    playMem12.stop();
    playMem12.play(AudioSample12);
     Serial.println("we're re-playing #12");
  }

  
  if (dataLog[1] == 13 && playMem13.isPlaying() == 0) {
    playMem13.play(AudioSample13);
         Serial.println("we're playing #13");
  }
  else  if (dataLog[1] == 13 && playMem13.isPlaying() != 0) {
    playMem13.stop();
    playMem13.play(AudioSample13);
         Serial.println("we're re-playing #13");
  }
  
  if (dataLog[1] == 14 && playMem14.isPlaying() == 0) {
    playMem14.play(AudioSample14);
     Serial.println("we're playing #14");
  }
   else if (dataLog[1] == 14 && playMem14.isPlaying() != 0) {
    playMem14.stop();
    playMem14.play(AudioSample14);
     Serial.println("we're re-playing #14");
  }

  
  if (dataLog[1] == 15 && playMem15.isPlaying() == 0) {
    playMem15.play(AudioSample15);
         Serial.println("we're playing #15");
  }
  else if (dataLog[1] == 15 && playMem15.isPlaying() != 0) {
    playMem15.stop();
    playMem15.play(AudioSample15);
         Serial.println("we're re-playing #15");
  }

    if (dataLog[1] == 16 && playMem16.isPlaying() == 0) {
    playMem16.play(AudioSample16);
         Serial.println("we're playing #16");
  }
 else  if (dataLog[1] == 16 && playMem16.isPlaying() != 0) {
    playMem16.stop();
    playMem16.play(AudioSample16);
         Serial.println("we're re-playing #16");
  }

  
  if (dataLog[1] == 17 && playMem17.isPlaying() == 0) {
    playMem17.play(AudioSample17);
     Serial.println("we're playing #17");
  }
  else if (dataLog[1] == 17 && playMem17.isPlaying() != 0) {
    playMem17.stop();
    playMem17.play(AudioSample17);
     Serial.println("we're re-playing #17");
  }

  
  if (dataLog[1] == 18 && playMem18.isPlaying() == 0) {
    playMem18.play(AudioSample18);
         Serial.println("we're playing #18");
  }
    else  if (dataLog[1] == 18 && playMem18.isPlaying() != 0) {
      playMem18.stop();
      playMem18.play(AudioSample18);
           Serial.println("we're re-playing #18");
    }
  
  if (dataLog[1] == 19 && playMem19.isPlaying() == 0) {
    playMem19.play(AudioSample19);
     Serial.println("we're playing #19");
  }
   else if (dataLog[1] == 19 && playMem19.isPlaying() != 0) {
    playMem19.stop();
    playMem19.play(AudioSample19);
     Serial.println("we're re-playing #19");
  }

  
  if (dataLog[1] == 20 && playMem20.isPlaying() == 0) {
    playMem20.play(AudioSample20);
         Serial.println("we're playing #20");
  }
  
  else  if (dataLog[1] == 20 && playMem20.isPlaying() != 0) {
    playMem20.stop();
    playMem20.play(AudioSample20);
         Serial.println("we're re-playing #20");
  }
  



}

