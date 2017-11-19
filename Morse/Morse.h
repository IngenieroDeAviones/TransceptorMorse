//Librería Morse ---- ARCHIVO .H

#include "Arduino.h"
#ifndef Morse_h
#define Morse_h

class Morse
{

	public:

		Morse(int pin, int timeDot);
		void aMorse(int CodeIn);

	private:
		
		void dot();
		void dash();
		int _pin;
		int _CodeIn;
		int _timeDot;

};

#endif
