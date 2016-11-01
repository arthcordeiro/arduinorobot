#include <Ultrasonic.h>

//pinos do Sensor ultrassonico

int triger = //pin trigger
int echo = //pin echo

//pinos dos motores

const int AIA = //pino de controle do motor direito
const int AIB = //pino de controle do motor direito
const int BIA = //pino de controle do motor esquerdo
const int BIB = //pino de controle do motor esquerdo

//Velocidade

#define VEL_MAX 254
#define VEL_MIN 120
#define VEL_MED 187

/*
 A -> Automático
 M -> Manual 
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

void automatico(){
  
}

void manual(){
  
}

