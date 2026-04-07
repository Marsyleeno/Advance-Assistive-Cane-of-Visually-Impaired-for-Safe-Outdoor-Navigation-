#include <SoftwareSerial.h> 

SoftwareSerial myGSM(8,12); 
int butswitch = 7; 
int butstate; 
int count = 0; 

void setup() { 
  pinMode(butswitch, INPUT_PULLUP);
  myGSM.begin(19200); // Setting the baud rate of GSM Module
  delay(100); 
} 

void loop() {
  butstate = digitalRead(butswitch); 
  
  if (butstate == LOW) { 
    SendMessage(); 
    delay(5000); 
    callGSM(); 
  } 
} 

void SendMessage() { 
  myGSM.println("AT+CMGF=1"); // AT command that Sets the GSM Module in Text Mode
  delay(100);
  myGSM.print("AT+CMGS=\"+639998162027\"\r"); // AT command that assigns the mobile number of the SMS recepient
  delay(100); 
  myGSM.println("PLEASE CALL ME ITS AN EMERGENCY"); // The SMS text you want to send 
  delay(100); 
  myGSM.println((char)26); 
  delay(100); 
} 

void callGSM() { 
  myGSM.print("ATD"); // AT command to make outgoing call
  delay(100); 
  myGSM.print("+639998162027"); // the mobile number to make a call to 
  delay(100); 
  myGSM.println(";"); 
  delay(20000);
  myGSM.print("ATH"); 
  delay(100);
} 