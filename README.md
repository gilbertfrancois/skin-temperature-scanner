# Skin Temperature Scanner

## Abstract

This project aims to estimate the human body temperature with a
thermal camera connected to a Raspberry Pi computer. Packaged with
a battery and small screen, you can create a portable, handheld
device to have a quick measure if someone has fever or not.

|animation   | device  |
|---|---|
|<img alt="preview" src="resources/doc/preview.gif" height=400 width=240> | <img alt="box" src="resources/doc/01.jpg" height=400 width=533>|

## Part list

For this prototype, the following hardware has been used:
- Raspberry Pi 2, 3 or 4
- MLX90640 Thermal Sensor, 32x24 px 
- Waveshare 4.3inch HDMI LCD (B), 800x480, IPS
- 5V 2.4A power adapter (2x)
- microSD card 8Gb or larger

## MLX90640 Far infrared Thermal Sensor

The [MLX90640](https://www.melexis.com/en/product/MLX90640/Far-Infrared-Thermal-Sensor-Array) is a thermal camera
made by Melexis N.V. It has a I2C interface, which is perfect for the Raspberry Pi and other embedded devices. You can 
find the C++ API, driver and documentation on their [Github](https://github.com/melexis/mlx90640-library) page.
The company Pimoroni has made a breakout board 
[breakout board](https://shop.pimoroni.com/products/mlx90640-thermal-camera-breakout?variant=12536948654163) around this
sensor, for easy integration with a Raspberry Pi.

## Research

| Setting                        | Value                 | Reference |
| ------------------------------ | --------------------- | --------- |
| Emisitivity of human skin      | 0.99                  | [1]       |
| Average human skin temperature | 32-34 degrees Celsius | [2]       |


## Setup the Raspberry Pi

The software is made and tested on Raspbian (Buster). Open `/boot/config.txt` and make the following changes:

```
## Display settings
max_usb_current=1
hdmi_group=2
hdmi_mode=87
hdmi_cvt 800 480 60 6 0 0 0 
# Rotate the screen to portrait mode
display_rotate=3

## Settings for the thermal sensor
dtparam=i2c_arm=on
dtparam=spi=on
# Add support for FPS > 16
dtparam=i2c1_baudrate=1000000
```

If you don't want to make these settings by hand, you can also copy the `resources/boot/config.txt` from this project:

```shell script
cp ./resources/boot/config.txt /boot/config.txt
```

## Dependencies

```shell script
sudo apt install \
  cmake \
  libavutil-dev \
  libavcodec-dev \
  libavformat-dev \
  libsdl2-dev \
  libsdl2-ttf-2.0-0 \
  libsdl2-ttf-dev
```

## Build

```shell script
git clone https://github.com/gilbertfrancois/skin-temperature-scanner.git
cd skin-temperature-scanner
mkdir build
cd build
cmake ..
make
./ThermalCamera
``` 

## References

[1] [Table of emissivity values in the Infrared](https://www.optotherm.com/emiss-table.htm)

[2] [Temperature of a Healthy Human (Skin Temperature)](https://hypertextbook.com/facts/2001/AbantyFarzana.shtml)

[3] [Raspberry Pi display](https://www.raspberrypi.org/documentation/hardware/display/)

[4] [Waveshare 4.3" display wiki](https://www.waveshare.com/wiki/4.3inch_HDMI_LCD_(B))
