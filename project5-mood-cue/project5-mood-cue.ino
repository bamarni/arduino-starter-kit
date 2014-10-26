#include <Servo.h>

Servo servo;
int const POT_PIN = A0;
int const BAUD_RATE = 9600;
int const POT_MAX = 1023;
int const SERVO_MAX = 179;
int const LOOP_DELAY = 15;
int potVal; // value retrieved from potentiometer
int servoAngle; // angle to position to servo

void setup() {
	servo.attach(9);
	Serial.begin(BAUD_RATE);
}

void loop() {
	changeServoAngle();
	delay(LOOP_DELAY);
}

// sets servo position to a position mapped to the potentiometer value
void changeServoAngle() {
	potVal = analogRead(POT_PIN);

	// map() scales number. this call scales potVal from 0 to 1023 to a 
	// number between 0 and 179
	servoAngle = map(potVal, 0 , POT_MAX, 0 , SERVO_MAX);

	servo.write(servoAngle);

	printToSerialMonitor(potVal, servoAngle);
}

void printToSerialMonitor(int potVal, int servoAngle) {
	Serial.print("potVal: ");
	Serial.print(potVal);
	Serial.print(", servoAngle: ");
	Serial.println(servoAngle);
}