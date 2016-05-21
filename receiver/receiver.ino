#include <VirtualWire.h>

void setup() {
  Serial.begin(9600);
  vw_set_rx_pin(12);
  vw_setup(2000); // bits per second
  vw_rx_start();
}

void loop() {
  uint8_t buf[VW_MAX_MESSAGE_LEN];
  uint8_t buflen = VW_MAX_MESSAGE_LEN;
  if (vw_get_message(buf, &buflen)) {
    if (buf[0] == '1') {
      Serial.print("1");
      digitalWrite(13,1);
    }
    if (buf[0] == '0') {
      Serial.print("0");
      digitalWrite(13,0);
    }
  }
}
