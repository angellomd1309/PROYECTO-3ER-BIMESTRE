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

const char mensajeInicial[] = "SELECCIONE PRODUCTO"; //Hacemos un const char con los mensajes, para ahorrar algo de tiempo.
const char mensajeMoneda[] = "INSERTE MONEDA";
const char mensajeProcesando[] = "PROCESANDO...";

int seleccion = 0; //Variable para guardar la selección del usuario
LiquidCrystal_I2C lcd(0x27, 16, 2); // Construimos el I2C

int DARPRODUCTO;

void AUTORIZACION(void);

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
  lcd.print(mensajeInicial);
}

void loop() {
  AUTORIZACION();
  
  // Verificar si se ha presionado algún botón
  if (digitalRead(boton1Pin) == LOW) {
    seleccion = 1;
    lcd.clear();
    lcd.print(mensajeMoneda);
    //Si hay deteccion de la moneda, el codigo proseguira.
  if (AUTORIZACION == LOW) {
    lcd.print(mensajeProcesando);
    delay(1000);
    ejecutarMotor(seleccion);
    reiniciar();
    } }
    
  // Verificar si se ha presionado algún botón
    else if (digitalRead(boton2Pin) == LOW) {
    seleccion = 2;
    lcd.clear();
    lcd.print(mensajeMoneda);
    //Si hay deteccion de la moneda, el codigo proseguira.
  if (AUTORIZACION == LOW) {
    lcd.print(mensajeProcesando);
    delay(1000);
    ejecutarMotor(seleccion);
    reiniciar();
    } }
  }

void ejecutarMotor(int motor) {
  // Mover el motor durante 5 segundos
  unsigned long tiempoInicio = millis();
  unsigned long duracion = 5000; //5 Segundos

  if (motor == 1) {
    while (millis() - tiempoInicio < duracion) {
      for (int i = 0; i < 4; i++) {
        for (int pin = 0; pin < 4; pin++) {
          digitalWrite(motor1Pins[pin], (i == pin) ? HIGH : LOW);
        }
        delay(5);
      }
    }
  } else if (motor == 2) {
    while (millis() - tiempoInicio < duracion) {
      for (int i = 3; i >= 0; i--) {
        for (int pin = 0; pin < 4; pin++) {
          digitalWrite(motor2Pins[pin], (i == pin) ? HIGH : LOW);
        }
        delay(5);
      }
    }
  }

  // Detener el motor
  for (int pin = 0; pin < 4; pin++) {
    digitalWrite(motor1Pins[pin], LOW);
    digitalWrite(motor2Pins[pin], LOW);
  }
}

void reiniciar() { //Funcion para reiniciar
  seleccion = 0;
  lcd.clear();
  lcd.print(mensajeInicial);
}

void AUTORIZACION(void){ //Funcion para dar autorizacion para seguir el codigo.
  DARPRODUCTO = HIGH;
  DARPRODUCTO = digitalRead(obstaculoPin);
  delay (500);
  DARPRODUCTO = HIGH;
  
}
