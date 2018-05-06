// MIDI Contoller that sends via serial.
// Use a serial midi converter program:
// http://projectgus.github.io/hairless-midiserial/
// http://www.spikenzielabs.com/SpikenzieLabs/Serial_MIDI.html

#include <MIDI.h>

uint8_t c = 0; // Column counter

// Button Mapping - based on Novation Launchpad MK2 mapping https://global.novationmusic.com/sites/default/files/novation/downloads/10529/launchpad-mk2-programmers-reference-guide_0.pdf
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
                
                if(cb[] == 1)
                {
                    MIDI.sendNoteOn(bMap[0], 127, 1);
                }
                else
                {
                  MIDI.sendNoteOff(bMap[], 0, 1); 
                }
            }
            
            if(cB[1] != r1[0])
            {
                Serial.println((String)"R1 B0:" + cB[1]);
                r1[0] = cB[1];
                
                if(cb[] == 1)
                {
                    MIDI.sendNoteOn(bMap[], 127, 1);
                }
                else
                {
                  MIDI.sendNoteOff(bMap[], 0, 1); 
                }
            }
            
            if(cB[2] != r2[0])
            {
                Serial.println((String)"R2 B0:" + cB[2]);
                r2[0] = cB[2];
                                
                if(cb[] == 1)
                {
                    MIDI.sendNoteOn(bMap[], 127, 1);
                }
                else
                {
                  MIDI.sendNoteOff(bMap[], 0, 1); 
                }
            }
            
            if(cB[3] != r3[0])
            {
                Serial.println((String)"R3 B0:" + cB[3]);
                r3[0] = cB[3];
                                
                if(cb[] == 1)
                {
                    MIDI.sendNoteOn(bMap[], 127, 1);
                }
                else
                {
                  MIDI.sendNoteOff(bMap[], 0, 1); 
                }
            }

            if(cB[4] != r4[0])
            {
                Serial.println((String)"R4 B0:" + cB[4]);
                r4[0] = cB[4];
                                
                if(cb[] == 1)
                {
                    MIDI.sendNoteOn(bMap[], 127, 1);
                }
                else
                {
                  MIDI.sendNoteOff(bMap[], 0, 1); 
                }
            }

            if(cP != pP[0])
            {
                Serial.println((String)"P0:" + cP);
                pP[0] = cP;

                // Need to figure out what to do with the POTs.
            }
        break;
        
        case 1:
            if(cB[0] != r0[1])
            {
                Serial.println((String)"RO B1:" + cB[0]);
                r0[1] = cB[0];
                                
                if(cb[] == 1)
                {
                    MIDI.sendNoteOn(bMap[], 127, 1);
                }
                else
                {
                  MIDI.sendNoteOff(bMap[], 0, 1); 
                }
            }
            
            if(cB[1] != r1[1])
            {
                Serial.println((String)"R1 B1:" + cB[1]);
                r1[1] = cB[1];
                                
                if(cb[] == 1)
                {
                    MIDI.sendNoteOn(bMap[], 127, 1);
                }
                else
                {
                  MIDI.sendNoteOff(bMap[], 0, 1); 
                }
            }
            
            if(cB[2] != r2[1])
            {
                Serial.println((String)"R2 B1:" + cB[2]);
                r2[1] = cB[2];
                                
                if(cb[] == 1)
                {
                    MIDI.sendNoteOn(bMap[], 127, 1);
                }
                else
                {
                  MIDI.sendNoteOff(bMap[], 0, 1); 
                }
            }
            
            if(cB[3] != r3[1])
            {
                Serial.println((String)"R3 B1:" + cB[3]);
                r3[1] = cB[3];
                                
                if(cb[] == 1)
                {
                    MIDI.sendNoteOn(bMap[], 127, 1);
                }
                else
                {
                  MIDI.sendNoteOff(bMap[], 0, 1); 
                }
            }

            if(cB[4] != r4[1])
            {
                Serial.println((String)"R4 B1:" + cB[4]);
                r4[1] = cB[4];
                                
                if(cb[] == 1)
                {
                    MIDI.sendNoteOn(bMap[], 127, 1);
                }
                else
                {
                  MIDI.sendNoteOff(bMap[], 0, 1); 
                }
            }

            if(cP != pP[1])
            {
                Serial.println((String)"P1:" + cP);
                pP[1] = cP;
            }
        break;

        case 2:
            if(cB[0] != r0[2])
            {
                Serial.println((String)"RO B2:" + cB[0]);
                r0[2] = cB[0];
                                
                if(cb[] == 1)
                {
                    MIDI.sendNoteOn(bMap[], 127, 1);
                }
                else
                {
                  MIDI.sendNoteOff(bMap[], 0, 1); 
                }
            }
            
            if(cB[1] != r1[2])
            {
                Serial.println((String)"R1 B2:" + cB[1]);
                r1[2] = cB[1];
                                
                if(cb[] == 1)
                {
                    MIDI.sendNoteOn(bMap[], 127, 1);
                }
                else
                {
                  MIDI.sendNoteOff(bMap[], 0, 1); 
                }
            }
            
            if(cB[2] != r2[2])
            {
                Serial.println((String)"R2 B2:" + cB[2]);
                r2[2] = cB[2];
                                
                if(cb[] == 1)
                {
                    MIDI.sendNoteOn(bMap[], 127, 1);
                }
                else
                {
                  MIDI.sendNoteOff(bMap[], 0, 1); 
                }
            }
            
            if(cB[3] != r3[2])
            {
                Serial.println((String)"R3 B2:" + cB[3]);
                r3[2] = cB[3];
                                
                if(cb[] == 1)
                {
                    MIDI.sendNoteOn(bMap[], 127, 1);
                }
                else
                {
                  MIDI.sendNoteOff(bMap[], 0, 1); 
                }
            }

            if(cB[4] != r4[2])
            {
                Serial.println((String)"R4 B2:" + cB[4]);
                r4[2] = cB[4];
                                
                if(cb[] == 1)
                {
                    MIDI.sendNoteOn(bMap[], 127, 1);
                }
                else
                {
                  MIDI.sendNoteOff(bMap[], 0, 1); 
                }
            }

            if(cP != pP[2])
            {
                Serial.println((String)"P2:" + cP);
                pP[2] = cP;
                
            }
        break;

        case 3:
            if(cB[0] != r0[3])
            {
                Serial.println((String)"RO B3:" + cB[0]);
                r0[3] = cB[0];

                if(cb[] == 1)
                {
                    MIDI.sendNoteOn(bMap[], 127, 1);
                }
                else
                {
                  MIDI.sendNoteOff(bMap[], 0, 1); 
                }
            }
            
            if(cB[1] != r1[3])
            {
                Serial.println((String)"R1 B3:" + cB[1]);
                r1[3] = cB[1];
                
                if(cb[] == 1)
                {
                    MIDI.sendNoteOn(bMap[], 127, 1);
                }
                else
                {
                  MIDI.sendNoteOff(bMap[], 0, 1); 
                }
            }
            
            if(cB[2] != r2[3])
            {
                Serial.println((String)"R2 B3:" + cB[2]);
                r2[3] = cB[2];
                
                if(cb[] == 1)
                {
                    MIDI.sendNoteOn(bMap[], 127, 1);
                }
                else
                {
                  MIDI.sendNoteOff(bMap[], 0, 1); 
                }
            }
            
            if(cB[3] != r3[3])
            {
                Serial.println((String)"R3 B3:" + cB[3]);
                r3[3] = cB[3];
                
                if(cb[] == 1)
                {
                    MIDI.sendNoteOn(bMap[], 127, 1);
                }
                else
                {
                  MIDI.sendNoteOff(bMap[], 0, 1); 
                }
            }

            if(cB[4] != r4[3])
            {
                Serial.println((String)"R4 B3:" + cB[4]);
                r4[3] = cB[4];
                
                if(cb[] == 1)
                {
                    MIDI.sendNoteOn(bMap[], 127, 1);
                }
                else
                {
                  MIDI.sendNoteOff(bMap[], 0, 1); 
                }
            }

            if(cP != pP[3])
            {
                Serial.println((String)"P3:" + cP);
                pP[3] = cP;
            }
        break;
        
        case 4:
            if(cB[0] != r0[4])
            {
                Serial.println((String)"RO B4:" + cB[0]);
                r0[4] = cB[0];
                
                if(cb[] == 1)
                {
                    MIDI.sendNoteOn(bMap[], 127, 1);
                }
                else
                {
                  MIDI.sendNoteOff(bMap[], 0, 1); 
                }
            }
            
            if(cB[1] != r1[4])
            {
                Serial.println((String)"R1 B4:" + cB[1]);
                r1[4] = cB[1];
                
                if(cb[] == 1)
                {
                    MIDI.sendNoteOn(bMap[], 127, 1);
                }
                else
                {
                  MIDI.sendNoteOff(bMap[], 0, 1); 
                }
            }
            
            if(cB[2] != r2[4])
            {
                Serial.println((String)"R2 B4:" + cB[2]);
                r2[4] = cB[2];
                
                if(cb[] == 1)
                {
                    MIDI.sendNoteOn(bMap[], 127, 1);
                }
                else
                {
                  MIDI.sendNoteOff(bMap[], 0, 1); 
                }
            }
            
            if(cB[3] != r3[4])
            {
                Serial.println((String)"R3 B4:" + cB[3]);
                r3[4] = cB[3];
                                
                if(cb[] == 1)
                {
                    MIDI.sendNoteOn(bMap[], 127, 1);
                }
                else
                {
                  MIDI.sendNoteOff(bMap[], 0, 1); 
                }
            }

            if(cB[4] != r4[4])
            {
                Serial.println((String)"R4 B4:" + cB[4]);
                r4[4] = cB[4];
                
                if(cb[] == 1)
                {
                    MIDI.sendNoteOn(bMap[], 127, 1);
                }
                else
                {
                  MIDI.sendNoteOff(bMap[], 0, 1); 
                }
            }

            if(cP != pP[4])
            {
                Serial.println((String)"P4:" + cP);
                pP[4] = cP;
            }
        break;
        
        case 5:
            if(cB[0] != r0[5])
            {
                Serial.println((String)"RO B5:" + cB[0]);
                r0[5] = cB[0];
                
                if(cb[] == 1)
                {
                    MIDI.sendNoteOn(bMap[], 127, 1);
                }
                else
                {
                  MIDI.sendNoteOff(bMap[], 0, 1); 
                }
            }
            
            if(cB[1] != r1[5])
            {
                Serial.println((String)"R1 B5:" + cB[1]);
                r1[5] = cB[1];
                
                if(cb[] == 1)
                {
                    MIDI.sendNoteOn(bMap[], 127, 1);
                }
                else
                {
                  MIDI.sendNoteOff(bMap[], 0, 1); 
                }
            }
            
            if(cB[2] != r2[5])
            {
                Serial.println((String)"R2 B5:" + cB[2]);
                r2[5] = cB[2];
                
                if(cb[] == 1)
                {
                    MIDI.sendNoteOn(bMap[], 127, 1);
                }
                else
                {
                  MIDI.sendNoteOff(bMap[], 0, 1); 
                }
            }
            
            if(cB[3] != r3[5])
            {
                Serial.println((String)"R3 B5:" + cB[3]);
                r3[5] = cB[3];
                
                if(cb[] == 1)
                {
                    MIDI.sendNoteOn(bMap[], 127, 1);
                }
                else
                {
                  MIDI.sendNoteOff(bMap[], 0, 1); 
                }
            }

            if(cB[4] != r4[5])
            {
                Serial.println((String)"R4 B5:" + cB[4]);
                r4[5] = cB[4];
                
                if(cb[] == 1)
                {
                    MIDI.sendNoteOn(bMap[], 127, 1);
                }
                else
                {
                  MIDI.sendNoteOff(bMap[], 0, 1); 
                }
            }

            if(cP != pP[5])
            {
                Serial.println((String)"P5:" + cP);
                pP[5] = cP;
            }
        break;
        
        case 6:
            if(cB[0] != r0[6])
            {
                Serial.println((String)"RO B6:" + cB[0]);
                r0[6] = cB[0];
                
                if(cb[] == 1)
                {
                    MIDI.sendNoteOn(bMap[], 127, 1);
                }
                else
                {
                  MIDI.sendNoteOff(bMap[], 0, 1); 
                }
            }
            
            if(cB[1] != r1[6])
            {
                Serial.println((String)"R1 B6:" + cB[1]);
                r1[6] = cB[1];
                
                if(cb[] == 1)
                {
                    MIDI.sendNoteOn(bMap[], 127, 1);
                }
                else
                {
                  MIDI.sendNoteOff(bMap[], 0, 1); 
                }
            }
            
            if(cB[2] != r2[6])
            {
                Serial.println((String)"R2 B6:" + cB[2]);
                r2[6] = cB[2];
                
                if(cb[] == 1)
                {
                    MIDI.sendNoteOn(bMap[], 127, 1);
                }
                else
                {
                  MIDI.sendNoteOff(bMap[], 0, 1); 
                }
            }
            
            if(cB[3] != r3[6])
            {
                Serial.println((String)"R3 B6:" + cB[3]);
                r3[6] = cB[3];
                
                if(cb[] == 1)
                {
                    MIDI.sendNoteOn(bMap[], 127, 1);
                }
                else
                {
                  MIDI.sendNoteOff(bMap[], 0, 1); 
                }
            }

            if(cB[4] != r4[6])
            {
                Serial.println((String)"R4 B6:" + cB[4]);
                r4[6] = cB[4];
                
                if(cb[] == 1)
                {
                    MIDI.sendNoteOn(bMap[], 127, 1);
                }
                else
                {
                  MIDI.sendNoteOff(bMap[], 0, 1); 
                }
            }

            if(cP != pP[6])
            {
                Serial.println((String)"P6:" + cP);
                pP[6] = cP;
            }
        break;
       
        case 7:
            if(cB[0] != r0[7])
            {
                Serial.println((String)"RO B7:" + cB[0]);
                r0[7] = cB[0];
                
                if(cb[] == 1)
                {
                    MIDI.sendNoteOn(bMap[], 127, 1);
                }
                else
                {
                  MIDI.sendNoteOff(bMap[], 0, 1); 
                }
            }
            
            if(cB[1] != r1[7])
            {
                Serial.println((String)"R1 B7:" + cB[1]);
                r1[7] = cB[1];
                
                if(cb[] == 1)
                {
                    MIDI.sendNoteOn(bMap[], 127, 1);
                }
                else
                {
                  MIDI.sendNoteOff(bMap[], 0, 1); 
                }
            }
            
            if(cB[2] != r2[7])
            {
                Serial.println((String)"R2 B7:" + cB[2]);
                r2[7] = cB[2];
                
                if(cb[] == 1)
                {
                    MIDI.sendNoteOn(bMap[], 127, 1);
                }
                else
                {
                  MIDI.sendNoteOff(bMap[], 0, 1); 
                }
            }
            
            if(cB[3] != r3[7])
            {
                Serial.println((String)"R3 B7:" + cB[3]);
                r3[7] = cB[3];
                
                if(cb[] == 1)
                {
                    MIDI.sendNoteOn(bMap[], 127, 1);
                }
                else
                {
                  MIDI.sendNoteOff(bMap[], 0, 1); 
                }
            }

            if(cB[4] != r4[7])
            {
                Serial.println((String)"R4 B7:" + cB[4]);
                r4[7] = cB[4];
                
                if(cb[] == 1)
                {
                    MIDI.sendNoteOn(bMap[], 127, 1);
                }
                else
                {
                  MIDI.sendNoteOff(bMap[], 0, 1); 
                }
            }

            if(cP != pP[7])
            {
                Serial.println((String)"P7:" + cP);
                pP[7] = cP;
                
                if(cb[] == 1)
                {
                    MIDI.sendNoteOn(bMap[], 127, 1);
                }
                else
                {
                  MIDI.sendNoteOff(bMap[], 0, 1); 
                }
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
    
    //delay(500); // Wait for 1000 millisecond(s)
}
