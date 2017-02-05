  // Define output pins
  #define LATCH_PIN_HOUR 2
  #define DATA_PIN_HOUR 3
  #define CLK_PIN_HOUR 4
  #define LATCH_PIN_MIN 2
  #define DATA_PIN_MIN 3
  #define CLK_PIN_MIN 4
  #define LATCH_PIN_SEC 2
  #define DATA_PIN_SEC 3
  #define CLK_PIN_SEC 4

  // Set up Chars for shift register
  int charTable[] = {0,1,2,3,4,5,6,7,8,9,16,17,18,19,20,21,22,23,24,25,32,33,34,35,36,37,38,39,40,41,48,49,50,51,52,53,54,55,56,57,64,65,66,67,68,69,70,71,72,73,80,81,82,83,84,85,86,87,88,89};
  int hour =22; // Change to zero when done!!
  int min = 58; // Change to zero when done!!
  int sec = 58; // Change to zero when done!!
  char nixieHour = 255;
  char nixieMin = 255;
  char nixieSec = 255;
  
void setup() {
  Serial.begin(9600);
  Serial.println("Set pintmode to OUTPUT");
  pinMode(LATCH_PIN_HOUR, OUTPUT);
  pinMode(DATA_PIN_HOUR, OUTPUT);  
  pinMode(CLK_PIN_HOUR, OUTPUT);
  pinMode(LATCH_PIN_MIN, OUTPUT);
  pinMode(DATA_PIN_MIN, OUTPUT);  
  pinMode(CLK_PIN_MIN, OUTPUT);
  pinMode(LATCH_PIN_SEC, OUTPUT);
  pinMode(DATA_PIN_SEC, OUTPUT);  
  pinMode(CLK_PIN_SEC, OUTPUT);

  // Read Clock and set 
}

void loop() {

// Hour loop
  while (hour < 24) {

    // Minute loop
    while (min < 60) {

      // Second loop
      while (sec < 60) {
        Serial.print("Time in digital form: ");
        Serial.print(hour);
        Serial.print(":");
        Serial.print(min);
        Serial.print(":");
        Serial.println(sec);

        nixieHour = charTable[hour];
        nixieMin = charTable[min];
        nixieSec = charTable[sec];

        delay(1000);
        sec++;
        updateSecRegister();
      }
      sec = 55; // Change to zero when done!!
      min++;
      updateMinRegister();
    }
    min = 57; // Change to zero when done!!
    hour++;
    updateHourRegister();
  }

hour = 22; // Change to zero when done!!
min = 57; // Change to zero when done!!
sec = 55; // Change to zero when done!!
// End Main loop
}


// Shift Hour
void updateHourRegister(){
  digitalWrite(LATCH_PIN_HOUR, LOW);
  shiftOut(DATA_PIN_HOUR, CLK_PIN_HOUR, LSBFIRST, nixieHour);
  digitalWrite(LATCH_PIN_HOUR, HIGH);
  Serial.println("Hours register updated");
}

// Shift Minute
void updateMinRegister(){
  digitalWrite(LATCH_PIN_MIN, LOW);
  shiftOut(DATA_PIN_MIN, CLK_PIN_MIN, LSBFIRST, nixieMin);
  digitalWrite(LATCH_PIN_MIN, HIGH);
  Serial.println("Minutes register updated");
}

// Shift Second
void updateSecRegister(){
  digitalWrite(LATCH_PIN_SEC, LOW);
  shiftOut(DATA_PIN_SEC, CLK_PIN_SEC, LSBFIRST, nixieSec);
  digitalWrite(LATCH_PIN_SEC, HIGH);
  Serial.println("Seconds register updated");
}

