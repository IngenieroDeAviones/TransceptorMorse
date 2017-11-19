#include <Morse.h>

int timeDot = 35;

Morse Buzzer(13, timeDot);

int CodeIn;


void setup() {
  Serial.begin(9600);
}

void loop() {
  CodeIn = getChar();
  Buzzer.aMorse(CodeIn);
  delay(3*timeDot);
}



char getChar()// Get a character from the serial buffer
{
  while(Serial.available() == 0);
  return((char)Serial.read());
}
