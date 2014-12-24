
int leds[] = {9, 10, 11};
int no_leds = 3;


void setup() {
    int i;
    for (i=0; i<no_leds;i++) {
        pinMode(leds[i], OUTPUT);
    }
}

#define STEP 1
#define MIN 10
#define MAX 150

void loop() {
    int i;
    int d;
    int step;
    
    d = MIN+STEP;
    step = STEP;
    while (1) {
        for (i=0; i<no_leds;i++) {
            if (i==0) {
               digitalWrite(leds[no_leds-1], LOW);
            } else {
               digitalWrite(leds[i-1], LOW);
            }
            digitalWrite(leds[i], HIGH);
            if (d>=MAX || d<=MIN) {
                step = 0-step;
            }
            d=d+step;
            delay(d);

        }
    }
}
