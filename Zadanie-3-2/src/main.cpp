#include <Arduino.h>
#include <LiquidCrystal.h>

// Inicjalizacja obiektu klasy LiquidCrystal: RS, E, DB4, DB5, DB6, DB7
LiquidCrystal lcd(9, 8, 7, 6, 5, 4) ;
int menu=1; //Numer aktualnie wyswietlanego ekranu

void setup() {
  lcd.begin(16,2);// Ustawienie kolumn i wierszy
}

void loop() {
  dispMenu() ; //Wyswietlanie menu
  delay(1000);
  menu++; // Zmiana ekranu menu
  if(menu>3) menu=1;
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