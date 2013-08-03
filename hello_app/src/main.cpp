#include "mbed.h"

DigitalOut myled(LED1);

int main() {
  while (true) {
    wait(0.5);
    myled = !myled;
  }
}
