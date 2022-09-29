
// this fucking thing runs once:
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); // opens a serial port to the computer
}

// this fucking thing runs over and over and over:
void loop() {
  // put your main code here, to run repeatedly:
  int a = analogRead(A0); // read pin 2 and stash it in 'a'
  int b = !digitalRead(2); // read pin 2 and stash it in 'a'
  int c = !digitalRead(3); // read pin 2 and stash it in 'a'
  int d = analogRead(A1); // read pin 2 and stash it in 'a'
  Serial.print(a); // print that out
  Serial.print(" "); // space
  Serial.print(b); // print that out
  Serial.print(" "); // space
  Serial.print(c); // print that out
  Serial.print(" "); // space
  Serial.println(d); // print that out
}
