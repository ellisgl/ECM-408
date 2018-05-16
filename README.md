ECM-408 (Electronic Control Module 40 buttons 8 pots)
=====================================================

Arduino based analog and digital controller for what ever you want to do, HID, MIDI, etc...

### Features
* 40 digital inputs (24 mm OBSC-24 arcade buttons)
* 8 analog inputs (6mm shaft 10K POTs)


### Parts
* Push buttons (x 40)
* 10K POTs (x 8)
* Wire
* Microcontroller board with at least 1 analog port and 5 digital ports.
* 8x8 74xx4051 mux (x 1 if using a small board) (https://github.com/ellisgl/analog-multiplexer-8x8)

### Directories
base_sb_mux: Base code that works with the smaller Arduino boards (Uno and such). Uses an 8x8 multiplexer.
base_lb: Base code that works with the larger Arduino boards (Mega and such). No mux needed.
midi_serial_sb_mux: Serial MIDI controller version of base_sb_mux.
midi_serial_lb: Serial MIDI controller version of base_lb.

### TODO
* Schematics for the two main types.
* Update diagrams for default button map.
* Add a Row / Column mapping image.
* Create HID versions.
* Create a hardware debounced versions - will involve a seperate CPLD project done in Verilog.
* Maybe move the mapping into their own file?