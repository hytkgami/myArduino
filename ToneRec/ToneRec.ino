#define WHITE_PIN 13
#define BLACK_PIN 11
#define RED_PIN 10
#define BLUE_PIN 8
#define YELLOW_PIN 6
#define RED_PIN2 4
#define GREEN_PIN 2
#define OCTAVE_PIN 7
#define HALF_PIN 12
#define OCT_PIN 3

int blackbtn = 0;
int whitebtn = 0;
int redbtn = 0;
int redbtn2 = 0;
int yellowbtn = 0;
int bluebtn = 0;
int greenbtn = 0;
int octave = 0;
int octbtn = 0;
int halfbtn = 0;

void setup() {
  Serial.begin(19200);
  Serial.flush();
  pinMode(RED_PIN, INPUT);
  pinMode(RED_PIN2, INPUT);
  pinMode(YELLOW_PIN, INPUT);
  pinMode(BLUE_PIN, INPUT);
  pinMode(GREEN_PIN, INPUT);
  pinMode(BLACK_PIN, INPUT);
  pinMode(WHITE_PIN, INPUT);
  pinMode(OCTAVE_PIN, INPUT);
  pinMode(HALF_PIN, INPUT);
  pinMode(OCT_PIN, INPUT);
}

void loop() {
  octave = digitalRead(OCTAVE_PIN);
  redbtn = digitalRead(RED_PIN);
  redbtn2 = digitalRead(RED_PIN2);
  yellowbtn = digitalRead(YELLOW_PIN);
  bluebtn = digitalRead(BLUE_PIN);
  greenbtn = digitalRead(GREEN_PIN);
  blackbtn = digitalRead(BLACK_PIN);
  whitebtn = digitalRead(WHITE_PIN);
  octbtn = digitalRead(OCT_PIN);
  halfbtn = digitalRead(HALF_PIN);

  int num = octave*7;
  
  if (redbtn == HIGH) {
    Serial.write(1 + num);
  } else if (bluebtn == HIGH) {
    Serial.write(2 + num);
  } else if (yellowbtn == HIGH) {
    Serial.write(3 + num);
  } else if (redbtn2 == HIGH) {
    Serial.write(4 + num);
  } else if (greenbtn == HIGH) {
    Serial.write(5 + num);
  } else if (blackbtn == HIGH) {
    Serial.write(6 + num);
  } else if (whitebtn == HIGH) {
    Serial.write(7 + num);
  } else if (octbtn == HIGH) {
    Serial.write(8 + num);
  } else {
    Serial.write(0);
  }
  delay(100);
}

