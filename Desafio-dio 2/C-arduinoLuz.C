const int ldrPin = A0;      // Pino do LDR
const int ledPin = 13;      // LED que simula a lâmpada

// Usar RTC (DS3231 ou DS1307): permite ler a hora real mesmo sem o PC.
// Para isso, você precisaria de uma biblioteca como RTClib.h e um módulo RTC conectado ao Arduino.
// Aqui, vamos simular a hora atual com uma variável inteira.

int horaAtual = 18;         // Simulando a hora atual (18h)
// Para simular a hora atual, você pode usar um módulo RTC (Real Time Clock) ou definir manualmente
int valorLDR = 0;           // Valor lido do LDR

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  valorLDR = analogRead(ldrPin); // Lê o valor do LDR
  Serial.print("Hora atual: ");
  Serial.println(horaAtual);
  Serial.print("Luz ambiente (LDR): ");
  Serial.println(valorLDR);

  // Condição: depois das 18h e está escuro
  if (horaAtual >= 18 && valorLDR < 500) {
    digitalWrite(ledPin, HIGH); // Liga a luz
    Serial.println("Ambiente escuro após as 18h - Luz ligada!");
  } else {
    digitalWrite(ledPin, LOW);  // Desliga a luz
    Serial.println("Luz desligada.");
  }

  delay(2000); // Espera 2 segundos antes de repetir
}
