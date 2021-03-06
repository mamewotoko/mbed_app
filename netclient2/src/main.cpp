#include "mbed.h"

////////////////////////////////////////
////////    For TextLCD         ////////
////////////////////////////////////////
//#include "TextLCD.h"
//starboard orange setting
//TextLCD     lcd( p24, p26, p27, p28, p29, p30 ); // rs, e, d0-d3

#include "EthernetInterface.h"
#include "TCPSocketConnection.h"
 
EthernetInterface eth;
 
int main() 
{
  //lcd.locate(0, 0);
  //lcd.printf("netclient2");
    eth.init(); //Use DHCP 
    eth.connect();
    //lcd.locate(0, 1);

    char* address = eth.getIPAddress();
    printf(address);
    TCPSocketConnection sock;

    sock.connect("49.212.175.192", 80);
    int bufsize = 4098;
    char buf[bufsize];
    memset(buf, 0, bufsize);
    //backslash on Mac JIS keyboard: Option - yen 
    char* request = "GET / HTTP/1.0\r\n\r\n";
    printf(request);
    sock.send(request, strlen(request));
    sock.receive(buf, 1024);
    //lcd.locate(0, 1);
    printf(buf);
  //  lcd.printf(buf);
    sock.close();
    printf("finished");
    eth.disconnect();  
 }
