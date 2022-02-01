


#include <SpeedData.h>
#include <LiquidCrystal.h>

LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

//#define Uno   //Descomente essa linha caso utilizar um Arduino UNO
#define Mega   //Descomente essa linha caso utilizar um Arduino Mega

#ifdef Uno
#include <SoftwareSerial.h>
SoftwareSerial mySerial(2, 3); // RX, TX
#endif

#ifdef Mega
SpeedData SData(&Serial1);		// Serail 1 Mega
#endif

#ifdef Uno
SpeedData SData(&mySerial);		// SoftwareSerial Uno
#endif

void setup() {
  lcd.begin(16,2);
  lcd.setCursor(0,0); lcd.print("   Speeduino");
  lcd.setCursor(0,1); lcd.print("   Dashboard");
  delay(1500);
  lcd.clear();
 
  #ifdef Uno
  mySerial.begin(115200); //Serial dedicada ao acesso Can do Speeduino via Serial3
  Serial.begin(115200); 
  #endif

  #ifdef Mega
  Serial.begin(115200); 
  Serial1.begin(115200);  //Deletar essa linha caso esteja usando um ARDUINO UNO ou similar
  #endif
 
}

void loop() {

int RPM = SData.getRPM(100);
float AFR = SData.getActualAFR(100);
int BAT = SData.getBattVoltage(500);
int CLT = SData.getWaterTemp(1000);
   
lcd.setCursor(0,0); lcd.print("RPM:"); lcd.print(RPM);
lcd.setCursor(0,1); lcd.print("AFR:"); lcd.print(AFR,1);
lcd.setCursor(9,0); lcd.print("BAT:"); lcd.print(BAT);
lcd.setCursor(9,1); lcd.print("CLT:"); lcd.print(CLT);




   
}
