#include <WiFi.h>
#include <esp_now.h>
#include <esp_wifi.h>

typedef struct __attribute__((packed)) {

  uint8_t on;

} LampMsg;


uint8_t RECEIVER_MAC[] = { 

  0x1C, 0xDB, 0xD4, 0x36, 0x9D, 0xF8 

};

static const int BUTTON_PIN = 0;
bool lampOn = false;

void onSend(const wifi_tx_info_t *info, esp_now_send_status_t status) {

  Serial.print("Send: ");
  Serial.println(status == ESP_NOW_SEND_SUCCESS ? "OK" : "FAIL");

}

void setup() {

  Serial.begin(115200);
  pinMode(BUTTON_PIN, INPUT_PULLUP);

  WiFi.mode(WIFI_STA);
  esp_wifi_set_channel(1, WIFI_SECOND_CHAN_NONE);

  if (esp_now_init() != ESP_OK) {

    Serial.println("ESP-NOW init failed");

    while (true) {
      
      delay(1000);
      
    }

  }

  esp_now_register_send_cb(onSend);

  esp_now_peer_info_t peerInfo = {};
  memcpy(peerInfo.peer_addr, RECEIVER_MAC, 6);
  peerInfo.channel = 0;
  peerInfo.encrypt = false;

  if (esp_now_add_peer(&peerInfo) != ESP_OK) {

    Serial.println("Failed to add peer");

    while (true) {
      
      delay(1000);

    }

  }

  Serial.println("Sender ready. Press button to toggle.");

}

void sendLamp(bool on) {

  LampMsg msg{ 
    
    (uint8_t)(on ? 1 : 0) 
    
  };

  esp_err_t r = esp_now_send(RECEIVER_MAC, (uint8_t*)&msg, sizeof(msg));
  Serial.println(r == ESP_OK ? (on ? "Queued ON" : "Queued OFF") : "Send error");

}

void loop() {

  static bool last = HIGH;
  bool now = digitalRead(BUTTON_PIN);

  if (last == HIGH && now == LOW) {

    lampOn = !lampOn;
    sendLamp(lampOn);
    delay(250);

  }

  last = now;
  
}