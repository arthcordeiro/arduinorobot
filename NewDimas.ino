#include <DHT.h>
#include <DHT_U.h>
#include <Ultrasonic.h>
#include <Servo.h>

#define dht_pin  //Pino de controle de dados do DHT
#define DHTTYPE DHT11

//pinos do Sensor ultrassonico

int triger = A2; //pin trigger
int echo = A3; //pin echo

//pinos dos motores

const int AIA = 3; //pino de controle do motor direito
const int AIB = 2; //pino de controle do motor direito
const int BIA = 5; //pino de controle do motor esquerdo
const int BIB = 4; //pino de controle do motor esquerdo

//Velocidade

#define VEL_MAX 254
#define VEL_MIN 120
#define VEL_MED 187

//Inicializa variável que controla o sensor US e Servo

Ultrasonic us(trigger, echo);
Servo servoUS;

long dist; //Variável de distância

/*
 A -> Automático
 M -> Manual 
 F -> Frente
 P -> Parar
 E -> Esquerda
 D -> Direita
 Gd -> Girar Direita
 Ge -> Girar Esquerda
 Gb -> Girar 180°
 */

void setup() {
  
  //Definindo pinos como saída
  pinMode(AIA, OUTPUT);
  pinMode(AIB, OUTPUT);
  pinMode(BIA, OUTPUT);
  pinMode(BIB, OUTPUT);

  
  Serial.begin(9600);
}

void loop() {
  unsigned char com;

  com = Serial.read();
  switch(com){
    case 'A':
      automatico();
      break;
    case 'M':
      manual();
      break;
    default:
      break;
  }

}

void andar(){ //Faz o robo seguir em frente (linha reta)
  analogWrite(AIA, VEL_MAX);
  analogWrite(AIB, LOW);
  analogWrite(BIA, VEL_MA0);
  analogWrite(BIB, LOW);
}

void parar(){
  analogWrite(AIA, LOW);
  analogWrite(AIB, VEL_MED);
  analogWrite(BIA, LOW);
  analogWrite(BIB, VEL_MED);
}

void virarDir(){
  analogWrite(AIA, VEL_MIN);
  analogWrite(AIB, LOW);
  analogWrite(BIA, VEL_MAX);
  analogWrite(BIB, LOW);
}

void viarEsq(){
  analogWrite(AIA, VEL_MAX);
  analogWrite(AIB, LOW);
  analogWrite(BIA, VEL_MIN);
  analogWrite(BIB, LOW);
}

void toBack(){
  analogWrite(AIA, VEL_MED);
  analogWrite(AIB, LOW);
  analogWrite(BIA, LOW);
  analogWrite(BIB, VEL_MED);
  delay(1500);
}

void toLeft(){
  analogWrite(AIA, VEL_MED);
  analogWrite(AIB, LOW);
  analogWrite(BIA, LOW);
  analogWrite(BIB, VEL_MED);
  delay(750);
}

void toRight(){
  analogWrite(AIA, LOW);
  analogWrite(AIB, VEL_MED);
  analogWrite(BIA, VEL_MED);
  analogWrite(BIB, LOW);
  delay(750);
}

long verificaDist(){
 dist = us.convert(us.timing(), Ultrasonic::CM);
 delay(25);
 return dist;
}

void reposicionaServo(){
 servoUS.write(90);
 delay(200);
}



void automatico(){
 reposicionaServo();
 if(verificaDist() > 25){
  andar();
 }else{
  parar();
}

void manual(){
  
}

