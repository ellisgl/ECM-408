// EMC-408 for smaller boards (Uno and the like)
// Uses an 8x8 analog mux made from 4051's
// https://github.com/ellisgl/analog-multiplexer-8x8
// This version is a MIDI Contoller that sends via serial.
// Use a serial MIDI converter program:
// http://projectgus.github.io/hairless-midiserial/
// And a virtual MIDI device:
// http://www.tobias-erichsen.de/software/loopmidi.html

// Include debounce library.
#include <Bounce2.h>

// Include the MIDI library.
#include <MIDI.h>

// Instantiate the Bounce objects.
Bounce b0 = Bounce();
Bounce b1 = Bounce();
Bounce b2 = Bounce();
Bounce b3 = Bounce();
Bounce b4 = Bounce();

// Instantiate the MIDI object.
MIDI_CREATE_DEFAULT_INSTANCE(); 

// Column counter.
uint8_t c   = 0; 

// Button Mapping
const uint8_t bMap[40] = {
    12, 13, 14, 15, 16, 17, 18, 19, 
    20, 21, 22, 23, 24, 25, 26, 27, 
    28, 28, 30, 31, 32, 33, 34, 35, 
    36, 37, 38, 39, 40, 41, 42, 43,
    44, 45, 46, 47, 48, 49, 50, 51
};

// Potentiometer control change (CC) mapping:
// http://nickfever.com/music/midi-cc-list
const uint8_t pMap[8] ={
    102, 103, 104, 105, 106, 107, 108, 109
};

// Previous button states.
bool pB[40] = {
  0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 
  0, 0, 0, 0, 0, 0, 0, 0
}; 

//Previous POT states
int pP[8]   = {0, 0, 0, 0, 0, 0, 0, 0};

// Current states
bool cB[5]  = {0, 0, 0, 0, 0};
int cP      = 0;

void setup()
{
    // Using pull mode for less chance of noise issues.
    pinMode(2, INPUT_PULLUP);
    pinMode(3, INPUT_PULLUP);
    pinMode(4, INPUT_PULLUP);
    pinMode(5, INPUT_PULLUP);
    pinMode(6, INPUT_PULLUP);

    // Address select
    pinMode(11, OUTPUT); // A
    pinMode(12, OUTPUT); // B
    pinMode(13, OUTPUT); // C

    // Attach buttons to the Bounce instance
    b0.attach(2);
    b1.attach(3);
    b2.attach(4);
    b3.attach(5);
    b4.attach(6);

    // Set the debounce interval to 3 ms
    b0.interval(3);
    b1.interval(3);
    b2.interval(3);
    b3.interval(3);
    b4.interval(3);
    
    // Start the serial port at the MIDI baudrate (31250) and listen to all incoming messages.
    MIDI.begin(MIDI_CHANNEL_OMNI);

    // Change baud rate to 115200 - Hairless doesn't do 31250.
    Serial.begin(115200);
}

void loop()
{
    // Enable a column
    switch(c)
    {
        case 0:
            digitalWrite(11, LOW);
            digitalWrite(12, LOW);
            digitalWrite(13, LOW);
        break;

        case 1:
            digitalWrite(11, HIGH);
            digitalWrite(12, LOW);
            digitalWrite(13, LOW);
        break;
 
        case 2:
            digitalWrite(11, LOW);
            digitalWrite(12, HIGH);
            digitalWrite(13, LOW);
        break;

        case 3:
            digitalWrite(11, HIGH);
            digitalWrite(12, HIGH);
            digitalWrite(13, LOW);
        break;

        case 4:
            digitalWrite(11, LOW);
            digitalWrite(12, LOW);
            digitalWrite(13, HIGH);
        break;

        case 5:
            digitalWrite(11, HIGH);
            digitalWrite(12, LOW);
            digitalWrite(13, HIGH);
        break;

        case 6:
            digitalWrite(11, LOW);
            digitalWrite(12, HIGH);
            digitalWrite(13, HIGH);
        break;

        case 7:
            digitalWrite(11, HIGH);
            digitalWrite(12, HIGH);
            digitalWrite(13, HIGH);
        break;
    }


    // Update value from bounce library.
    b0.update();
    b1.update();
    b2.update();
    b3.update();
    b4.update();

    // Read the value into current values.
    cB[0] = b0.read();
    cB[1] = b1.read();
    cB[2] = b2.read();
    cB[3] = b3.read();
    cB[4] = b4.read();
    
    // Read and scale analog value from 0-1023 to 0-127.
    cP    = map(analogRead(A5), 0, 1023, 0, 127);

    // Compare and do MIDI stuff.
    switch(c)
    {
        case 0:
            if(cB[0] != pB[0])
            {
                if(cB[0] == LOW)
                {
                    MIDI.sendNoteOn(bMap[0], 127, 1);
                }
                else
                {
                    MIDI.sendNoteOff(bMap[0], 0, 1);
                }

                pB[0] = cB[0];
            }

            if(cB[1] != pB[8])
            {
                if(cB[1] == LOW)
                {
                    MIDI.sendNoteOn(bMap[8], 127, 1);
                }
                else
                {
                    MIDI.sendNoteOff(bMap[8], 0, 1);
                }

                pB[8] = cB[1];
            }

            if(cB[2] != pB[16])
            {
                if(cB[2] == LOW)
                {
                    MIDI.sendNoteOn(bMap[16], 127, 1);
                }
                else
                {
                    MIDI.sendNoteOff(bMap[16], 0, 1);
                }

                pB[16] = cB[2];
            }

            if(cB[3] != pB[24])
            {
                if(cB[3] == LOW)
                {
                    MIDI.sendNoteOn(bMap[24], 127, 1);
                }
                else
                {
                    MIDI.sendNoteOff(bMap[24], 0, 1);
                }

                pB[24] = cB[3];
            }

            if(cB[4] != pB[32])
            {
                if(cB[4] == LOW)
                {
                    MIDI.sendNoteOn(bMap[32], 127, 1);
                }
                else
                {
                    MIDI.sendNoteOff(bMap[32], 0, 1);
                }

                pB[32] = cB[4];
            }

            if(cP != pP[0])
            {
                MIDI.sendControlChange(pMap[0], cP, 1);

                pP[0] = cP;
            }
        break;

        case 1:
            if(cB[0] != pB[1])
            {
                if(cB[0] == LOW)
                {
                    MIDI.sendNoteOn(bMap[1], 127, 1);
                }
                else
                {
                    MIDI.sendNoteOff(bMap[1], 0, 1);
                }

                pB[1] = cB[0];
            }

            if(cB[1] != pB[9])
            {
                if(cB[1] == LOW)
                {
                    MIDI.sendNoteOn(bMap[9], 127, 1);
                }
                else
                {
                    MIDI.sendNoteOff(bMap[9], 0, 1);
                }

                pB[9] = cB[1];
            }

            if(cB[2] != pB[17])
            {
                if(cB[2] == LOW)
                {
                    MIDI.sendNoteOn(bMap[17], 127, 1);
                }
                else
                {
                    MIDI.sendNoteOff(bMap[17], 0, 1);
                }

                pB[17] = cB[2];
            }

            if(cB[3] != pB[25])
            {
                if(cB[3] == LOW)
                {
                    MIDI.sendNoteOn(bMap[25], 127, 1);
                }
                else
                {
                    MIDI.sendNoteOff(bMap[25], 0, 1);
                }

                pB[25] = cB[3];
            }

            if(cB[4] != pB[33])
            {
                if(cB[4] == LOW)
                {
                    MIDI.sendNoteOn(bMap[33], 127, 1);
                }
                else
                {
                    MIDI.sendNoteOff(bMap[33], 0, 1);
                }

                pB[33] = cB[4];
            }

            if(cP != pP[1])
            {
                MIDI.sendControlChange(pMap[1], cP, 1);

                pP[1] = cP;
            }
        break;

        case 2:
            if(cB[0] != pB[2])
            {
                if(cB[0] == LOW)
                {
                    MIDI.sendNoteOn(bMap[2], 127, 1);
                }
                else
                {
                    MIDI.sendNoteOff(bMap[2], 0, 1);
                }

                pB[2] = cB[0];
            }

            if(cB[1] != pB[10])
            {
                if(cB[1] == LOW)
                {
                    MIDI.sendNoteOn(bMap[10], 127, 1);
                }
                else
                {
                    MIDI.sendNoteOff(bMap[10], 0, 1);
                }

                pB[10] = cB[1];
            }

            if(cB[2] != pB[18])
            {
                if(cB[2] == LOW)
                {
                    MIDI.sendNoteOn(bMap[18], 127, 1);
                }
                else
                {
                    MIDI.sendNoteOff(bMap[18], 0, 1);
                }

                pB[18] = cB[2];
            }

            if(cB[3] != pB[26])
            {
                if(cB[3] == LOW)
                {
                    MIDI.sendNoteOn(bMap[26], 127, 1);
                }
                else
                {
                    MIDI.sendNoteOff(bMap26[], 0, 1);
                }

                pB[26] = cB[3];
            }

            if(cB[4] != pB[34])
            {
                if(cB[4] == LOW)
                {
                    MIDI.sendNoteOn(bMap[34], 127, 1);
                }
                else
                {
                    MIDI.sendNoteOff(bMap[34], 0, 1);
                }

                pB[34] = cB[4];
            }

            if(cP != pP[2])
            {
                MIDI.sendControlChange(pMap[2], cP, 1);

                pP[2] = cP;
            }
        break;

        case 3:
            if(cB[0] != pB[3])
            {
                if(cB[0] == LOW)
                {
                    MIDI.sendNoteOn(bMap[3], 127, 1);
                }
                else
                {
                    MIDI.sendNoteOff(bMap[3], 0, 1);
                }

                pB[3] = cB[0];
            }

            if(cB[1] != pB[11])
            {
                if(cB[1] == LOW)
                {
                    MIDI.sendNoteOn(bMap[11], 127, 1);
                }
                else
                {
                    MIDI.sendNoteOff(bMap[11], 0, 1);
                }

                pB[11] = cB[1];
            }

            if(cB[2] != pB[19])
            {
                if(cB[2] == LOW)
                {
                    MIDI.sendNoteOn(bMap[19], 127, 1);
                }
                else
                {
                    MIDI.sendNoteOff(bMap[19], 0, 1);
                }

                pB[19] = cB[2];
            }

            if(cB[3] != pB[27])
            {
                if(cB[3] == LOW)
                {
                    MIDI.sendNoteOn(bMap[27], 127, 1);
                }
                else
                {
                    MIDI.sendNoteOff(bMap[27], 0, 1);
                }

                pB[27] = cB[3];
            }

            if(cB[4] != pB[35])
            {
                if(cB[4] == LOW)
                {
                    MIDI.sendNoteOn(bMap[35], 127, 1);
                }
                else
                {
                    MIDI.sendNoteOff(bMap[35], 0, 1);
                }

                pB[35] = cB[4];
            }

            if(cP != pP[3])
            {
                MIDI.sendControlChange(pMap[3], cP, 1);

                pP[3] = cP;
            }
        break;

        case 4:
            if(cB[0] != pB[4])
            {
                if(cB[0] == LOW)
                {
                    MIDI.sendNoteOn(bMap[4], 127, 1);
                }
                else
                {
                    MIDI.sendNoteOff(bMap[4], 0, 1);
                }

                pB[4] = cB[0];
            }

            if(cB[1] != pB[12])
            {
                if(cB[1] == LOW)
                {
                    MIDI.sendNoteOn(bMap[12], 127, 1);
                }
                else
                {
                    MIDI.sendNoteOff(bMap[12], 0, 1);
                }

                pB[12] = cB[1];
            }

            if(cB[2] != pB[20])
            {
                if(cB[2] == LOW)
                {
                    MIDI.sendNoteOn(bMap[20], 127, 1);
                }
                else
                {
                    MIDI.sendNoteOff(bMap[20], 0, 1);
                }

                pB[20] = cB[2];
            }

            if(cB[3] != pB[28])
            {
                if(cB[3] == LOW)
                {
                    MIDI.sendNoteOn(bMap[28], 127, 1);
                }
                else
                {
                    MIDI.sendNoteOff(bMap[28], 0, 1);
                }

                pB[28] = cB[3];
            }

            if(cB[4] != pB[36])
            {
                if(cB[4] == LOW)
                {
                    MIDI.sendNoteOn(bMap[36], 127, 1);
                }
                else
                {
                    MIDI.sendNoteOff(bMap[36], 0, 1);
                }

                pB[36] = cB[4];
            }

            if(cP != pP[4])
            {
                MIDI.sendControlChange(pMap[4], cP, 1);

                pP[4] = cP;
            }
        break;

        case 5:
            if(cB[0] != pB[5])
            {
                if(cB[0] == LOW)
                {
                    MIDI.sendNoteOn(bMap[5], 127, 1);
                }
                else
                {
                    MIDI.sendNoteOff(bMap[5], 0, 1);
                }

                pB[5] = cB[0];
            }

            if(cB[1] != pB[13])
            {
                if(cB[1] == LOW)
                {
                    MIDI.sendNoteOn(bMap[13], 127, 1);
                }
                else
                {
                    MIDI.sendNoteOff(bMap[13], 0, 1);
                }

                pB[13] = cB[1];
            }

            if(cB[2] != pB[21])
            {
                if(cB[2] == LOW)
                {
                    MIDI.sendNoteOn(bMap[21], 127, 1);
                }
                else
                {
                    MIDI.sendNoteOff(bMap[21], 0, 1);
                }

                pB[21] = cB[2];
            }

            if(cB[3] != pB[29])
            {
                if(cB[3] == LOW)
                {
                    MIDI.sendNoteOn(bMap[29], 127, 1);
                }
                else
                {
                    MIDI.sendNoteOff(bMap[29], 0, 1);
                }

                pB[29] = cB[3];
            }

            if(cB[4] != pB[37])
            {
                if(cB[4] == LOW)
                {
                    MIDI.sendNoteOn(bMap[37], 127, 1);
                }
                else
                {
                    MIDI.sendNoteOff(bMap[37], 0, 1);
                }

                pB[37] = cB[4];
            }

            if(cP != pP[5])
            {
                MIDI.sendControlChange(pMap[5], cP, 1);

                pP[5] = cP;
            }
        break;

        case 6:
            if(cB[0] != pB[6])
            {
                if(cB[0] == LOW)
                {
                    MIDI.sendNoteOn(bMap[6], 127, 1);
                }
                else
                {
                    MIDI.sendNoteOff(bMap[6], 0, 1);
                }

                pB[6] = cB[0];
            }

            if(cB[1] != pB[14])
            {
                if(cB[1] == LOW)
                {
                    MIDI.sendNoteOn(bMap[14], 127, 1);
                }
                else
                {
                    MIDI.sendNoteOff(bMap[14], 0, 1);
                }

                pB[14] = cB[1];
            }

            if(cB[2] != pB[22])
            {
                if(cB[2] == LOW)
                {
                    MIDI.sendNoteOn(bMap[22], 127, 1);
                }
                else
                {
                    MIDI.sendNoteOff(bMap[22], 0, 1);
                }

                pB[22] = cB[2];
            }

            if(cB[3] != pB[30])
            {
                if(cB[3] == LOW)
                {
                    MIDI.sendNoteOn(bMap[30], 127, 1);
                }
                else
                {
                    MIDI.sendNoteOff(bMap[30], 0, 1);
                }

                pB[30] = cB[3];
            }

            if(cB[4] != pB[38])
            {
                if(cB[4] == LOW)
                {
                    MIDI.sendNoteOn(bMap[38], 127, 1);
                }
                else
                {
                    MIDI.sendNoteOff(bMap[38], 0, 1);
                }

                pB[38] = cB[4];
            }

            if(cP != pP[6])
            {
                MIDI.sendControlChange(pMap[6], cP, 1);

                pP[6] = cP;
            }
        break;

        case 7:
            if(cB[0] != pB[7])
            {
                if(cB[0] == LOW)
                {
                    MIDI.sendNoteOn(bMap[7], 127, 1);
                }
                else
                {
                    MIDI.sendNoteOff(bMap[7], 0, 1);
                }

                pB[7] = cB[0];
            }

            if(cB[1] != pB[15])
            {
                if(cB[1] == LOW)
                {
                    MIDI.sendNoteOn(bMap[15], 127, 1);
                }
                else
                {
                    MIDI.sendNoteOff(bMap[15], 0, 1);
                }

                pB[15] = cB[1];
            }

            if(cB[2] != pB[23])
            {
                if(cB[2] == LOW)
                {
                    MIDI.sendNoteOn(bMap[23], 127, 1);
                }
                else
                {
                    MIDI.sendNoteOff(bMap[23], 0, 1);
                }

                pB[23] = cB[2];
            }

            if(cB[3] != pB[31])
            {
                if(cB[3] == LOW)
                {
                   MIDI.sendNoteOn(bMap[31], 127, 1);
                }
                else
                {
                    MIDI.sendNoteOff(bMap[31], 0, 1);
                }

                pB[31] = cB[3];
            }

            if(cB[4] != pB[39])
            {
                if(cB[4] == LOW)
                {
                    MIDI.sendNoteOn(bMap[39], 127, 1);
                }
                else
                {
                    MIDI.sendNoteOff(bMap[39], 0, 1);
                }

                pB[39] = cB[4];
            }

            if(cP != pP[7])
            {
                MIDI.sendControlChange(pMap[7], cP, 1);

                pP[7] = cP;
            }
        break;
    }

    // Increment column counter
    c++;
    
    // Reset on 8
    if(c > 7)
    {
        c = 0;
    }
}
