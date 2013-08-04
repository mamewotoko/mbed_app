// ugh!: use < >
#include "mbed.h"
#include "TextLCD.h"

//using starboard orange
TextLCD     lcd( p24, p26, p27, p28, p29, p30 ); // rs, e, d0-d3
DigitalOut myled(LED3);

int main() {
  lcd.printf("Hello mbed\n");
  while (true) {
    wait(0.5);
    myled = !myled;
  }
}
