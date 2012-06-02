/*
  NesController.h - function to read nes controller button presses on your arduino
*/

#ifndef _NES_CONTROLLER_H
#define _NES_CONTROLLER_H


// NES Controller Pins for controller 1
#define CLOCK_1         14
#define LATCH_1         15
#define DATA_OUT_1      16

// NES Controller Pins for controller 2
#define CLOCK_2         17
#define LATCH_2         18
#define DATA_OUT_2      19

// NES Controller Buttons
#define NES_A           1
#define NES_B           2
#define NES_SELECT      4
#define NES_START       8
#define NES_UP          16
#define NES_DOWN        32
#define NES_LEFT        64
#define NES_RIGHT       128


/*============================================================================*/
/*  setup functions   */
void setupNesController(uint8_t clock, uint8_t latch, uint8_t data_out);
void setupNesController1();
void setupNesController2();

/*  button read functions   */
uint8_t readNesController(uint8_t clock, uint8_t latch, uint8_t data_out);
uint8_t readNesController1();
uint8_t readNesController2();

#endif /* _NES_CONTROLLER_H */

