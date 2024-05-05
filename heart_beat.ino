/*
  Fade

  This example shows how to fade an LED on pin 9 using the analogWrite()
  function.

  The analogWrite() function uses PWM, so if you want to change the pin you're
  using, be sure to use another PWM capable pin. On most Arduino, the PWM pins
  are identified with a "~" sign, like ~3, ~5, ~6, ~9, ~10 and ~11.

  This example code is in the public domain.

  https://www.arduino.cc/en/Tutorial/BuiltInExamples/Fade
*/

int led_1[3] = {11, 10, 9};       // the PWM pin the LED is attached to (R, G, B)
int led_2[3] = {3, 5, 6};         // the PWM pin the LED is attached to (R, G, B)


int color[3] = {255, 10, 20};

// float brightness_pulse[] = {0.0, 0.1, 0.2, 0.4, 0.6, 0.4, 0.2, 0.4, 0.8, 0.9, 0.8, 0.4, 0.2, 0.1, 0.0, 0.0};
float brightness_pulse[] = {0.4, 0.8, 1.0, 1.0, 0.8, 0.4, 0.6, 0.8, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 0.8, 0.6, 0.5, 0.4, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0};
int num_time_steps = sizeof(brightness_pulse) / sizeof(brightness_pulse[0]);

float heart_rate_schedule_bpm[] = {60, 60, 60, 60, 80, 80, 80, 80, 100, 100, 100, 100};
int num_heart_beats = sizeof(heart_rate_schedule_bpm) / sizeof(heart_rate_schedule_bpm[0]);
int beat_index = 0;

int t_global = 0;

// the setup routine runs once when you press reset:
void setup() {
  Serial.begin(9600); // open the serial port at 9600 bps:

  // declare pin 9 to be an output:
  for (int i = 0; i < 3; ++i) {
    pinMode(led_1[i], OUTPUT);
    pinMode(led_2[i], OUTPUT);
  }
}

void single_heart_beat() {
  Serial.println("Taking a beat!");
  int brightness = 0;
  int t;

  for (t = 0; t < num_time_steps; ++t) {
    // set the brightness of LED pins:
    brightness = brightness_pulse[t % num_time_steps];
    Serial.println("Updating brightness!");
    for (int i = 0; i < 3; ++i) {
      analogWrite(led_1[i], brightness * color[i]);
      analogWrite(led_2[i], brightness * color[i]);
    }

    // change the brightness for next time through the loop:
    t++;

    // wait for 30 milliseconds to see the dimming effect
    delay(30);
  }

  return t;
}

// the loop routine runs over and over again forever:
void loop() {
  single_heart_beat();
  float bpm = heart_rate_schedule_bpm[beat_index % num_heart_beats];
  float minutes_per_beat = 1.0 / bpm;
  float seconds_per_beat = 60 * minutes_per_beat;
  beat_index++;
  delay(seconds_per_beat * 1000);
}
