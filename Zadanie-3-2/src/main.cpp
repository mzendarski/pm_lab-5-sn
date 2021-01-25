#include <Arduino.h>
#include <LiquidCrystal.h>

#define buttonUp  11// Przycisk Następny - pin 11
#define buttonDown  13// Przycisk Poprzedni - pin 13

// Inicjalizacja obiektu klasy LiquidCrystal: RS, E, DB4, DB5, DB6, DB7
LiquidCrystal lcd(9, 8, 7, 6, 5, 4) ;
int menu=1; //Numer aktualnie wyswietlanego ekranu

void setup() {
 lcd.begin(16,2); // Ustawianie liczby kolumn i wierszy
// Konfiguracja wyprowadzeń mikrokontrolera
pinMode (buttonUp, INPUT_PULLUP);
pinMode (buttonDown, INPUT_PULLUP);
}

void loop(void) {
    dispMenu(); // Wyswietlanie menu
    changeMenu(); // Zmiana menu
}

void dispMenu(void) {
  switch(menu) {
    case 1:
        lcd.setCursor(0,0);
        lcd.print("Menu 1");
        break;
    case 2:
        lcd.setCursor(0,0);
        lcd.print("Menu 2");
    case 3:
        lcd.setCursor(0,0);
        lcd.print("Menu 3");
        break;
  }
}

void changeMenu(void) {
   if(digitalRead(buttonUp) ==HIGH) { // Przycisk UP wciśnięty
      menu=menu+1; // Następny ekran
      if(menu>3){
         menu=1;
      }
}
if(digitalRead(buttonDown) == HIGH) { // Przycisk DOWN wcisniety
   menu=menu-1; //Poprzedni ekran
  if(menu<1) {
     menu=3;
  }
 }
}