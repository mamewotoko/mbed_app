#include <mbed.h>

DigitalOut myled(LED1);
DigitalOut myled2(LED2);

int main() {
  printf("Hello mbed\n");
  while (true) {
    wait(0.5);
    myled2 = myled;
    myled = !myled;
  }
}
