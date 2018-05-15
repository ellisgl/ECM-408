// EMC-408 for larger boards (Mega and the like)
// No mux needed, since there are enough inputs
// Include debounce library.
#include <Bounce2.h>

// Instantiate the Bounce objects
Bounce b00 = Bounce();
Bounce b01 = Bounce();
Bounce b02 = Bounce();
Bounce b03 = Bounce();
Bounce b04 = Bounce();
Bounce b05 = Bounce();
Bounce b06 = Bounce();
Bounce b07 = Bounce();
Bounce b08 = Bounce();
Bounce b09 = Bounce();
Bounce b10 = Bounce();
Bounce b11 = Bounce();
Bounce b12 = Bounce();
Bounce b13 = Bounce();
Bounce b14 = Bounce();
Bounce b15 = Bounce();
Bounce b16 = Bounce();
Bounce b17 = Bounce();
Bounce b18 = Bounce();
Bounce b19 = Bounce();
Bounce b20 = Bounce();
Bounce b21 = Bounce();
Bounce b22 = Bounce();
Bounce b23 = Bounce();
Bounce b24 = Bounce();
Bounce b25 = Bounce();
Bounce b26 = Bounce();
Bounce b27 = Bounce();
Bounce b28 = Bounce();
Bounce b29 = Bounce();
Bounce b30 = Bounce();
Bounce b31 = Bounce();
Bounce b32 = Bounce();
Bounce b33 = Bounce();
Bounce b34 = Bounce();
Bounce b35 = Bounce();
Bounce b36 = Bounce();
Bounce b37 = Bounce();
Bounce b38 = Bounce();
Bounce b39 = Bounce();

// Previous button states.
bool pB[40] = {
  0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 
  0, 0, 0, 0, 0, 0, 0, 0
}; 

//Previous Analog (POT) states
int pP[8]  = {0, 0, 0, 0, 0, 0, 0, 0};

// Current states
bool cB[40] = {
  0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 
  0, 0, 0, 0, 0, 0, 0, 0
}; 

int cP[8]  = {0, 0, 0, 0, 0, 0, 0, 0};

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
    pinMode(11, INPUT_PULLUP);
    pinMode(12, INPUT_PULLUP);
    pinMode(13, INPUT_PULLUP);
    pinMode(14, INPUT_PULLUP);
    pinMode(15, INPUT_PULLUP);
    pinMode(16, INPUT_PULLUP);
    pinMode(17, INPUT_PULLUP);
    pinMode(18, INPUT_PULLUP);
    pinMode(19, INPUT_PULLUP);
    pinMode(20, INPUT_PULLUP);
    pinMode(21, INPUT_PULLUP);
    pinMode(22, INPUT_PULLUP);
    pinMode(23, INPUT_PULLUP);
    pinMode(24, INPUT_PULLUP);
    pinMode(25, INPUT_PULLUP);
    pinMode(26, INPUT_PULLUP);
    pinMode(27, INPUT_PULLUP);
    pinMode(28, INPUT_PULLUP);
    pinMode(29, INPUT_PULLUP);
    pinMode(30, INPUT_PULLUP);
    pinMode(31, INPUT_PULLUP);
    pinMode(32, INPUT_PULLUP);
    pinMode(33, INPUT_PULLUP);
    pinMode(34, INPUT_PULLUP);
    pinMode(35, INPUT_PULLUP);
    pinMode(36, INPUT_PULLUP);
    pinMode(37, INPUT_PULLUP);
    pinMode(38, INPUT_PULLUP);
    pinMode(39, INPUT_PULLUP);
    pinMode(40, INPUT_PULLUP);
    pinMode(41, INPUT_PULLUP);

    // Attach buttons to the Bounce instance
    b00.attach(2);
    b01.attach(3);
    b02.attach(4);
    b03.attach(5);
    b04.attach(6);
    b05.attach(7);
    b06.attach(8);
    b07.attach(9);
    b08.attach(10);
    b09.attach(11);
    b10.attach(12);
    b11.attach(13);
    b12.attach(14);
    b13.attach(15);
    b14.attach(16);
    b15.attach(17);
    b16.attach(18);
    b17.attach(19);
    b18.attach(20);
    b19.attach(21);
    b20.attach(22);
    b21.attach(23);
    b22.attach(24);
    b23.attach(25);
    b24.attach(26);
    b25.attach(27);
    b26.attach(28);
    b27.attach(29);
    b28.attach(30);
    b29.attach(31);
    b30.attach(32);
    b31.attach(33);
    b32.attach(34);
    b33.attach(35);
    b34.attach(36);
    b35.attach(37);
    b36.attach(38);
    b37.attach(39);
    b38.attach(40);
    b39.attach(41);
    
    // Set the debounce interval to 3 ms
    b00.interval(3);
    b01.interval(3);
    b02.interval(3);
    b03.interval(3);
    b04.interval(3);
    b05.interval(3);
    b06.interval(3);
    b07.interval(3);
    b08.interval(3);
    b09.interval(3);
    b10.interval(3);
    b11.interval(3);
    b12.interval(3);
    b13.interval(3);
    b14.interval(3);
    b15.interval(3);
    b16.interval(3);
    b17.interval(3);
    b18.interval(3);
    b19.interval(3);
    b20.interval(3);
    b21.interval(3);
    b22.interval(3);
    b23.interval(3);
    b24.interval(3);
    b25.interval(3);
    b26.interval(3);
    b27.interval(3);
    b28.interval(3);
    b29.interval(3);
    b30.interval(3);
    b31.interval(3);
    b32.interval(3);
    b33.interval(3);
    b34.interval(3);
    b35.interval(3);
    b36.interval(3);
    b37.interval(3);
    b38.interval(3);
    b39.interval(3);

    // Start serial
    Serial.begin(115200);
}

void loop()
{
    // Update value from bounce library.
    b00.update();
    b01.update();
    b02.update();
    b03.update();
    b04.update();
    b05.update();
    b06.update();
    b07.update();
    b08.update();
    b09.update();
    b10.update();
    b11.update();
    b12.update();
    b13.update();
    b14.update();
    b15.update();
    b16.update();
    b17.update();
    b18.update();
    b19.update();
    b20.update();
    b21.update();
    b22.update();
    b23.update();
    b24.update();
    b25.update();
    b26.update();
    b27.update();
    b28.update();
    b29.update();
    b30.update();
    b31.update();
    b32.update();
    b33.update();
    b34.update();
    b35.update();
    b36.update();
    b37.update();
    b38.update();
    b39.update();

    // Read the value into current values.
    cB[0]  = b00.read();
    cB[1]  = b01.read();
    cB[2]  = b02.read();
    cB[3]  = b03.read();
    cB[4]  = b04.read();
    cB[5]  = b05.read();
    cB[6]  = b06.read();
    cB[7]  = b07.read();
    cB[8]  = b08.read();
    cB[9]  = b09.read();
    cB[10] = b10.read();
    cB[11] = b11.read();
    cB[12] = b12.read();
    cB[13] = b13.read();
    cB[14] = b14.read();
    cB[15] = b15.read();
    cB[16] = b16.read();
    cB[17] = b17.read();
    cB[18] = b18.read();
    cB[19] = b19.read();
    cB[20] = b20.read();
    cB[21] = b21.read();
    cB[22] = b22.read();
    cB[23] = b23.read();
    cB[24] = b24.read();
    cB[25] = b25.read();
    cB[26] = b26.read();
    cB[27] = b27.read();
    cB[28] = b28.read();
    cB[29] = b29.read();
    cB[30] = b30.read();
    cB[31] = b31.read();
    cB[32] = b32.read();
    cB[33] = b33.read();
    cB[34] = b34.read();
    cB[35] = b35.read();
    cB[36] = b36.read();
    cB[37] = b37.read();
    cB[38] = b38.read();
    cB[39] = b39.read();

    // Read analog inputs into current values.
    cP[0] = analogRead(A0);
    cP[1] = analogRead(A1);
    cP[2] = analogRead(A2);
    cP[3] = analogRead(A3);
    cP[4] = analogRead(A4);
    cP[5] = analogRead(A5);
    cP[6] = analogRead(A6);
    cP[7] = analogRead(A7);
    
    // Compare and do stuff
    // Digital
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

    if(cB[1] != pB[1])
    {
        if(cB[1] == LOW)
        {
            Serial.println((String)"Button 1 is on.");
        }
        else
        {
            Serial.println((String)"Button 1 is off.");
        }

        pB[1] = cB[1];
    }

    if(cB[2] != pB[2])
    {
        if(cB[2] == LOW)
        {
            Serial.println((String)"Button 2 is on.");
        }
        else
        {
            Serial.println((String)"Button 2 is off.");
        }

        pB[2] = cB[2];
    }

    if(cB[3] != pB[3])
    {
        if(cB[3] == LOW)
        {
            Serial.println((String)"Button 3 is on.");
        }
        else
        {
            Serial.println((String)"Button 3 is off.");
        }

        pB[3] = cB[3];
    }

    if(cB[4] != pB[4])
    {
        if(cB[4] == LOW)
        {
            Serial.println((String)"Button 4 is on.");
        }
        else
        {
            Serial.println((String)"Button 4 is off.");
        }

        pB[4] = cB[4];
    }

    if(cB[5] != pB[5])
    {
        if(cB[5] == LOW)
        {
            Serial.println((String)"Button 5 is on.");
        }
        else
        {
            Serial.println((String)"Button 5 is off.");
        }

        pB[5] = cB[5];
    }

    if(cB[6] != pB[6])
    {
        if(cB[6] == LOW)
        {
            Serial.println((String)"Button 6 is on.");
        }
        else
        {
            Serial.println((String)"Button 6 is off.");
        }

        pB[6] = cB[6];
    }

    if(cB[7] != pB[7])
    {
        if(cB[7] == LOW)
        {
            Serial.println((String)"Button 7 is on.");
        }
        else
        {
            Serial.println((String)"Button 7 is off.");
        }

        pB[7] = cB[7];
    }

    if(cB[8] != pB[8])
    {
        if(cB[8] == LOW)
        {
            Serial.println((String)"Button 8 is on.");
        }
        else
        {
            Serial.println((String)"Button 8 is off.");
        }

        pB[8] = cB[8];
    }

    if(cB[9] != pB[9])
    {
        if(cB[9] == LOW)
        {
            Serial.println((String)"Button 9 is on.");
        }
        else
        {
            Serial.println((String)"Button 9 is off.");
        }

        pB[9] = cB[9];
    }

    if(cB[10] != pB[10])
    {
        if(cB[10] == LOW)
        {
            Serial.println((String)"Button 10 is on.");
        }
        else
        {
            Serial.println((String)"Button 10 is off.");
        }

        pB[10] = cB[10];
    }

    if(cB[11] != pB[11])
    {
        if(cB[11] == LOW)
        {
            Serial.println((String)"Button 11 is on.");
        }
        else
        {
            Serial.println((String)"Button 11 is off.");
        }

        pB[11] = cB[11];
    }

    if(cB[12] != pB[12])
    {
        if(cB[12] == LOW)
        {
            Serial.println((String)"Button 12 is on.");
        }
        else
        {
            Serial.println((String)"Button 12 is off.");
        }

        pB[12] = cB[12];
    }

    if(cB[13] != pB[13])
    {
        if(cB[13] == LOW)
        {
            Serial.println((String)"Button 13 is on.");
        }
        else
        {
            Serial.println((String)"Button 13 is off.");
        }

        pB[13] = cB[13];
    }

    if(cB[14] != pB[14])
    {
        if(cB[14] == LOW)
        {
            Serial.println((String)"Button 14 is on.");
        }
        else
        {
            Serial.println((String)"Button 14 is off.");
        }

        pB[14] = cB[14];
    }

    if(cB[15] != pB[15])
    {
        if(cB[15] == LOW)
        {
            Serial.println((String)"Button 15 is on.");
        }
        else
        {
            Serial.println((String)"Button 15 is off.");
        }

        pB[15] = cB[15];
    }

    if(cB[16] != pB[16])
    {
        if(cB[16] == LOW)
        {
            Serial.println((String)"Button 16 is on.");
        }
        else
        {
            Serial.println((String)"Button 16 is off.");
        }

        pB[16] = cB[16];
    }

    if(cB[17] != pB[17])
    {
        if(cB[17] == LOW)
        {
            Serial.println((String)"Button 17 is on.");
        }
        else
        {
            Serial.println((String)"Button 17 is off.");
        }

        pB[17] = cB[17];
    }

    if(cB[18] != pB[18])
    {
        if(cB[18] == LOW)
        {
            Serial.println((String)"Button 18 is on.");
        }
        else
        {
            Serial.println((String)"Button 18 is off.");
        }

        pB[18] = cB[18];
    }

    if(cB[19] != pB[19])
    {
        if(cB[19] == LOW)
        {
            Serial.println((String)"Button 19 is on.");
        }
        else
        {
            Serial.println((String)"Button 19 is off.");
        }

        pB[19] = cB[19];
    }

    if(cB[20] != pB[20])
    {
        if(cB[20] == LOW)
        {
            Serial.println((String)"Button 20 is on.");
        }
        else
        {
            Serial.println((String)"Button 20 is off.");
        }

        pB[20] = cB[20];
    }

    if(cB[21] != pB[21])
    {
        if(cB[21] == LOW)
        {
            Serial.println((String)"Button 21 is on.");
        }
        else
        {
            Serial.println((String)"Button 21 is off.");
        }

        pB[21] = cB[21];
    }

    if(cB[22] != pB[22])
    {
        if(cB[22] == LOW)
        {
            Serial.println((String)"Button 22 is on.");
        }
        else
        {
            Serial.println((String)"Button 22 is off.");
        }

        pB[22] = cB[22];
    }

    if(cB[23] != pB[23])
    {
        if(cB[23] == LOW)
        {
            Serial.println((String)"Button 23 is on.");
        }
        else
        {
            Serial.println((String)"Button 23 is off.");
        }

        pB[23] = cB[23];
    }

    if(cB[24] != pB[24])
    {
        if(cB[24] == LOW)
        {
            Serial.println((String)"Button 24 is on.");
        }
        else
        {
            Serial.println((String)"Button 24 is off.");
        }

        pB[24] = cB[24];
    }

    if(cB[25] != pB[25])
    {
        if(cB[25] == LOW)
        {
            Serial.println((String)"Button 25 is on.");
        }
        else
        {
            Serial.println((String)"Button 25 is off.");
        }

        pB[25] = cB[25];
    }

    if(cB[26] != pB[26])
    {
        if(cB[26] == LOW)
        {
            Serial.println((String)"Button 26 is on.");
        }
        else
        {
            Serial.println((String)"Button 26 is off.");
        }

        pB[26] = cB[26];
    }

    if(cB[27] != pB[27])
    {
        if(cB[27] == LOW)
        {
            Serial.println((String)"Button 27 is on.");
        }
        else
        {
            Serial.println((String)"Button 27 is off.");
        }

        pB[27] = cB[27];
    }

    if(cB[28] != pB[28])
    {
        if(cB[28] == LOW)
        {
            Serial.println((String)"Button 28 is on.");
        }
        else
        {
            Serial.println((String)"Button 28 is off.");
        }

        pB[28] = cB[28];
    }

    if(cB[29] != pB[29])
    {
        if(cB[29] == LOW)
        {
            Serial.println((String)"Button 29 is on.");
        }
        else
        {
            Serial.println((String)"Button 29 is off.");
        }

        pB[29] = cB[29];
    }

    if(cB[30] != pB[30])
    {
        if(cB[30] == LOW)
        {
            Serial.println((String)"Button 30 is on.");
        }
        else
        {
            Serial.println((String)"Button 30 is off.");
        }

        pB[30] = cB[30];
    }

    if(cB[31] != pB[31])
    {
        if(cB[31] == LOW)
        {
            Serial.println((String)"Button 31 is on.");
        }
        else
        {
            Serial.println((String)"Button 31 is off.");
        }

        pB[31] = cB[31];
    }

    if(cB[32] != pB[32])
    {
        if(cB[32] == LOW)
        {
            Serial.println((String)"Button 32 is on.");
        }
        else
        {
            Serial.println((String)"Button 32 is off.");
        }

        pB[32] = cB[32];
    }

    if(cB[33] != pB[33])
    {
        if(cB[33] == LOW)
        {
            Serial.println((String)"Button 33 is on.");
        }
        else
        {
            Serial.println((String)"Button 33 is off.");
        }

        pB[33] = cB[33];
    }

    if(cB[34] != pB[34])
    {
        if(cB[34] == LOW)
        {
            Serial.println((String)"Button 34 is on.");
        }
        else
        {
            Serial.println((String)"Button 34 is off.");
        }

        pB[34] = cB[34];
    }

    if(cB[35] != pB[35])
    {
        if(cB[35] == LOW)
        {
            Serial.println((String)"Button 35 is on.");
        }
        else
        {
            Serial.println((String)"Button 35 is off.");
        }

        pB[35] = cB[35];
    }

    if(cB[36] != pB[36])
    {
        if(cB[36] == LOW)
        {
            Serial.println((String)"Button 36 is on.");
        }
        else
        {
            Serial.println((String)"Button 36 is off.");
        }

        pB[36] = cB[36];
    }

    if(cB[37] != pB[37])
    {
        if(cB[37] == LOW)
        {
            Serial.println((String)"Button 37 is on.");
        }
        else
        {
            Serial.println((String)"Button 37 is off.");
        }

        pB[37] = cB[37];
    }

    if(cB[38] != pB[38])
    {
        if(cB[38] == LOW)
        {
            Serial.println((String)"Button 38 is on.");
        }
        else
        {
            Serial.println((String)"Button 38 is off.");
        }

        pB[38] = cB[38];
    }

    if(cB[39] != pB[39])
    {
        if(cB[39] == LOW)
        {
            Serial.println((String)"Button 39 is on.");
        }
        else
        {
            Serial.println((String)"Button 39 is off.");
        }

        pB[39] = cB[39];
    }

    // Analog
    if(cP[0] != pP[0])
    {
        Serial.println((String)"P0 changed from: " + pP[0] + " to:" + cP[0]);
        
        pP[0] = cP[0];
    }

    if(cP[1] != pP[1])
    {
        Serial.println((String)"P1 changed from: " + pP[1] + " to:" + cP[1]);
        
        pP[1] = cP[1];
    }

    if(cP[2] != pP[2])
    {
        Serial.println((String)"P2 changed from: " + pP[2] + " to:" + cP[2]);
        
        pP[2] = cP[2];
    }

    if(cP[3] != pP[3])
    {
        Serial.println((String)"P3 changed from: " + pP[3] + " to:" + cP[3]);
        
        pP[3] = cP[3];
    }

    if(cP[4] != pP[4])
    {
        Serial.println((String)"P4 changed from: " + pP[4] + " to:" + cP[4]);
        
        pP[4] = cP[4];
    }

    if(cP[5] != pP[5])
    {
        Serial.println((String)"P5 changed from: " + pP[5] + " to:" + cP[5]);
        
        pP[5] = cP[5];
    }

    if(cP[6] != pP[6])
    {
        Serial.println((String)"P6 changed from: " + pP[6] + " to:" + cP[6]);
        
        pP[6] = cP[6];
    }

    if(cP[7] != pP[7])
    {
        Serial.println((String)"P7 changed from: " + pP[7] + " to:" + cP[7]);
        
        pP[7] = cP[7];
    }
}
