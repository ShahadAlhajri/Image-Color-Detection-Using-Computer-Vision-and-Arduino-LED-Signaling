char receivedChar; 
bool newData = false;

// Define the LED pins 
const int RED_LED_PIN = 13; 
const int GREEN_LED_PIN = 12; 
const int BLUE_LED_PIN = 11; 
const int YELLOW_LED_PIN = 10; 

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); 
  pinMode(RED_LED_PIN, OUTPUT); 
  pinMode(GREEN_LED_PIN, OUTPUT); 
  pinMode(BLUE_LED_PIN, OUTPUT); 
  pinMode(YELLOW_LED_PIN, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  recvWithEndMarker();
  showNewData(); 

}

void recvWithEndMarker() { 
  static byte ndx = 0; 
  char endMarker = '\n'; 
  char rc;

  while (Serial.available() > 0 && newData == false) { 
      rc = Serial.read(); 

      if (rc != endMarker) { 
          receivedChar = rc; 
          ndx++; 
      } else { 
          ndx = 0; 
          newData = true; 
      }  
   } 
} 
        
void showNewData() { 
    if (newData == true) { 
        Serial.print("Received char: ");
        Serial.print(receivedChar);
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
          newData = false; 
     } 
}
