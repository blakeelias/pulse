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

int led_r = 11;         // the PWM pin the LED is attached to
int led_g = 10;         // the PWM pin the LED is attached to
int led_b = 9;         // the PWM pin the LED is attached to

int color[3] = {255, 10, 20};

// float brightness_pulse[] = {0.0, 0.1, 0.2, 0.4, 0.6, 0.4, 0.2, 0.4, 0.8, 0.9, 0.8, 0.4, 0.2, 0.1, 0.0, 0.0};
float brightness_pulse[] = {0.4, 0.8, 0.9, 1.0, 0.9, 0.8, 0.4, 0.6, 0.8, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 0.8, 0.6, 0.5, 0.4, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0};
int num_time_steps = sizeof(brightness_pulse) / sizeof(brightness_pulse[0]);

int brightness = 0;  // how bright the LED is
int fadeAmount = 5;  // how many points to fade the LED by

int t = 0;

// the setup routine runs once when you press reset:
void setup() {
  // declare pin 9 to be an output:
  pinMode(led_r, OUTPUT);
  pinMode(led_g, OUTPUT);
  pinMode(led_b, OUTPUT);
}

// the loop routine runs over and over again forever:
void loop() {
  // set the brightness of LED pins:
  brightness = brightness_pulse[t % num_time_steps];
  analogWrite(led_r, brightness * color[0]);
  analogWrite(led_g, brightness * color[1]);
  analogWrite(led_b, brightness * color[2]);

  // change the brightness for next time through the loop:
  t++;

  // wait for 30 milliseconds to see the dimming effect
  delay(30);
}
