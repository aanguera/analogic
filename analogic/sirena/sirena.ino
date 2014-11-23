/*************************************************************************************
**                                                                                  **
**             Aquest programa fa una lectura analgica del canal A0                 **
**             la lectura de la tensio determina la durada de la sirena             **
**                                                                                  **
*************************************************************************************/
 
//******  Includes  ******************************************************************



//******  Variables  *****************************************************************

const int speakerPin = 9;
int duradaSirena = 0;


//******  Includes  ******************************************************************
void setup() {                
  pinMode(speakerPin, OUTPUT);     
}



//******  Loop  **********************************************************************
void loop() {
 duradaSirena = 2 * analogRead(A0);
 playTone(1700, duradaSirena);
 delay(800);
}

//********** Funcions *************************************************************
void playTone(int tone, int duration) {
  for (long i = 0; i < duration * 1000L; i += tone * 2) {
    digitalWrite(speakerPin, HIGH);
    delayMicroseconds(tone);
    digitalWrite(speakerPin, LOW);
    delayMicroseconds(tone);
  }
}
