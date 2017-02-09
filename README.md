# Arduino library for SSD1306 based OLED display
for using only with Ascii characters

Note: This repository forked from: https://github.com/greiman/SSD1306Ascii
and refactored to able to store completly @ arduino libraries folder.

## Introduction
SSD1306Ascii is an unbuffered character only library for small OLED
displays like the Adafruit 1.3" and 0.96" Monochrome displays.
![SSD1306 oled displays](https://raw.githubusercontent.com/bbkbarbar/Arduino-SSD1306Ascii/master/ssd1306sample.jpg)
Many low cost OLED displays with SSD1306 controllers are available on [ebay](http://www.ebay.com/sch/i.html?_odkw=ssd1306+display+module&_sop=15&_osacat=0&_from=R40&_trksid=p2045573.m570.l1313.TR0.TRC0.H0.Xssd1306+display+i2c.TRS0&_nkw=ssd1306+display+i2c&_sacat=0).

SSD1306Ascii runs on Arduino AVR boards, Arduino Due and many other
Arduino style boards that have the SPI or Wire library.

## Advantages
The SSD1306Ascii library only requires a few bytes of RAM.

Here is memory use for the SPI "Hello world!" example with
scrolling disabled: <br>
Sketch <b>uses 2,622 bytes (8%) of program storage space</b>.
Maximum is 32,256 bytes. <br>
Global variables <b>use 53 bytes (2%) of </b>dynamic <b>memory</b>, leaving 1,995
bytes for local variables. Maximum is 2,048 bytes.

## Collaboration
This library is still in development so the API and features may
change. The library may have bugs. <br>
Feedback for future development is welcome.<br>
This is a total rewrite of an earlier version of this library.
The previous version is located here: <br>
https://code.google.com/p/beta-lib/downloads/list
