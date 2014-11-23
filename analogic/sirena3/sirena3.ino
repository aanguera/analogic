/*************************************************************************************
**                                                                                  **
**             Aquest programa fa una lectura analgica del canal A0 i A1            **
**             la lectura de la tensio (A0) determina la durada de la sirena.       **
**             la lectura de la tensio (A1) determina la frequencia dela sirena.    **
**                                                                                  **
*************************************************************************************/
 
//******  Includes  ******************************************************************



//******  Variables  *****************************************************************

const int speakerPin = 9;
int duradaSirena = 0;
int freqSirena = 0;

//******  Includes  ******************************************************************
void setup() {                
  pinMode(speakerPin, OUTPUT);     
}



//******  Loop  **********************************************************************
void loop() {
  duradaSirena = 2 * analogRead(A0);
  freqSirena = 2 * analogRead(A1);   
  playTone(freqSirena, duradaSirena);
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
