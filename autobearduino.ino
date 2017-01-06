#include <Servo.h>

Servo myservo;
char serialData;
boolean animate = false;

byte count = 0;
byte pose_n;

struct pose {
  byte from;
  byte to_boundary;
  byte step;
  byte delay;
};

pose poses[][2] = {
    // from, to_boundary, step, delay
    // first is down, second is up
    { {80, 1, 4, 18}, {5, 90, 10, 18} },
    { {129, 3, 5, 18}, {5, 110, 10, 18} },
    { {170, 3, 3, 8}, {3, 90, 9, 18} },
    { {90, 3, 5, 18}, {3, 90, 10, 18} },
    { {130, 1, 3, 18}, {1, 130, 10, 18} },
};

void setup() 
{
    myservo.attach(9);
    myservo.write(90);
    Serial.begin(9600);

    // wait for serial port to connect. Needed for Leonardo only
    while (!Serial) {
        ;
    }
}

void serialEvent() 
{
    while (Serial.available()) {
        serialData = (char) Serial.read();
        if (serialData == 'g') {
            animate = true;
        } else if (serialData == 'x') {
            animate = false;
        }
    }
}

void servo_move(pose pose_down, pose pose_up)
{
    byte val = 0;

    for (val = pose_down.from; val >= pose_down.to_boundary; val -= pose_down.step) {
        myservo.write(val);
        delay(pose_down.delay);
    }

    for (val = pose_up.from; val <= pose_up.to_boundary; val += pose_up.step) {
        myservo.write(val);
        delay(pose_up.delay);
    }
}

void loop() 
{
    if (animate) {
        if (count == 255) {
            count = 0;
        }

        pose_n = count % 5;

        servo_move(poses[pose_n][0], poses[pose_n][1]);

        count++;
    }
}
