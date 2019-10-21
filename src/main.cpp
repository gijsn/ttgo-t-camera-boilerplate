#include <Adafruit_GFX.h>
#include <Adafruit_ST7789.h>
#include "app_camera.h"

Adafruit_ST7789 tft = Adafruit_ST7789(TFT_CS, TFT_DC, TFT_RST);

// INFO: you can set CAMERA_FRAME_SIZE to FRAMESIZE_HQVGA in app_camera.h
#define PREVIEW_W 240
#define PREVIEW_H 176
// INFO: you can set CAMERA_PIXEL_FORMAT to PIXFORMAT_RGB565 in app_camera.h

#define TFT_W 240
#define TFT_H 240
#define TFT_ROTATION 2

void setupDisplay() {
  pinMode(TFT_BK, OUTPUT);
  digitalWrite(TFT_BK, HIGH);
  tft.init(TFT_W, TFT_H);
}

void setup() {
  Serial.begin(9600);
  Serial.println("Starting...");

  setupDisplay();
  // rotate the screen so the USB port is facing down
  tft.setRotation(TFT_ROTATION);
  tft.fillScreen(ST77XX_BLACK);

  app_camera_init();
}

unsigned long lastMillis = 0;
uint16_t *rgbBitmap = new uint16_t[PREVIEW_W * PREVIEW_H];

void loop() {
  delay(100);
  camera_fb_t *fb = esp_camera_fb_get();
  if (fb) {
    // convert array of uint8_t to uint16_t (RGB565)
    for (int ptr = 0; ptr < fb->width * fb->height * 2; ptr += 2) {
      // we rotate the bitmap by 180 degrees here, and join two bytes to get an RGB565 uint16_t
      rgbBitmap[fb->width * fb->height - (ptr / 2)] = fb->buf[ptr] << 8 | fb->buf[ptr + 1];
    }
    tft.drawRGBBitmap(0, 0, rgbBitmap, fb->width, fb->height);

    tft.setCursor(0, 0);
    tft.setTextColor(ST77XX_WHITE);
    tft.print(String(fb->width) + "x" + String(fb->height) + String(" FPS: ") + String(1000 / (millis() - lastMillis)));
    lastMillis = millis();

    // release resources
    esp_camera_fb_return(fb);
    fb = NULL;
  }
}
