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


// Operating Constants
// -------------------------
#define ADT7410_CONV_TIME    240   // 240 ms conversion time (auto)
#define ADT7410_RANGE_HIGH   150   // Device temperature limits (in deg C)
#define ADT7410_RANGE_LOW    -55
#define ADT7410_RESET        0x2F  // Reset to POD
#define ADT7410_RESET_DELAY  220   // Reset time, in microseconds


// Device I2C Address Values
// -------------------------
// The device I2C address is determined by the A0 and A1 pins, which
// may be connected to GND (0) or VDD (1).
#define ADT7410_I2C0  0x48    // A1 = 0, A0 = 0
#define ADT7410_I2C1  0x49    // A1 = 0, A0 = 1
#define ADT7410_I2C2  0x4A    // A1 = 1, A0 = 0
#define ADT7410_I2C3  0x4B    // A1 = 1, A0 = 1


// ADT7410 Register Power-On Default Values
// ----------------------------------------
#define ADT7410_STATUS_POD  0x80    // 0b_1000_0000
#define ADT7410_CONFIG_POD  0x00    // 0b_0000_0000


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


// Status (Register 0x02)
// ---------------------------------------------------
// Status Register bits 4, 5, 6, ans 7 are used as flags.
#define ADT7410_STAT_TLOW       4     // T Low flag
#define ADT7410_STAT_THIGH      5     // T High flag
#define ADT7410_STAT_TCRIT      6     // T Crit flag
#define ADT7410_STAT_RDY        7     // Ready flag (active low)


// Configuration (Register 0x03)
// ---------------------------------------------------
// Use one configuration option from each of the six categories.
//     1. Resolution.
//     2. Operation mode.
//     3. Mode for the INT and CT pins.
//     4. Active polarity of the CT pin.
//     5. Active polarity of the INT pin.
//     6. Number of consecutive faults required to activate the
//        INT and CT pins.

// 1. Temperature Resolution
#define ADT7410_RESOLUTION_POD   0x00  // power-on default
#define ADT7410_RESOLUTION_13    0x00  // 13-bit resolution
#define ADT7410_RESOLUTION_16    0x80  // 16-bit resolution

// 2. Operation Mode
#define ADT7410_OPMODE_POD   0x00  // power-on default
#define ADT7410_OPMODE_NORM  0x00  // continuous conversion
#define ADT7410_OPMODE_1SHOT 0x20  // one-shot
#define ADT7410_OPMODE_1SPS  0x40  // 1 SPS
#define ADT7410_OPMODE_SD    0x60  // shutdown

// 3. Comparator or Interrupt Mode for the INT and CT Pins
#define ADT7410_FAULTMODE_POD         0x00  // power-on default
#define ADT7410_FAULTMODE_INTERRUPT   0x00
#define ADT7410_FAULTMODE_COMPARATOR  0x10

// 4. Active Polarity for the CT Pin
#define ADT7410_CT_ACTIVE_POD    0x00  //  power-on default
#define ADT7410_CT_ACTIVE_LOW    0x00  //  CT pin active low
#define ADT7410_CT_ACTIVE_HIGH   0x04  //  CT pin active high

// 5. Active Polarity for the INT Pin
#define ADT7410_INT_ACTIVE_POD   0x00  //  power-on default
#define ADT7410_INT_ACTIVE_LOW   0x00  // INT pin active low
#define ADT7410_INT_ACTIVE_HIGH  0x08  // INT pin active high

// 6. Fault Count - Determines the number of consecutive
//        under/over temperature readings allowed before
//        activating the INT and CT pins.
#define ADT7410_FAULTQUEUE_POD 0x00  // power-on default
#define ADT7410_FAULTQUEUE_1   0x00
#define ADT7410_FAULTQUEUE_2   0x01
#define ADT7410_FAULTQUEUE_3   0x02
#define ADT7410_FAULTQUEUE_4   0x03



#endif /* ADT7410_DEFS_HPP_ */
