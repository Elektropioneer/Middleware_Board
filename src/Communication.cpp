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

#include "Communication.h"

#include <Arduino.h>

#define _SERIAL_RPI Serial1
#define _SERIAL_ODOMETRY Serial2
#define _SERIAL_ACTUATOR Serial3

static uint8_t _bufferRpi[COM_BUFFER_SIZE_RPI];
static uint8_t _bufferOdometry[COM_BUFFER_SIZE_ODOMETRY];
static uint8_t _bufferActuator[COM_BUFFER_SIZE_ACTUATOR];

uint8_t _bufferRpiSize;
uint8_t _bufferOdometrySize;
uint8_t _bufferActuatorSize;

COM_callback _callbackRpi;
COM_callback _callbackOdometry;
COM_callback _callbackActuator;

void _COM_readRpi(void);

void COM_init(void)
{
    _bufferRpiSize = 0;
    _bufferOdometrySize = 0;
    _bufferActuatorSize = 0;
    _callbackRpi = NULL;
    _callbackOdometry = NULL;
    _callbackActuator = NULL;

    _SERIAL_RPI.begin(9600);
}

void COM_update(void)
{
    _COM_readRpi();
}

void COM_writeRpi(uint8_t *buffer, uint8_t size)
{
    for (uint8_t i = 0; i < size; i++)
    {
        _SERIAL_RPI.write(buffer[i]);
    }
}

void COM_writeOdometry(uint8_t *buffer, uint8_t size)
{
    for (uint8_t i = 0; i < size; i++)
    {
        _SERIAL_ODOMETRY.write(buffer[i]);
    }
}

void COM_writeActuator(uint8_t *buffer, uint8_t size)
{
    for (uint8_t i = 0; i < size; i++)
    {
        _SERIAL_ACTUATOR.write(buffer[i]);
    }
}

void COM_registerRpiCallback(COM_callback callback)
{
    _callbackRpi = callback;
}

void COM_registerOdometryCallback(COM_callback callback)
{
    _callbackOdometry = callback;
}

void COM_registerActuatorRpiCallback(COM_callback callback)
{
    _callbackActuator = callback;
}

void _COM_readRpi(void)
{
    if (!_SERIAL_RPI.available())
    {
        return;
    }

    _bufferRpi[_bufferRpiSize] = (uint8_t)_SERIAL_RPI.read();
    _bufferRpiSize++;

    if ((_bufferRpiSize == 1 && _bufferRpi[0] != COM_ESC) ||
        (_bufferRpiSize == 2 && _bufferRpi[1] != COM_STX) ||
        (_bufferRpiSize > 1 && _bufferRpi[0] != COM_ESC && _bufferRpi[1] != COM_STX) ||
        (_bufferRpiSize >= COM_BUFFER_SIZE_RPI))
    {
        _bufferRpiSize = 0;
        return;
    }

    if (_bufferRpiSize > 2 && _bufferRpi[_bufferRpiSize - 2] == COM_ESC && _bufferRpi[_bufferRpiSize - 1] == COM_STX) 
    {
        _bufferRpi[0] = COM_ESC;
        _bufferRpi[1] = COM_STX;
        _bufferRpiSize = 2;
    }

    if (_bufferRpiSize > 1)
    {
        if (_bufferRpi[_bufferRpiSize - 2] == COM_ESC && _bufferRpi[_bufferRpiSize - 1] == COM_ETX)
        {
            if (_callbackRpi)
            {
                _callbackRpi(_bufferRpi, _bufferRpiSize);
                _bufferRpiSize = 0;
            }
        }
    }
}
