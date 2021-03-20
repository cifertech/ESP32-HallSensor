#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#define OLED_RESET 4

Adafruit_SSD1306 display = Adafruit_SSD1306(128, 32, &Wire);

int val = 0;

byte count;
byte sensorArray[128];
byte drawHeight;

char filled = 'F'; 
char drawDirection = 'R'; 
char slope = 'W'; 


void setup() {
  
    Serial.begin(9600);
    
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);  

  for (count = 0; count <= 128; count++) 
  {
    sensorArray[count] = 0;
  }
  
}

void loop() {

  val = hallRead();

  Serial.println(val);//to graph 

  drawHeight = map(hallRead(), 0, 200, 0, 29 );
  sensorArray[0] = drawHeight;

  for (count = 1; count <= 80; count++ )
  {
    if (filled == 'D' || filled == 'd')
    {
      if (drawDirection == 'L' || drawDirection == 'l')
      {
        display.drawPixel(count, 32 - sensorArray[count - 1], WHITE);
      }
      else //else, draw dots from right to left
      {
        display.drawPixel(80 - count, 32 - sensorArray[count - 1], WHITE);
      }
    }


    

    else
    {
      if (drawDirection == 'L' || drawDirection == 'l')
      {
        if (slope == 'W' || slope == 'w')
        {
          display.drawLine(count, 32, count, 32 - sensorArray[count - 1], WHITE);
        }
        else
        {
          display.drawLine(count, 1, count, 32 - sensorArray[count - 1], WHITE);

        }
      }



      else
      {
        if (slope == 'W' || slope == 'w')
        {
          display.drawLine(127 - count, 32, 127 - count, 32 - sensorArray[count - 1], WHITE);
        }
        else
        {
          display.drawLine(127 - count, 1, 127 - count, 32 - sensorArray[count - 1], WHITE);
        }
      }
    }
  }

  drawAxises();
  display.display(); 
  display.clearDisplay(); 

  for (count = 120; count >= 2; count--) 
  {
    sensorArray[count - 1] = sensorArray[count - 2];
  }

}


void drawAxises()  
{
  display.drawLine(0, 0, 0, 32, WHITE);
  display.drawLine(127, 0, 127, 32, WHITE);

  for (count = 10; count < 127; count += 10)
  {
    display.drawPixel(count, 0 , WHITE);
    display.drawPixel(count, 31 , WHITE);
  }

  delay(50);
}
