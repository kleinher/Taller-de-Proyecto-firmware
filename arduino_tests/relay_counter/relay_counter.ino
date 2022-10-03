/************************************************
Name： 4 channel_relay
Description: control the 4 channel relay module to ON or OFF
Website: www.handsontec.com
Email: techsupport@handsontec.com
*****************************************************/

//the relays connect to
int RelayControl1 = 4; // Digital Arduino Pin used to control the motor
int RelayControl2 = 5;
int RelayControl3 = 6;
int RelayControl4 = 7;

int BinRelay[64] = { LOW, LOW, LOW, LOW,    // 0
                     LOW, LOW, LOW,HIGH,    // 1
                     LOW, LOW,HIGH, LOW,    // 2
                     LOW, LOW,HIGH,HIGH,    // 3
                     LOW,HIGH, LOW, LOW,    // 4
                     LOW,HIGH, LOW,HIGH,    // 5
                     LOW,HIGH,HIGH, LOW,    // 6
                     LOW,HIGH,HIGH,HIGH,    // 7
                    HIGH, LOW, LOW, LOW,    // 8
                    HIGH, LOW, LOW,HIGH,    // 9
                    HIGH, LOW,HIGH, LOW,    // A (10)
                    HIGH, LOW,HIGH,HIGH,    // B (11)
                    HIGH,HIGH, LOW, LOW,    // C (12)
                    HIGH,HIGH, LOW,HIGH,    // D (13)
                    HIGH,HIGH,HIGH, LOW,    // E (14)
                    HIGH,HIGH,HIGH,HIGH,};  // F (15)

void setup(){
Serial.begin(9600);
pinMode(RelayControl1, OUTPUT);
pinMode(RelayControl2, OUTPUT);
pinMode(RelayControl3, OUTPUT);
pinMode(RelayControl4, OUTPUT);
}

void loop() {
/*digitalWrite(RelayControl1,HIGH);// NO1 and COM1 Connected (LED on)
delay(1000);
digitalWrite(RelayControl1,LOW);// NO1 and COM1 disconnected (LED off)
delay(1000);
digitalWrite(RelayControl2,HIGH);
delay(1000);
digitalWrite(RelayControl2,LOW);
delay(1000);
digitalWrite(RelayControl3,HIGH);
delay(1000);
digitalWrite(RelayControl3,LOW);
delay(1000);
digitalWrite(RelayControl4,HIGH);
delay(1000);
digitalWrite(RelayControl4,LOW);
delay(1000);*/
  int j;
  for (int i=0;i<16;i++){
      j=4*i;
      digitalWrite(RelayControl1,!BinRelay[j]);
      digitalWrite(RelayControl2,!BinRelay[j+1]);
      digitalWrite(RelayControl3,!BinRelay[j+2]);
      digitalWrite(RelayControl4,!BinRelay[j+3]);
      delay(1000);
    }
}
