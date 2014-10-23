const int RED_LED_PIN = 11;
const int GREEN_LED_PIN =  9;
const int BLUE_LED_PIN = 10;

const int RED_SENSOR_PIN = A0;
const int GREEN_SENSOR_PIN = A1;
const int BLUE_SENSOR_PIN = A2;

const int BAUD_RATE = 9600;
const int ANALOG_READ_DELAY = 5;
const int SENSOR_TO_DUTY_CYCLE = 4;

int redValue = 0;
int greenValue = 0;
int blueValue = 0;

int redSensorValue = 0;
int greenSensorValue = 0;
int blueSensorValue = 0;

void setup() {
	Serial.begin(BAUD_RATE);

	pinMode(RED_LED_PIN, OUTPUT);
	pinMode(GREEN_LED_PIN, OUTPUT);
	pinMode(BLUE_LED_PIN, OUTPUT);
}

void loop() {
	readSensorValues();	
	printSensorValues();
	calculateDutyCycles();
	printDutyCycles();
	writeDutyCycles();
}

void readSensorValues() {
	redSensorValue = analogRead(RED_SENSOR_PIN);
	delay(ANALOG_READ_DELAY);
	greenSensorValue = analogRead(GREEN_SENSOR_PIN);
	delay(ANALOG_READ_DELAY);
	blueSensorValue = analogRead(BLUE_SENSOR_PIN);
}

void printSensorValues() {
	Serial.print("Raw Sensor Values \t Red: ");
	Serial.print(redSensorValue);
	Serial.print("\t Green: ");
	Serial.print(greenSensorValue);
	Serial.print("\t Blue: ");
	Serial.println(blueSensorValue);
}

void calculateDutyCycles() {
	redValue = redSensorValue / SENSOR_TO_DUTY_CYCLE;
	blueValue = blueSensorValue / SENSOR_TO_DUTY_CYCLE;
	greenValue = greenSensorValue / SENSOR_TO_DUTY_CYCLE;
}

void printDutyCycles() {
	Serial.print("Mapped Sensor Values \t Red: ");
	Serial.print(redValue);
	Serial.print("\t Green: ");
	Serial.print(greenValue);
	Serial.print("\t Blue: ");
	Serial.println(blueValue);
}

void writeDutyCycles() {
	analogWrite(RED_LED_PIN, redValue);
	analogWrite(GREEN_LED_PIN, greenValue);
	analogWrite(BLUE_LED_PIN, blueValue);
}