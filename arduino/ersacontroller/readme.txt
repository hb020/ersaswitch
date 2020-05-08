How to program the Attiny 214:

You need an Arduino Nano or the like, programmed as jtag2updi.

Use the Arduino IDE for dev and programming. 
It is not my preferred environment, but it was the easiest way to get started with the Attiny 214 through MegaTinyCore.

Inside Arduino IDE:

Board: ATtiny1614/...../214/...
Chip: 214
Port: /dev/cu.usbserial-10
Programmer: jtag2updi (MegaTinyCore)

Arduino IDE digitalRead/Write pin naming:
0 = PA4 (chip pin 2)
1 = PA5 (chip pin 3)
2 = PA6 (chip pin 4)
3 = PA7 (chip pin 5)
4 = PB3 (chip pin 6)
5 = PB2 (chip pin 7)
6 = PB1 (chip pin 8)
7 = PB0 (chip pin 9)
8 = PA1 (chip pin 11)
9 = PA2 (chip pin 12)
10 = PA3 (chip pin 13)


Investigate board:

> wget https://raw.githubusercontent.com/ElTangas/jtag2updi/master/avrdude.conf
> avrdude -c jtag2updi -P /dev/tty.usbserial-10 -p t214 -v -C avrdude.conf


avrdude: Version 6.3, compiled on Oct 11 2019 at 01:39:52
         Copyright (c) 2000-2005 Brian Dean, http://www.bdmicro.com/
         Copyright (c) 2007-2014 Joerg Wunsch

         System wide configuration file is "avrdude.conf"
         User configuration file is "/Users/hboot/.avrduderc"
         User configuration file does not exist or is not a regular file, skipping

         Using Port                    : /dev/tty.usbserial-10
         Using Programmer              : jtag2updi
JTAG ICE mkII sign-on message:
Communications protocol version: 1
M_MCU:
  boot-loader FW version:        1
  firmware version:              6.00
  hardware version:              1
S_MCU:
  boot-loader FW version:        1
  firmware version:              6.00
  hardware version:              1
Serial number:                   00:00:00:00:00:00
Device ID:                       JTAGICE mkII
         AVR Part                      : ATtiny214
         Chip Erase delay              : 0 us
         PAGEL                         : P00
         BS2                           : P00
         RESET disposition             : dedicated
         RETRY pulse                   : SCK
         serial program mode           : yes
         parallel program mode         : yes
         Timeout                       : 0
         StabDelay                     : 0
         CmdexeDelay                   : 0
         SyncLoops                     : 0
         ByteDelay                     : 0
         PollIndex                     : 0
         PollValue                     : 0x00
         Memory Detail                 :

                                  Block Poll               Page                       Polled
           Memory Type Mode Delay Size  Indx Paged  Size   Size #Pages MinW  MaxW   ReadBack
           ----------- ---- ----- ----- ---- ------ ------ ---- ------ ----- ----- ---------
           signature      0     0     0    0 no          3    0      0     0     0 0x00 0x00
           prodsig        0     0     0    0 no         61   61      0     0     0 0x00 0x00
           fuses          0     0     0    0 no          9    0      0     0     0 0x00 0x00
           fuse0          0     0     0    0 no          1    0      0     0     0 0x00 0x00
           fuse1          0     0     0    0 no          1    0      0     0     0 0x00 0x00
           fuse2          0     0     0    0 no          1    0      0     0     0 0x00 0x00
           fuse4          0     0     0    0 no          1    0      0     0     0 0x00 0x00
           fuse5          0     0     0    0 no          1    0      0     0     0 0x00 0x00
           fuse6          0     0     0    0 no          1    0      0     0     0 0x00 0x00
           fuse7          0     0     0    0 no          1    0      0     0     0 0x00 0x00
           fuse8          0     0     0    0 no          1    0      0     0     0 0x00 0x00
           lock           0     0     0    0 no          1    0      0     0     0 0x00 0x00
           data           0     0     0    0 no          0    0      0     0     0 0x00 0x00
           usersig        0     0     0    0 no         32   32      0     0     0 0x00 0x00
           flash          0     0     0    0 no       2048   64      0     0     0 0x00 0x00
           eeprom         0     0     0    0 no         64   32      0     0     0 0x00 0x00

         Programmer Type : JTAGMKII_PDI
         Description     : JTAGv2 to UPDI bridge
         M_MCU hardware version: 1
         M_MCU firmware version: 6.00
         S_MCU hardware version: 1
         S_MCU firmware version: 6.00
         Serial number:          00:00:00:00:00:00
         Vtarget         : 5.0 V

avrdude: AVR device initialized and ready to accept instructions

Reading | ################################################## | 100% 0.05s

avrdude: Device signature = 0x1e9120 (probably t214)

avrdude done.  Thank you.