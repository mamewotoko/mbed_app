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
  wait(1);
  myled1 = 1;
  lcd.cls();
  lcd.printf("Hello USB!!!!\n");

  printf("fopen: usb/....");
  FILE *fp = fopen("/usb/usbwrite.txt", "w");

#if 0  
  printf("FP: %X\n", fp);
  myled2 = 1;
  if(fp == NULL){
    lcd.printf("write failed");
    error("usb write failed");
  }

  fprintf(fp, "write to usb memory\n");
  fclose(fp);
  lcd.printf("Written");
  while (true) {
    wait(0.5);
    myled = !myled;
  }
#endif
}
