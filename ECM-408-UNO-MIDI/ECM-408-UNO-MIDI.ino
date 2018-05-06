// MIDI Contoller that sends via serial.
// Use a serial midi converter program:
// http://projectgus.github.io/hairless-midiserial/
// http://www.spikenzielabs.com/SpikenzieLabs/Serial_MIDI.html

#include <MIDI.h>

uint8_t c = 0; // Column counter

// Button Mapping
// Based on Novation Launchpad MK2 mapping:
// https://global.novationmusic.com/sites/default/files/novation/downloads/10529/launchpad-mk2-programmers-reference-guide_0.pdf
uint8_t bMap[40] = {
  11, 12, 13, 14, 15, 16, 17, 18, 19, 29,
  21, 22, 23, 24, 25, 26, 27, 28, 39, 49,
  31, 32, 33, 34, 35, 36, 37, 38, 59, 69,
  41, 42, 43, 44, 45, 46, 47, 48, 79, 89
}

// Previous button states (Row values)
bool r0[8] = {0, 0, 0, 0, 0, 0, 0, 0}; // Row 0 is the bottom row 
bool r1[8] = {0, 0, 0, 0, 0, 0, 0, 0};
bool r2[8] = {0, 0, 0, 0, 0, 0, 0, 0};
bool r3[8] = {0, 0, 0, 0, 0, 0, 0, 0}; 
bool r4[8] = {0, 0, 0, 0, 0, 0, 0, 0}; // Row 4 is the top row

//Previous POT states
int pP[8] = {0, 0, 0, 0, 0, 0, 0, 0};

// Current states
bool cB[5] = {0, 0, 0, 0, 0}; // Buttons
int cP = 0; // POT

void setup()
{
    // Setup the column select output pins
    pinMode(2, OUTPUT);
    pinMode(3, OUTPUT);
    pinMode(4, OUTPUT);
    pinMode(5, OUTPUT);
    pinMode(6, OUTPUT);
    pinMode(7, OUTPUT);
    pinMode(8, OUTPUT);
    pinMode(9, OUTPUT);

    // Start the serial port at the MIDI baudrate (31250) and listen to all incoming messages.
    MIDI.begin(MIDI_CHANNEL_OMNI);
}

void loop()
{
    // Disable all columns
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
    digitalWrite(8, LOW);
    digitalWrite(9, LOW);

    // Enable a column
    switch(c)
    {
        case 0:
            digitalWrite(2, HIGH);
        break;

        case 1:
            digitalWrite(3, HIGH);
        break;

        case 2:
            digitalWrite(4, HIGH);
        break;

        case 3:
            digitalWrite(5, HIGH);
        break;

        case 4:
            digitalWrite(6, HIGH);
        break;

        case 5:
            digitalWrite(7, HIGH);
        break;

        case 6:
            digitalWrite(8, HIGH);
        break;

        case 7:
            digitalWrite(9, HIGH);
        break;
    }
    
    // Read current values
    cB[0] = digitalRead(A0);  
    cB[1] = digitalRead(A1);
    cB[2] = digitalRead(A2);
    cB[3] = digitalRead(A3);
    cB[4] = digitalRead(A4);
    cP    = analogRead(A5);

    // Compare and do stuff
    switch(c)
    {
        case 0:
            if(cB[0] != r0[0])
            {
                r0[0] = cB[0];
                
                if(cb[0] == 1)
                {
                    MIDI.sendNoteOn(bMap[0], 127, 1);
                }
                else
                {
                  MIDI.sendNoteOff(bMap[0], 0, 1); 
                }
            }
            
            if(cB[1] != r1[0])
            {
                r1[0] = cB[1];
                
                if(cb[1] == 1)
                {
                    MIDI.sendNoteOn(bMap[10], 127, 1);
                }
                else
                {
                    MIDI.sendNoteOff(bMap[10], 0, 1); 
                }
            }
            
            if(cB[2] != r2[0])
            {
                r2[0] = cB[2];
                                
                if(cb[2] == 1)
                {
                    MIDI.sendNoteOn(bMap[20], 127, 1);
                }
                else
                {
                    MIDI.sendNoteOff(bMap[20], 0, 1); 
                }
            }
            
            if(cB[3] != r3[0])
            {
                r3[0] = cB[3];
                                
                if(cb[3] == 1)
                {
                    MIDI.sendNoteOn(bMap[30], 127, 1);
                }
                else
                {
                    MIDI.sendNoteOff(bMap[30], 0, 1); 
                }
            }

            if(cB[4] != r4[0])
            {
                r4[0] = cB[4];
                                
                if(cb[4] == 1)
                {
                    MIDI.sendNoteOn(bMap[8], 127, 1);
                }
                else
                {
                    MIDI.sendNoteOff(bMap[8], 0, 1); 
                }
            }

            // TODO: Figure out what to do with the POTs.
            if(cP != pP[0])
            {
                pP[0] = cP;
            }
        break;
        
        case 1:
            if(cB[0] != r0[1])
            {
                r0[1] = cB[0];
                                
                if(cb[0] == 1)
                {
                    MIDI.sendNoteOn(bMap[1], 127, 1);
                }
                else
                {
                    MIDI.sendNoteOff(bMap[1], 0, 1); 
                }
            }
            
            if(cB[1] != r1[1])
            {
                r1[1] = cB[1];
                                
                if(cb[1] == 1)
                {
                    MIDI.sendNoteOn(bMap[11], 127, 1);
                }
                else
                {
                    MIDI.sendNoteOff(bMap[11], 0, 1); 
                }
            }
            
            if(cB[2] != r2[1])
            {
                r2[1] = cB[2];
                                
                if(cb[2] == 1)
                {
                    MIDI.sendNoteOn(bMap[21], 127, 1);
                }
                else
                {
                    MIDI.sendNoteOff(bMap[21], 0, 1); 
                }
            }
            
            if(cB[3] != r3[1])
            {
                r3[1] = cB[3];
                                
                if(cb[3] == 1)
                {
                    MIDI.sendNoteOn(bMap[31], 127, 1);
                }
                else
                {
                    MIDI.sendNoteOff(bMap[31], 0, 1); 
                }
            }

            if(cB[4] != r4[1])
            {
                r4[1] = cB[4];
                                
                if(cb[4] == 1)
                {
                    MIDI.sendNoteOn(bMap[9], 127, 1);
                }
                else
                {
                    MIDI.sendNoteOff(bMap[9], 0, 1); 
                }
            }

            if(cP != pP[1])
            {
                pP[1] = cP;
            }
        break;

        case 2:
            if(cB[0] != r0[2])
            {
                r0[2] = cB[0];
                                
                if(cb[0] == 1)
                {
                    MIDI.sendNoteOn(bMap[2], 127, 1);
                }
                else
                {
                    MIDI.sendNoteOff(bMap[2], 0, 1); 
                }
            }
            
            if(cB[1] != r1[2])
            {
                r1[2] = cB[1];
                                
                if(cb[1] == 1)
                {
                    MIDI.sendNoteOn(bMap[12], 127, 1);
                }
                else
                {
                    MIDI.sendNoteOff(bMap[12], 0, 1); 
                }
            }
            
            if(cB[2] != r2[2])
            {
                r2[2] = cB[2];
                                
                if(cb[2] == 1)
                {
                    MIDI.sendNoteOn(bMap[22], 127, 1);
                }
                else
                {
                    MIDI.sendNoteOff(bMap[22], 0, 1); 
                }
            }
            
            if(cB[3] != r3[2])
            {
                r3[2] = cB[3];
                                
                if(cb[3] == 1)
                {
                    MIDI.sendNoteOn(bMap[32], 127, 1);
                }
                else
                {
                    MIDI.sendNoteOff(bMap[32], 0, 1); 
                }
            }

            if(cB[4] != r4[2])
            {
                r4[2] = cB[4];
                                
                if(cb[4] == 1)
                {
                    MIDI.sendNoteOn(bMap[18], 127, 1);
                }
                else
                {
                    MIDI.sendNoteOff(bMap[18], 0, 1); 
                }
            }

            if(cP != pP[2])
            {
                pP[2] = cP;
            }
        break;

        case 3:
            if(cB[0] != r0[3])
            {
                r0[3] = cB[0];

                if(cb[0] == 1)
                {
                    MIDI.sendNoteOn(bMap[3], 127, 1);
                }
                else
                {
                    MIDI.sendNoteOff(bMap[3], 0, 1); 
                }
            }
            
            if(cB[1] != r1[3])
            {
                Serial.println((String)"R1 B3:" + cB[1]);
                r1[3] = cB[1];
                
                if(cb[1] == 1)
                {
                    MIDI.sendNoteOn(bMap[13], 127, 1);
                }
                else
                {
                    MIDI.sendNoteOff(bMap[13], 0, 1); 
                }
            }
            
            if(cB[2] != r2[3])
            {
                r2[3] = cB[2];
                
                if(cb[2] == 1)
                {
                    MIDI.sendNoteOn(bMap[23], 127, 1);
                }
                else
                {
                    MIDI.sendNoteOff(bMap[23], 0, 1); 
                }
            }
            
            if(cB[3] != r3[3])
            {
                r3[3] = cB[3];
                
                if(cb[3] == 1)
                {
                    MIDI.sendNoteOn(bMap[33], 127, 1);
                }
                else
                {
                    MIDI.sendNoteOff(bMap[33], 0, 1); 
                }
            }

            if(cB[4] != r4[3])
            {
                r4[3] = cB[4];
                
                if(cb[4] == 1)
                {
                    MIDI.sendNoteOn(bMap[19], 127, 1);
                }
                else
                {
                    MIDI.sendNoteOff(bMap[19], 0, 1); 
                }
            }

            if(cP != pP[3])
            {
                pP[3] = cP;
            }
        break;
        
        case 4:
            if(cB[0] != r0[4])
            {
                r0[4] = cB[0];
                
                if(cb[0] == 1)
                {
                    MIDI.sendNoteOn(bMap[4], 127, 1);
                }
                else
                {
                    MIDI.sendNoteOff(bMap[4], 0, 1); 
                }
            }
            
            if(cB[1] != r1[4])
            {
                r1[4] = cB[1];
                
                if(cb[1] == 1)
                {
                    MIDI.sendNoteOn(bMap[14], 127, 1);
                }
                else
                {
                    MIDI.sendNoteOff(bMap[14], 0, 1); 
                }
            }
            
            if(cB[2] != r2[4])
            {
                r2[4] = cB[2];
                
                if(cb[2] == 1)
                {
                    MIDI.sendNoteOn(bMap[24], 127, 1);
                }
                else
                {
                    MIDI.sendNoteOff(bMap[24], 0, 1); 
                }
            }
            
            if(cB[3] != r3[4])
            {
                r3[4] = cB[3];
                                
                if(cb[3] == 1)
                {
                    MIDI.sendNoteOn(bMap[34], 127, 1);
                }
                else
                {
                    MIDI.sendNoteOff(bMap[34], 0, 1); 
                }
            }

            if(cB[4] != r4[4])
            {
                r4[4] = cB[4];

                if(cb[4] == 1)
                {
                    MIDI.sendNoteOn(bMap[28], 127, 1);
                }
                else
                {
                    MIDI.sendNoteOff(bMap[28], 0, 1); 
                }
            }

            if(cP != pP[4])
            {
                pP[4] = cP;
            }
        break;
        
        case 5:
            if(cB[0] != r0[5])
            {
                r0[5] = cB[0];
                
                if(cb[0] == 1)
                {
                    MIDI.sendNoteOn(bMap[5], 127, 1);
                }
                else
                {
                    MIDI.sendNoteOff(bMap[5], 0, 1); 
                }
            }
            
            if(cB[1] != r1[5])
            {
                r1[5] = cB[1];
                
                if(cb[1] == 1)
                {
                    MIDI.sendNoteOn(bMap[15], 127, 1);
                }
                else
                {
                    MIDI.sendNoteOff(bMap[15], 0, 1); 
                }
            }
            
            if(cB[2] != r2[5])
            {
                r2[5] = cB[2];
                
                if(cb[2] == 1)
                {
                    MIDI.sendNoteOn(bMap[25], 127, 1);
                }
                else
                {
                    MIDI.sendNoteOff(bMap[25], 0, 1); 
                }
            }
            
            if(cB[3] != r3[5])
            {
                r3[5] = cB[3];
                
                if(cb[3] == 1)
                {
                    MIDI.sendNoteOn(bMap[35], 127, 1);
                }
                else
                {
                    MIDI.sendNoteOff(bMap[35], 0, 1); 
                }
            }

            if(cB[4] != r4[5])
            {
                r4[5] = cB[4];
                
                if(cb[4] == 1)
                {
                    MIDI.sendNoteOn(bMap[29], 127, 1);
                }
                else
                {
                    MIDI.sendNoteOff(bMap[29], 0, 1); 
                }
            }

            if(cP != pP[5])
            {
                pP[5] = cP;
            }
        break;
        
        case 6:
            if(cB[0] != r0[6])
            {
                r0[6] = cB[0];
                
                if(cb[0] == 1)
                {
                    MIDI.sendNoteOn(bMap[6], 127, 1);
                }
                else
                {
                    MIDI.sendNoteOff(bMap[6], 0, 1); 
                }
            }
            
            if(cB[1] != r1[6])
            {
                r1[6] = cB[1];
                
                if(cb[1] == 1)
                {
                    MIDI.sendNoteOn(bMap[16], 127, 1);
                }
                else
                {
                    MIDI.sendNoteOff(bMap[16], 0, 1); 
                }
            }
            
            if(cB[2] != r2[6])
            {
                r2[6] = cB[2];
                
                if(cb[2] == 1)
                {
                    MIDI.sendNoteOn(bMap[26], 127, 1);
                }
                else
                {
                    MIDI.sendNoteOff(bMap[26], 0, 1); 
                }
            }

            if(cB[3] != r3[6])
            {
                r3[6] = cB[3];
                
                if(cb[3] == 1)
                {
                    MIDI.sendNoteOn(bMap[36], 127, 1);
                }
                else
                {
                    MIDI.sendNoteOff(bMap[36], 0, 1); 
                }
            }

            if(cB[4] != r4[6])
            {
                r4[6] = cB[4];
                
                if(cb[4] == 1)
                {
                    MIDI.sendNoteOn(bMap[38], 127, 1);
                }
                else
                {
                    MIDI.sendNoteOff(bMap[38], 0, 1); 
                }
            }

            if(cP != pP[6])
            {
                pP[6] = cP;
            }
        break;
       
        case 7:
            if(cB[0] != r0[7])
            {
                r0[7] = cB[0];
                
                if(cb[0] == 1)
                {
                    MIDI.sendNoteOn(bMap[7], 127, 1);
                }
                else
                {
                    MIDI.sendNoteOff(bMap[7], 0, 1); 
                }
            }
            
            if(cB[1] != r1[7])
            {
                r1[7] = cB[1];
                
                if(cb[1] == 1)
                {
                    MIDI.sendNoteOn(bMap[17], 127, 1);
                }
                else
                {
                    MIDI.sendNoteOff(bMap[17], 0, 1); 
                }
            }
            
            if(cB[2] != r2[7])
            {
                r2[7] = cB[2];
                
                if(cb[2] == 1)
                {
                    MIDI.sendNoteOn(bMap[27], 127, 1);
                }
                else
                {
                    MIDI.sendNoteOff(bMap[27], 0, 1); 
                }
            }
            
            if(cB[3] != r3[7])
            {
                r3[7] = cB[3];
                
                if(cb[3] == 1)
                {
                    MIDI.sendNoteOn(bMap[37], 127, 1);
                }
                else
                {
                    MIDI.sendNoteOff(bMap[37], 0, 1); 
                }
            }

            if(cB[4] != r4[7])
            {
                r4[7] = cB[4];
                
                if(cb[4] == 1)
                {
                    MIDI.sendNoteOn(bMap[39], 127, 1);
                }
                else
                {
                    MIDI.sendNoteOff(bMap[39], 0, 1); 
                }
            }

            if(cP != pP[7])
            {
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
