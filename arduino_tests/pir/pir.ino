#define PIR_INPUT 8

void setup() {
  pinMode(PIR_INPUT,INPUT);
  pinMode(LED_BUILTIN,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  uint8_t valor;
  while (1) {
    valor=digitalRead(PIR_INPUT);
    digitalWrite(LED_BUILTIN,valor);
  }
}
