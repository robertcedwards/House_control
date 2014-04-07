#include <RCSwitch.h>
RCSwitch mySwitch = RCSwitch();
#include <Bridge.h>
#include <YunServer.h>
#include <YunClient.h>

YunServer server;
String msg;

void setup() {
  Serial.begin(9600);
  Bridge.begin();
  server.listenOnLocalhost();
  server.begin();
  
  mySwitch.enableTransmit(10);
  mySwitch.setPulseLength(445);  
  mySwitch.setProtocol(1); 
}

void loop() {
YunClient client = server.accept(); //check new clients
   
  if(client) {
    String command = client.readStringUntil('/');  //read the incoming data 
    if (command == "1/on") {      
       one_on();          // read the incoming data
    }
    client.stop();   
  }  
  
   
   
}  
  
alloff();
allon();
alloff();
one_on();
one_off();
two_on();
two_off();
three_on();
three_off();
allon();
}


void allon(){mySwitch.send("10000100001000000000010100");delay(1000);}
void alloff(){mySwitch.send("01000100001000000000010100");delay(1000);}
void one_on(){mySwitch.send("10001000001001000000010100");delay(1000);}
void one_off(){mySwitch.send("01001000001001000000010100");delay(1000);}
void two_on(){mySwitch.send("10001000001000100000010100");delay(1000);}  
void two_off(){mySwitch.send("01001000001000100000010100");delay(1000);}
void three_on(){mySwitch.send("10001000001001100000010100");delay(1000);}
void three_off(){mySwitch.send("01001000001001100000010100");delay(1000);}



