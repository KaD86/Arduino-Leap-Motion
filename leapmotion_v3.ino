/*
   Control de Gestos para PC. (Arduino+Python)
   Karen Delgado N y Andres rodriguez A.
   Ufidelitas: 21-04-2018
   Github repository: https://github.com/KaD86/Arduino-Leap-Motion
*/

#include <LiquidCrystal.h>

//Variables constantes para los pines de la pantalla
const int rs = 12;
const int en = 11;
const int d4 = 10;
const int d5 = 9;
const int d6 = 8;
const int d7 = 7;

String derecha = "Derecha: ";
String izquierda = "Izquierda: ";

LiquidCrystal lcd(rs, en, d4, d5, d6, d7); //Inicializa el objeto con los pines anteriormente especificados

//Variables constantes para los pines de ambos sensores
const int trigger1 = 2; //Trigger pin de 1er sensor
const int echo1 = 3; //Echo pin de 1er Sesnor
const int trigger2 = 4; //Trigger pin de 2ndo Sensor
const int echo2 = 5;//Echo pin de 2ndo Sensor

//Variables fluctuantes para medir tiempo y distancia
long time_taken;
int dist, distI, distD; //distancia, dist sensor izq, dist sensor derecho



void setup() {
  Serial.begin(9600);

  pinMode(trigger1, OUTPUT);
  pinMode(echo1, INPUT);
  pinMode(trigger2, OUTPUT);
  pinMode(echo2, INPUT);
  lcd.begin(16, 2); //Especificar filas y columnas del LCD
}

/*Funcion para calcular distancia*/
void calculate_distance(int trigger, int echo)
{
  digitalWrite(trigger, LOW);
  delayMicroseconds(2);
  digitalWrite(trigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigger, LOW);

  //Medir tiempo...luego calcular por medio de Delays
  time_taken = pulseIn(echo, HIGH);
  dist = time_taken * 0.034 / 2;
  if (dist > 50)
    dist = 50;
}

void loop() { //Loop Infinito
  calculate_distance(trigger1, echo1);
  distI = dist; //Distancia del sensor izquierdo

  calculate_distance(trigger2, echo2);
  distD = dist; //Distancia del sensor derecho

  //Descomente para debuguear en: Arduino IDE > Tools > Serial Monitor
  lcd.clear(); //Limpia la pantalla para que no queden letras
  lcd.setCursor(0, 0); 
  //Especifica donde va a imprimir

  Serial.print("L=");
  Serial.println(distI);

  Serial.print("R=");
  Serial.println(distD);
  lcd.print(izquierda + distI);
  lcd.setCursor(0, 1);
  lcd.print(derecha + distD);
  //Pause Modes -Hold entre 40 y 50cm
  if ((distI > 30 && distD > 30) && (distI < 40 && distD < 40)) //Detectar ambas manos entre 40cm y 50cm
  {
    Serial.println("PlayStop");
    delay (500);
  }

  calculate_distance(trigger1, echo1);
  distI = dist;

  calculate_distance(trigger2, echo2);
  distD = dist;



  //Control Modes
  //Lock izquierda - Control Mode
  if (distI >= 13 && distI <= 17)
  {
    delay(100); //Hand Hold Time
    calculate_distance(trigger1, echo1);
    distI = dist;
    if (distI >= 13 && distI <= 17)
    {
      Serial.println("Left Locked");
      while (distI <= 40)
      {
        calculate_distance(trigger1, echo1);
        distI = dist;
        if (distI < 10) //Hand pushed in
        {
          Serial.println ("Vup");
          delay (300);
        }
        if (distI > 20) //Hand pulled out
        {
          Serial.println ("Vdown");
          delay (300);
        }
      }
    }
  }

  //Lock Derecha - Control Mode
  if (distD >= 13 && distD <= 17)
  {
    delay(100); //Hand Hold Time
    calculate_distance(trigger2, echo2);
    distD = dist;
    if (distD >= 13 && distD <= 17)
    {
      Serial.println("Right Locked");
      while (distD <= 40)
      {
        calculate_distance(trigger2, echo2);
        distD = dist;
        if (distD < 10) //Mano derecha  pushed in
        {
          Serial.println ("Rewind");
          delay (300);
        }
        if (distD > 20) //Mano derecha pulled out
        {
          Serial.println ("Forward");
          delay (300);
        }
      }
    }
  }

  
  delay(500);
}

