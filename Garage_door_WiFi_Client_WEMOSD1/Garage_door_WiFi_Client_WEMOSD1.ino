/*
 *  This sketch demonstrates how to scan WiFi networks.
 *  The API is almost the same as with the WiFi Shield library,
 *  the most obvious difference being the different file you need to include:
 */
#include "WiFi.h"

void setup()
{
    Serial.begin(115200);

    // Set WiFi to station mode and disconnect from an AP if it was previously connected
    WiFi.mode(WIFI_STA);
    WiFi.disconnect();
    delay(100);
}

void loop()
{
    // WiFi.scanNetworks will return he number of networks found
    int n = WiFi.scanNetworks();
    Serial.println("scan done");
    if (n == 0) {
        Serial.println("no networks found");
    } else {
        for (int i = 0; i < n; ++i) {
            // Print SSID and RSSI for each network found
            Serial.println(WiFi.SSID(i));
            Serial.println(WiFi.RSSI(i));
            Serial.println(WiFi.encryptionType(i));
            delay(10);
        }
    }

    // Wait a bit before scanning again
    delay(5000);
}
