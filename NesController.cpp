/*
  NesController.c - library to read an NES Controllers.
  Copyright (c) Chad Grant 2012

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/

#if ARDUINO >= 100
#include <Arduino.h> 
#else
#include <WProgram.h> 
#endif

#include "NesController.h"

/*  setup functions   */
void setupNesController(uint8_t clock, uint8_t latch, uint8_t data_out);
void setupNesController1();
void setupNesController2();

void setupNesController(uint8_t clock, uint8_t latch, uint8_t data_out)
{
    pinMode(clock, OUTPUT);
    pinMode(latch, OUTPUT);
    pinMode(data_out, INPUT);

    digitalWrite(clock, HIGH);
    digitalWrite(latch, LOW);
}

void setupNesController1()
{
    setupNesController(CLOCK_1, LATCH_1, DATA_OUT_1);
}

void setupNesController2()
{
    setupNesController(CLOCK_2, LATCH_2, DATA_OUT_2);
}

/*  button read functions   */
uint8_t readNesController(uint8_t clock, uint8_t latch, uint8_t data_out)
{
    uint8_t nes = 0;

    digitalWrite(latch, HIGH);
    digitalWrite(latch, LOW);

    for (int i = 0; i < 8; i++)
    {
        digitalWrite(clock, LOW);
        nes += ((~digitalRead(data_out) & 1) << i);
        digitalWrite(clock, HIGH);
    }

    return nes;
}

uint8_t readNesController1()
{
    return readNesController(CLOCK_1, LATCH_1, DATA_OUT_1);
}

uint8_t readNesController2()
{
    return readNesController(CLOCK_2, LATCH_2, DATA_OUT_2);
}
