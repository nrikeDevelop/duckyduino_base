#include <Keyboard.h>

// Utility function
void typeKey(int key){
  Keyboard.press(key);
  delay(50);
  Keyboard.release(key);
}

void instructionKey(String instruction){

  String action = instruction;
  action.replace("/", "&");  
  action.replace(":", ">"); 
  
  Keyboard.print(action);
  typeKey(KEY_RETURN);
  delay(250);
}

void setup()
{
  // Start Keyboard and Mouse
  Keyboard.begin();

  // Start Payload
  delay(1000);

  Keyboard.press(KEY_LEFT_ALT);
  Keyboard.press(KEY_F2);
  Keyboard.releaseAll();

  delay(500);

  instructionKey("xterm");
  instructionKey("ifconfig");
  instructionKey("cd /home/susy");
  instructionKey("mkdir prueba");
  instructionKey("cd prueba");
  instructionKey("wget https://wallpaperbrowse.com/media/images/303836.jpg");

  

  // End Payload

  // Stop Keyboard and Mouse
  Keyboard.end();
}

// Unused
void loop() {}
