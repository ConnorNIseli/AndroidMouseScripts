/*
MouseKeyboarScript_S7

Issue mouse and keyboard commands to enable USB-Debugging on Samsung Galaxy S7 devices.

*/

#if ARDUINO > 10605
#include <Mouse.h>
#endif  //ARDUINO > 10605
#include <Keyboard.h>
#include <MouseTo.h>


const byte pin10 = 10; //Initialize P10
const byte pin11 = 11; //Initialize P11
const byte pin6 = 6; //Initialize P6


void setup() {
  
    Mouse.begin();
    MouseTo.setScreenResolution(2560, 1440);
    MouseTo.setCorrectionFactor(0.33);
    pinMode(pin6, OUTPUT);
    pinMode(pin10, INPUT_PULLUP);
    pinMode(pin11, INPUT_PULLUP);
    Keyboard.begin();
  
}


void loop() {
    //Start program when pin 10 is connected to ground
    while (digitalRead(pin10) == LOW) {

        //*************************************************************
        // Welcome screen after Factory Reset
        //
        //
        //*************************************************************
        delay(2000);
    
        //Set home location
        MouseTo.setTarget(0, 0);      
        while (MouseTo.move() == false) {}
        delay(2000);
        Mouse.click(MOUSE_MIDDLE);
        delay(600);

        // Welcome START
        Keyboard.write(KEY_TAB);
        delay(800);
        Keyboard.write(KEY_TAB);
        delay(800);
        Keyboard.write(KEY_DOWN_ARROW);
        delay(800);
        Keyboard.write(KEY_DOWN_ARROW);
        delay(800);
        Keyboard.write(KEY_RETURN);
        delay(1000);
        
        // USE Wi-Fi
        Keyboard.write(KEY_RETURN);
        delay(1000);
        // NEXT
        Keyboard.write(KEY_RETURN);
        delay(1000);
        // SKIP: Set Up Wi-Fi
        MouseTo.setTarget(1250, 2500);      
        while (MouseTo.move() == false) {}
        delay(800);
        Mouse.click();
        delay(2000);
    
        // No Network Connection
        //  SKIP ANYWAYS
        Keyboard.write(KEY_TAB);
        delay(800);
        Keyboard.write(KEY_TAB);
        delay(800);
        Keyboard.write(KEY_RETURN);
        delay(1000);
        
        //Google Services setup
        MouseTo.setTarget(1250, 2500);      
        while (MouseTo.move() == false) {}
        delay(1000);
        Mouse.click();
        delay(2000);
        
        Mouse.click();
        delay(2000);
        
        // NEXT
        Mouse.click();
        delay(4000);

        // NEXT: Date and Time
        Mouse.click();
        delay(4000);

        // NEXT: Name
        Mouse.click();
        delay(4000);

        //Say no to setup any security (lock screen, fingerprint, etc.)
        Keyboard.write(KEY_TAB);
        delay(800);
        Keyboard.write(KEY_TAB);
        delay(800);
        Keyboard.write(KEY_TAB);
        delay(800);
        Keyboard.write(KEY_RETURN);
        delay(1000);
        MouseTo.setTarget(1250, 2500);      
        while (MouseTo.move() == false) {}
        delay(1000);
        Mouse.click();
        delay(2000);
        Keyboard.write(KEY_TAB);
        delay(800);
        Keyboard.write(KEY_TAB);
        delay(800);
        Keyboard.write(KEY_RETURN);
        delay(1000);
    
        MouseTo.setTarget(1250, 2500);      
        while (MouseTo.move() == false) {}
        delay(1000);
        Mouse.click();
        delay(2000);
        
        Mouse.click();
        delay(2000);

        Mouse.click();
        delay(2000);
    
        Keyboard.write(KEY_RETURN);
        delay(800);
        Keyboard.write(KEY_RETURN);
        delay(10000);
    
        /////////////////////////////////////////////////////////////////////////////
        
        //Click low battery prompt if phone is below 5%
        Keyboard.write(KEY_RETURN);
        delay(800);
        Keyboard.write(KEY_RETURN);
        delay(800);
        
        //*************************************************************
        // Enable USB-Debugging through settings
        //*************************************************************
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
    
        MouseTo.setTarget(1250, 100);         //Resolution 2560x1440 (WQHD)
        while (MouseTo.move() == false) {}
        delay(1000);
        Mouse.click();
        delay(1000);
    
        /*Search for Apps option and press Enter*/
        Keyboard.write(KEY_TAB);           //Enter key
        delay(800);
        Keyboard.write(KEY_RETURN);        //Enter key
        delay(800);

        Keyboard.println("app");           //Could be "Applications" or "Apps"; also "Default apps"                                                                                                                                                                                                
        delay(10000);
        Keyboard.write(KEY_TAB);           //Enter key
        delay(1000);
        Keyboard.write(KEY_TAB);           //Enter key
        delay(1000);
        Keyboard.write(KEY_RETURN);        //Enter key
        delay(4000);
    
        //Find Settings app and press enter.
        Keyboard.println("settings");      //Look for Settings app
        delay(4000);
        Keyboard.write(KEY_TAB);           //Enter key
        delay(800);
        Keyboard.write(KEY_TAB);           //Enter key
        delay(800);
        Keyboard.write(KEY_RETURN);        //Enter key
        delay(800);    
        Keyboard.write(KEY_TAB);           //Enter key
        delay(600);
        Keyboard.write(KEY_RETURN);        //Select "Clear Data"
        delay(800); 
        //Dialog appears prompting to confirm deletion.
        Keyboard.write(KEY_TAB);           //Select "Delete"
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
        MouseTo.setTarget(1350, 100);      
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
        delay(4000);
        Keyboard.write(KEY_TAB);          //Enter key
        delay(800);
        Keyboard.write(KEY_TAB);          //Enter key
        delay(800);
        Keyboard.write(KEY_RETURN);       //Enter key
        delay(1000);
        for(int i = 0; i < 9; i++) {
            Keyboard.write(KEY_RETURN);   //Enter key 10 times
            delay(1000);
        }
    
        //Press Escape key to return to the previous settings menu
        Keyboard.write(KEY_ESC);
        delay(1000);
        Keyboard.write(KEY_TAB);         //Open search bar
        delay(1000);
        Keyboard.write(KEY_RETURN);      //Enter Key
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
        Keyboard.write(KEY_RIGHT_ARROW);   //Choose "OK"
        delay(800);  
        Keyboard.write(KEY_RETURN);        //Confirm developer mode
        delay(800);  
    
        //Choose "USB Debugging" option
        Keyboard.write(KEY_TAB);           //Enable USB debugging
        delay(800);  
        Keyboard.write(KEY_RETURN);        //Confirm developer mode
        delay(800);  
        
        //Confirmation prompt to enable  USB debugging
        Keyboard.write(KEY_RIGHT_ARROW);    //Choose "OK"
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
        Keyboard.write(KEY_TAB);           //Tab key
        delay(1000);
        Keyboard.write(KEY_TAB);           //Tab key
        delay(1000);
        Keyboard.write(KEY_RETURN);        //Enter Key
        delay(1000); 
        Keyboard.write(KEY_RETURN);        //Enable NFC
        delay(800);  

        Keyboard.write(KEY_TAB);           //Tab key
        delay(1000);
        Keyboard.write(KEY_RIGHT_ARROW);   //Clear dialog prompt
        delay(800);
        Keyboard.write(KEY_RETURN);        //Confirm NFC enable
        delay(800);
        
        //Return to home screen
        Mouse.click(MOUSE_MIDDLE);
        delay(600);
    }

    //Wait for button input to pair to Bluetooth Module
    while (digitalRead(pin11) == LOW){
        Keyboard.write(KEY_RIGHT_ARROW);           //"No"
        delay(800);
        Keyboard.write(KEY_RIGHT_ARROW);           //"Yes"
        delay(800);
        Keyboard.write(KEY_RETURN);                //Confirm Bluetooth connection
        delay(800);
    }
}
