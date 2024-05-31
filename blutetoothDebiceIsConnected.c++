#include <AFMotor.h>  // Biblioteca para controle dos motores
#include <SoftwareSerial.h> // Biblioteca para comunicação serial com Bluetooth

// Definindo os pinos dos sensores de linha
#define SENSOR_ESQUERDO A0
#define SENSOR_CENTRO A1
#define SENSOR_DIREITO A2

// Configurando os motores
AF_DCMotor motorEsquerdo(1);
AF_DCMotor motorDireito(2);

// Configurando a comunicação Bluetooth
SoftwareSerial bluetooth(10, 11); // RX, TX

void setup() {
  // Inicializando a comunicação serial e Bluetooth
  Serial.begin(9600);
  bluetooth.begin(9600);

  // Configurando os pinos dos sensores de linha como entrada
  pinMode(SENSOR_ESQUERDO, INPUT);
  pinMode(SENSOR_CENTRO, INPUT);
  pinMode(SENSOR_DIREITO, INPUT);

  // Configurando a velocidade inicial dos motores
  motorEsquerdo.setSpeed(150);
  motorDireito.setSpeed(150);
}

void loop() {
  // Leitura dos sensores de linha
  int valorEsquerdo = analogRead(SENSOR_ESQUERDO);
  int valorCentro = analogRead(SENSOR_CENTRO);
  int valorDireito = analogRead(SENSOR_DIREITO);

  // Variável para armazenar comandos recebidos via Bluetooth
  char comando;

  // Verifica se há dados disponíveis no Bluetooth
  if (bluetooth.available()) {
    comando = bluetooth.read();
    executarComando(comando);
  } else {
    seguirLinha(valorEsquerdo, valorCentro, valorDireito);
  }
}

void seguirLinha(int esq, int centro, int dir) {
  // Definindo a lógica de seguimento de linha
  if (centro > 500) {
    // Linha no centro
    motorEsquerdo.run(FORWARD);
    motorDireito.run(FORWARD);
  } else if (esq > 500) {
    // Linha à esquerda
    motorEsquerdo.run(BACKWARD);
    motorDireito.run(FORWARD);
  } else if (dir > 500) {
    // Linha à direita
    motorEsquerdo.run(FORWARD);
    motorDireito.run(BACKWARD);
  } else {
    // Sem linha detectada
    motorEsquerdo.run(RELEASE);
    motorDireito.run(RELEASE);
  }
}

void executarComando(char cmd) {
  // Executa o comando recebido via Bluetooth
  switch (cmd) {
    case 'F':
      motorEsquerdo.run(FORWARD);
      motorDireito.run(FORWARD);
      break;
    case 'B':
      motorEsquerdo.run(BACKWARD);
      motorDireito.run(BACKWARD);
      break;
    case 'L':
      motorEsquerdo.run(BACKWARD);
      motorDireito.run(FORWARD);
      break;
    case 'R':
      motorEsquerdo.run(FORWARD);
      motorDireito.run(BACKWARD);
      break;
    case 'S':
      motorEsquerdo.run(RELEASE);
      motorDireito.run(RELEASE);
      break;
    default:
      // Comando desconhecido
      break;
  }
}