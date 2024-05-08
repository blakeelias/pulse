/*  PulseSensor Starter Project and Signal Tester
 *  The Best Way to Get Started  With, or See the Raw Signal of, your PulseSensor.com™ & Arduino.
 *
 *  Here is a link to the tutorial (including wiring diagram for connecting pulse sensor to Arduino)
 *  https://pulsesensor.com/pages/code-and-guide
 *
 *  WATCH ME (Tutorial Video):
 *  https://www.youtube.com/watch?v=RbB8NSRa5X4
 *
 *
-------------------------------------------------------------
1) This shows a live human Heartbeat Pulse.
2) Live visualization in Arduino's Cool "Serial Plotter".
3) Blink an LED on each Heartbeat.
4) This is the direct Pulse Sensor's Signal.
5) A great first-step in troubleshooting your circuit and connections.
6) "Human-readable" code that is newbie friendly."

*/


// LED setup:
// PWM pins for LED digital output (R, G, B)
int led_1[3] = {11, 10, 9};
int led_2[3] = {3, 5, 6};
// Color to display:
int color[3] = {255, 10, 20};
float brightness;

//  Pulse Sensor Configuration
int pulse_sensor_input_pin = 0;      // Pulse Sensor PURPLE WIRE connected to ANALOG PIN 0
int pulse_sensor_signal;                // holds the incoming raw data. Signal value can range from 0-1024
int pulse_sensor_threshold = 580;       // Determine which Signal to "count as a beat", and which to ingore.


// Keep track of time
int t = 0;


// the setup routine runs once when you press reset:
void setup() {
  // declare LED pins to be outputs:
  for (int i = 0; i < 3; ++i) {
    pinMode(led_1[i], OUTPUT);
    pinMode(led_2[i], OUTPUT);
  }
}

// the loop routine runs over and over again forever:
void loop() {
  pulse_sensor_signal = analogRead(pulse_sensor_input_pin);  // Read the PulseSensor's value
  Serial.println("Signal " + String(pulse_sensor_signal)); // Send "reading " followed by the Signal value to Serial Plotter (open with "Tools -> Serial Plotter" to see graph during live demo)

  // set the brightness of LED pins:
  brightness = (pulse_sensor_signal > pulse_sensor_threshold) ? 1.0 : 0.0;
  for (int i = 0; i < 3; ++i) {
    analogWrite(led_1[i], brightness * color[i]);
    analogWrite(led_2[i], brightness * color[i]);
  }

  // Keep track of time
  t++;

  // wait for 10 milliseconds to see the dimming effect
  delay(10);
}
