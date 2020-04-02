#include <Wire.h>;
#include <LiquidCrystal_I2C.h>;
#include <dht.h>
#include "EmonLib.h"
#define dht_dpin A1

//EnergyMonitor emon1;

LiquidCrystal_I2C lcd(0x27,20,4);
int Menu = 0; // Inicializa valores para Menu
int estado = 0; // Inicializa valores para estado
int rede = 220.0;
int pino_sct = 1;
void setup() {

  lcd.init();
  lcd.backlight();
  lcd.begin(20, 4); // Estabelece caracteres do display

clearPrintTitle();

}

  void loop() {


 
MenuPrincipal();

}

  void MenuPrincipal() {
  int ValEstado = 0; // Inicializa valores para ValEstado
  int x = analogRead (0);

    lcd.setCursor(0,0); // Posiciona Cursor

if (x < 80) { // Define valores máximos para UP em ValEstado = 1
}

else if (x < 200) {
ValEstado = 1;
}

else if (x < 400){ // Define valores máximos para Down em ValEstado = 2
ValEstado = 2;
}

else if (x < 600){ // Define ação nula para Left
ValEstado = 4;
}

else if (x < 800){ // Define valores máximos para Select em ValEstado = 3
ValEstado = 3;
}

if (Menu < 0 || Menu > 4) {
Menu = 0;
}

if (ValEstado != estado) {
if (ValEstado == 1) {
Menu = Menu - 1;
displayMenu(Menu);
} 

else if (ValEstado == 2) {
Menu = Menu + 1;
displayMenu(Menu);

} 
else if (ValEstado == 3) {
selectMenu(Menu);
}

else if (ValEstado == 4) {
displayMenu(Menu);
}

estado = ValEstado;
}

delay(5);

}




void displayMenu(int x) {
switch (x) {

case 1:
  clearPrintTitle();
    lcd.setCursor(23, 0);
    lcd.print ("- Temp fonte -"); // Imprime na tela a opção do Menu
break;

case 2:
  clearPrintTitle();
    lcd.setCursor(23, 0);
    lcd.print ("- Temp / gerador -"); // Imprime na tela a opção do Menu
break;

case 3:
  clearPrintTitle();
    lcd.setCursor(23, 0);
    lcd.print ("- Voltagem / Cons amper -"); // Imprime na tela a opção do Menu
break;

case 4:
  clearPrintTitle();
    lcd.setCursor(23, 0);
    lcd.print ("- Op. Manual -"); // Imprime na tela a opção do Menu
break;

}

}

void clearPrintTitle() {

  lcd.clear();
  lcd.setCursor(1,0);
  lcd.print(" Think - Nobreaks "); // Primeiro texto do display
}

void selectMenu(int x) {
switch (x) {

case 1:
  clearPrintTitle();
    lcd.setCursor(20, 0);
    lcd.print ("Selecionado item 1"); // Imprime na tela opção escolhida
    sensor(); // Imprime na tela opção escolhida
break;

case 2:
  clearPrintTitle();
    lcd.print ("Selec. Item 2"); // Imprime na tela opção escolhida
    voltagem();
break;

case 3:
  clearPrintTitle();
    lcd.print ("Selec. Item 3"); // Imprime na tela opção escolhida
break;

case 4:
  clearPrintTitle();
    lcd.print ("Selec. Item 4"); // Imprime na tela opção escolhida
break;

}

}

// execucao da primeira opcao do menu

void sensor () {

  dht DHT; //Inicializa o sensor
       lcd.init();
    lcd.backlight();
      delay(500);
  DHT.read11(dht_dpin); //Lê as informações do sensor
    lcd.setCursor(20, 0);
      lcd.print("Umde = ");
      lcd.print(DHT.humidity/1.3);
      lcd.print(" % ");
    lcd.setCursor(0, 1);
      lcd.print("Temp = ");
      lcd.print(DHT.temperature/1.3);
      lcd.setCursor(13, 1);
      lcd.print("C ");
  delay(1000); // tempo de leitura do sensor

 }

 void voltagem () {

//void loop() {
lcd.setCursor(0, 0);
lcd.print("********************");
lcd.setCursor(4, 1);
lcd.print("BLOG USINAINFO");
lcd.setCursor(0, 2);
lcd.print("DISPLAY 20X4 COM I2C");
lcd.setCursor(0, 3);
lcd.print("********************");

// }
 }
