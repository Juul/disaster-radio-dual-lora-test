#include <SPI.h>
#include <LoRa.h>

#define ss_lora1 16 // SS pin for 1st LoRa module
#define ss_lora2 34 // SS pin for 2nd LoRa module
#define rst 5 // setting to ESP LED since we don't have reset
//#define dio0 21

int counter = 0;

void setup() {

  Serial.begin(115200);

  Serial.println("LoRa Sender");

  pinMode(ss_lora1, OUTPUT);
  pinMode(ss_lora2, OUTPUT);
  digitalWrite(ss_lora1, LOW);
  digitalWrite(ss_lora2, LOW);

  LoRa.setPins(ss_lora1, rst);
  
  while (!LoRa.begin(915E6)) {
    Serial.println(".");
    delay(500);
  }
  
  // Change sync word (0xF3) to match the receiver
  // The sync word assures you don't get LoRa messages from other LoRa transceivers
  // ranges from 0-0xFF
  LoRa.setSyncWord(0xF3);
  Serial.println("LoRa Initializing OK!");
}

void loop() {
  Serial.print("Sending packet: ");
  Serial.println(counter);

  LoRa.beginPacket();
  LoRa.print("hello ");
  LoRa.print(counter);
  LoRa.endPacket();

  counter++;

  delay(10000);
}
