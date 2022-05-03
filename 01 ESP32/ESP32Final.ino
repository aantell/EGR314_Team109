#include <WiFi.h>
#include "WiFiClientSecure.h"
#include "Adafruit_MQTT.h"
#include "Adafruit_MQTT_Client.h"
#include <SoftwareSerial.h>

#define WLAN_SSID "photon"
#define WLAN_PASS "particle"

#define AIO_SERVER      "io.adafruit.com"

#define AIO_SERVERPORT  8883

#define AIO_USERNAME "zgoode"
#define AIO_KEY      "aio_pfwx68G5qnnjunIBqUFUJ0pVmn5t"

WiFiClientSecure client;

Adafruit_MQTT_Client mqtt(&client, AIO_SERVER, AIO_SERVERPORT, AIO_USERNAME, AIO_KEY);

const char* adafruitio_root_ca = \
                                 "-----BEGIN CERTIFICATE-----\n" \
                                 "MIIDrzCCApegAwIBAgIQCDvgVpBCRrGhdWrJWZHHSjANBgkqhkiG9w0BAQUFADBh\n" \
                                 "MQswCQYDVQQGEwJVUzEVMBMGA1UEChMMRGlnaUNlcnQgSW5jMRkwFwYDVQQLExB3\n" \
                                 "d3cuZGlnaWNlcnQuY29tMSAwHgYDVQQDExdEaWdpQ2VydCBHbG9iYWwgUm9vdCBD\n" \
                                 "QTAeFw0wNjExMTAwMDAwMDBaFw0zMTExMTAwMDAwMDBaMGExCzAJBgNVBAYTAlVT\n" \
                                 "MRUwEwYDVQQKEwxEaWdpQ2VydCBJbmMxGTAXBgNVBAsTEHd3dy5kaWdpY2VydC5j\n" \
                                 "b20xIDAeBgNVBAMTF0RpZ2lDZXJ0IEdsb2JhbCBSb290IENBMIIBIjANBgkqhkiG\n" \
                                 "9w0BAQEFAAOCAQ8AMIIBCgKCAQEA4jvhEXLeqKTTo1eqUKKPC3eQyaKl7hLOllsB\n" \
                                 "CSDMAZOnTjC3U/dDxGkAV53ijSLdhwZAAIEJzs4bg7/fzTtxRuLWZscFs3YnFo97\n" \
                                 "nh6Vfe63SKMI2tavegw5BmV/Sl0fvBf4q77uKNd0f3p4mVmFaG5cIzJLv07A6Fpt\n" \
                                 "43C/dxC//AH2hdmoRBBYMql1GNXRor5H4idq9Joz+EkIYIvUX7Q6hL+hqkpMfT7P\n" \
                                 "T19sdl6gSzeRntwi5m3OFBqOasv+zbMUZBfHWymeMr/y7vrTC0LUq7dBMtoM1O/4\n" \
                                 "gdW7jVg/tRvoSSiicNoxBN33shbyTApOB6jtSj1etX+jkMOvJwIDAQABo2MwYTAO\n" \
                                 "BgNVHQ8BAf8EBAMCAYYwDwYDVR0TAQH/BAUwAwEB/zAdBgNVHQ4EFgQUA95QNVbR\n" \
                                 "TLtm8KPiGxvDl7I90VUwHwYDVR0jBBgwFoAUA95QNVbRTLtm8KPiGxvDl7I90VUw\n" \
                                 "DQYJKoZIhvcNAQEFBQADggEBAMucN6pIExIK+t1EnE9SsPTfrgT1eXkIoyQY/Esr\n" \
                                 "hMAtudXH/vTBH1jLuG2cenTnmCmrEbXjcKChzUyImZOMkXDiqw8cvpOp/2PV5Adg\n" \
                                 "06O/nVsJ8dWO41P0jmP6P6fbtGbfYmbW0W5BjfIttep3Sp+dWOIrWcBAI+0tKIJF\n" \
                                 "PnlUkiaY4IBIqDfv8NZ5YBberOgOzW6sRBc4L0na4UU+Krk2U886UAb3LujEV0ls\n" \
                                 "YSEY1QSteDwsOoBrp+uvFRTp2InBuThs4pFsiv9kuXclVzDAGySj4dzp30d8tbQk\n" \
                                 "CAUw7C29C79Fv1C5qfPrmAESrciIxpg0X40KPMbp1ZWVbd4=\n" \
                                 "-----END CERTIFICATE-----\n";

Adafruit_MQTT_Publish test = Adafruit_MQTT_Publish(&mqtt, AIO_USERNAME "/feeds/test");
Adafruit_MQTT_Publish moist = Adafruit_MQTT_Publish(&mqtt, AIO_USERNAME "/feeds/moist");

#define RXp2 17
#define TXp2 16

int blep;

SoftwareSerial mySerial(16, 17);

unsigned int HighByte = 0;
unsigned int LowByte  = 0;
unsigned int Len  = 0;

void setup() {
  Serial.begin(9600);
  mySerial.begin(9600);

  WiFi.begin(WLAN_SSID, WLAN_PASS);
  delay(2000);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
  }

  Serial.print("setup done");

  client.setCACert(adafruitio_root_ca);
}

void loop() {
  MQTT_connect();
  if (mySerial.available()) {
    blep = (mySerial.read());
    moist.publish(mySerial.read());
    if (blep < 150) {
      mySerial.println(1);
    } else {
      mySerial.println(0);
    }
  }

  Serial.flush();
  Serial.write(0X55);
  delay(100);
  Serial.print("test2");

  if (Serial.available() >= 2) {
    HighByte = Serial.read();
    LowByte  = Serial.read();
    Len  = HighByte * 256 + LowByte;
    if ((Len > 1) && (Len < 10000)) {
      if (blep < 30) {
        mySerial.println(1);
      } else {
        mySerial.println(0);
      }

      test.publish(Len);
    }
  }
}

void MQTT_connect() {
  int8_t ret;

  // Stop if already connected.
  if (mqtt.connected()) {
    return;
  }

  uint8_t retries = 0;
  while ((ret = mqtt.connect()) != 0) { // connect will return 0 for connected
    mqtt.disconnect();
    delay(5000);  // wait 5 seconds
    retries--;
    if (retries == 0) {
      // basically die and wait for WDT to reset me
      while (1);
    }
  }
}
