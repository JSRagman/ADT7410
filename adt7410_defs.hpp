/*
 * adt7410_defs.hpp
 *
 *  Created on: Sep 19, 2018
 *      Author: JSRagman
 *
 *  Description:
 *    Definitions for use with the ADT7410 16-bit digital
 *    I2C temperature sensor.
 *
 *    These definitions are derived from the Analog Devices
 *    ADT7410 Data Sheet, Rev C.
 */

#ifndef ADT7410_DEFS_HPP_
#define ADT7410_DEFS_HPP_


// Device I2C Address Values
// -------------------------
#define ADT7410_I2C0  0x48
#define ADT7410_I2C1  0x49
#define ADT7410_I2C2  0x4A
#define ADT7410_I2C3  0x4B



#define ADT7410_CONV_TIME   240 // 240 ms conversion time (auto)

#define ADT7410_LOW_LIMIT   -55 // Device temperature limits (in deg C)
#define ADT7410_HIGH_LIMIT  150


// ADT7410 Register Addresses
// --------------------------

#define ADT7410_R_TEMP       0x00
#define ADT7410_R_STATUS     0x02
#define ADT7410_R_CONFIG     0x03
#define ADT7410_R_THIGH      0x04
#define ADT7410_R_TLOW       0x06
#define ADT7410_R_TCRIT      0x08
#define ADT7410_R_THYST      0x0A
#define ADT7410_R_ID         0x0B


#define ADT7410_RESET        0x2F  // Reset to POD
#define ADT7410_RESET_DELAY  220   // Reset time, in microseconds



// Status (Register 0x02)
// ---------------------------------------------------
// Status Register bits 4, 5, 6, ans 7 are used as flags.
#define ADT7410_STAT_TLOW       4     // T Low flag
#define ADT7410_STAT_THIGH      5     // T High flag
#define ADT7410_STAT_TCRIT      6     // T Crit flag
#define ADT7410_STAT_RDY        7     // Ready flag (active low)



// Configuration (Register 0x03)
// ---------------------------------------------------

// Fault Count - Determines the number of consecutive under/over
//               temperature readings allowed before setting the
//               INT and CT pins.
#define ADT7410_FAULT_1   0x00
#define ADT7410_FAULT_2   0x01
#define ADT7410_FAULT_3   0x02
#define ADT7410_FAULT_4   0x03

// CT and INT Pin Polarity
#define ADT7410_CT_LOW    0x00  //  CT pin active low
#define ADT7410_CT_HIGH   0x04  //  CT pin active high
#define ADT7410_INT_LOW   0x00  // INT pin active low
#define ADT7410_INT_HIGH  0x08  // INT pin active high

// Select Comparator Mode or Interrupt Mode
#define ADT7410_INTERRUPT   0x00  // interrupt mode
#define ADT7410_COMPARATOR  0x10  // comparator mode

// Operation Mode
#define ADT7410_MODE_NORM 0x00  // continuous conversion
#define ADT7410_MODE_ONCE 0x20  // one-shot mode
#define ADT7410_MODE_SPS  0x40  // SPS mode
#define ADT7410_MODE_SD   0x60  // shutdown

// Temperature Resolution
#define ADT7410_RES_13    0x00  // 13-bit resolution
#define ADT7410_RES_16    0x80  // 16-bit resolution




#endif /* ADT7410_DEFS_HPP_ */
