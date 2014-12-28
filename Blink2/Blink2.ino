
int leds[] = {3, 5, 6, 9, 10};
int no_leds = 5;


void setup() {
    int i;
    for (i=0; i<no_leds;i++) {
        pinMode(leds[i], OUTPUT);
    }
}

#define DELAY 200

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
    d = DELAY;

    for (i=0; i<no_leds;i++) {
        moveto(leds[i]);
        delay(d);
    }

    for (i=no_leds-2; i>0;i--) {
        moveto(leds[i]);
        delay(d);
    }
}
