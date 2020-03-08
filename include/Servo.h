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

#ifndef _SERVO_H_
#define _SERVO_H_

#define SERVO_1         PB1
#define SERVO_2         PB0
#define SERVO_3         PA7
#define SERVO_4         PA6

#define SERVO_PWM_MIN   2096
#define SERVO_PWM_MAX   8096

void SERVO_init(void);
uint8_t SERVO_getAngle(uint8_t servo);
void SERVO_setAngle(uint8_t servo, uint8_t angle);
void SERVO_off(uint8_t servo);

#endif // _SERVO_H_
