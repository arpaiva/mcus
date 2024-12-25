const int motor1_pin1 = 2;
const int motor1_pin2 = 3;
const int motor1_pwm = 9;

const int motor2_pin1 = 4;
const int motor2_pin2 = 5;
const int motor2_pwm = 10;

void setup() {
  // put your setup code here, to run once:
  pinMode(motor1_pin1, OUTPUT);
  pinMode(motor1_pin2, OUTPUT);
  pinMode(motor1_pwm, OUTPUT);

  pinMode(motor2_pin1, OUTPUT);
  pinMode(motor2_pin2, OUTPUT);
  pinMode(motor2_pwm, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

  analogWrite(motor1_pwm, 64);  // first motor at a quarter speed
  analogWrite(motor2_pwm, 255);  // second motor at full speed
  
  digitalWrite(motor1_pin1, HIGH);
  digitalWrite(motor1_pin2, LOW);
  digitalWrite(motor2_pin1, HIGH);
  digitalWrite(motor2_pin2, LOW);
  delay(1000);

  digitalWrite(motor1_pin1, LOW);
  digitalWrite(motor1_pin2, HIGH);
  digitalWrite(motor2_pin1, LOW);
  digitalWrite(motor2_pin2, HIGH);
  delay(1000);
}
