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

#ifndef _SWITCH_H_
#define _SWITCH_H_

#include <Arduino.h>

#define SWITCH_1            0
#define SWITCH_2            1
#define SWITCH_3            2
#define SWITCH_4            3
#define SWITCH_5            4

#define SWITCH_PIN_1_1      PB9
#define SWITCH_PIN_1_2      PB8
#define SWITCH_PIN_2_1      PB15
#define SWITCH_PIN_2_2      PB14
#define SWITCH_PIN_3_1      PB13
#define SWITCH_PIN_3_2      PB12
#define SWITCH_PIN_4_1      PA0
#define SWITCH_PIN_4_2      PA1
#define SWITCH_PIN_5_1      PA4
#define SWITCH_PIN_5_2      PA5

void SWITCH_init(void);
uint8_t SWITCH_check(uint8_t sw);

#endif // _SWITCH_H_
