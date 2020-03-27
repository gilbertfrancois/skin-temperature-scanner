# Skin Temperature Scanner

## Abstract

This project aims to estimate the human body temperature with a
thermal camera connected to a Raspberry Pi computer. Packaged with
a battery and small screen, you can create a portable, handheld
device to have a quick measure if someone has fever or not.

<img alt="preview" src="resources/images/preview.gif" height=400 width=240>

## Part list

For this prototype, the following hardware has been used:
- Raspberry Pi 2, 3 or 4
- MLX90640 Thermal Sensor, 32x24 px 
- Waveshare 4.3" TFT screen (optional)

## MLX90640 Far infrared Thermal Sensor

The [MLX90640](https://www.melexis.com/en/product/MLX90640/Far-Infrared-Thermal-Sensor-Array) is a thermal camera
made by Melexis N.V. It has a I2C interface, which is perfect for the Raspberry Pi and other embedded devices. You can 
find the C++ API, driver and documentation on their [Github](https://github.com/melexis/mlx90640-library) page.

## Waveshare 4.3" HDMI display

Open and modify the /boot/config.txt file, which located at root directory (BOOT) of SD card, append these lines to config.txt file
```shell script
max_usb_current=1
hdmi_group=2
hdmi_mode=87
hdmi_cvt 800 480 60 6 0 0 0 
# Rotate the screen to portrait mode
display_rotate=3
```
Note that for the setting `display_rotate=3`, the GL driver must be set to _Legacy_ in the `raspi-config` tool.

## Research

| Setting                        | Value                 | Reference |
| ------------------------------ | --------------------- | --------- |
| Emisitivity of human skin      | 0.99                  | [1]       |
| Average human skin temperature | 32-34 degrees Celsius | [2]       |

## Dependencies

```shell script
sudo apt install libavutil-dev libavcodec-dev libavformat-dev libsdl2-dev libsdl2-ttf-2.0-0 libsdl2-ttf-dev
```

## Build

```shell script
git clone <thermalcam>
cd skin-temperature-scanner
./bin/install_dependencies.sh
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
