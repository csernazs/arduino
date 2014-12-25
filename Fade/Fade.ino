
int leds[] = {3, 5, 6, 9, 10};
int no_leds = 5;


void setup() {
    int i;
    for (i=0; i<no_leds;i++) {
        pinMode(leds[i], OUTPUT);
    }
}

#define STEP 1
#define MIN 10
#define MAX 150
#define DELAY 10

void update(int brightness, int modulo) {
    int i;
    int cbrightness;

    for (i=0; i<no_leds;i++) {
        if (i%2 == modulo) {
            cbrightness = MAX-brightness;
        } else {
            cbrightness = brightness;
        }
        analogWrite(leds[i], cbrightness); 
    }
}
void loop() {
    int i;
    for (i=MIN; i<=MAX; i++) {
        update(i, 0);
        delay(DELAY);
    }
    for (i=MIN; i<=MAX; i++) {
        update(i, 1);
        delay(DELAY);
    }
}
