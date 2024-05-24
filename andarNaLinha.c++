//CÓDIGO COM TENTATIVA DE CORREAÇÃO E PRONTO PARA TESTE:// Define os pinos para os motores do lado direito
#include <Servo.h>

int direita = 0;

int esquerda = 0;

int limite = 30;

Servo servo;

long readUltrasonicDistance(int triggerPin, int echoPin)
{
  pinMode(triggerPin, OUTPUT);  // Clear the trigger
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  // Sets the trigger pin to HIGH state for 10 microseconds
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  // Reads the echo pin, and returns the sound wave travel time in microseconds
  return pulseIn(echoPin, HIGH);
}

int motor1H = 6;
int motor1L = 7;

// Define os pinos para os motores do lado esquerdo
int motor2H = 4;
int motor2L = 5;

// Define os pinos para os fotorresistores
int fotorresistor1 = 3;
int fotorresistor2 = 12;

void setup()
{
  // Configura os pinos como saída ou entrada conforme necessário
  servo.attach(11, 544, 2400);
  Serial.begin(9600);

  servo.write(90);

  pinMode(motor1H, OUTPUT);
  pinMode(motor1L, OUTPUT);
  pinMode(motor2H, OUTPUT);
  pinMode(motor2L, OUTPUT);
  pinMode(fotorresistor1, INPUT_PULLUP);
  pinMode(fotorresistor2, INPUT_PULLUP);

  // Inicia a comunicação serial
  Serial.begin(9600);
}

void loop()
{
  // Lê os valores dos fotorresistores
  int valorFotorresistor1 = digitalRead(fotorresistor1);
  int valorFotorresistor2 = digitalRead(fotorresistor2);

  // Verifica se ambos os sensores detectam preto
  if (valorFotorresistor1 == 0 && valorFotorresistor2 == 0) {
    // Ambos os fotorresistores detectam a linha preta, avança
    analogWrite(motor1H, 190);
    analogWrite(motor1L, 0);
    analogWrite(motor2H, 0);
    analogWrite(motor2L, 190);
  }
  else if (valorFotorresistor1 == 1 && valorFotorresistor2 == 1) {
    // Ambos os fotorresistores detectam a linha preta, avança
    analogWrite(motor1H, 0);
    analogWrite(motor1L, 0);
    analogWrite(motor2H, 0);
    analogWrite(motor2L, 0);
  } else if (valorFotorresistor1 == 0) {
    // Apenas o fotorresistor 1 detecta a linha preta, para a roda direita
    analogWrite(motor1H, 0);
    analogWrite(motor1L, 0);
    analogWrite(motor2H, 0);
    analogWrite(motor2L, 190);
  } else if (valorFotorresistor2 == 0) {
    // Apenas o fotorresistor 2 detecta a linha preta, para a roda esquerda
    analogWrite(motor1H, 190);
    analogWrite(motor1L, 0);
    analogWrite(motor2H, 0);
    analogWrite(motor2L, 0);
  }

  if (0.01723 * readUltrasonicDistance(4, 5) < limite) {
    servo.write(0);
    delay(3000); // Wait for 3000 millisecond(s)
    if (servo.read() == 0) {
      esquerda = 0.01723 * readUltrasonicDistance(4, 5);
    }
    servo.write(180);
    delay(4000); // Wait for 4000 millisecond(s)
    if (servo.read() == 180) {
      direita = 0.01723 * readUltrasonicDistance(4, 5);
    }
    if (direita >= esquerda) {
      Serial.print("Direita: ");
      Serial.print(direita);
      Serial.print("  Esquerda: ");
      Serial.print(esquerda);
      Serial.println("------------  Direita");
      Serial.println("==============================================");
      servo.write(90);
    } else {
      Serial.print("Direita: ");
      Serial.print(direita);
      Serial.print("  Esquerda: ");
      Serial.print(esquerda);
      Serial.println("------------  Esquerda");
      Serial.println("================================");
      servo.write(90);
    }
  }

  // Define a velocidade dos motores

  // Aguarda um curto período de tempo antes de repetir o loop
}

// C++ code
//