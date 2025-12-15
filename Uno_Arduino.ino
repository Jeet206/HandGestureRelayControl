#define LED 7  // Connected to IN1
#define BUZZER 8  // Connected to IN2

void setup() {
    Serial.begin(9600);  // Start Serial Communication
    pinMode(LED, OUTPUT);
    pinMode(BUZZER, OUTPUT);
    digitalWrite(LED, LOW);  // Start with relays OFF
    digitalWrite(BUZZER, LOW);
}

void loop() {
    if (Serial.available()) {
        char command = Serial.read();  // Read data from Serial
        
        if (command == '3') {
            digitalWrite(LED, HIGH);  // Relay 1 ON
            digitalWrite(BUZZER, LOW);  // Relay 2 ON
        }
        else if (command == '2') {
            digitalWrite(LED, LOW); // Relay 1 OFF
            digitalWrite(BUZZER, LOW);  // Relay 2 ON
        }
        else if (command == '1') {
            digitalWrite(LED, HIGH);  // Relay 1 ON
            digitalWrite(BUZZER, LOW); // Relay 2 OFF
        }
        else if (command == '0') {
            digitalWrite(LED, LOW); // Relay 1 OFF
            digitalWrite(BUZZER, LOW); // Relay 2 OFF
        }
    }
}
