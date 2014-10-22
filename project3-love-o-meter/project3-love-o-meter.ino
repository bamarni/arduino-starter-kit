const int TEMP_SENSOR_PIN = A0;
const float BASELINE_TEMP = 23;
const int BAUD_RATE = 9600;
const int FIRST_LED_PIN = 2;
const int LAST_LED_PIN = 4;
const float VOLTAGE_CONVERSION = 5.0/1024.0;
const int TEMPERATURE_OFFSET_PER_LED = 2;

void setup() {
	// set up temperature sensor
	Serial.begin(BAUD_RATE);
	pinMode(TEMP_SENSOR_PIN, INPUT);

	// set up LEDs
	for (int ledPin = FIRST_LED_PIN; ledPin <= LAST_LED_PIN; ledPin++) {
		pinMode(ledPin, OUTPUT);
		digitalWrite(ledPin, LOW);
	}
}

// get data and calculate, light up LEDs
void loop() {
	int sensorVal = analogRead(TEMP_SENSOR_PIN);
	float voltage = sensorVal * VOLTAGE_CONVERSION;
	float temperature = convertVoltageToTemperature(voltage);
	printData(sensorVal, voltage, temperature);

	lightUpLEDsBasedOnTemperature(temperature);
	delay(1);
}

float convertVoltageToTemperature(float voltage) {
	return (voltage - .5) * 100;
}

void lightUpLEDsBasedOnTemperature(float temperature) {
	float difference = temperature - BASELINE_TEMP;
	int numberOfLEDsToLight = difference / TEMPERATURE_OFFSET_PER_LED;

	for (int ledPin = FIRST_LED_PIN; ledPin <= LAST_LED_PIN; ledPin++) {
		
		// turn on if it is numberOfLEDsToLight LEDs have not been lit up yet
		digitalWrite(ledPin, ledPin <= numberOfLEDsToLight ? HIGH : LOW);
	}
}

void printData(int sensorVal, float voltage, float temperature) {

	// indicate data type is String (Arduino string concatenation is weird)
	String statement = "Sensor Value: ";
	statement = statement + sensorVal + ", " + voltage + "V, " + temperature 
				+ " degrees C.";
	Serial.println(statement);
}