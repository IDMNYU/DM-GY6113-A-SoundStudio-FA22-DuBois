
// this fucking thing runs once:
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); // opens a serial port to the computer
}

// this fucking thing runs over and over and over:
void loop() {
  // put your main code here, to run repeatedly:
  int a = analogRead(A0); // read pin A0 and stash it in 'a'
  Serial.println(a); // print that out
}
