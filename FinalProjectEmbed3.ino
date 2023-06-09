#include <PS2Keyboard.h>
#include "RTClib.h"
#include <MD_Parola.h>
#include <SPI.h>
#include <Wire.h>
#include <fontDigiClock.h>

const int KeyData = 8;
const int KeyClk  = 3;
PS2Keyboard keyboard;
RTC_DS1307 rtc;

#define HARDWARE_TYPE MD_MAX72XX::FC16_HW
#define MAX_DEVICES 4
#define CLK_PIN   13
#define DATA_PIN  11
#define CS_PIN 10


MD_Parola P = MD_Parola(HARDWARE_TYPE, CS_PIN, MAX_DEVICES);
//mengontrol modul dot matrix

MD_MAX72XX::fontType_t FontEmbed[] PROGMEM = 
{
	0, 	// 0
	0, 	// 1
	0, 	// 2
	0, 	// 3
	0, 	// 4
	0, 	// 5
	0, 	// 6
	0, 	// 7
	0, 	// 8
	0, 	// 9
	0, 	// 10
	0, 	// 11
	0, 	// 12
	0, 	// 13
	0, 	// 14
	0, 	// 15
	0, 	// 16
	0, 	// 17
	0, 	// 18
	0, 	// 19
	0, 	// 20
	0, 	// 21
	0, 	// 22
	0, 	// 23
	0, 	// 24
	0, 	// 25
	0, 	// 26
	0, 	// 27
	0, 	// 28
	0, 	// 29
	0, 	// 30
	0, 	// 31
	1, 0, 	// 32
	0, 	// 33
	0, 	// 34
	0, 	// 35
	0, 	// 36
	0, 	// 37
	0, 	// 38
	0, 	// 39
	0, 	// 40
	0, 	// 41
	0, 	// 42
	0, 	// 43
	1, 48, 	// 44
	2, 8, 8, 	// 45
	1, 32, 	// 46
	0, 	// 47
	3, 62, 34, 62, 	// 48
	3, 0, 62, 0, 	// 49
	3, 58, 42, 46, 	// 50
	3, 42, 42, 62, 	// 51
	3, 14, 8, 62, 	// 52
	3, 46, 42, 58, 	// 53
	3, 62, 42, 58, 	// 54
	3, 50, 10, 6, 	// 55
	3, 62, 42, 62, 	// 56
	3, 46, 42, 62, 	// 57
	1, 20, 	// 58
	1, 52, 	// 59
	0, 	// 60
	2, 20, 20, 	// 61
	0, 	// 62
	0, 	// 63
	0, 	// 64
	4, 60, 10, 10, 60, 	// 65
	4, 62, 42, 42, 20, 	// 66
	4, 28, 34, 34, 20, 	// 67
	4, 62, 34, 34, 28, 	// 68
	4, 62, 42, 42, 42, 	// 69
	4, 62, 10, 10, 10, 	// 70
	4, 28, 34, 42, 58, 	// 71
	4, 62, 8, 8, 62, 	// 72
	3, 34, 62, 34, 	// 73
	4, 18, 34, 34, 30, 	// 74
	4, 62, 8, 20, 34, 	// 75
	4, 62, 32, 32, 32, 	// 76
	5, 62, 4, 8, 4, 62, 	// 77
	4, 62, 4, 8, 62, 	// 78
	4, 28, 34, 34, 28, 	// 79
	4, 62, 10, 10, 4, 	// 80
	4, 4, 10, 10, 62, 	// 81
	4, 62, 10, 10, 52, 	// 82
	4, 4, 42, 42, 16, 	// 83
	5, 2, 2, 62, 2, 2, 	// 84
	4, 30, 32, 32, 30, 	// 85
	5, 14, 16, 32, 16, 14, 	// 86
	5, 30, 32, 28, 32, 30, 	// 87
	4, 54, 8, 8, 54, 	// 88
	4, 6, 40, 40, 30, 	// 89
	4, 34, 50, 42, 38, 	// 90
	0, 	// 91
	0, 	// 92
	0, 	// 93
	0, 	// 94
	0, 	// 95
	0, 	// 96
	0, 	// 97
	0, 	// 98
	0, 	// 99
	0, 	// 100
	0, 	// 101
	0, 	// 102
	0, 	// 103
	0, 	// 104
	0, 	// 105
	0, 	// 106
	0, 	// 107
	0, 	// 108
	0, 	// 109
	0, 	// 110
	0, 	// 111
	0, 	// 112
	0, 	// 113
	0, 	// 114
	0, 	// 115
	0, 	// 116
	0, 	// 117
	0, 	// 118
	0, 	// 119
	0, 	// 120
	0, 	// 121
	0, 	// 122
	0, 	// 123
	0, 	// 124
	0, 	// 125
	0, 	// 126
	0, 	// 127
	0, 	// 128
	0, 	// 129
	0, 	// 130
	0, 	// 131
	0, 	// 132
	0, 	// 133
	0, 	// 134
	0, 	// 135
	0, 	// 136
	0, 	// 137
	0, 	// 138
	0, 	// 139
	0, 	// 140
	0, 	// 141
	0, 	// 142
	0, 	// 143
	0, 	// 144
	0, 	// 145
	0, 	// 146
	0, 	// 147
	0, 	// 148
	0, 	// 149
	0, 	// 150
	0, 	// 151
	0, 	// 152
	0, 	// 153
	0, 	// 154
	0, 	// 155
	0, 	// 156
	0, 	// 157
	0, 	// 158
	0, 	// 159
	0, 	// 160
	0, 	// 161
	0, 	// 162
	0, 	// 163
	0, 	// 164
	0, 	// 165
	0, 	// 166
	0, 	// 167
	0, 	// 168
	0, 	// 169
	0, 	// 170
	0, 	// 171
	0, 	// 172
	0, 	// 173
	0, 	// 174
	0, 	// 175
	2, 6, 6, 	// 176
	0, 	// 177
	0, 	// 178
	0, 	// 179
	0, 	// 180
	0, 	// 181
	0, 	// 182
	0, 	// 183
	0, 	// 184
	0, 	// 185
	0, 	// 186
	0, 	// 187
	0, 	// 188
	0, 	// 189
	0, 	// 190
	0, 	// 191
	0, 	// 192
	0, 	// 193
	0, 	// 194
	0, 	// 195
	0, 	// 196
	0, 	// 197
	0, 	// 198
	0, 	// 199
	0, 	// 200
	0, 	// 201
	0, 	// 202
	0, 	// 203
	0, 	// 204
	0, 	// 205
	0, 	// 206
	0, 	// 207
	0, 	// 208
	0, 	// 209
	0, 	// 210
	0, 	// 211
	0, 	// 212
	0, 	// 213
	0, 	// 214
	0, 	// 215
	0, 	// 216
	0, 	// 217
	0, 	// 218
	0, 	// 219
	0, 	// 220
	0, 	// 221
	0, 	// 222
	0, 	// 223
	0, 	// 224
	0, 	// 225
	0, 	// 226
	0, 	// 227
	0, 	// 228
	0, 	// 229
	0, 	// 230
	0, 	// 231
	0, 	// 232
	0, 	// 233
	0, 	// 234
	0, 	// 235
	0, 	// 236
	0, 	// 237
	0, 	// 238
	0, 	// 239
	0, 	// 240
	0, 	// 241
	0, 	// 242
	0, 	// 243
	0, 	// 244
	0, 	// 245
	0, 	// 246
	0, 	// 247
	0, 	// 248
	0, 	// 249
	0, 	// 250
	0, 	// 251
	0, 	// 252
	0, 	// 253
	0, 	// 254
	0, 	// 255
};

void setup() {
  Serial.begin(9600);
  P.begin();
  pinMode(2, OUTPUT);
  keyboard.begin (KeyData, KeyClk);
  
  if (! rtc.begin()) {
    Serial.println("Couldn't find RTC");
    Serial.flush();
    while (1) delay(10);
  }

  if (! rtc.isrunning()) {
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
    // This line sets the RTC with an explicit date & time, for example to set
    // January 21, 2014 at 3am you would call:
    // rtc.adjust(DateTime(2014, 1, 21, 3, 0, 0));
  }

  P.setFont(FontEmbed);
  P.setIntensity(0);

  P.displayText("MUHAMMAD RASYID IBENZANI - 5024201044" , PA_CENTER, 50, 0, PA_SCROLL_LEFT, PA_SCROLL_LEFT);
  while (!P.displayAnimate());
}

String Month;
String Year;
String Date;

String Hour;
String Minute;
String Second;
String Temp;
String Clock;


void loop()
{
  
  int brightness = analogRead(A0);
  
  int SensorSuhu = analogRead (A1);
  float tegangan = SensorSuhu * (5.0/1023.0);

  digitalWrite(2, LOW);

  if(brightness <= 530)
  {
    P.setIntensity(0);    
  }
  else if (brightness >= 540)
  {
    P.setIntensity(10);
  }
  DateTime now = rtc.now();
  Date = now.day();
  Month = now.month();
  if (Month.length() < 2){
    Month = "0" + Month;
  }  

  Year = now.year() - 2000;
  

  Hour = now.hour();
  if (Hour.length() < 2)
  {
    Hour = "0"+ Hour;
  }
 

  Minute = now.minute();
  if (Minute.length() < 2)
  {
    Minute = "0"+ Minute;
  }

  Second = now.second();
  if (Second.length() < 2)
  {
    Second = "0"+ Second;
  }


  float temperatur = tegangan * 100;
  float t = (float)temperatur/1.0;
  Temp = String(t,1);
  Temp = Temp + "°C";

  char *TEMP = Temp.c_str();

  if (now.second()%2 == 0){
    Clock = Hour + ":" + Minute + ":" + Second;
  }
  else{
    Clock = Hour + " " + Minute + " " + Second;
  }

  char *ClockC = Clock.c_str();

  String DATE = Date + "-" + Month + "-" + Year;
  char *DateC = DATE.c_str();

  

   
  if (now.second() == 10 || now.second() == 40){
    P.displayText(DateC, PA_CENTER, 50, 3000, PA_SCROLL_DOWN, PA_NO_EFFECT);
    while (!P.displayAnimate());
  }
  else if (now.second() == 13 || now.second() == 43){
    P.displayText(TEMP, PA_CENTER, 50, 1000, PA_OPENING, PA_NO_EFFECT);
    while (!P.displayAnimate());
  }
  P.displayText(ClockC, PA_CENTER, 50, 50, PA_NO_EFFECT, PA_NO_EFFECT);
    while (!P.displayAnimate());  

    if (keyboard.available())
  {
    char Key = keyboard.read();

    if (Key == 1){
      P.displayText(DateC, PA_CENTER, 50, 3000, PA_SCROLL_DOWN, PA_NO_EFFECT);
    while (!P.displayAnimate());
    }
    else if (Key == 2){
      P.displayText(TEMP, PA_CENTER, 50, 1000, PA_OPENING, PA_NO_EFFECT);
    while (!P.displayAnimate());
    }
    else if (Key == 3){
      
    }
  }
}