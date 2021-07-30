/*
   This file is part of ArduinoIoTCloud.

   Copyright 2020 ARDUINO SA (http://www.arduino.cc/)

   This software is released under the GNU General Public License version 3,
   which covers the main part of arduino-cli.
   The terms of this license can be found at:
   https://www.gnu.org/licenses/gpl-3.0.en.html

   You can be released from the requirements of the above licenses by purchasing
   a commercial license. Buying such a license is mandatory if you want to modify or
   otherwise use the software for commercial activities involving the Arduino
   software without disclosing the source code of your own applications. To purchase
   a commercial license, send an email to license@arduino.cc.
*/

#ifndef ARDUINO_IOT_CLOUD_TIME_SERVICE_H_
#define ARDUINO_IOT_CLOUD_TIME_SERVICE_H_

/**************************************************************************************
 * INCLUDE
 **************************************************************************************/

#include <Arduino_ConnectionHandler.h>

#ifdef ARDUINO_ARCH_SAMD
  #include <RTCZero.h>
#endif

#ifdef ARDUINO_ARCH_MBED
  #include <mbed_rtc_time.h>
#endif

/**************************************************************************************
 * CLASS DECLARATION
 **************************************************************************************/

class TimeService
{

public:

  TimeService();


  void          begin  (ConnectionHandler * con_hdl);
  unsigned long getTime();

private:

  ConnectionHandler * _con_hdl;
#if defined (ARDUINO_ARCH_SAMD) || defined (ARDUINO_ARCH_MBED)
  bool _is_rtc_configured;
#endif

  unsigned long getRemoteTime();
  static bool isTimeValid(unsigned long const time);

};

#endif /* ARDUINO_IOT_CLOUD_TIME_SERVICE_H_ */
