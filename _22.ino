int enA = 10;  // Pin PWM pour la vitesse
int in1 = 8;  // Pin direction 1
int in2 = 7;  // Pin direction 2
int joyX = A0;

void setup() {
  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
}

void loop() {
  int val = analogRead(joyX);

  if (val > 550) { // Avancer
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    int vitesse = map(val, 550, 1023, 0, 255);
    analogWrite(enA, vitesse);
  } 
  else if (val < 470) { // Reculer
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    int vitesse = map(val, 470, 0, 0, 255);
    analogWrite(enA, vitesse);
  } 
  else { // Arrêt (zone morte au centre)
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
    analogWrite(enA, 0);
  }
}

