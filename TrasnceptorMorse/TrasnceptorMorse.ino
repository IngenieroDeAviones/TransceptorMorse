#include <Morse.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE); //Definimos el display LCD


int btnRST = 12; //Botón para limpiar la pantalla
int potTMR = 0; //Potenciómetro para ajustar el tiempo

int CodeIn; //Varaible asociadad a la funcion GetChar()



void setup() 
{
  Serial.begin(9600); //Se inicia la comunicación Serie

  pinMode(btnRST, INPUT_PULLUP); //Definimos el botón de limpieza de pantalla
  
  lcd.begin(16, 2); //Se definen las propiedades de la pantalla LCD
  lcd.clear(); //Limpiamos pantalla para mostrar el mensaje de Bienvenida

  //Mensaje de Bienvenida al Usuario
  lcd.print("  MorseTrainer");
  lcd.setCursor(5, 1);
  lcd.print("V1.0");
  delay(1500);
  lcd.clear();
  lcd.print("Autor:  Jorge MG");
  delay(1000);
  lcd.clear();
  
}



void loop() 
{
 
  int timeDot = timeDotSelect();
  Morse Buzzer(13, timeDot); //Definimos el buzzer como un objeto de tipo morse
  Morse led(14, timeDot); //Definimos el led como un objeto de tipo morse
    
    while(1)
    { 
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
  int valPot; //Variable que almcavenará el valor del Potenciómetro

  while(digitalRead(btnRST)== 1) //Hasta que no se pulse el boton, no termina el ciclo
  {
    valPot = analogRead(potTMR);
    valPot = map(valPot, 0, 1023, 25, 250); //El tiempo de un punto oscilará entre [50, 250] milisegundos
    lcd.print("Tiempo Dot:");
    lcd.print(valPot);
    lcd.print("ms");
    delay(250);
    lcd.clear();
  }
  
  lcd.print("Seleccionado  :D");   
  delay(1000);
  lcd.clear();
  lcd.print("A JUGAR!!!");
  delay(1000);
  lcd.clear();

  return valPot;

}


