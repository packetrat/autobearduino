#include <Servo.h>

Servo myservo;
char serialData;
boolean animate = false;

int val = 0;
int count = 0;
int pose;

void setup() {
    myservo.attach(9);
    myservo.write(90);
    Serial.begin(9600);

    // wait for serial port to connect. Needed for Leonardo only
    while (!Serial) {
        ;
    }
}

void serialEvent() {
    while (Serial.available()) {
        serialData = (char) Serial.read();
        if (serialData == 'g') {
            animate = true;
        } else if (serialData == 'x') {
            animate = false;
        }
    }
}

void loop() {
    if (animate) {
        count++;
        pose = count % 5;
        
        if (pose == 4) {
            for (val = 130; val >= 1; val -= 3) {
                myservo.write(val);
                delay(18);
            }
            for (val = 1; val <= 130; val += 10) {
                myservo.write(val);
                delay(18);
            }
        } else if (pose == 3) {
            for (val = 90; val >= 3; val -= 5) {
                myservo.write(val);
                delay(18);
            }
            for (val = 3; val <= 90; val += 10) {
                myservo.write(val);
                delay(18);
            }
        } else if (pose == 2) {
            for (val = 170; val >= 3; val -= 3) {
                myservo.write(val);
                delay(8);
            }
            for (val = 3; val <= 90; val += 9) {
                myservo.write(val);
                delay(18);
            }
        } else if (pose == 1) {
            for (val = 129; val >= 3; val -= 5) {
                myservo.write(val);
                delay(18);
            }
            for (val = 5; val <= 110; val += 10) {
                myservo.write(val);
                delay(18);
            }
        } else if (pose == 0) {
            for (val = 80; val >= 1; val -= 4) {
                myservo.write(val);
                delay(18);
            }
            for (val = 5; val <= 90; val += 10) {
                myservo.write(val);
                delay(18);
            }
        }
    }
}
