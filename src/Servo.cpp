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

#include "Servo.h"

#include <Arduino.h>
#include <HardwareTimer.h>

HardwareTimer servo(3);

void SERVO_init(void)
{
    pinMode(SERVO_1, PWM);
    pinMode(SERVO_2, PWM);
    pinMode(SERVO_3, PWM);
    pinMode(SERVO_4, PWM);

    // Frequency for servo motors
    servo.setPrescaleFactor(21);
}

uint8_t SERVO_getAngle(uint8_t servo)
{
    uint8_t value = 0;
    return value;
}

void SERVO_setAngle(uint8_t servo, uint8_t angle)
{
    uint8_t value = map(angle, 0, 180, SERVO_PWM_MIN, SERVO_PWM_MAX);
    pwmWrite(servo, value);
}

void SERVO_off(uint8_t servo)
{
    pinMode(servo, INPUT);
}
