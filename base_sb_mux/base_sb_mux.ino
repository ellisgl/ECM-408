// EMC-408 for smaller boards (Uno and the like)
// Uses an 8x8 analog mux made from 4051's
// https://github.com/ellisgl/analog-multiplexer-8x8
// Include debounce library.
#include <Bounce2.h>

// Instantiate the Bounce objects
Bounce b0 = Bounce();
Bounce b1 = Bounce();
Bounce b2 = Bounce();
Bounce b3 = Bounce();
Bounce b4 = Bounce();

// Column counter
uint8_t c   = 0; 

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
    
    // Start serial
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
    
    cP    = analogRead(A5);

    // Compare and do stuff
    switch(c)
    {
        case 0:
            if(cB[0] != pB[0])
            {
                if(cB[0] == LOW)
                {
                    Serial.println((String)"Button 0 is on.");
                }
                else
                {
                    Serial.println((String)"Button 0 is off.");
                }

                pB[0] = cB[0];
            }

            if(cB[1] != pB[8])
            {
                if(cB[1] == LOW)
                {
                    Serial.println((String)"Button 8 is on.");
                }
                else
                {
                    Serial.println((String)"Button 8 is off.");
                }

                pB[8] = cB[1];
            }

            if(cB[2] != pB[16])
            {
                if(cB[2] == LOW)
                {
                    Serial.println((String)"Button 16 is on.");
                }
                else
                {
                    Serial.println((String)"Button 16 is off.");
                }

                pB[16] = cB[2];
            }

            if(cB[3] != pB[24])
            {
                if(cB[3] == LOW)
                {
                    Serial.println((String)"Button 24 is on.");
                }
                else
                {
                    Serial.println((String)"Button 24 is off.");
                }

                pB[24] = cB[3];
            }

            if(cB[4] != pB[32])
            {
                if(cB[4] == LOW)
                {
                    Serial.println((String)"Button 32 is on.");
                }
                else
                {
                    Serial.println((String)"Button 32 is off.");
                }

                pB[32] = cB[4];
            }

            if(cP != pP[0])
            {
                Serial.println((String)"P0 changed from: " + pP[0] + " to:" + cP);

                pP[0] = cP;
            }
        break;

        case 1:
            if(cB[0] != pB[1])
            {
                if(cB[0] == LOW)
                {
                    Serial.println((String)"Button 1 is on.");
                }
                else
                {
                    Serial.println((String)"Button 1 is off.");
                }

                pB[1] = cB[0];
            }

            if(cB[1] != pB[9])
            {
                if(cB[1] == LOW)
                {
                    Serial.println((String)"Button 9 is on.");
                }
                else
                {
                    Serial.println((String)"Button 9 is off.");
                }

                pB[9] = cB[1];
            }

            if(cB[2] != pB[17])
            {
                if(cB[2] == LOW)
                {
                    Serial.println((String)"Button 17 is on.");
                }
                else
                {
                    Serial.println((String)"Button 17 is off.");
                }

                pB[17] = cB[2];
            }

            if(cB[3] != pB[25])
            {
                if(cB[3] == LOW)
                {
                    Serial.println((String)"Button 25 is on.");
                }
                else
                {
                    Serial.println((String)"Button 25 is off.");
                }

                pB[25] = cB[3];
            }

            if(cB[4] != pB[33])
            {
                if(cB[4] == LOW)
                {
                    Serial.println((String)"Button 33 is on.");
                }
                else
                {
                    Serial.println((String)"Button 33 is off.");
                }

                pB[33] = cB[4];
            }

            if(cP != pP[1])
            {
                Serial.println((String)"P1 changed from: " + pP[1] + " to:" + cP);

                pP[1] = cP;
            }
        break;

        case 2:
            if(cB[0] != pB[2])
            {
                if(cB[0] == LOW)
                {
                    Serial.println((String)"Button 2 is on.");
                }
                else
                {
                    Serial.println((String)"Button 2 is off.");
                }

                pB[2] = cB[0];
            }

            if(cB[1] != pB[10])
            {
                if(cB[1] == LOW)
                {
                    Serial.println((String)"Button 10 is on.");
                }
                else
                {
                    Serial.println((String)"Button 10 is off.");
                }

                pB[10] = cB[1];
            }

            if(cB[2] != pB[18])
            {
                if(cB[2] == LOW)
                {
                    Serial.println((String)"Button 18 is on.");
                }
                else
                {
                    Serial.println((String)"Button 18 is off.");
                }

                pB[18] = cB[2];
            }

            if(cB[3] != pB[26])
            {
                if(cB[3] == LOW)
                {
                    Serial.println((String)"Button 26 is on.");
                }
                else
                {
                    Serial.println((String)"Button 26 is off.");
                }

                pB[26] = cB[3];
            }

            if(cB[4] != pB[34])
            {
                if(cB[4] == LOW)
                {
                    Serial.println((String)"Button 34 is on.");
                }
                else
                {
                    Serial.println((String)"Button 34 is off.");
                }

                pB[34] = cB[4];
            }

            if(cP != pP[2])
            {
                Serial.println((String)"P2 changed from: " + pP[2] + " to:" + cP);

                pP[2] = cP;
            }
        break;

        case 3:
            if(cB[0] != pB[3])
            {
                if(cB[0] == LOW)
                {
                    Serial.println((String)"Button 3 is on.");
                }
                else
                {
                    Serial.println((String)"Button 3 is off.");
                }

                pB[3] = cB[0];
            }

            if(cB[1] != pB[11])
            {
                if(cB[1] == LOW)
                {
                    Serial.println((String)"Button 11 is on.");
                }
                else
                {
                    Serial.println((String)"Button 11 is off.");
                }

                pB[11] = cB[1];
            }

            if(cB[2] != pB[19])
            {
                if(cB[2] == LOW)
                {
                    Serial.println((String)"Button 19 is on.");
                }
                else
                {
                    Serial.println((String)"Button 19 is off.");
                }

                pB[19] = cB[2];
            }

            if(cB[3] != pB[27])
            {
                if(cB[3] == LOW)
                {
                    Serial.println((String)"Button 27 is on.");
                }
                else
                {
                    Serial.println((String)"Button 27 is off.");
                }

                pB[27] = cB[3];
            }

            if(cB[4] != pB[35])
            {
                if(cB[4] == LOW)
                {
                    Serial.println((String)"Button 35 is on.");
                }
                else
                {
                    Serial.println((String)"Button 35 is off.");
                }

                pB[35] = cB[4];
            }

            if(cP != pP[3])
            {
                Serial.println((String)"P3 changed from: " + pP[3] + " to:" + cP);

                pP[3] = cP;
            }
        break;

        case 4:
            if(cB[0] != pB[4])
            {
                if(cB[0] == LOW)
                {
                    Serial.println((String)"Button 4 is on.");
                }
                else
                {
                    Serial.println((String)"Button 4 is off.");
                }

                pB[4] = cB[0];
            }

            if(cB[1] != pB[12])
            {
                if(cB[1] == LOW)
                {
                    Serial.println((String)"Button 12 is on.");
                }
                else
                {
                    Serial.println((String)"Button 12 is off.");
                }

                pB[12] = cB[1];
            }

            if(cB[2] != pB[20])
            {
                if(cB[2] == LOW)
                {
                    Serial.println((String)"Button 20 is on.");
                }
                else
                {
                    Serial.println((String)"Button 20 is off.");
                }

                pB[20] = cB[2];
            }

            if(cB[3] != pB[28])
            {
                if(cB[3] == LOW)
                {
                    Serial.println((String)"Button 28 is on.");
                }
                else
                {
                    Serial.println((String)"Button 28 is off.");
                }

                pB[28] = cB[3];
            }

            if(cB[4] != pB[36])
            {
                if(cB[4] == LOW)
                {
                    Serial.println((String)"Button 36 is on.");
                }
                else
                {
                    Serial.println((String)"Button 36 is off.");
                }

                pB[36] = cB[4];
            }

            if(cP != pP[4])
            {
                Serial.println((String)"P4 changed from: " + pP[4] + " to:" + cP);

                pP[4] = cP;
            }
        break;

        case 5:
            if(cB[0] != pB[5])
            {
                if(cB[0] == LOW)
                {
                    Serial.println((String)"Button 5 is on.");
                }
                else
                {
                    Serial.println((String)"Button 5 is off.");
                }

                pB[5] = cB[0];
            }

            if(cB[1] != pB[13])
            {
                if(cB[1] == LOW)
                {
                    Serial.println((String)"Button 13 is on.");
                }
                else
                {
                    Serial.println((String)"Button 13 is off.");
                }

                pB[13] = cB[1];
            }

            if(cB[2] != pB[21])
            {
                if(cB[2] == LOW)
                {
                    Serial.println((String)"Button 21 is on.");
                }
                else
                {
                    Serial.println((String)"Button 21 is off.");
                }

                pB[21] = cB[2];
            }

            if(cB[3] != pB[29])
            {
                if(cB[3] == LOW)
                {
                    Serial.println((String)"Button 29 is on.");
                }
                else
                {
                    Serial.println((String)"Button 29 is off.");
                }

                pB[29] = cB[3];
            }

            if(cB[4] != pB[37])
            {
                if(cB[4] == LOW)
                {
                    Serial.println((String)"Button 37 is on.");
                }
                else
                {
                    Serial.println((String)"Button 37 is off.");
                }

                pB[37] = cB[4];
            }

            if(cP != pP[5])
            {
                Serial.println((String)"P5 changed from: " + pP[5] + " to:" + cP);

                pP[5] = cP;
            }
        break;

        case 6:
            if(cB[0] != pB[6])
            {
                if(cB[0] == LOW)
                {
                    Serial.println((String)"Button 6 is on.");
                }
                else
                {
                    Serial.println((String)"Button 6 is off.");
                }

                pB[6] = cB[0];
            }

            if(cB[1] != pB[14])
            {
                if(cB[1] == LOW)
                {
                    Serial.println((String)"Button 14 is on.");
                }
                else
                {
                    Serial.println((String)"Button 14 is off.");
                }

                pB[14] = cB[1];
            }

            if(cB[2] != pB[22])
            {
                if(cB[2] == LOW)
                {
                    Serial.println((String)"Button 22 is on.");
                }
                else
                {
                    Serial.println((String)"Button 22 is off.");
                }

                pB[22] = cB[2];
            }

            if(cB[3] != pB[30])
            {
                if(cB[3] == LOW)
                {
                    Serial.println((String)"Button 30 is on.");
                }
                else
                {
                    Serial.println((String)"Button 30 is off.");
                }

                pB[30] = cB[3];
            }

            if(cB[4] != pB[38])
            {
                if(cB[4] == LOW)
                {
                    Serial.println((String)"Button 38 is on.");
                }
                else
                {
                    Serial.println((String)"Button 38 is off.");
                }

                pB[38] = cB[4];
            }

            if(cP != pP[6])
            {
                Serial.println((String)"P6 changed from: " + pP[6] + " to:" + cP);

                pP[6] = cP;
            }
        break;

        case 7:
            if(cB[0] != pB[7])
            {
                if(cB[0] == LOW)
                {
                    Serial.println((String)"Button 7 is on.");
                }
                else
                {
                    Serial.println((String)"Button 7 is off.");
                }

                pB[7] = cB[0];
            }

            if(cB[1] != pB[15])
            {
                if(cB[1] == LOW)
                {
                    Serial.println((String)"Button 15 is on.");
                }
                else
                {
                    Serial.println((String)"Button 15 is off.");
                }

                pB[15] = cB[1];
            }

            if(cB[2] != pB[23])
            {
                if(cB[2] == LOW)
                {
                    Serial.println((String)"Button 23 is on.");
                }
                else
                {
                    Serial.println((String)"Button 23 is off.");
                }

                pB[23] = cB[2];
            }

            if(cB[3] != pB[31])
            {
                if(cB[3] == LOW)
                {
                    Serial.println((String)"Button 31 is on.");
                }
                else
                {
                    Serial.println((String)"Button 31 is off.");
                }

                pB[31] = cB[3];
            }

            if(cB[4] != pB[39])
            {
                if(cB[4] == LOW)
                {
                    Serial.println((String)"Button 39 is on.");
                }
                else
                {
                    Serial.println((String)"Button 39 is off.");
                }

                pB[39] = cB[4];
            }

            if(cP != pP[7])
            {
                Serial.println((String)"P7 changed from: " + pP[7] + " to:" + cP);

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
