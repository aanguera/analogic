/*************************************************************************************
**                                                                                  **
**             Aquest programa fa una lectura analgica del canal A0                 **
**             modula la intensitat del led amb PWM de la sortida 3                 **
**                                                                                  **
*************************************************************************************/
 
//******  Includes  ******************************************************************



//******  Variables  *****************************************************************

const int speakerPin = 9;
int sensorValue = 0;


//******  Includes  ******************************************************************
void setup() {                
  pinMode(speakerPin, OUTPUT);     
}



//******  Loop  **********************************************************************
void loop() {
  sensorValue = analogRead(A0);
 // analogWrite(9, sensorValue/4);
 playTone(1700, 300);
 //playTone(820, sensorValue);
 delay(sensorValue);
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
