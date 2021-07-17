/*
* Blink with photoresistor (scaled with serial output)
*/
const int sensorPin = A0; // connect sensor to analog input 0

// low and high values for the sensor readings; you may need to adjust these
const int low = 200;
const int high = 800;

// The next two lines set the min and max delay between blinks.
const int minDuration = 100; // minimum wait between blinks
const int maxDuration = 2000; // maximum wait between blinks

void setup()
{
  pinMode(LED_BUILTIN, OUTPUT); // enable output on the LED pin
  Serial.begin(9600);           // initialize Serial
}

void loop()
{
  int delayval = analogRead(sensorPin); // read the analog input
  
  // the next line scales the delay value between the min and max values
  delayval = map(delayval, low, high, minDuration, maxDuration);
  delayval = constrain(delayval, minDuration, maxDuration);

  Serial.println(delayval);        //print delay value to serial monitor
  digitalWrite(LED_BUILTIN, HIGH); // set the LED on
  delay(delayval);                 // delay is dependent on light level
  digitalWrite(LED_BUILTIN, LOW);  // set the LED off
  delay(delayval);
}
