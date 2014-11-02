const long MIN_TO_COUNT_UP_TO = 60;
const int TILT_SWITCH_PIN = 8;
const long INTERVAL = MIN_TO_COUNT_UP_TO * 10000; 
const int LOW_LED = 2;
const int HIGH_LED = 7;

unsigned long previousTime = 0;
int switchState = 0;
int prevSwitchState = 0;

int currentLED = LOW_LED;

void setup() {
    for (int led = LOW_LED; led <= HIGH_LED; led++) {
        pinMode(led, OUTPUT);
    }

    pinMode(TILT_SWITCH_PIN, INPUT);
}

void loop() {

    // get time since program started
    unsigned long currentTime = millis();

    // write a new led if enough time has passed
    if (currentTime - previousTime > INTERVAL) {
        previousTime = currentTime;
        digitalWrite(currentLED, HIGH);
        currentLED++;
    }   

    switchState = digitalRead(TILT_SWITCH_PIN);

    // if the tilt switch changes
    if (switchState != prevSwitchState) {
        resetLEDs(currentTime);
    }
    
    prevSwitchState = switchState;
}

void resetLEDs(unsigned long currentTime) {
    for (int led = LOW_LED; led <= HIGH_LED; led++) {
        digitalWrite(led, LOW);
    }

    currentLED = LOW_LED;
    previousTime = currentTime; 
}
