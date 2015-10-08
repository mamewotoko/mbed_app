#include <mbed.h>
#include <TextLCD.h>
#include <MSCFileSystem.h>

//using starboard orange
TextLCD     lcd( p24, p26, p27, p28, p29, p30 ); // rs, e, d0-d3
MSCFileSystem usb("usb");
DigitalOut myled1(LED1);
DigitalOut myled2(LED2);
DigitalOut myled(LED4);

int main() {
  myled1 = 0;
  wait(1);
  lcd.cls();
  myled1 = 1;
  lcd.printf("Hello USB!\n");
  printf("Hello USB! %p =========================================================\n", &(NVIC->ISER[((uint32_t)(USB_IRQn) >> 5)]));

  FILE *fp = fopen("/usb/usbwrite.txt", "w");

  printf("after fopen\n");

  myled2 = 1;
  if(fp == NULL){
    lcd.printf("write failed");
    error("usb write failed\n");
  }

  fprintf(fp, "write to usb memory\n");
  fclose(fp);
  lcd.printf("Written");
  while (true) {
    wait(0.5);
    myled = !myled;
  }
}
