void setup() {
  // open the serial port:
  Serial.begin(9600);
  // initialize control over the keyboard:
}

void loop() {
  // check for incoming serial data:
  if (Serial.available() > 0) {
    // read incoming serial data:
    String inChar = Serial.readString();
    long number =stringToLong(inChar); //notice the function change to atoL
    // Type the next ASCII value from what you received:
    number++;
    Serial.println(number);
  }
}

long stringToLong(String value) {
  long outLong = 0;
  long inLong = 1;
  int c = 0;
  int idx = value.length() - 1;
  for (int i = 0; i <= idx; i++) {

    c = (int)value[idx - i];
    outLong += inLong * (c - 48);
    inLong *= 10;
  }
  return outLong;
}

