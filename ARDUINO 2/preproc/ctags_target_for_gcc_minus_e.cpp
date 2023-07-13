# 1 "C:\\Users\\OMEGA EXODIA\\Desktop\\ARDUINO_2\\ARDUINO_2.ino"
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
# 13 "C:\\Users\\OMEGA EXODIA\\Desktop\\ARDUINO_2\\ARDUINO_2.ino"
const int boton3Pin = 2; //Pines de los botones
const int boton4Pin = 3;

const int motor1Pins[] = {4, 5, 6, 7}; //Pines para los motores steper.
const int motor2Pins[] = {8, 9, 10, 11};

const int obstaculoPin = 12;

const int SIGNALOUTPUT3 = A0;
const int SIGNALOUTPUT4 = A1;

    int SELECMOTOR;
      int pos = 0;

void setup() {

  // Configurar los pines de los botones como entradas
  pinMode(boton3Pin, 0x2);
  pinMode(boton4Pin, 0x2);

  // Configurar los pines de los motores stepper como salidas
  for (int i = 0; i < 4; i++) {
    pinMode(motor1Pins[i], 0x1);
    pinMode(motor2Pins[i], 0x1);
  }

  // Configurar el pin del detector de obstáculos como entrada
  pinMode(obstaculoPin, 0x0);
  pinMode(SIGNALOUTPUT3, 0x1);
  pinMode(SIGNALOUTPUT4, 0x1);
}

void loop() {
  if (digitalRead(boton3Pin) == 0x0) {
    SELECMOTOR = 1;
    digitalWrite(SIGNALOUTPUT3, 0x1);
  }
  if (SIGNALOUTPUT3,0x1) {
    delay(100);
    digitalWrite(SIGNALOUTPUT3, 0x0);
  }


  if (digitalRead(obstaculoPin) == 0x1) {
    ejecutarMotor();
    SELECMOTOR = 0;
    reiniciar();
    }

  // Verificar si se ha presionado algún botón
    if (digitalRead(boton4Pin) == 0x0) {
    SELECMOTOR = 2;
    digitalWrite(SIGNALOUTPUT4, 0x1);
    }
  if (SIGNALOUTPUT4,0x1) {
    delay(100);
    digitalWrite(SIGNALOUTPUT4, 0x0);
  }




  if (digitalRead(obstaculoPin) == 0x1) {

    ejecutarMotor();
    SELECMOTOR = 0;
    reiniciar();
    } }


void ejecutarMotor(void) {





  int demora = 100;


  if (SELECMOTOR == 1) {
  for (pos = 0; pos <= 10; pos += 1){

  digitalWrite(4, 0x1); //PASO 1
  digitalWrite(5, 0x0);
  digitalWrite(6, 0x0);
  digitalWrite(7, 0x1);
  delay(demora);

  digitalWrite(4, 0x0); //PASO 2
  digitalWrite(5, 0x0);
  digitalWrite(6, 0x0);
  digitalWrite(7, 0x1);
  delay(demora);

  digitalWrite(4, 0x0); //PASO 3
  digitalWrite(5, 0x0);
  digitalWrite(6, 0x1);
  digitalWrite(7, 0x1);
  delay(demora);

  digitalWrite(4, 0x0); //PASO 4
  digitalWrite(5, 0x0);
  digitalWrite(6, 0x1);
  digitalWrite(7, 0x0);
  delay(demora);

  digitalWrite(4, 0x0); //PASO 5
  digitalWrite(5, 0x1);
  digitalWrite(6, 0x1);
  digitalWrite(7, 0x0);
  delay(demora);

  digitalWrite(4, 0x0); //PASO 6
  digitalWrite(5, 0x1);
  digitalWrite(6, 0x0);
  digitalWrite(7, 0x0);
  delay(demora);

  digitalWrite(4, 0x1); //PASO 7
  digitalWrite(5, 0x1);
  digitalWrite(6, 0x0);
  digitalWrite(7, 0x0);
  delay(demora);

  digitalWrite(4, 0x1); //PASO 8
  digitalWrite(5, 0x0);
  digitalWrite(6, 0x0);
  digitalWrite(7, 0x0);
  delay(demora);

    } }


  else if (SELECMOTOR == 2) {
  for (pos = 0; pos <= 10; pos += 1){

   digitalWrite(8, 0x1); //PASO 1
  digitalWrite(9, 0x0);
  digitalWrite(10, 0x0);
  digitalWrite(11, 0x1);
  delay(demora);

  digitalWrite(8, 0x0); //PASO 2
  digitalWrite(9, 0x0);
  digitalWrite(10, 0x0);
  digitalWrite(11, 0x1);
  delay(demora);

  digitalWrite(8, 0x0); //PASO 3
  digitalWrite(9, 0x0);
  digitalWrite(10, 0x1);
  digitalWrite(11, 0x1);
  delay(demora);

  digitalWrite(8, 0x0); //PASO 4
  digitalWrite(9, 0x0);
  digitalWrite(10, 0x1);
  digitalWrite(11, 0x0);
  delay(demora);

  digitalWrite(8, 0x0); //PASO 5
  digitalWrite(9, 0x1);
  digitalWrite(10, 0x1);
  digitalWrite(11, 0x0);
  delay(demora);

  digitalWrite(8, 0x0); //PASO 6
  digitalWrite(9, 0x1);
  digitalWrite(10, 0x0);
  digitalWrite(11, 0x0);
  delay(demora);

  digitalWrite(8, 0x1); //PASO 7
  digitalWrite(9, 0x1);
  digitalWrite(10, 0x0);
  digitalWrite(11, 0x0);
  delay(demora);

  digitalWrite(8, 0x1); //PASO 8
  digitalWrite(9, 0x0);
  digitalWrite(10, 0x0);
  digitalWrite(11, 0x0);
  delay(demora);

    } }

    else {
  digitalWrite(8, 0x0); //PASO 8
  digitalWrite(9, 0x0);
  digitalWrite(10, 0x0);
  digitalWrite(11, 0x0);

  digitalWrite(4, 0x0); //PASO 8
  digitalWrite(5, 0x0);
  digitalWrite(6, 0x0);
  digitalWrite(7, 0x0);




    }




}

void reiniciar() { //Funcion para reiniciar
  pos = 0;
  SELECMOTOR = 0;

}
