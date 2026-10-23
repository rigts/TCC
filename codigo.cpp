#include "EmonLib.h" 
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2); EnergyMonitor emon1; 

void setup() {
  lcd.init(); 
  lcd.backlight(); 

  emon1.voltage(A1, 12, 0); 
  emon1.current(A0, 5.5); 

  lcd.setCursor(0, 0);
  lcd.print("  INICIALIZANDO "); 
  delay(2000);
  lcd.clear(); 
} 

void loop() { 
  emon1.calcVI(20,2000);
  lcd.setCursor(0, 0); 
  if (emon1.Vrms < 10.0) lcd.print(" ");
  lcd.print(emon1.Vrms,1); 
  lcd.print("V  ");
  if (emon1.Irms < 10.0) lcd.print(" ");
  lcd.print(emon1.Irms,2);
  lcd.print("A  ");
  lcd.setCursor(0, 1); 
  lcd.print("Pow: "); 
  if (emon1.realPower < 10.0) lcd.print(" "); 
  lcd.print(emon1.realPower,1); 
  lcd.print(" W   "); 
}
