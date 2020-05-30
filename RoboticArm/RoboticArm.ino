#include <Servo.h>

Servo pivotServo;
Servo shoulderServo;
Servo elbowServo;

void setup() {
    pivotServo.attach(8);
    shoulderServo.attach(9);
    elbowServo.attach(10);
}

void loop() {
    Serial.begin(9600); 
    int pivotInput = analogRead(0);
    int shoulderInput = analogRead(1);
    int elbowInput = analogRead(2);

    int pivotOutput = map(pivotInput, 0, 1023, 0, 180);
    int shoulderOutput = map(shoulderInput, 0, 1023, 0, 180);
    int elbowOutput = map(elbowInput, 0, 1023, 0, 180);

    Serial.println(pivotInput);

    pivotServo.write(pivotOutput);
    shoulderServo.write(shoulderOutput);
    elbowServo.write(elbowOutput);

    delay(50);

}
