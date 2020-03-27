//
// Created by G.F. Duivesteijn on 23.03.20.
//

#ifndef THERMALCAM_CONSTANTS_H
#define THERMALCAM_CONSTANTS_H


#define MLX_I2C_ADDR 0x33
#define SENSOR_W 24
#define SENSOR_H 32
// Valid frame rates are 1, 2, 4, 8, 16, 32 and 64
#define FPS 16
// The i2c baudrate is set to 1mhz to support these
#define FRAME_TIME_MICROS (1000000/FPS)
// Despite the framerate being ostensibly FPS hz
// The frame is often not ready in time
// This offset is added to the FRAME_TIME_MICROS
// to account for this.
#define OFFSET_MICROS 850

#endif //THERMALCAM_CONSTANTS_H
