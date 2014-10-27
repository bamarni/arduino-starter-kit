const int LED_PIN = 13; // on board LED, indicates that arduino is calibrating
const int CALIBRATION_TIME = 5000;
const int SENSOR_PIN = A0;
const int FREQUENCY_LOW = 50;
const int FREQUENCY_HIGH = 4000;
const int PIEZO_PIN = 8;
const int NOTE_LENGTH = 20;
const int LOOP_DELAY = 10;

int sensorValue;
int sensorLow = 1023; // to be calibrated
int sensorHigh = 0; // to be calibrated

void setup() {
	pinMode(LED_PIN, OUTPUT);
	calibrateSensor();
}

void calibrateSensor() {
	digitalWrite(LED_PIN, HIGH);
	while (millis() < CALIBRATION_TIME) {
		// update minimum and maximum sensor values
		sensorValue = analogRead(SENSOR_PIN);
		sensorHigh = sensorValue > sensorHigh ? sensorValue : sensorHigh;
		sensorLow = sensorValue < sensorLow ? sensorValue : sensorLow;
	}	
	digitalWrite(LED_PIN, LOW);	
}

void loop() {
	sensorValue = analogRead(SENSOR_PIN);
	int pitch = map(sensorValue, sensorLow, sensorHigh, FREQUENCY_LOW, 
					FREQUENCY_HIGH);
	tone(PIEZO_PIN, pitch, NOTE_LENGTH);
	delay(LOOP_DELAY);
}