#ifndef Pins_Arduino_h
#define Pins_Arduino_h

#include <stdint.h>

#define EXTERNAL_NUM_INTERRUPTS 16
#define NUM_DIGITAL_PINS        40
#define NUM_ANALOG_INPUTS       16

#define analogInputToDigitalPin(p)  (((p)<20)?(esp32_adc2gpio[(p)]):-1)
#define digitalPinToInterrupt(p)    (((p)<40)?(p):-1)
#define digitalPinHasPWM(p)         (p < 34)

static const uint8_t TX = 1;
static const uint8_t RX = 3;

static const uint8_t LED_BUILTIN = -1; // 22;
#define BUILTIN_LED  LED_BUILTIN // backward compatibility

static const uint8_t SDA = 18;
// Despite the many diagrams from TTGO showing SCL on pin 22, due to the on-board LED
// also on this pin it is better to shift to 23 instead to avoid issues.
static const uint8_t SCL = 23;

// TFT & SD Card Pins
static const uint8_t SS    = 0;
static const uint8_t MOSI  = 19;
static const uint8_t MISO  = 22;
static const uint8_t SCK   = 21;
static const uint8_t DC    = 15;

static const uint8_t SD_CS = 0;
static const uint8_t SD_MOSI = 19;
static const uint8_t SD_MISO = 22;
static const uint8_t SD_CLK = 21;

static const uint8_t TFT_MOSI = 19;
static const uint8_t TFT_MISO = 22;
static const uint8_t TFT_SCLK = 21;
static const uint8_t TFT_CS = 12;
static const uint8_t TFT_DC = 15;
static const uint8_t TFT_BK = 2;
static const uint8_t TFT_RST = -1;

static const uint8_t A0 = 36;
static const uint8_t A3 = 39;
static const uint8_t A4 = 32;
static const uint8_t A5 = 33;
static const uint8_t A6 = 34;
static const uint8_t A7 = 35;
static const uint8_t A10 = 4;
static const uint8_t A11 = 0;
static const uint8_t A12 = 2;
static const uint8_t A13 = 15;
static const uint8_t A14 = 13;
static const uint8_t A15 = 12;
static const uint8_t A16 = 14;
static const uint8_t A17 = 27;
static const uint8_t A18 = 25;
static const uint8_t A19 = 26;

static const uint8_t T0 = 4;
static const uint8_t T1 = 0;
static const uint8_t T2 = 2;
static const uint8_t T3 = 15;
static const uint8_t T4 = 13;
static const uint8_t T5 = 12;
static const uint8_t T6 = 14;
static const uint8_t T7 = 27;
static const uint8_t T8 = 33;
static const uint8_t T9 = 32;

static const uint8_t DAC1 = 25;
static const uint8_t DAC2 = 26;


// mic pins
static const uint8_t I2S_SCLK =	14;
static const uint8_t I2S_LCLK = 32;
static const uint8_t I2S_DOUT =	33;
// static const uint8_t I2S_DIN = No use


// camera pins
static const uint8_t CAM_Y9 = 36;
static const uint8_t CAM_Y8 = 37;
static const uint8_t CAM_Y7 = 38;
static const uint8_t CAM_Y6 = 39;
static const uint8_t CAM_Y5 = 35;
static const uint8_t CAM_Y4 = 26;
static const uint8_t CAM_Y3 = 13;
static const uint8_t CAM_Y2 = 34;
static const uint8_t CAM_VSNC = 5;
static const uint8_t CAM_HREF = 27;
static const uint8_t CAM_PCLK = 25;
static const uint8_t CAM_XCLK = 4;
static const uint8_t CAM_SIOD = 18;
static const uint8_t CAM_SIOC = 23;
// static const uint8_t CAM_PWD = No use
// static const uint8_t CAM_RESET = No use

#endif /* Pins_Arduino_h */
