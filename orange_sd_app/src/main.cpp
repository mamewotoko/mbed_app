#include <mbed.h>
#include <TextLCD.h>
#include <SDFileSystem.h>

//using starboard orange
TextLCD     lcd(p24, p26, p27, p28, p29, p30); // rs, e, d0-d3
SDFileSystem sd(p5, p6, p7, p8, "sd");

DigitalOut myled(LED3);

int main() {
  FILE *fp = NULL;

  lcd.cls();
  lcd.locate(0, 0);
  wait(1);
  lcd.printf("Hello mbed\n");
  fp = fopen("/sd/hello.txt", "w");
  if(fp == NULL){
    lcd.printf("file write error\n");
    error("Could not open file for write\n");
  }
  fprintf(fp, "Hello file in mbed SDsssssssssssssssssss\n");
  fclose(fp);
  lcd.printf("SD Written");

  while (true) {
    wait(0.5);
    myled = !myled;
  }
}
