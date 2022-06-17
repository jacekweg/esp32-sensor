#include <Adafruit_BMP085.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
Adafruit_BMP085 bmp;
LiquidCrystal_I2C lcd(0x27, 16, 2);

byte degree_symbol[8] = 
              {
                0b00111,
                0b00101,
                0b00111,
                0b00000,
                0b00000,
                0b00000,
                0b00000,
                0b00000
              };
void setup()
{
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0,6);
  lcd.print("ESP32");
  lcd.setCursor(0,5);
  lcd.print("Sensor");
  lcd.createChar(0, degree_symbol);
  if (!bmp.begin())
  {
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("   BMP180   ");
    lcd.setCursor(0,1);
    lcd.print("   not found!   ");
    while (1)
    {
    
    }
  }
  delay(2000);
  lcd.clear();
}

void loop()
{
  lcd.setCursor(0,0);
  lcd.print("Press = ");
  lcd.setCursor(10,0);
  lcd.print(bmp.readPressure()/ 100);
  lcd.setCursor(12,0);
  lcd.print("hPa");

  lcd.setCursor(0,1);
  lcd.print("  Temp = ");
  lcd.setCursor(9,1);
  lcd.print(bmp.readTemperature());
  lcd.write(0);
  lcd.print("C");
  delay(1000);
}
