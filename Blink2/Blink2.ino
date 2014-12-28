
#define DELAY 200
#define MIN_DELAY 50
#define PIN_IN 2

int leds[] = {3, 5, 6, 9, 10};
int no_leds = 5;

void setup() {
    int i;
    for (i=0; i<no_leds;i++) {
        pinMode(leds[i], OUTPUT);
    }
    pinMode(PIN_IN, INPUT);
}

int oldpin = -1;

void moveto(int pin) {
    digitalWrite(pin, HIGH);
    if (oldpin!=-1) {
        digitalWrite(oldpin, LOW);
    }
    oldpin = pin;
}

void loop() {
    int i;
    int d;
    for (i=0; i<no_leds;i++) {
        moveto(leds[i]);
        if (digitalRead(PIN_IN) == HIGH) {
            d = MIN_DELAY;
        } else {
            d = DELAY;
        }
        delay(d);
    }

    for (i=no_leds-2; i>0;i--) {
        moveto(leds[i]);
        if (digitalRead(PIN_IN) == HIGH) {
            d = MIN_DELAY;
        } else {
            d = DELAY;
        }
        delay(d);
    }
}
