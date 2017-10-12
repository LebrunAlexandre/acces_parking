#include "I2c.h"
#include "test.h"
#include <Wire.h>


void setup() {
  Wire.begin();
  initI2C(122);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int testTempo = 1,tempo = 0;
  static int nombreVoiture = 0;

  // Gestion de la sortie d'un vehicule

  if (lireAmont() == 1 && lireAval() == 0) {
    ouvrir();
    while (lireAmont() == 1 && lireAval() == 0);
    if (lireAmont() == 0 || lireAval() == 0) {
      while (lireAmont() == 0 || lireAval() == 0);
      nombreVoiture--;
      Serial.print("Nombre de voiture sur le parking : "); 
      Serial.println(nombreVoiture, DEC);
    }
    fermer();
  }

  // Gestion de l'entre d'un vehicule

  if (lireAmont() == 0 && lireAval() == 1) {
   // Serial.print("Entrez votre carte ou un code");
    if (validation() == 0) {
      ouvrir();
      while (lireAmont() == 0 && lireAval() == 1 && testTempo == 1){
    tempo++;
    delay(10);
    if(tempo == 1000){
      testTempo = 0;
      }
    }
    if(lireAmont() == 1 || lireAval() == 0){
      if(lireAmont() == 0 || lireAval() ==  0){
        while(lireAmont() == 0 || lireAval() == 0);
        nombreVoiture++; 
        Serial.print("Nombre de voiture sur le parking : "); 
        Serial.println(nombreVoiture, DEC);
        }
      }
      fermer();
    }
  }
}






