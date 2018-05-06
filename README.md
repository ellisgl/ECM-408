ECM-408 (Electronic Control Module 40 buttons 8 pots)
=====================================================

Arduino based analog and digital controller for what ever you want to do, HID, MIDI, etc...

### Features
* 40 digital inputs (24 mm OBSC-24 arcade buttons)
* 8 analog inputs (6mm shaft 10K POTs)
* Doesn't use 4071's or 74595's

### Directories
KiCad Schematic: Schematic in KiCad...

ECM-408-UNO-MIDI:  This uses [FortySevenEffects MIDI library](https://github.com/FortySevenEffects/arduino_midi_library/) and outputs via serial. Will need a virtual MIDI converter like, ( http://projectgus.github.io/hairless-midiserial/) or (http://www.spikenzielabs.com/SpikenzieLabs/Serial_MIDI.html). The button mapping is based around the Launchpad MK2. Compatible with the ATmega328 based Arduinos.

### Parts
* Push buttons (x 40)
* 10K POTs (x 8)
* 1N4148 diodes (x 8)
* Wire
* Microcontroller board with at least 6 analog ports and 8 digital ports.

### TODO
* MIDI
  * Figure out what to map POTs to.
  * Create Mega version.
  * Create UNO-MIDI-USB version that uses the DFU mod.
  * Create Leonardo version.
  * Create Due version.
* Application controller
  * I'm up for suggestions here. 
   


