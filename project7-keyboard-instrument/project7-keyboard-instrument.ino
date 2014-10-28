const int BAUD_RATE = 9600;
const int INPUT_PIN = A0;
const int PIEZO_PIN = 8;
const int NOTES[] = {262, 294, 330, 349}; // Hz. C, D, E and F

void setup() {
	Serial.begin(BAUD_RATE);
}

void loop() {
	int keyVal = analogRead(INPUT_PIN);
	Serial.println(keyVal);

	if (keyVal == 1023) {
		tone(PIEZO_PIN, NOTES[0]);

	} else if (keyVal >= 990 && keyVal <= 1010) {
		tone(PIEZO_PIN, NOTES[1]);

	} else if (keyVal >= 505 && keyVal <= 515) {
		tone(PIEZO_PIN, NOTES[2]);

	} else if (keyVal >= 4 && keyVal <= 15) {
		tone(PIEZO_PIN, NOTES[3]);
		
	} else {
		noTone(PIEZO_PIN);
	}
}
