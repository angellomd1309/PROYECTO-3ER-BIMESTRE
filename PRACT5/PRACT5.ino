
/*
 * Fundacion Kinal
 * Centro educativo tecnico laboral Kinal
 * Electronica
 * Grado: Quinto
 * Sección: A
 * Curso: Taller de electronica digital y reparación de computadoras I
 * Nombre: Pablo David Hernandez y Angello Gabriel Mnsilla Dieugez
 * Carnet: 2022472 y 2022380
 * Proyecto: Uso del controlador led max7219 y una matriz led 8x8
*/

//Librerias
#include <Ticker.h>
#include <LedControl.h>   //libreria que me permite usar el controlador led max7219

//Directivas de preprocesador
#define dataPin0   12   //pin 12 conectado al pin de datos del max7219.
#define dataClock0 10   //pin 11 conectado al pin de clock del max7219.
#define dataLoad0  11   //pin 10 conectado al pin de carga del max7219.


//Constructores
LedControl MATRIX = LedControl(dataPin0,dataClock0,dataLoad0,1);
/*
 * Variable:
 * Estas variables especifican que leds deben de encenderse en la matriz
 * de manera similar a como creabamos caracteres especiales en una lcd.
*/
byte FUEGO1[8]= {        //SPRITE FUEGUITO 1
B00010000,
B00100000,
B00011000,
B00111100,
B00111110,
B01111110,
B01111100,
B00111000

};
byte FUEGO2[8]= {       // array que contiene todos los elementos de las
B00000010,
B00001110,
B00011110,
B00111100,
B01111100,
B01111110,
B01111110,
B00111000


};

byte FUEGO3[8]= {       // array que contiene todos los elementos de las
B00000010,
B00000100,
B00011110,
B00111100,
B00111100,
B01111110,
B01111100,
B00111000
};

byte FRIO[8]= {       // array que contiene todos los elementos de las
  B10011001,
  B01011010,
  B00111100,
  B11100111,
  B11100111,
  B00111100,
  B01011010,
  B10011001,
};

int i;
int o;
int u;

int SENSREAD, MAPING;

void LECTURA (void);
Ticker LECTURATICKER(LECTURA, 2000);

void setup()
{
  Serial.begin(9600); //Inicio la comunicacion serial a 9600 baudios.
  MATRIX.shutdown(0,false); //Activo el max7219 para poder mostrar los digitos.
  MATRIX.setIntensity(0,15);  //Brilo a la mitad 
  MATRIX.clearDisplay(0);    //limpio el display
  Serial.println("---DETECTOR DE FUEGO---");
  LECTURATICKER.start();
}


void loop() 
{
  i = 0;
  o = 0;
  u = 0;  
  LECTURATICKER.update();  
  if (MAPING < 20) {
    Serial.println("No Hay Algo Inflamble");
  while(i < 8){
    i++;
    MATRIX.setRow(0, i, FRIO[i]);
  }
  delay(500);
  }
  
  if (MAPING >= 20) {
    Serial.println("Alerta, Gas Flamable Detectado");
  while(i<8)  {
    i++;
    MATRIX.setRow(0, i, FUEGO1[i]);
    delay(50);
    }
  while(o<8)  {
    o++;
    MATRIX.setRow(0, o, FUEGO2[o]);
    delay(50);    
    }
  while(u<8) {
    u++;
    MATRIX.setRow(0, u, FUEGO3[u]);
    delay(50);    
  }
      delay(500);
      }   
  }
void LECTURA(void) {

  SENSREAD = analogRead(A0);
  MAPING = map(SENSREAD, 0, 1023, 0, 100);
  Serial.println(MAPING);  
}
