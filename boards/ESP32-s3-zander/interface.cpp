#include "core/powerSave.h"
#include <RotaryEncoder.h>
#include <interface.h>
// extern RotaryEncoder encoder;
extern RotaryEncoder *encoder;
IRAM_ATTR void checkPosition();
/***************************************************************************************
** Function name: _setup_gpio()
** Location: main.cpp
** Description:   initial setup for the device
***************************************************************************************/
void _setup_gpio() {
    pinMode(BK_BTN, INPUT_PULLDOWN); // Added internal pull-up resistor
    pinMode(ENCODER_KEY, INPUT_PULLUP);
    // use FOUR3 mode to count only at detent positions
    encoder = new RotaryEncoder(ENCODER_INA, ENCODER_INB, RotaryEncoder::LatchMode::FOUR3);

    // register interrupt routine
    attachInterrupt(digitalPinToInterrupt(ENCODER_INA), checkPosition, CHANGE);
    attachInterrupt(digitalPinToInterrupt(ENCODER_INB), checkPosition, CHANGE);
}

/***************************************************************************************
** Function name: getBattery()
** location: display.cpp
** Description:   Delivers the battery value from 1-100
***************************************************************************************/
int getBattery() { return 0; }

/***************************************************************************************
** Function name: isCharging()
** Description:   Default implementation that returns false
***************************************************************************************/
bool isCharging() { return false; }

void _post_setup_gpio() {
    // Brightness control must be initialized after tft in this case @Pirata
    pinMode(TFT_BL, OUTPUT);
}

/*********************************************************************
** Function: setBrightness
** location: settings.cpp
** set brightness value
** sets brightness by flashing the screen on and off very fast
**********************************************************************/
void _setBrightness(uint8_t brightval) {
    int dutyCycle;
    if (brightval == 100) dutyCycle = 255;
    else if (brightval == 75) dutyCycle = 130;
    else if (brightval == 50) dutyCycle = 70;
    else if (brightval == 25) dutyCycle = 20;
    else if (brightval == 0) dutyCycle = 0;
    else dutyCycle = ((brightval * 255) / 100);

    log_i("dutyCycle for bright 0-255: %d", dutyCycle);
    analogWrite(TFT_BL, dutyCycle);
}
// idfk why this exists
RotaryEncoder *encoder = nullptr;
IRAM_ATTR void checkPosition() {
    encoder->tick(); // just call tick() to check the state.
}

/*********************************************************************
** Function: InputHandler
** Handles the variables PrevPress, NextPress, SelPress, AnyKeyPress and EscPress
**********************************************************************/
void InputHandler(void) {
    static unsigned long tm = millis();  // debauce for buttons
    static unsigned long tm2 = millis(); // delay between Select and encoder (avoid missclick)
    static int _last_dir = 0;
    bool sel = !BTN_ACT;
    bool esc = !BTN_ACT;
    _last_dir = (int)encoder->getDirection();

    if (millis() - tm > 200 || LongPress) {
        sel = digitalRead(SEL_BTN);
        esc = digitalRead(BK_BTN);
    }
    if (_last_dir != 0 || sel == BTN_ACT || esc == BTN_ACT) {
        if (!wakeUpScreen()) AnyKeyPress = true;
        else return;
    }
    if (_last_dir > 0) {
        _last_dir = 0;
        PrevPress = true;
#ifdef HAS_ENCODER_LED
        EncoderLedChange = -1;
#endif
        tm2 = millis();
    }
    if (_last_dir < 0) {
        _last_dir = 0;
        NextPress = true;
#ifdef HAS_ENCODER_LED
        EncoderLedChange = 1;
#endif
        tm2 = millis();
    }

    if (sel == BTN_ACT && millis() - tm2 > 200) {
        _last_dir = 0;
        SelPress = true;
        tm = millis();
    }
    if (esc == BTN_ACT) {
        AnyKeyPress = true;
        EscPress = true;
        Serial.println("EscPressed");
        tm = millis();
    }
}

/*********************************************************************
** Function: powerOff
** location: mykeyboard.cpp
** Turns off the device (or try to)
**********************************************************************/
void powerOff() {}

/*********************************************************************
** Function: checkReboot
** location: mykeyboard.cpp
** Btn logic to turnoff the device (name is odd btw)
**********************************************************************/
void checkReboot() {}
