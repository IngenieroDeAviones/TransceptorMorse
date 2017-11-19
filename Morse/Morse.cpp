
#include "Arduino.h"
#include "Morse.h"

Morse::Morse(int pin, int timeDot){
	
	pinMode(pin, OUTPUT);
	_pin = pin;
	_timeDot = timeDot;
	
}

void Morse::dot(){
	
	digitalWrite(_pin, HIGH);
	delay(_timeDot);
	digitalWrite(_pin, LOW);
	delay(_timeDot);
	
}

void Morse::dash(){
	
	digitalWrite(_pin, HIGH);
	delay(3*_timeDot);
	digitalWrite(_pin, LOW);
	delay(3*_timeDot);
	
}

void Morse::aMorse(int CodeIn){
	_CodeIn = CodeIn;

	switch(_CodeIn)
	{
		case 'A': 
			Serial.print(".-");
			dot(); dash();
			break;

		case 'B': 
			Serial.print("-...");
			dash();dot();dot();dot();
			break;
			
		case 'C': 
			Serial.print("-.-.");
			dash();dot();dash();dot();
			break;
			
		case 'D': 
			Serial.print("-..");
			dash();dot();dot();
			break;
		
		case 'E': 
			Serial.print(".");
			dot();
			break;
			
		case 'F': 
			Serial.print("..--");
			dot();dot();dash();dash();
			break;
			
		case 'G': 
			Serial.print("--.");
			dash();dash();dot();
			break;
			
		case 'H': 
			Serial.print("....");
			dot();dot();dot();dot();
			break;
			
		case 'I': 
			Serial.print("..");
			dot();dot();
			break;
			
		case 'J': 
			Serial.print(".---");
			dot();dash();dash();dash();
			break;
			
		case 'K': 
			Serial.print("-.-");
			dash();dot();dash();
			break;
			
		case 'L': 
			Serial.print(".-..");
			dot();dash();dot();dot();
			break;
		
		case 'M': 
			Serial.print("--");
			dash(); dash();
			break;
			
		case 'N': 
			Serial.print("-.");
			dash();dot();
			break;
			
		case 'O': 
			Serial.print("---");
			dash();dash();dash();
			break;
			
		case 'P': 
			Serial.print(".--.");
			dot();dash();dash();dot();
			break;
			
		case 'Q': 
			Serial.print("--.-");
			dash();dash();dot();dash();
			break;
			
		case 'R': 
			Serial.print(".-.");
			dot();dash();dot();
			break;
			
		case 'S': 
			Serial.print("...");
			dot();dot();dot();
			break;
			
		case 'T': 
			Serial.print("-");
			dash();
			break;
			
		case 'U': 
			Serial.print("..-");
			dot();dot();dash();
			break;
			
		case 'V': 
			Serial.print("...-");
			dot();dot();dot();dash();
			break;
			
		case 'W': 
			Serial.print(".--");
			dot();dash();dash();
			break;
			
		case 'X': 
			Serial.print("-..-");
			dash();dot();dot();dash();
			break;
			
		case 'Y': 
			Serial.print("-.--");
			dash();dot();dash();dash();
			break;
			
		case 'Z': 
			Serial.print("--..");
			dash();dash();dot();dot();
			break;
	

	}
}
