# TTGO T-Camera-Plus Boilerplate

This is a boilerplate with minimal examples to get the hardware of the TTGO T-Camera board to work.

# Getting Started

First, install the `ttgo-t-camera` board into platformio:

    cp pins_arduino.h ~/.platformio/packages/framework-arduinoespressif32/variants/ttgo-t-camera/pins_arduino.h
    cp ttgo-t-camera.json ~/.platformio/platforms/espressif32/boards/ttgo-t-camera.json

Then, install dependencies:

    pio lib install
