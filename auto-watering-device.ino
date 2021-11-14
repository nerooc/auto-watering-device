#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

const int analogInPin_moisture = A0;
const int analogInPin_waterLevel = A1;

const int digitalOutPin_waterPump = 13;

// Set the LCD address to 0x27 for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x27,20,4);

int sensorValue_moisture = 0;
int sensorValue_waterLevel = 0;

int mappedValue_moisture = 0;
int mappedValue_waterLevel = 0;

bool flowerNeedsWater = false;
bool tankIsEmpty = false;

void setup() {
  // Initialize serial communications at 9600 bps
  Serial.begin(9600); 
  
  lcd.init();
  lcd.backlight();
  pinMode(digitalOutPin_waterPump, OUTPUT);
}

void loop() {
  sensorValue_moisture = analogRead(analogInPin_moisture);
  sensorValue_waterLevel = analogRead(analogInPin_waterLevel);

  mappedValue_moisture = map(sensorValue_moisture, 0, 1023, 0, 100);
  mappedValue_waterLevel = map(sensorValue_waterLevel, 0, 1023, 0, 100);

  flowerNeedsWater = mappedValue_moisture <= 40;
  tankIsEmpty = mappedValue_waterLevel <= 30;

//  analogWrite(analogOutPin0, 1); // raport do Labview?

  Serial.print("Wilgotnosc: ");
  Serial.print(sensorValue_moisture);
  Serial.print("\t");
  Serial.print("Poziom wody: ");
  Serial.println(sensorValue_waterLevel);

  Serial.print("Wilgotnosc (map): ");
  Serial.print(mappedValue_moisture);
  Serial.print("\t");
  Serial.print("Poziom wody (map): ");
  Serial.println(mappedValue_waterLevel);

//  Serial.println(flowerNeedsWater);
//  Serial.println(tankIsNotEmpty);

  // LCD
  lcd.clear();
  lcd.setCursor(0,0);
  if(tankIsEmpty) 
  {
    lcd.print("Tank needs water!");
  }
  else 
  {
    lcd.print("Tank is fine!");
    lcd.setCursor(0,1);
    lcd.print(mappedValue_waterLevel);
    lcd.print("%");
    digitalWrite(13, HIGH); // Sets the digital pin 13 on
    delay(1000);            // Waits for a second
    digitalWrite(13, LOW);  // Sets the digital pin 13 off
  }

  delay(1000);
}
