# ESP32_Hub75_Display
An ESP32 Arduino Project to control LED Matrix Display (e.g. 64x32, 64x64) via HUB75 connector

/*
   LED Matrix 64x64 wire setup
   Connector Input
   +---------+      Panel - ESP32 pins
   |  R1 G1  |      R1   - IO25      G1   - IO26
   |  B1 GND |      B1   - IO27
   |  R2 G2  |      R2   - IO21      G2   - IO22
   |  B2 GND |      B2   - IO23
   |   A B   |      A    - IO12      B    - IO16
   |   C D   |      C    - IO17      D    - IO18
   | CLK LAT |      CLK  - IO15      LAT  - IO32
   |  OE GND |      OE   - IO33
   +---------+
*/

/*
   LED Matrix 64x64 wire setup V8
   Connector Input
   +---------+      Panel - ESP32 pins
   |  R1 G1  |      R1   - IO35      G1   - IO26
   |  B1 GND |      B1   - IO27
   |  R2 G2  |      R2   - IO21      G2   - IO22
   |  B2 GND |      B2   - IO23      E    - IO19
   |   A B   |      A    - IO12      B    - IO16
   |   C D   |      C    - IO17      D    - IO18
   | CLK LAT |      CLK  - IO15      LAT  - IO32
   |  OE GND |      OE   - IO33
   +---------+
*/
