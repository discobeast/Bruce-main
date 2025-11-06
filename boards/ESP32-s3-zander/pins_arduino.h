#ifndef Pins_Arduino_h
#define Pins_Arduino_h

#include "soc/soc_caps.h"
#include <stdint.h>
// Generic shit
static const uint8_t TX = 43;
static const uint8_t RX = 44;

static const uint8_t A0 = 1;
static const uint8_t A1 = 2;
static const uint8_t A2 = 3;
static const uint8_t A3 = 4;
static const uint8_t A4 = 5;
static const uint8_t A5 = 6;
static const uint8_t A6 = 7;
static const uint8_t A7 = 8;
static const uint8_t A8 = 9;
static const uint8_t A9 = 10;
static const uint8_t A10 = 11;
static const uint8_t A11 = 12;
static const uint8_t A12 = 13;
static const uint8_t A13 = 14;
static const uint8_t A14 = 15;
static const uint8_t A15 = 16;
static const uint8_t A16 = 17;
static const uint8_t A17 = 18;
static const uint8_t A18 = 19;
static const uint8_t A19 = 20;

static const uint8_t T1 = 1;
static const uint8_t T2 = 2;
static const uint8_t T3 = 3;
static const uint8_t T4 = 4;
static const uint8_t T5 = 5;
static const uint8_t T6 = 6;
static const uint8_t T7 = 7;
static const uint8_t T8 = 8;
static const uint8_t T9 = 9;
static const uint8_t T10 = 10;
static const uint8_t T11 = 11;
static const uint8_t T12 = 12;
static const uint8_t T13 = 13;
static const uint8_t T14 = 14;

//-BUTTON/ENCODER-PINS-
#define ENCODER_INA 4
#define ENCODER_INB 5
#define ENCODER_KEY 6 // ENCODER BUTTON
#define BK_BTN 7      // BACK BUTTON
//---------------------

//-TFT-DISPLAY-PINS----
#define ROTATION 3 // Rotation of screen
#define TFT_WIDTH 128
#define TFT_HEIGHT 160
#define TFT_BL 14
#define TFT_MISO -1
#define TFT_MOSI 11
#define TFT_SCLK 12
#define TFT_CS 13
#define TFT_DC 9
#define TFT_RST 10
#define USE_HSPI_PORT         // Makes screen work somehow
#define TFT_BACKLIGHT_ON HIGH // Turns screen on at boot
#define TFT_RGB_ORDER TFT_RGB
#define ST7735_GREENTAB2
#define ST7735_DRIVER // makes screen use right driver
//---------------------

// GAY-LED-SETUP-------
#define RGB_LED 48
#define LED_TYPE WS2812B
#define LED_ORDER GRB
#define LED_TYPE_IS_RGBW 0
#define LED_COUNT 1
#define LED_COLOR_STEP 5
//----------------------

// MAIN-IC2-BUS---------
#define NRF24_CE_PIN 16
#define NRF24_SS_PIN 17
#define SPI_SCK_PIN 18
#define SPI_MOSI_PIN 8
#define SPI_MISO_PIN 46
#define SPI_SS_PIN 21
static const uint8_t SS = SPI_SS_PIN; // Makes the SS,MOSI,MISO and SCK pins same as the SPI library
static const uint8_t MOSI = SPI_MOSI_PIN;
static const uint8_t SCK = SPI_SCK_PIN;
static const uint8_t MISO = SPI_MISO_PIN;

//----------------------

// NRF24LO1--------------
#define NRF24_MOSI_PINS SPI_MOSI_PIN
#define NRF24_SCK_PIN SPI_SCK_PIN
#define NRF24_MISO_PINS SPI_MISO_PIN
//----------------------

// SD-CARD-SETUP--------
// needed for compile even if not used
#define SDCARD_CS -1
#define SDCARD_MISO -1
#define SDCARD_MOSI -1
#define SDCARD_SCK -1
//----------------------

//-GROVE_CONNECTIONS----
// needed for compile even if not used
#define GROVE_SDA 44
#define GROVE_SCL 43
static const uint8_t SDA = GROVE_SDA;
static const uint8_t SCL = GROVE_SCL;
//----------------------

//-MISC-----------------
#define SPI_FREQUENCY 40000000
#define SEL_BTN ENCODER_KEY // Just makes the select button the encoder key
#define BTN_ACT LOW
#define BTN_ALIAS "\"Mid\"" // Cosmetic name for the button (needed for compile)
#define SMOOTH_FONT 1
#endif /* Pins_Arduino_h */
