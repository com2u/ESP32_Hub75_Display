#ifndef _ESP32_P3_RGB_64_32_MATRIX_PANEL
#define _ESP32_P3_RGB_64_32_MATRIX_PANEL


#include <vector>
#include <array>
#include "Adafruit_GFX.h"

class RGBMatrixPanel : public Adafruit_GFX {
  public:
 
   const static int panelwidth = 64;
   const static int panelHeight = 64;
   const static int screenWidth = 64;
   const static int screenHeight = 64;
   const static int scanDevider = 32;
   
   RGBMatrixPanel(uint8_t _pinR1, uint8_t _pinG1, uint8_t _pinB1, uint8_t _pinR2, uint8_t _pinG2, uint8_t _pinB2, uint8_t _pinCLK, uint8_t _pinLAT, uint8_t _pinOE, uint8_t _pinA, uint8_t _pinB, uint8_t _pinC, uint8_t _pinD,   bool _doubleBuffer = false)
      : Adafruit_GFX(panelwidth, panelHeight), pinR1(_pinR1), pinG1(_pinG1), pinB1(_pinB1), pinR2(_pinR2), pinG2(_pinG2), pinB2(_pinB2), pinCLK(_pinCLK), pinLAT(_pinLAT), pinOE(_pinOE), pinA(_pinA), pinB(_pinB), pinC(_pinC), pinD(_pinD),  doubleBuffer(_doubleBuffer) {
      initMatrixBuff();
    }
    RGBMatrixPanel(bool _doubleBuffer = false)
      : Adafruit_GFX(panelwidth, panelHeight), doubleBuffer(_doubleBuffer) {
      initMatrixBuff();
    }
    void begin(void);
    void stop(void);
    virtual void drawPixel(int16_t x, int16_t y, uint16_t color);
     virtual uint16_t getPixel(int16_t x, int16_t y);

    uint16_t color444(uint8_t b, uint8_t g, uint8_t r) { return ((r & 0xf) << 1) | ((uint16_t)(g & 0xf) << 6) | ((uint16_t)(b & 0xf) << 11); }
    uint16_t color555(uint8_t r, uint8_t g, uint8_t b) { return (r&0x1f) | ((uint16_t)(g & 0x1f) << 5) | ((uint16_t)(b & 0x1f) << 10); }
    uint16_t colorHSV(long hue, uint8_t sat, uint8_t val);

    void swapBuffer() {
      matrixbuff = drawBuffer();
    }

    uint16_t* matrixbuff;
    std::vector<std::array<uint16_t, panelwidth*panelHeight>> _matrixbuff;

    void copyBuffer() {
      if (!doubleBuffer) return;
      if (matrixbuff == _matrixbuff[0].data())
        _matrixbuff[0] = _matrixbuff[1];
      else
        _matrixbuff[1] = _matrixbuff[0];
    }

  private:
    void initMatrixBuff() {
      _matrixbuff.resize(doubleBuffer ? 2 : 1);
      matrixbuff = _matrixbuff[0].data();
    }
    static void IRAM_ATTR onTimer(void);
    void IRAM_ATTR draw();

    uint16_t* drawBuffer() {
      if (!doubleBuffer) return _matrixbuff[0].data();
      if (matrixbuff == _matrixbuff[0].data())
        return _matrixbuff[1].data();
      else
        return _matrixbuff[0].data();
    }

    hw_timer_t* timer;

 
    uint8_t pinR1 = 25;
    uint8_t pinG1 = 26;
    uint8_t pinB1 = 27;
    uint8_t pinR2 = 21;
    uint8_t pinG2 = 22;
    uint8_t pinB2 = 23;

    uint8_t pinCLK = 15;
    uint8_t pinLAT = 32;
    uint8_t pinOE = 33;

    uint8_t pinA = 12;
    uint8_t pinB = 16;
    uint8_t pinC = 17;
    uint8_t pinD = 18;
    uint8_t pinE = 19;
    
/* V8
    uint8_t pinR1 = 35;
    uint8_t pinG1 = 26;
    uint8_t pinB1 = 27;
    uint8_t pinR2 = 21;
    uint8_t pinG2 = 22;
    uint8_t pinB2 = 23;
    uint8_t pinCLK = 15;
    uint8_t pinLAT = 32;
    uint8_t pinOE = 33;
    uint8_t pinA = 13;
    uint8_t pinB = 16;
    uint8_t pinC = 17;
    uint8_t pinD = 18;
    uint8_t pinE = 0;
*/
    bool doubleBuffer;

    static volatile SemaphoreHandle_t timerSemaphore;
    static RGBMatrixPanel *singleton;
};

#endif

