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

#ifndef _COM_H_
#define _COM_H_

#include <Arduino.h>

#define COM_BUFFER_SIZE_RPI             50
#define COM_BUFFER_SIZE_ODOMETRY        20
#define COM_BUFFER_SIZE_ACTUATOR        20

#define COM_ESC                         0x1B
#define COM_STX                         0x02
#define COM_ETX                         0x03

typedef void (*COM_callback)(uint8_t *buffer, uint8_t size);

void COM_init(void);
void COM_update(void);
void COM_writeRpi(uint8_t *buffer, uint8_t size);
void COM_writeOdometry(uint8_t *buffer, uint8_t size);
void COM_writeActuator(uint8_t *buffer, uint8_t size);
void COM_registerRpiCallback(COM_callback callback);
void COM_registerOdometryCallback(COM_callback callback);
void COM_registerActuatorRpiCallback(COM_callback callback);

#endif // _COM_H_
