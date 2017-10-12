#include "arduino.h"
#include <Wire.h>
#include "test.h"


void ouvrir(){
Wire.beginTransmission(0x20);         // Adresse du moteur et ,debut de la transmission
Wire.write(0xFD);                     // Ouvrir Barriere
Wire.endTransmission();               // Fin de transmission
}

void fermer(){
  Wire.beginTransmission(0x20);
Wire.write(0xFE);                     // Fermer Barriere
Wire.endTransmission();
}

short lireAmont(){
  Wire.requestFrom (0x20, 1);         // Boucle amont
short boucleAm = Wire.read();       // lecture de boucle amont et stockage dans variable
boucleAm = (boucleAm & 0x20)>>5;    // masque Boucle amont + decalage de 5 se qui donne 0 ou 1 comme valeur             
return boucleAm;
}

short lireAval(){
  Wire.requestFrom (0x20, 1);         // Boucle aval
short boucleAv = Wire.read();       // lecture de boucle aval et stockage dans variable
boucleAv = (boucleAv & 0x40)>>6;    // masque Boucle aval + decalage de 6 se qui donne 0 ou 1 comme valeur                   
return boucleAv;
}

short validation(){
  Wire.beginTransmission(0x21);         // Adresse du moteur et ,debut de la transmission
  short carte = Wire.read();
  carte = (carte & 0x01);
  Serial.print(carte);
  return carte;
  
}



