// EMC-408 for smaller boards (Uno and the like)
// Uses an 8x8 analog mux made from 4051's
// https://github.com/ellisgl/analog-multiplexer-8x8
uint8_t c = 0; // Column counter

// Previous button states (By row)
bool r0[8] = {0, 0, 0, 0, 0, 0, 0, 0};
bool r1[8] = {0, 0, 0, 0, 0, 0, 0, 0};
bool r2[8] = {0, 0, 0, 0, 0, 0, 0, 0};
bool r3[8] = {0, 0, 0, 0, 0, 0, 0, 0}; 
bool r4[8] = {0, 0, 0, 0, 0, 0, 0, 0}; 
// Continue to r6[8] if you are looking to expand 
// buttons by another 2 rows of 8
// Continue to r7[8] if you don't need analog
// and remove pP[8] and cP

//Previous POT states
int pP[8]  = {0, 0, 0, 0, 0, 0, 0, 0};

// Current states
bool cB[5] = {0, 0, 0, 0, 0};
int cP     = 0;

void setup()
{
    // Using pull mode for less chance of noise issues.
    pinMode(2, INPUT_PULLUP);
    pinMode(3, INPUT_PULLUP);
    pinMode(4, INPUT_PULLUP);
    pinMode(5, INPUT_PULLUP);
    pinMode(6, INPUT_PULLUP);
    pinMode(7, INPUT_PULLUP);
    pinMode(8, INPUT_PULLUP);
    pinMode(9, INPUT_PULLUP);
    pinMode(10, INPUT_PULLUP);

    // Address select
    pinMode(11, OUTPUT); // A
    pinMode(12, OUTPUT); // B
    pinMode(13, OUTPUT); // C

    // Start serial
    Serial.begin(115200);
}

void loop() {
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

    // Read current values
    cB[0] = digitalRead(2);
    cB[1] = digitalRead(3);
    cB[2] = digitalRead(4);
    cB[3] = digitalRead(5);
    cB[4] = digitalRead(6);
    cP    = analogRead(A5);

    // Compare and do stuff
    switch(c)
    {
        case 0:
            if(cB[0] != r0[0])
            {
                Serial.println((String)"RO B0:" + cB[0]);
                r0[0] = cB[0];
            }
            
            if(cB[1] != r1[0])
            {
                Serial.println((String)"R1 B0:" + cB[1]);
                r1[0] = cB[1];
            }
            
            if(cB[2] != r2[0])
            {
                Serial.println((String)"R2 B0:" + cB[2]);
                r2[0] = cB[2];
            }
            
            if(cB[3] != r3[0])
            {
                Serial.println((String)"R3 B0:" + cB[3]);
                r3[0] = cB[3];
            }

            if(cB[4] != r4[0])
            {
                Serial.println((String)"R4 B0:" + cB[4]);
                r4[0] = cB[4];
            }

            if(cP != pP[0])
            {
                Serial.println((String)"P0:" + cP);
                pP[0] = cP;
            }
        break;
        
        case 1:
            if(cB[0] != r0[1])
            {
                Serial.println((String)"RO B1:" + cB[0]);
                r0[1] = cB[0];
            }
            
            if(cB[1] != r1[1])
            {
                Serial.println((String)"R1 B1:" + cB[1]);
                r1[1] = cB[1];
            }
            
            if(cB[2] != r2[1])
            {
                Serial.println((String)"R2 B1:" + cB[2]);
                r2[1] = cB[2];
            }
            
            if(cB[3] != r3[1])
            {
                Serial.println((String)"R3 B1:" + cB[3]);
                r3[1] = cB[3];
            }

            if(cB[4] != r4[1])
            {
                Serial.println((String)"R4 B1:" + cB[4]);
                r4[1] = cB[4];
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
            }
            
            if(cB[1] != r1[2])
            {
                Serial.println((String)"R1 B2:" + cB[1]);
                r1[2] = cB[1];
            }
            
            if(cB[2] != r2[2])
            {
                Serial.println((String)"R2 B2:" + cB[2]);
                r2[2] = cB[2];
            }
            
            if(cB[3] != r3[2])
            {
                Serial.println((String)"R3 B2:" + cB[3]);
                r3[2] = cB[3];
            }

            if(cB[4] != r4[2])
            {
                Serial.println((String)"R4 B2:" + cB[4]);
                r4[2] = cB[4];
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
            }
            
            if(cB[1] != r1[3])
            {
                Serial.println((String)"R1 B3:" + cB[1]);
                r1[3] = cB[1];
            }
            
            if(cB[2] != r2[3])
            {
                Serial.println((String)"R2 B3:" + cB[2]);
                r2[3] = cB[2];
            }
            
            if(cB[3] != r3[3])
            {
                Serial.println((String)"R3 B3:" + cB[3]);
                r3[3] = cB[3];
            }

            if(cB[4] != r4[3])
            {
                Serial.println((String)"R4 B3:" + cB[4]);
                r4[3] = cB[4];
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
            }
            
            if(cB[1] != r1[4])
            {
                Serial.println((String)"R1 B4:" + cB[1]);
                r1[4] = cB[1];
            }
            
            if(cB[2] != r2[4])
            {
                Serial.println((String)"R2 B4:" + cB[2]);
                r2[4] = cB[2];
            }
            
            if(cB[3] != r3[4])
            {
                Serial.println((String)"R3 B4:" + cB[3]);
                r3[4] = cB[3];
            }

            if(cB[4] != r4[4])
            {
                Serial.println((String)"R4 B4:" + cB[4]);
                r4[4] = cB[4];
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
            }
            
            if(cB[1] != r1[5])
            {
                Serial.println((String)"R1 B5:" + cB[1]);
                r1[5] = cB[1];
            }
            
            if(cB[2] != r2[5])
            {
                Serial.println((String)"R2 B5:" + cB[2]);
                r2[5] = cB[2];
            }
            
            if(cB[3] != r3[5])
            {
                Serial.println((String)"R3 B5:" + cB[3]);
                r3[5] = cB[3];
            }

            if(cB[4] != r4[5])
            {
                Serial.println((String)"R4 B5:" + cB[4]);
                r4[5] = cB[4];
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
            }
            
            if(cB[1] != r1[6])
            {
                Serial.println((String)"R1 B6:" + cB[1]);
                r1[6] = cB[1];
            }
            
            if(cB[2] != r2[6])
            {
                Serial.println((String)"R2 B6:" + cB[2]);
                r2[6] = cB[2];
            }
            
            if(cB[3] != r3[6])
            {
                Serial.println((String)"R3 B6:" + cB[3]);
                r3[6] = cB[3];
            }

            if(cB[4] != r4[6])
            {
                Serial.println((String)"R4 B6:" + cB[4]);
                r4[6] = cB[4];
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
            }
            
            if(cB[1] != r1[7])
            {
                Serial.println((String)"R1 B7:" + cB[1]);
                r1[7] = cB[1];
            }
            
            if(cB[2] != r2[7])
            {
                Serial.println((String)"R2 B7:" + cB[2]);
                r2[7] = cB[2];
            }
            
            if(cB[3] != r3[7])
            {
                Serial.println((String)"R3 B7:" + cB[3]);
                r3[7] = cB[3];
            }

            if(cB[4] != r4[7])
            {
                Serial.println((String)"R4 B7:" + cB[4]);
                r4[7] = cB[4];
            }

            if(cP != pP[7])
            {
                Serial.println((String)"P7:" + cP);
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
