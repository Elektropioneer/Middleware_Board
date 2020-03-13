/* 
 * This file is part of the Middleware Board distribution (https://github.com/Elektropioneer/Middleware_Board).
 * Copyright (c) 2020 Miloš Zivlak (milos.zivlak@sensa-group.net).
 * 
 * This program is free software: you can redistribute it and/or modify  
 * it under the terms of the GNU General Public License as published by  
 * the Free Software Foundation, version 3.
 *
 * This program is distributed in the hope that it will be useful, but 
 * WITHOUT ANY WARRANTY; without even the implied warranty of 
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU 
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License 
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#include <Arduino.h>

#include "Communication.h"

static void _rpiReceiveCallback(uint8_t *buffer, uint8_t size);

void setup()
{
  COM_init();
  pinMode(PC13, OUTPUT);

  COM_registerRpiCallback(_rpiReceiveCallback);

  //Serial1.begin(9600);
}

void loop()
{
  COM_update();
}

static void _rpiReceiveCallback(uint8_t *buffer, uint8_t size)
{
  if (buffer[2] == 'b' && buffer[3] == 'c')         // Switch
  {
  }
  else if (buffer[2] == 'm' && buffer[3] == 's')    // Servo
  {
  }
  else if (buffer[2] == 'o' && buffer[3] == 'd')    // Odometry
  {
  }
  else if (buffer[2] == 'a' && buffer[3] == 'c')    // Actuator
  {
  }
}
