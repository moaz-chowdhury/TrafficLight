const int redPin = 9;
const int yellowPin = 10;
const int greenPin = 11;

enum TrafficState { RED, YELLOW, GREEN };
TrafficState currentState = RED;
bool afterGreen = false;  // Flag to track transition

void setup() {
    pinMode(redPin, OUTPUT);
    pinMode(yellowPin, OUTPUT);
    pinMode(greenPin, OUTPUT);
    currentState = RED;
    digitalWrite(redPin, HIGH); // Start with Red light
}

void loop() {
    switch (currentState) {
        case RED:
            digitalWrite(redPin, HIGH);
            delay(20000); // Stay Red for 20 seconds
            digitalWrite(redPin, LOW);
            currentState = YELLOW;
            afterGreen = false; // Reset flag
            break;

        case YELLOW:
            digitalWrite(yellowPin, HIGH);
            delay(5000); // Stay Yellow for 5 seconds
            digitalWrite(yellowPin, LOW);
            // Transition based on the afterGreen flag
            if (afterGreen) {
                currentState = RED;  // Go back to Red after Green
            } else {
                currentState = GREEN; // Go to Green after Red
                afterGreen = true;    // Set flag for next Yellow transition
            }
            break;

        case GREEN:
            digitalWrite(greenPin, HIGH);
            delay(20000); // Stay Green for 20 seconds
            digitalWrite(greenPin, LOW);
            currentState = YELLOW; // Transition to Yellow
            break;
    }
}
