#include <SoftwareSerial.h>

// Definição dos pinos para comunicação com o módulo Bluetooth
int bluetoothTx = 9;  // Pino TX do módulo Bluetooth conectado ao RX do Arduino
int bluetoothRx = 8;  // Pino RX do módulo Bluetooth conectado ao TX do Arduino

// Inicialização do objeto para comunicação Bluetooth
SoftwareSerial bluetooth(bluetoothRx, bluetoothTx);


void setup() 
{
  // Inicialização da comunicação serial padrão (para comunicação com o computador via USB)
  Serial.begin(9600);
  
  // Inicialização da comunicação serial com o módulo Bluetooth
  bluetooth.begin(9600);

  // Motor Esquerdo
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  //motor direito
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);

}
void loop(){  
if(bluetooth.available() > 0)
   {
	char X = bluetooth.read();
    // Condicional para frente
    if (X == '2') {
    digitalWrite(5, HIGH);
    digitalWrite(6, HIGH);
    digitalWrite(4, LOW);
    digitalWrite(7, LOW);
    } 
    // Condicional para ré
    if (X == '3') {
    digitalWrite(4, HIGH);
    digitalWrite(7, HIGH);
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
    }     
    // Condicional para direita
    if(X == '4') {
    digitalWrite(7, HIGH);
    digitalWrite(5, HIGH);
    digitalWrite(4, LOW);
    digitalWrite(6, LOW);
    }    
    // Condicional para esquerda
    if(X == '5'){
    digitalWrite(6, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(5, LOW);
    digitalWrite(7, LOW);
    }
    // Condicional para parada
    if (X == '9'){
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
    digitalWrite(4, LOW);
    digitalWrite(7, LOW);
    } 

  // delay(10); // Delay a little bit to improve simulation performance
}
}