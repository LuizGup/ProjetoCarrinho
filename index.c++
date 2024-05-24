//CÓDIGO COM TENTATIVA DE CORREAÇÃO E PRONTO PARA TESTE:// Define os pinos para os motores do lado direito
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

  // Define a velocidade dos motores

  // Aguarda um curto período de tempo antes de repetir o loop
}