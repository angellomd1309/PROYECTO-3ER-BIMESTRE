/*
FUNDACION KINAL
CENTRO EDUCATIVO TECNICO LARELEORAL KINAL
PERITO EN ELECTRONICA
QUINTO PERITO
SECCION: A
CURSO: TALLER DE ELECTRONICA DIGITAL Y REPARACION DE COMPUTADORAS
ALUMNOS: ANGELLO MANSILLA, RUDY CANEL, PABLO HERNANDEZ, CHRISTIAN SOLORZANO, DAVID DEL CID, DIEGO QUEME.
CARNETS: 2022380, 2022449,2022472, 2022323, 2022482,2021430.
PROYECTO 2, MAQUINA EXPENDEDORA
*/

#include <Wire.h>
#include <LiquidCrystal_I2C.h> //Incluimos las librerias correspondientes.

const int boton1Pin = 2; //Pines de los botones
const int boton2Pin = 3;


const int motor1Pins[] = {4, 5, 6, 7}; //Pines para los motores steper.
const int motor2Pins[] = {8, 9, 10, 11}; 

const int obstaculoPin = 12; //Detector de monedas(el sensor de obstaculos

const char mensajeInicial[] = "SELECCIONE"; //Hacemos un const char con los mensajes, para ahorrar algo de tiempo.
const char mensajeInicial2[] = "PRODUCTO"; //Hacemos un const char con los mensajes, para ahorrar algo de tiempo.
const char mensajeMoneda[] = "INSERTE MONEDA";
const char mensajeProcesando[] = "PROCESANDO...";

int seleccion = 0; //Variable para guardar la selección del usuario
LiquidCrystal_I2C lcd(0x20, 16, 2); // Construimos el I2C
    int SELECMOTOR;
    unsigned long duracion = 5000;
    unsigned long tiempoInicio = millis();

void setup() {

  // Configurar los pines de los botones como entradas
  pinMode(boton1Pin, INPUT_PULLUP);
  pinMode(boton2Pin, INPUT_PULLUP);

  // Configurar los pines de los motores stepper como salidas
  for (int i = 0; i < 4; i++) {
    pinMode(motor1Pins[i], OUTPUT);
    pinMode(motor2Pins[i], OUTPUT);
  }

  // Configurar el pin del detector de obstáculos como entrada
  pinMode(obstaculoPin, INPUT);

  // Inicializar el LCD
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print(mensajeInicial);
  delay(100);
  lcd.setCursor(0,1);
  lcd.print(mensajeInicial2);
}

void loop() {
  if (digitalRead(boton1Pin) == LOW) {
    SELECMOTOR = 1;
    seleccion = 1;
    lcd.clear();
    lcd.print(mensajeMoneda);}

  if (digitalRead(obstaculoPin) == LOW) {
    tiempoInicio = 0;
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print(mensajeProcesando);
    ejecutarMotor();
    SELECMOTOR = 0;
    reiniciar();
    }  
    
  // Verificar si se ha presionado algún botón
    if (digitalRead(boton2Pin) == LOW) {
    SELECMOTOR = 2;
    seleccion = 2;
    lcd.clear();
    lcd.print(mensajeMoneda);}
    //Si hay deteccion de la moneda, el codigo proseguira.
  if (digitalRead(obstaculoPin) == LOW) {
    tiempoInicio = 0;
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print(mensajeProcesando);
    ejecutarMotor();
    SELECMOTOR = 0;    
    reiniciar();
    } }
  

void ejecutarMotor(void) {
  
  int demora = 2.0;


  if (SELECMOTOR == 1) {  
  while (millis() - tiempoInicio < duracion) {

  digitalWrite(4, HIGH); //PASO 1
  digitalWrite(5, LOW);
  digitalWrite(6, LOW);
  digitalWrite(7, HIGH);
  delay(demora);

  digitalWrite(4, LOW); //PASO 2
  digitalWrite(5, LOW);
  digitalWrite(6, LOW);
  digitalWrite(7, HIGH);
  delay(demora);

  digitalWrite(4, LOW); //PASO 3
  digitalWrite(5, LOW);
  digitalWrite(6, HIGH);
  digitalWrite(7, HIGH);
  delay(demora);

  digitalWrite(4, LOW); //PASO 4
  digitalWrite(5, LOW);
  digitalWrite(6, HIGH);
  digitalWrite(7, LOW);
  delay(demora);

  digitalWrite(4, LOW); //PASO 5
  digitalWrite(5, HIGH);
  digitalWrite(6, HIGH);
  digitalWrite(7, LOW);
  delay(demora);

  digitalWrite(4, LOW); //PASO 6
  digitalWrite(5, HIGH);
  digitalWrite(6, LOW);
  digitalWrite(7, LOW);
  delay(demora);

  digitalWrite(4, HIGH); //PASO 7
  digitalWrite(5, HIGH);
  digitalWrite(6, LOW);
  digitalWrite(7, LOW);
  delay(demora);

  digitalWrite(4, HIGH); //PASO 8
  digitalWrite(5, LOW);
  digitalWrite(6, LOW);
  digitalWrite(7, LOW);
  delay(demora);
      
    } }


  else if (SELECMOTOR == 2) {  
  while (millis() - tiempoInicio < duracion) {

   digitalWrite(8, HIGH); //PASO 1
  digitalWrite(9, LOW);
  digitalWrite(10, LOW);
  digitalWrite(11, HIGH);
  delay(demora);

  digitalWrite(8, LOW); //PASO 2
  digitalWrite(9, LOW);
  digitalWrite(10, LOW);
  digitalWrite(11, HIGH);
  delay(demora);

  digitalWrite(8, LOW); //PASO 3
  digitalWrite(9, LOW);
  digitalWrite(10, HIGH);
  digitalWrite(11, HIGH);
  delay(demora);

  digitalWrite(8, LOW); //PASO 4
  digitalWrite(9, LOW);
  digitalWrite(10, HIGH);
  digitalWrite(11, LOW);
  delay(demora);

  digitalWrite(8, LOW); //PASO 5
  digitalWrite(9, HIGH);
  digitalWrite(10, HIGH);
  digitalWrite(11, LOW);
  delay(demora);

  digitalWrite(8, LOW); //PASO 6
  digitalWrite(9, HIGH);
  digitalWrite(10, LOW);
  digitalWrite(11, LOW);
  delay(demora);

  digitalWrite(8, HIGH); //PASO 7
  digitalWrite(9, HIGH);
  digitalWrite(10, LOW);
  digitalWrite(11, LOW);
  delay(demora);

  digitalWrite(8, HIGH); //PASO 8
  digitalWrite(9, LOW);
  digitalWrite(10, LOW);
  digitalWrite(11, LOW);
  delay(demora);
      
    } }

    else {
  digitalWrite(8, LOW); //PASO 8
  digitalWrite(9, LOW);
  digitalWrite(10, LOW);
  digitalWrite(11, LOW);

  digitalWrite(4, LOW); //PASO 8
  digitalWrite(5, LOW);
  digitalWrite(6, LOW);
  digitalWrite(7, LOW);  


      
      
    }




}

void reiniciar() { //Funcion para reiniciar
  seleccion = 0;
  tiempoInicio = tiempoInicio-5000;
  SELECMOTOR = 0;
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print(mensajeInicial);
  delay(100);
  lcd.setCursor(0,1);
  lcd.print(mensajeInicial2);

}
