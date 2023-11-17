#define r_pin 3
#define g_pin 5
#define b_pin 6

long r;
long g;
long b;

void setup() {
  pinMode(b_pin, OUTPUT);
  pinMode(r_pin, OUTPUT);
  pinMode(g_pin, OUTPUT);
  Serial.begin(9600);
  randomSeed(analogRead(0));
}

void rgbFlash(int rval, int gval, int bval, int rp, int gp, int bp) {
  analogWrite(rp, rval);
  analogWrite(gp, gval);
  analogWrite(bp, bval);

  // Print RGB values on the same line
  Serial.print(rval);
  Serial.print(", ");
  Serial.print(gval);
  Serial.print(", ");
  Serial.println(bval);
}

void loop() {
  // Generate random RGB values
  r = random(0, 225);
  g = random(0, 225);
  b = random(0, 225);

  // Flash RGB LED with random values
  rgbFlash(r, g, b, r_pin, g_pin, b_pin);

  delay(500);
}
