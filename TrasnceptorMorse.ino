#include <Morse.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);


int btnRST = 12;
int potTMR = 0;

int CodeIn; //Varaible asociadad a la funcion GetChar()


void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.clear();
  lcd.print("  MorseTrainer");
  lcd.setCursor(5, 1);
  lcd.print("V1.0");
  delay(5000);
  lcd.clear();
  pinMode(btnRST, INPUT_PULLUP);
  
  
  
}

void loop() {
 
int timeDot = timeDotSelect();
Morse Buzzer(13, timeDot); //Definimos el buzzer como un objeto de tipo morse
Morse led(14, timeDot); //Definimos el led como un objeto de tipo morse
  
  while(1){ //Aplicar Condición Menú
    CodeIn = getChar(); //Leemos una letra introducida por el pueto serie y la imprimimos por el puerto Serie
    Buzzer.morseConvert(CodeIn); //Se obtiene el código de la lera;
    lcd.print(char(CodeIn));
    delay(3*timeDot); 
  }
 
}



char getChar()// Get a character from the serial buffer
{
  while(Serial.available() == 0)
  {
      if(digitalRead(btnRST) == 0)
      {
        lcd.clear();
      }
  }
  
  return((char)Serial.read());
}

int timeDotSelect()
{
  int valPot;
  while(digitalRead(btnRST)== 1)
  {
    valPot = analogRead(potTMR);
    valPot = map(valPot, 0, 1023, 50, 250);
    lcd.print("Tiempo Dot:");
    lcd.print(valPot);
    lcd.print("ms");
    delay(500);
    lcd.clear();
  }
  
    lcd.print("Seleccionado");
  
  
    delay(3000);
    lcd.clear();
    return valPot;
}


