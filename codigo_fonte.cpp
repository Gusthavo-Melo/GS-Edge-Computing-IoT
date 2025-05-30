// Desenvolvedor:
// Gusthavo Costa de Melo - RM: 561330.

#include <LiquidCrystal_I2C.h>

// Definições dos pinos
#define TRIG_PIN 6
#define ECHO_PIN 7
#define LED_G 2
#define LED_Y 3
#define LED_R 4
#define BUZZER 5

// Inicialização dos objetos
LiquidCrystal_I2C lcd(0x27, 20, 4);

void setup() {
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(LED_G, OUTPUT);
  pinMode(LED_Y, OUTPUT);
  pinMode(LED_R, OUTPUT);
  pinMode(BUZZER, OUTPUT);

  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
}

void loop() {
  // Medição do sensor ultrassônico
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  long duracao = pulseIn(ECHO_PIN, HIGH);
  float distancia = duracao * 0.034 / 2.0; // cm

  Serial.print("Distancia: ");
  Serial.print(distancia, 1);
  Serial.println("cm");

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Distancia: ");
  lcd.print(distancia, 1);
  lcd.print("cm");

  lcd.setCursor(0, 1);

if (distancia > 70) {
  // Caso 1: Água longe (nível baixo) — Status OK
  digitalWrite(LED_G, HIGH);    // Liga LED verde
  digitalWrite(LED_Y, LOW);
  digitalWrite(LED_R, LOW);
  noTone(BUZZER);              // Buzzer desligado
  lcd.print("Status: Normal");

} else if (distancia <= 70 && distancia > 30) {
  // Caso 2: Água em nível intermediário — Status ALERTA
  digitalWrite(LED_G, LOW);
  digitalWrite(LED_Y, HIGH);    // Liga LED amarelo
  digitalWrite(LED_R, LOW);
  noTone(BUZZER);              // Buzzer desligado
  lcd.print("Status: ALERTA");

} else if (distancia <= 30) {
  // Caso 3: Água muito próxima — Status crítico de enchente
  digitalWrite(LED_G, LOW);
  digitalWrite(LED_Y, LOW);
  digitalWrite(LED_R, HIGH);    // Liga LED vermelho
  tone(BUZZER, 1000);          // Ativa buzzer com som de alerta
  lcd.print("!!! ENCHENTE !!!");
}

delay(500);
}