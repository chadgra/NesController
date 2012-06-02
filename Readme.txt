Readme file for Arduino NesController Library

NesController is a library that provides button reading from an NES Controller functionality for Arduino.

NES controller pinout:
     o 4
1 o  o 5
2 o  o 6
3 o  o 7

1: +5VDC
2: Unused
3: Unused
4: GND
5: Clock
6: Latch
7: Data out

It is intended that the first NES controller would be connected to A0, A1, & A2.  Specifically:
A0 - Clock (5)
A1 - Latch (6)
A2 - Data out (7)

A second NES controller could be connected to A3, A4, & A5:
A3 - Clock (5)
A4 - Latch (6)
A5 - Data out (7)

If different pins are required then the #defines can be modified in NesController.h, or the functions that allow the pin numbers for the Clock, Latch, and Data out can be used.