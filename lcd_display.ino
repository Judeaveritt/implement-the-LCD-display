/**
 * This lab repo contains code to display a DHT11 to a 16x2 LCD screen
 * First Last - Month Year
 */

#include <DHT.h>
#include <LiquidCrystal.h>

const int dhtPin = 2;
const int rs = 7;
const int en = 8;
const int d4 = 9;
const int d5 = 10;
const int d6 = 11;
const int d7 = 12;

const int pause = 5000;

// set up objects
DHT dht(dhtPin, DHT11);

LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

/**
 * @brief Converts a temperature from Celsius to Fahrenheit.
 *
 * @param tempC Temperature in Celsius
 * @return Temperature in Fahrenheit
 */
float celsiusToFahrenheit(float tempC) {
  //  Convert Celsius to Fahrenheit
  return tempC * 1.8 + 32;
}

void setup() {
  dht.begin();

  //initialize the 16x2 LCD
  lcd.begin(16,2);

  // Display a short welcome message
  lcd.print("Hello");
}

void loop() {
    float tempCelsius = dht.readTemperature();
    float humidity = dht.readHumidity();

    //  Convert the temperature to Fahrenheit
  float tempFahrenheit = celsiusToFahrenheit(tempCelsius);

    // TODO: position cursor at start of row 1
    lcd.setCursor(0, 0);
    // TODO: Display temp in Fahrenheit
    // format - Temp: xx.x F
    lcd.print("Temp: ");
    lcd.print(tempFahrenheit, 1);
    lcd.print(" F");
    // TODO: position cursor at start of row 2
    // format - Humidity: xx.x%

    //  wait 5 seconds before updating
   delay(5000);
}