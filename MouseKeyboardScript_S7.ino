/*
MouseKeyboarScript_S7

Issue mouse and keyboard commands to enable USB-Debugging on Samsung Galaxy S7 devices.

*/

#if ARDUINO > 10605
#include <Mouse.h>
#include <Keyboard.h>
#endif  //ARDUINO > 10605
#include <MouseTo.h>


const byte pin = 10; //Initialize P10

void setup() {
  Mouse.begin();
  MouseTo.setScreenResolution(2560, 1440);
  MouseTo.setCorrectionFactor(1);
  pinMode(pin, INPUT_PULLUP);

  Keyboard.begin();
  
}

void loop() {

  //Start program when pin 10 is connected to ground
  while (digitalRead(pin) == LOW) {
    
    //Set home location
    MouseTo.setTarget(0, 0);      
    while (MouseTo.move() == false) {}
    delay(1000);

    //Click low battery prompt if phone is below 5%
    MouseTo.setTarget(900, 1400);      
    while (MouseTo.move() == false) {}
    delay(1000);
    Mouse.click();
    delay(1000);
    
    //Move and drag to unlock the screen, then move to top left
    MouseTo.setTarget(525, 1700); 
    while (MouseTo.move() == false) {}
    delay(1000);
    Mouse.press();
    MouseTo.setTarget(0, 0);
    while (MouseTo.move() == false) {}
    Mouse.release();
    delay(1000);

    //Make sure phone is on home screen
    Mouse.click(MOUSE_MIDDLE);
    delay(1000);
    
    //Click to open pull down menu
    Mouse.click();
    delay(1000);

    //Move and click settings button
    MouseTo.setTarget(450, 25);      
    while (MouseTo.move() == false) {}
    delay(1000);
    Mouse.click();
    delay(1000);

 /*Search for Apps option and press Enter*/
    Keyboard.write(KEY_RETURN);        //Enter key
    delay(800);
    Keyboard.write(KEY_RETURN);        //Enter key
    delay(800);
    Keyboard.println("apps");                                                                                                                                                                                                           
    delay(4000);
    Keyboard.write(KEY_TAB);        //Enter key
    delay(800);
    Keyboard.write(KEY_TAB);        //Enter key
    delay(800);
    Keyboard.write(KEY_RETURN);        //Enter key
    delay(2500);

    //Find Settings app and press enter.
    Keyboard.println("settings");      //Look for Setting app
    delay(4000);
    Keyboard.write(KEY_TAB);        //Enter key
    delay(800);
    Keyboard.write(KEY_TAB);        //Enter key
    delay(800);
    Keyboard.write(KEY_RETURN);        //Enter key
    delay(800);    
    Keyboard.write(KEY_TAB);        //Enter key
    delay(600);
    Keyboard.write(KEY_RETURN);        //Select "Clear Data"
    delay(800); 
    //Dialog appears prompting to confirm deletion.
    Keyboard.write(KEY_TAB);        //Select "Delete"
    delay(800);
    Keyboard.write(KEY_RETURN);        //Confirm
    delay(1000); 

    //Settings app closes and script must access it again.
    //Move and click settings button
    MouseTo.setTarget(0, 0);
    while (MouseTo.move() == false) {}
    Mouse.release();
    delay(1000);

    //Make sure phone is on home screen
    Mouse.click(MOUSE_MIDDLE);
    delay(1000);
    
    //Click to open pull down menu
    Mouse.click();
    delay(1000);

    //Move and click settings button
    MouseTo.setTarget(450, 25);      
    while (MouseTo.move() == false) {}
    delay(1000);
    Mouse.click();
    delay(1000);
    
    //Search for "Build Number" and press enter.
    Keyboard.write(KEY_RETURN);        //Enter key
    delay(600);
    Keyboard.write(KEY_RETURN);        //Enter key
    delay(600);
    Keyboard.println("build number");                                                                                                                                                                                                           
    delay(2500);
    Keyboard.write(KEY_TAB);        //Enter key
    delay(600);
    Keyboard.write(KEY_TAB);        //Enter key
    delay(600);
    Keyboard.write(KEY_RETURN);        //Enter key
    delay(1000);
    for(int i = 0; i < 9; i++) {
        Keyboard.write(KEY_RETURN);        //Enter key 10 times
        delay(1000);
    }

    //Press Escape key to return to the previous settings menu
    Keyboard.write(KEY_ESC);
    delay(1000);
    Keyboard.write(KEY_TAB);        //Open search bar
    delay(1000);
    Keyboard.write(KEY_RETURN);        //Enter Key
    delay(1000); 
    
    //Search for "USB Debugging" and press enter.
    Keyboard.println("usb debugging");
    delay(4000);
    Keyboard.write(KEY_TAB);        //Enter key
    delay(800);
    Keyboard.write(KEY_TAB);        //Enter key
    delay(800);
    Keyboard.write(KEY_RETURN);        
    delay(1000);  

    //Toggle Developer options on and off to clear any previous user settings
    Keyboard.write(KEY_RETURN);        //Off
    delay(800);  
    Keyboard.write(KEY_RETURN);        //Toggle Developer options on
    delay(800);

    //Prompt "Use development settings"
    Keyboard.write(KEY_TAB);           //Choose "OK"
    delay(800);  
    Keyboard.write(KEY_RETURN);        //Confirm developer mode
    delay(800);  

    //Choose "USB Debugging" option
    Keyboard.write(KEY_TAB);           //Enable USB debugging
    delay(800);  
    Keyboard.write(KEY_RETURN);        //Confirm developer mode
    delay(800);  
    
    //Confirmation prompt to enable  USB debugging
    Keyboard.write(KEY_TAB);           //Choose "OK"
    delay(800);  
    Keyboard.write(KEY_RETURN);        //Confirm developer mode
    delay(800);  

    //Press Escape key to return to the previous settings menu
    Keyboard.write(KEY_ESC);
    delay(800);
    
    Keyboard.write(KEY_TAB);        //Select search bar
    delay(1000);
    Keyboard.write(KEY_RETURN);        //Open search bar
    delay(1000); 

    //Search for "NFC and payment" and press enter.
    Keyboard.println("nfc and payment");
    delay(4000);
    Keyboard.write(KEY_TAB);        //Tab key
    delay(1000);
    Keyboard.write(KEY_TAB);        //Tab key
    delay(1000);
    Keyboard.write(KEY_RETURN);        //Enter Key
    delay(1000); 
    Keyboard.write(KEY_RETURN);        //Enable NFC
    delay(800);  
    //Not needed?
    Keyboard.write(KEY_TAB);           //Clear dialog prompt
    delay(800);
    Keyboard.write(KEY_RETURN);        //Confirm NFC enable
    delay(800);
    
    //Return to home screen
    Mouse.click(MOUSE_MIDDLE);
    delay(600);

    while(1) {} //only runs the program one time
  }
}
