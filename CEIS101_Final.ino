#define door 6
#define buzzer 9
#define photocell A0
#define light 20
#define trigPin 7
#define echoPin 8
#define Rled 4
#define Yled 3
#define Gled 2

void setup() {
    Serial.begin(9600);
    Serial.println("CEIS101 Course Final");
    Serial.println("Name: Michael Desormeaux");

    pinMode(door, INPUT_PULLUP);
    pinMode(buzzer, OUTPUT);
    pinMode(light, OUTPUT);
    pinMode(trigPin, OUTPUT); 
    pinMode(echoPin, INPUT); 
    pinMode(Rled, OUTPUT); 
    pinMode(Yled, OUTPUT); 
    pinMode(Gled, OUTPUT); 
}

void loop() {
    // Door Signal
    int doorValue = digitalRead(door);
    if (doorValue != 0) {
        tone(buzzer, 250);
    }

    // Automated Lights
    int lightValue = analogRead(photocell);
    Serial.println(lightValue);

    if (lightValue < 750) {
        digitalWrite(light, HIGH);

    }
    else {
        digitalWrite(light, LOW);
    }

    // Distance Sensor
    long dur, dis;
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);

    dur = pulseIn(echoPin, HIGH);
    dis = (dur / 2) * 0.0135;

    if (dis < 100) {
        if (dis <=25) { //Red Alert
            digitalWrite(Rled, HIGH);
            digitalWrite(Yled, LOW);
            digitalWrite(Gled, LOW);
            tone(buzzer, 1000);
        }
        else if (dis <=50 and dis > 25) { //Warning
            digitalWrite(Yled, HIGH);
            digitalWrite(Rled, LOW);
            digitalWrite(Gled, LOW);
            tone(buzzer, 500);
        }
        else { //Safe
            digitalWrite(Rled, LOW);
            digitalWrite(Yled, LOW);
            digitalWrite(Gled, HIGH);
        }
    }

    delay(500);
    noTone(buzzer);
}
