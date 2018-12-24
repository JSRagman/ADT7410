/*
 * adt7410.hpp
 *
 *  Created on: Sep 19, 2018
 *      Author: JSRagman
 *
 *  Description:
 *    Header for Analog Devices 16-Bit Digital I2C Temperature
 *    Sensor.
 *
 */

#ifndef ADT7410_HPP_
#define ADT7410_HPP_


#include <stdint.h>

#include "adt7410_defs.hpp"
#include "bbb-i2c.hpp"


namespace ad_adt7410
{

/*
 * OpMode Enumeration:
 *   Device operating mode is set by bits 5 and 6 of the device
 *   Configuration register.
 *
 *   The enumeration values below were obtained by setting configuration
 *   bits [6:5] in accordance with the operation modes listed in Table 11
 *   of the Analog Devices ADT7410 Data Sheet, Rev C.
 */
enum OpMode { normal=0x00, oneshot=0x20, sps=0x40, shutdown=0x60 };

class ADT7410
{
  protected:
	bbbi2c::I2CBus* i2cbus;
	uint8_t i2caddr;

	void  GetRegs  ( uint8_t regaddr, uint8_t* data, int len );
	void  SetRegs  ( uint8_t* data, int len );
	void  SetLimit ( uint8_t regaddr, double t_limit );

  public:
	 ADT7410 ( bbbi2c::I2CBus* bus, uint8_t addr );
	~ADT7410 ();

	uint8_t GetConfig   ();
	uint8_t GetDeviceID ();
	uint8_t GetStatus   ();
	int16_t GetTemperature ();

	void Reset ();
    void SetConfig ( uint8_t config );

    void SetHysteresis ( uint8_t hyst );
    void SetLimits ( double t_crit, double t_high, double t_low );
    void SetMode   ( OpMode mode    );
    void SetTCrit  ( double t_crit  );
    void SetTHigh  ( double t_high  );
    void SetTLow   ( double t_low   );

};

} // namespace ad_adt7410

#endif /* ADT7410_HPP_ */
