#include <LiquidCrystal.h>
#include <Keypad.h>

LiquidCrystal lcd(12, 11, 10, 9, 8, 7);

const byte KEYPAD_ROWS = 4;
const byte KEYPAD_COLS = 4;
byte rowPins[KEYPAD_ROWS] = {5, 4, 3, 2}; 
byte colPins[KEYPAD_COLS] = {A3, A2, A1, A0};
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

void setup() {
  lcd.begin(16, 2);
  lcd.print("Bienvenido");
  delay(1000);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Ingrese clave");
  lcd.setCursor(4, 1);

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
      }
    }
  }

