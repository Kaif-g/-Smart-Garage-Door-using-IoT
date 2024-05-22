#include <LiquidCrystal.h>

#define D4 8
#define D5 9
#define D6 10
#define D7 11
#define E 12
#define RS 13


LiquidCrystal lcd(RS, E, D4, D5, D6, D7);  


#define PIR_sensor 14

#define m11 0

#define m12 1


void setup() 

{

  lcd.begin(16,2);

  pinMode(m11, OUTPUT);

  pinMode(m12, OUTPUT);

  pinMode(PIR_sensor, INPUT);

  lcd.print("    Smart    ");

  lcd.setCursor(0,1); 

  lcd.print("   Mall Door    ");

  delay(3000);

  lcd.clear();

  
}


void loop() 

{

  if(digitalRead(PIR_sensor))

  {

    lcd.setCursor(0,0);

    lcd.print("Movement Detected");

    lcd.setCursor(0, 1);

    lcd.print("    Door Opened    ");

    digitalWrite(m11, HIGH);         // gate opening

    digitalWrite(m12, LOW);

    delay(2000);

    digitalWrite(m11, LOW);          // gate stop for a while

    digitalWrite(m12, LOW);

    delay(3000);

    lcd.clear();

    lcd.print("   Door Closed    ");

    digitalWrite(m11, LOW);           // gate closing

    digitalWrite(m12, HIGH);

    delay(1000);

    digitalWrite(m11, LOW);            // gate closed

    digitalWrite(m12, LOW);

    delay(1000);

  }

  

  else 

  {

    lcd.setCursor(0,0);

    lcd.print("   No Movement   ");

    lcd.setCursor(0,1);

    lcd.print("   Door Closed   ");

    digitalWrite(m11, LOW);

    digitalWrite(m12, LOW);

  }

}


