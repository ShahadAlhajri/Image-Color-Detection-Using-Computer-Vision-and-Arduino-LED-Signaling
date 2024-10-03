// Define the LED pins 
const int RED_LED_PIN = 13; 
const int GREEN_LED_PIN = 12; 
const int BLUE_LED_PIN = 11; 
const int YELLOW_LED_PIN = 10; 

void setup() { 

    // Initialize serial communication at 9600 baud rate 
    Serial.begin(9600); 

    // Initialize LED pins as outputs 
    pinMode(RED_LED_PIN, OUTPUT); 
    pinMode(GREEN_LED_PIN, OUTPUT); 
    pinMode(BLUE_LED_PIN, OUTPUT); 
    pinMode(YELLOW_LED_PIN, OUTPUT); 
} 

void loop() { 

    // Check if data is available to read 
    if (Serial.available() > 0) { 
        // Read the incoming character 
        char receivedChar = Serial.read(); 
        // Control LEDs based on the received character 
        switch(receivedChar) { 

            case 'R': 
                digitalWrite(RED_LED_PIN, HIGH); 
                break; 
            case 'G': 
                digitalWrite(GREEN_LED_PIN, HIGH); 
                break; 
            case 'B': 
                digitalWrite(BLUE_LED_PIN, HIGH); 
                break; 
            case 'Y': 
                digitalWrite(YELLOW_LED_PIN, HIGH); 
                break; 

        } 
    } 
}