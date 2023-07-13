# 1 "C:\\Users\\OMEGA EXODIA\\Desktop\\MAQUINA_EXPENDEDORA\\MAQUINA_EXPENDEDORA.ino"
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
# 13 "C:\\Users\\OMEGA EXODIA\\Desktop\\MAQUINA_EXPENDEDORA\\MAQUINA_EXPENDEDORA.ino"
# 14 "C:\\Users\\OMEGA EXODIA\\Desktop\\MAQUINA_EXPENDEDORA\\MAQUINA_EXPENDEDORA.ino" 2
# 15 "C:\\Users\\OMEGA EXODIA\\Desktop\\MAQUINA_EXPENDEDORA\\MAQUINA_EXPENDEDORA.ino" 2

const int boton1Pin = 2; //Pines de los botones
const int boton2Pin = 3;


const int motor1Pins[] = {4, 5, 6, 7}; //Pines para los motores steper.
const int motor2Pins[] = {8, 9, 10, 11};

const int SIGNALINPUT3 = A0;
const int SIGNALINPUT4 = A1;
const int SIGNALOUTPUT = A2;


const int obstaculoPin = 12; //Detector de monedas(el sensor de obstaculos

const char mensajeInicial[] = "SELECCIONE"; //Hacemos un const char con los mensajes, para ahorrar algo de tiempo.
const char mensajeInicial2[] = "PRODUCTO"; //Hacemos un const char con los mensajes, para ahorrar algo de tiempo.
const char mensajeMoneda[] = "INSERTE MONEDA";
const char mensajeProcesando[] = "PROCESANDO...";

int seleccion = 0; //Variable para guardar la selección del usuario
LiquidCrystal_I2C lcd(0x20, 16, 2); // Construimos el I2C
    int SELECMOTOR;
      int pos = 0;

void setup() {

  // Configurar los pines de los botones como entradas
  pinMode(boton1Pin, 0x2);
  pinMode(boton2Pin, 0x2);

  // Configurar los pines de los motores stepper como salidas
  for (int i = 0; i < 4; i++) {
    pinMode(motor1Pins[i], 0x1);
    pinMode(motor2Pins[i], 0x1);
  }

  // Configurar el pin del detector de obstáculos como entrada
  pinMode(obstaculoPin, 0x0);
  pinMode(SIGNALINPUT3, 0x0);
  pinMode(SIGNALINPUT4, 0x0);
  pinMode(SIGNALOUTPUT, 0x1);


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
  if (digitalRead(boton1Pin) == 0x0) {
    SELECMOTOR = 1;
    lcd.clear();
    lcd.print(mensajeMoneda);}

  if (digitalRead(obstaculoPin) == 0x0) {
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print(mensajeProcesando);
    ejecutarMotor();
    SELECMOTOR = 0;
    reiniciar();
    }

  // Verificar si se ha presionado algún botón
    if (digitalRead(boton2Pin) == 0x0) {
    SELECMOTOR = 2;
    lcd.clear();
    lcd.print(mensajeMoneda);}
    //Si hay deteccion de la moneda, el codigo proseguira.
  if (digitalRead(obstaculoPin) == 0x0) {
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print(mensajeProcesando);
    ejecutarMotor();
    SELECMOTOR = 0;
    reiniciar();
    }

  if (digitalRead(SIGNALINPUT3) == 0x1) {
    SELECMOTOR = 3;
    lcd.clear();
    lcd.print(mensajeMoneda);}

  if (digitalRead(obstaculoPin) == 0x0) {
    digitalWrite(SIGNALOUTPUT, 0x1);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print(mensajeProcesando);
    ejecutarMotor();
    SELECMOTOR = 0;
    reiniciar();
    }

  if (digitalRead(SIGNALINPUT4) == 0x1) {
    SELECMOTOR = 4;
    lcd.clear();
    lcd.print(mensajeMoneda);}

  if (digitalRead(obstaculoPin) == 0x0) {
    digitalWrite(SIGNALOUTPUT, 0x1);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print(mensajeProcesando);
    ejecutarMotor();
    SELECMOTOR = 0;
    reiniciar();
    }

}




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

  else if (SELECMOTOR == 3) {
      for (pos = 0; pos <= 10; pos += 1){

      }
  }

  else if (SELECMOTOR == 4) {
      for (pos = 0; pos <= 10; pos += 1){

      }
  }


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
  digitalWrite(SIGNALOUTPUT, 0x0);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print(mensajeInicial);
  delay(100);
  lcd.setCursor(0,1);
  lcd.print(mensajeInicial2);

}
