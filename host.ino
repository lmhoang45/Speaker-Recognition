
#include "ClickButton.h"
 
// initialize the library with the numbers of the interface pins
const int buttons = 8;      //1 Train button and 1 Load button
const int Train0 = 10;     // Pin 10 for train0 button
const int Train1 = 8;     // Pin 8 for train1 button
const int Train2 = 7;
const int Train3 = 6;
const int Train4 = 4;
const int Train5 = 2;
const int Load = 12;
const int Clear = 11;

// Instantiate ClickButton objects in an array
ClickButton button[8] = {
  ClickButton (Train0, LOW, CLICKBTN_PULLUP),
  ClickButton (Train1, LOW, CLICKBTN_PULLUP),
  ClickButton (Train2, LOW, CLICKBTN_PULLUP),
  ClickButton (Train3, LOW, CLICKBTN_PULLUP),
  ClickButton (Train4, LOW, CLICKBTN_PULLUP),
  ClickButton (Train5, LOW, CLICKBTN_PULLUP),
  ClickButton (Load, LOW, CLICKBTN_PULLUP),
  ClickButton (Clear, LOW, CLICKBTN_PULLUP),
};



void setup() {
  Serial.begin(115200);
  for (int i=0; i<buttons; i++){
    // Setup button timers (all in milliseconds / ms)
    // (These are default if not set, but changeable for convenience)
    button[i].debounceTime   = 10;   // Debounce timer in ms
    button[i].multiclickTime = 500;  // Time limit for multi clicks
    button[i].longClickTime  = 2000; // Time until long clicks register 
  }
}
 
void loop() 
{
  // Go through each button and set the corresponding LED function
for (int i=0; i<buttons; i++){
    // Update state of all button
    button[i].Update();
    }
     // Save click codes in LEDfunction, as clicks counts are reset at next Update()
    //if (button[i].clicks != 0) LEDfunction[i] = button[i].clicks;
    
    // train 0 if clicked
    if(button[0].clicks == 1){
      Serial.println ("train 0");
    }
    // train 1 if double clicked
    if(button[1].clicks == 1) {
      Serial.println ("train 1");
    }
    // train 2 if button1 is clicked
    if(button[2].clicks == 1){
      Serial.println ("train 2");
    }
    // train 3 if button1 is clicked
    if(button[3].clicks == 1){
      Serial.println ("train 3");
    }
    // train 4 if button1 is clicked
    if(button[4].clicks == 1){
      Serial.println ("train 4");
    }
    // train 5 if button1 is clicked
    if(button[5].clicks == 1){
      Serial.println ("train 5");
    }
    // load 1 2 3 4 5 if button1 is clicked
    if(button[6].clicks == 1){      
      Serial.println ("load 0 1 2 3 4 5");
    } 
    // clear all if button
    if(button[7].clicks == 1){
      Serial.println ("clear");
	}
  }

