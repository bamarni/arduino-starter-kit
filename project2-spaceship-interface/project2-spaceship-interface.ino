const int switchState = 0;
const int SWITCH = 2;
const int GREEN_LED = 3;
const int RED_LED1 = 4;
const int RED_LED2 = 5;
const int DELAY_LENGTH = 250;

void setup() {
	pinMode(SWITCH, INPUT);
	pinMode(GREEN_LED, OUTPUT);
	pinMode(RED_LED1, OUTPUT);
	pinMode(RED_LED2, OUTPUT);
}

void loop() {
	switchState = digitalRead(SWITCH);

	if (switchState == LOW) {
		systemReady();
	} else {
		engageHyperdrive();
	}
}

void systemReady() {
	digitalWrite(GREEN_LED, HIGH);
	digitalWrite(RED_LED1, LOW);
	digitalWrite(RED_LED2, LOW);
}

void engageHyperdrive() {
	digitalWrite(GREEN_LED, LOW);
	digitalWrite(RED_LED1, LOW);
	digitalWrite(RED_LED2, HIGH);

	delay(DELAY_LENGTH);
	digitalWrite(RED_LED1, HIGH);
	digitalWrite(RED_LED2, LOW);
	delay(DELAY_LENGTH);	
}
