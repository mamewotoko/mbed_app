#include "mbed.h"

DigitalOut myled(LED1);

int main() {
  printf("Hello mbed\n");
  while (true) {
    wait(0.5);
    myled = !myled;
  }
}
