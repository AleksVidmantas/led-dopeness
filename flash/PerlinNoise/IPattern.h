#ifndef IPATTERN_H
#define IPATTERN_H

#include <FastLED.h>

class IPattern {
public:
  /**
   * @brief Sets the list of colors
   * 
   * @param colors list of colors as pointer
   * @param ncolors number of colors
   */
  virtual void initialize(uint8_t * colors, uint8_t ncolors) = 0;

  /**
   * @brief Writes pattern to a set of LEDs
   * 
   * @param Leds LED array object
   * @param nleds Number of LEDs to write to
   * @param start Optional: LED index to start at (default = 0)
   */
  virtual void showPattern(CRGB * leds, short nleds, short start = 0) = 0;
};

#endif
