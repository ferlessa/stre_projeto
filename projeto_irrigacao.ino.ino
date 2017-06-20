#include "Timer.h"

Timer t;
int pin = 6;
int umidade = 0;
int umid_minima = 1020;

void setup()
{
  Serial.begin(9600);
  pinMode(pin, OUTPUT);  
  t.every(60000, takeReading); // 1 minuto
}

void loop()
{
  t.update();
}

void takeReading()
{
  Serial.print("A umidade agora e: "); //Escreve a umidade na Serial
  umidade = analogRead(A0);
  Serial.println(umidade);
  if(umidade<=umid_minima) //Condicional que testa a umidade do sistema
  {
   digitalWrite(pin, HIGH); //Liga a valvula e inicia a irrigacao
  } else {
    digitalWrite(pin, LOW); //Desliga a valvula
  }
  

  //
  //
}
