#include <VirtualWire.h>

void setup() {
  Serial.begin(9600);
  Serial.println("setup");
  vw_set_tx_pin(12);
  vw_setup(2000);// скорость передачи данных в Kbps
}

void loop() {
  char controller[1] = {'1'};
  digitalWrite(13,1);
  vw_send((uint8_t *)controller, 1);
  vw_wait_tx();
  digitalWrite(13,0);
  Serial.println("Sent: 1");
  delay(700);

  controller[0] = '0';
  digitalWrite(13,1);
  vw_send((uint8_t *)controller, 1);
  vw_wait_tx();
  digitalWrite(13,0);
  Serial.println("Sent: 0");
  delay(700);
}
