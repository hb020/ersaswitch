
/* #define TEST */


#ifndef TEST

//arduino digitalRead/Write pins:
//0 = PA4 (chip pin 2)
//1 = PA5 (chip pin 3)
//2 = PA6 (chip pin 4)
//3 = PA7 (chip pin 5)
//4 = PB3 (chip pin 6)
//5 = PB2 (chip pin 7)
//6 = PB1 (chip pin 8)
//7 = PB0 (chip pin 9)
//8 = PA1 (chip pin 11)
//9 = PA2 (chip pin 12)
//10 = PA3 (chip pin 13)

#define REL1 8
#define REL2 9
#define LED_1_R 2
#define LED_1_G 3
#define LED_2_R 0
#define LED_2_G 1
#define SWITCH 10

enum mystates {
  out1 = 0,
  goingto2_1,
  goingto2_2,
  out2,
  goingto1_1,
  goingto1_2
};

void setState(int state) {
  switch(state) {
    case out1:
      digitalWrite(REL1, LOW);
      digitalWrite(REL2, LOW);

      digitalWrite(LED_1_R, LOW);
      digitalWrite(LED_2_R, HIGH);
      digitalWrite(LED_1_G, HIGH);
      digitalWrite(LED_2_G, HIGH);
      break;      
    case goingto2_1:
      digitalWrite(REL1, LOW);
      digitalWrite(REL2, HIGH);

      digitalWrite(LED_1_R, LOW);
      digitalWrite(LED_2_R, HIGH);
      digitalWrite(LED_1_G, LOW);
      digitalWrite(LED_2_G, LOW);
      break;
    case goingto2_2:
      digitalWrite(REL1, HIGH);
      digitalWrite(REL2, HIGH);

      digitalWrite(LED_1_R, HIGH);
      digitalWrite(LED_2_R, LOW);
      digitalWrite(LED_1_G, LOW);
      digitalWrite(LED_2_G, LOW);
      break;
    case out2:
      digitalWrite(REL1, HIGH);
      digitalWrite(REL2, LOW);

      digitalWrite(LED_1_R, HIGH);
      digitalWrite(LED_2_R, LOW);
      digitalWrite(LED_1_G, HIGH);
      digitalWrite(LED_2_G, HIGH);
      break;
    case goingto1_1:
      digitalWrite(REL1, HIGH);
      digitalWrite(REL2, HIGH);

      digitalWrite(LED_1_R, HIGH);
      digitalWrite(LED_2_R, LOW);
      digitalWrite(LED_1_G, LOW);
      digitalWrite(LED_2_G, LOW);
      break;
    case goingto1_2:
      digitalWrite(REL1, LOW);
      digitalWrite(REL2, HIGH);

      digitalWrite(LED_1_R, LOW);
      digitalWrite(LED_2_R, HIGH);
      digitalWrite(LED_1_G, LOW);
      digitalWrite(LED_2_G, LOW);
      break;
  }
}

// The minimum time relays take to switch over. I am not allowed to switch the 2 at the same time.
#define RELAY_MIN_SWITCH_TIME_MSECS 100L

// The minimum time the ersa controller must see no tool connected to detect "No Tool" (the above will be added)
#define TOOL_SWITCH_TIME_MSECS 2000L

unsigned long getStateMaxTime_msec(int state) {
  switch(state) {
    case out1:
      return 0;  
    case goingto2_1:
      return RELAY_MIN_SWITCH_TIME_MSECS;
    case goingto2_2:
      return TOOL_SWITCH_TIME_MSECS;
    case out2:
      return 0;
    case goingto1_1:
      return TOOL_SWITCH_TIME_MSECS;
    case goingto1_2:
      return RELAY_MIN_SWITCH_TIME_MSECS;
  }
}

int mystate = out1;
unsigned long lastStateStartTime = 0;  // the last time state changed

void stateMaintenance() {
  unsigned long shouldWait = 0;
  bool shouldMoveOn = false;

  shouldWait = getStateMaxTime_msec(mystate);
  if (shouldWait == 0) {
    shouldMoveOn = switchGotPushed();
  }
  else {
    if ((millis() - lastStateStartTime) > shouldWait) {
      shouldMoveOn = true;
    }
  }

  if (shouldMoveOn) {
    lastStateStartTime = millis();
    mystate += 1;
    if (mystate > goingto1_2) {
      mystate = out1;
    }
  }
  setState(mystate);
}


// Variables will change:
int debouncedButtonState = LOW;  // the debounced reading from the input pin
int lastButtonState = LOW;   // the previous reading from the input pin

// the following variables are unsigned longs because the time, measured in
// milliseconds, will quickly become a bigger number than can be stored in an int.
unsigned long lastDebounceTime = 0;  // the last time the input pin was toggled
#define debounceDelay 50L    // the debounce time; increase if the output flickers


bool switchGotPushed() {
  bool justGotPushed = false;
  // read the state of the switch into a local variable:
  int reading = digitalRead(SWITCH);

  // check to see if you just pressed the button
  // (i.e. the input went from LOW to HIGH), and you've waited long enough
  // since the last press to ignore any noise:

  // If the switch changed, due to noise or pressing:
  if (reading != lastButtonState) {
    // reset the debouncing timer
    lastDebounceTime = millis();
  }

  // save the reading. Next time through the loop, it'll be the lastButtonState:
  lastButtonState = reading;
  
  if ((millis() - lastDebounceTime) > debounceDelay) {
    // whatever the reading is at, it's been there for longer than the debounce
    // delay, so take it as the actual current state:

    // if the button state has changed:
    if (reading != debouncedButtonState) {
      debouncedButtonState = reading;

      if (debouncedButtonState == HIGH) {
        justGotPushed = true;
      }
    }
  }

  return justGotPushed;
}

void setup() {
  
  digitalWrite(REL1, LOW);
  pinMode(REL1,OUTPUT);
  digitalWrite(REL1, LOW);
  
  digitalWrite(REL2, LOW);
  pinMode(REL2,OUTPUT);
  digitalWrite(REL2, LOW);

  digitalWrite(LED_1_R, HIGH);
  pinMode(LED_1_R,OUTPUT);
  digitalWrite(LED_1_R, HIGH);

  digitalWrite(LED_1_G, HIGH);
  pinMode(LED_1_G,OUTPUT);
  digitalWrite(LED_1_G, HIGH);

  digitalWrite(LED_2_R, HIGH);
  pinMode(LED_2_R,OUTPUT);
  digitalWrite(LED_2_R, HIGH);

  digitalWrite(LED_2_G, HIGH);
  pinMode(LED_2_G,OUTPUT);
  digitalWrite(LED_2_G, HIGH);

  pinMode(SWITCH,INPUT);
  
}

void loop() {

  stateMaintenance();
  
}


#else

#define MYPIN 1

int loopnr;

int offset = 0;
int maxnr = 11;

void setup() {
  for (int i = 0; i < maxnr; i++) {
    pinMode(i+offset,OUTPUT);
    digitalWrite(i+offset, HIGH);
  }
  loopnr = 0;
}


void loop() {
  loopnr += 1;
  for (int i = 0; i < maxnr; i++) {
    if (loopnr % (i+1) == 0) {
      int x = loopnr / (i+1);
      if (x & 1) {
        digitalWrite(i+offset, HIGH);
      } else {
        digitalWrite(i+offset, LOW);        
      }
    }
  }
  delay(100);
}

#endif
