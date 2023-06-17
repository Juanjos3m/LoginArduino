#include <LiquidCrystal.h>
#include <Keypad.h>

LiquidCrystal lcd(12, 11, 6, 5, 4, 3);

const byte KEYPAD_ROWS = 4;
const byte KEYPAD_COLS = 4;
byte rowPins[KEYPAD_ROWS] = {35, 37, 39, 41}; 
byte colPins[KEYPAD_COLS] = {43, 45, 47, 49};
char keys[KEYPAD_ROWS][KEYPAD_COLS] = {
  {'1', '2', '3', '+'},
  {'4', '5', '6', '-'},
  {'7', '8', '9', '*'},
  {'.', '0', '=', '/'}
};

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, KEYPAD_ROWS, KEYPAD_COLS);

char clave [] = "1006";
int contador = 0;
char password [4];
int count = 0;
boolean bandera = true;
int ledRojo = 16;
int ledVerde = 18;
int ledAzul = 19;

void setup() {
  lcd.begin(16, 2);
  lcd.print("Bienvenido");
  delay(1000);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Ingrese clave");
  lcd.setCursor(4, 1);

  pinMode(ledRojo, OUTPUT); // sets the redPin to be an output
  pinMode(ledVerde, OUTPUT); // sets the greenPin to be an output
  pinMode(ledAzul, OUTPUT); // sets the bluePin to be an output
}

void loop() {
  char key = keypad.getKey();
  if (key && count != 3){
    password[contador] = key;
    contador = contador + 1;
    lcd.print("*");
    if(contador == 4){
        if(password[0]==clave[0] && password[1]==clave[1] && password[2]==clave[2] && password[3]==clave[3]){
          delay(1000);
          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print("Contrasena");
          lcd.setCursor(0, 1);
          lcd.print("Correcta");
          delay(1000);
          color(0,255, 0); // Led verde
          delay(1000); 
          lcd.clear();
          count = 3;
          bandera = true;
        }else{
          delay(1000);
          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print("Contrasena");
          lcd.setCursor(0, 1);
          lcd.print("Incorrecta");
          count = count + 1;
          delay(1000);
          color(255, 0, 0); Led rojo
          delay(1000); 
          lcd.clear();
          if(count < 3){
              lcd.setCursor(0, 0);
              lcd.print("Ingrese clave");
              lcd.setCursor(4, 1);
          }
          bandera = false;
        }
        contador = 0;
      }
      if(count == 3 && !bandera){
          lcd.setCursor(0, 0);
          lcd.print("Sistema");
          lcd.setCursor(0, 1);
          lcd.print("bloqueado");
          delay(1000);
          color(0, 0, 255); // Led azul 
          delay(1000); 
      }
    }
    
  }
