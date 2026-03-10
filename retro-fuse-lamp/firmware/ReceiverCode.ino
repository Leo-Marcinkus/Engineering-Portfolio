#include <WiFi.h>
#include <esp_now.h>
#include <esp_wifi.h>

static const int LED_SW_PIN = 4;

typedef struct __attribute__((packed)) {

  uint8_t on;

} LampMsg;

void onDataRecv(const esp_now_recv_info_t *info, const uint8_t *data, int len) {

  if (len < (int)sizeof(LampMsg)) {

    return;

  }

  LampMsg msg;
  memcpy(&msg, data, sizeof(msg));
  digitalWrite(LED_SW_PIN, msg.on ? HIGH : LOW);
  Serial.println(msg.on ? "Got: ON" : "Got: OFF");

}

void setup() {

  Serial.begin(115200);

  pinMode(LED_SW_PIN, OUTPUT);
  digitalWrite(LED_SW_PIN, HIGH);

  WiFi.mode(WIFI_STA);
  delay(200);

  uint8_t mac[6];
  esp_wifi_get_mac(WIFI_IF_STA, mac);
  Serial.printf("Lamp MAC: %02X:%02X:%02X:%02X:%02X:%02X\n", mac[0], mac[1], mac[2], mac[3], mac[4], mac[5]);

  WiFi.mode(WIFI_STA);
  esp_wifi_set_channel(1, WIFI_SECOND_CHAN_NONE);

  if (esp_now_init() != ESP_OK) {

    Serial.println("ESP-NOW init failed");

    while (true) {
      
      delay(1000);
      
    }

  }

  esp_now_register_recv_cb(onDataRecv);
  Serial.println("Receiver ready.");

}

void loop() {}