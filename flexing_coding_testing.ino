

const int FLEX_PIN1 = A0;// Pin connected to voltage divider output
const int FLEX_PIN2 = A1;// Pin connected to voltage divider output
const int FLEX_PIN3 = A2;// Pin connected to voltage divider output
const int FLEX_PIN4 = A3;// Pin connected to voltage divider output
const int FLEX_PIN5 = A4;// Pin connected to voltage divider output

const int FLEX_PIN11 = A5;// Comfort Sensing

const int FLEX_PIN6 = A8;// Pin connected to voltage divider output
const int FLEX_PIN7 = A9;// Pin connected to voltage divider output
const int FLEX_PIN8 = A10;// Pin connected to voltage divider output
const int FLEX_PIN9 = A11;// Pin connected to voltage divider output
const int FLEX_PIN10 = A12;// Pin connected to voltage divider output


const float VCC = 5.00; 
const float R_DIV = 47000.0; // 47.0k resistor for Flex Sensor
const float R_DIV_Comfort = 2200.0; //2.2k resistor for comfort(force) Sensor



 float STRAIGHT_RESISTANCE1 = 0;
 float STRAIGHT_RESISTANCE2 = 0;
 float STRAIGHT_RESISTANCE3 = 0;
 float STRAIGHT_RESISTANCE4 = 0;
 float STRAIGHT_RESISTANCE5 = 0;
 float STRAIGHT_RESISTANCE6 = 0;
 float STRAIGHT_RESISTANCE7 = 0;
 float STRAIGHT_RESISTANCE8 = 0;
 float STRAIGHT_RESISTANCE9 = 0;
 float STRAIGHT_RESISTANCE10 = 0;
 
 float BEND_RESISTANCE1 = 0;
 float BEND_RESISTANCE2 = 0;
 float BEND_RESISTANCE3 = 0;
 float BEND_RESISTANCE4 = 0;
 float BEND_RESISTANCE5 = 0;
 float BEND_RESISTANCE6 = 0;
 float BEND_RESISTANCE7 = 0;
 float BEND_RESISTANCE8 = 0;
 float BEND_RESISTANCE9 = 0;
 float BEND_RESISTANCE10 = 0;



void setup() 
{
  Serial.begin(9600);
  pinMode(FLEX_PIN1, INPUT);
  pinMode(FLEX_PIN2, INPUT);
  pinMode(FLEX_PIN3, INPUT);
  pinMode(FLEX_PIN4, INPUT);
  pinMode(FLEX_PIN5, INPUT);
  pinMode(FLEX_PIN6, INPUT);
  pinMode(FLEX_PIN7, INPUT);
  pinMode(FLEX_PIN8, INPUT);
  pinMode(FLEX_PIN9, INPUT);
  pinMode(FLEX_PIN10, INPUT);
  pinMode(FLEX_PIN11, INPUT);

  int flexADC1 = 0;
  int flexADC2 = 0;
  int flexADC3 = 0;
  int flexADC4 = 0;
  int flexADC5 = 0;
  int flexADC6 = 0;
  int flexADC7 = 0;
  int flexADC8 = 0;
  int flexADC9 = 0;
  int flexADC10 = 0;
  int flexADC11 = 0;
  
  for(short i=0; i<20; i++)
  {
    flexADC1 += analogRead(FLEX_PIN1);
    delay(10);
    flexADC2 += analogRead(FLEX_PIN2);
    delay(10);
    flexADC3 += analogRead(FLEX_PIN3);
    delay(10);
    flexADC4 += analogRead(FLEX_PIN4);
    delay(10);
    flexADC5 += analogRead(FLEX_PIN5);
    delay(10);
    flexADC6 += analogRead(FLEX_PIN6);
    delay(10);
    flexADC7 += analogRead(FLEX_PIN7);
    delay(10);
    flexADC8 += analogRead(FLEX_PIN8);
    delay(10);
    flexADC9 += analogRead(FLEX_PIN9);
    delay(10);
    flexADC10 += analogRead(FLEX_PIN10);
    delay(10);
    flexADC11 += analogRead(FLEX_PIN11);
    delay(10);
  }

  flexADC1 = flexADC1/20;
  flexADC2 = flexADC2/20;
  flexADC3 = flexADC3/20;
  flexADC4 = flexADC4/20;
  flexADC5 = flexADC5/20;
  flexADC6 = flexADC6/20;
  flexADC7 = flexADC7/20;
  flexADC8 = flexADC8/20;
  flexADC9 = flexADC9/20;
  flexADC10 = flexADC10/20;
  flexADC11 = flexADC11/20;

  float flexV1 = flexADC1 * VCC / 1024.0;
  float flexR1 = R_DIV * (VCC / flexV1 - 1.0);

  float flexV2 = flexADC2 * VCC / 1024.0;
  float flexR2 = R_DIV * (VCC / flexV2 - 1.0);

  float flexV3 = flexADC3 * VCC / 1024.0;
  float flexR3 = R_DIV * (VCC / flexV3 - 1.0);

  float flexV4 = flexADC4 * VCC / 1024.0;
  float flexR4 = R_DIV * (VCC / flexV4 - 1.0);

  float flexV5 = flexADC5 * VCC / 1024.0;
  float flexR5 = R_DIV * (VCC / flexV5 - 1.0);

  float flexV6 = flexADC6 * VCC / 1024.0;
  float flexR6 = R_DIV * (VCC / flexV6 - 1.0);

  float flexV7 = flexADC7 * VCC / 1024.0;
  float flexR7 = R_DIV * (VCC / flexV7 - 1.0);

  float flexV8 = flexADC8 * VCC / 1024.0;
  float flexR8 = R_DIV * (VCC / flexV8 - 1.0);

  float flexV9 = flexADC9 * VCC / 1024.0;
  float flexR9 = R_DIV * (VCC / flexV9 - 1.0);

  float flexV10 = flexADC10 * VCC / 1024.0;
  float flexR10 = R_DIV * (VCC / flexV10 - 1.0);

  float flexV11 = flexADC11 * VCC / 1024.0;
  float flexR11 = R_DIV_Comfort * (VCC / flexV11 - 1.0);


  
  STRAIGHT_RESISTANCE1 =flexR1;
  BEND_RESISTANCE1 = STRAIGHT_RESISTANCE1-2400;

  STRAIGHT_RESISTANCE2 =flexR2;
  BEND_RESISTANCE2 = STRAIGHT_RESISTANCE2-2900;

  STRAIGHT_RESISTANCE3 =flexR3;
  BEND_RESISTANCE3 = STRAIGHT_RESISTANCE3-2600;

  STRAIGHT_RESISTANCE4 =flexR4;
  BEND_RESISTANCE4 = STRAIGHT_RESISTANCE4-3000;

  STRAIGHT_RESISTANCE5 =flexR5;
  BEND_RESISTANCE5 = STRAIGHT_RESISTANCE5-2500;

  STRAIGHT_RESISTANCE6 =flexR6;
  BEND_RESISTANCE6 = STRAIGHT_RESISTANCE6-2460;

  STRAIGHT_RESISTANCE7 =flexR7;
  BEND_RESISTANCE7 = STRAIGHT_RESISTANCE7-2150;

  STRAIGHT_RESISTANCE8 =flexR8;
  BEND_RESISTANCE8 = STRAIGHT_RESISTANCE8-2600;

  STRAIGHT_RESISTANCE9 =flexR9;
  BEND_RESISTANCE9 = STRAIGHT_RESISTANCE9-2350;

  STRAIGHT_RESISTANCE10 =flexR10;
  BEND_RESISTANCE10 = STRAIGHT_RESISTANCE10-2300;

}

void loop() 
{
 int flexADC1 = 0;
  int flexADC2 = 0;
  int flexADC3 = 0;
  int flexADC4 = 0;
  int flexADC5 = 0;
  int flexADC6 = 0;
  int flexADC7 = 0;
  int flexADC8 = 0;
  int flexADC9 = 0;
  int flexADC10 = 0;
  int flexADC11 = 0;
  
  for(short i=0; i<10; i++)
  {
    flexADC1 += analogRead(FLEX_PIN1);
    delay(2);
    flexADC2 += analogRead(FLEX_PIN2);
    delay(2);
    flexADC3 += analogRead(FLEX_PIN3);
    delay(2);
    flexADC4 += analogRead(FLEX_PIN4);
    delay(2);
    flexADC5 += analogRead(FLEX_PIN5);
    delay(2);
    flexADC6 += analogRead(FLEX_PIN6);
    delay(2);
    flexADC7 += analogRead(FLEX_PIN7);
    delay(2);
    flexADC8 += analogRead(FLEX_PIN8);
    delay(2);
    flexADC9 += analogRead(FLEX_PIN9);
    delay(2);
    flexADC10 += analogRead(FLEX_PIN10);
    delay(2);
    flexADC11 += analogRead(FLEX_PIN11);
    delay(2);
  }

  flexADC1 = flexADC1/10;
  flexADC2 = flexADC2/10;
  flexADC3 = flexADC3/10;
  flexADC4 = flexADC4/10;
  flexADC5 = flexADC5/10;
  flexADC6 = flexADC6/10;
  flexADC7 = flexADC7/10;
  flexADC8 = flexADC8/10;
  flexADC9 = flexADC9/10;
  flexADC10 = flexADC10/10;
  flexADC11 = flexADC11/10;

  float flexV1 = flexADC1 * VCC / 1024.0;
  float flexR1 = R_DIV * (VCC / flexV1 - 1.0);

  float flexV2 = flexADC2 * VCC / 1024.0;
  float flexR2 = R_DIV * (VCC / flexV2 - 1.0);

  float flexV3 = flexADC3 * VCC / 1024.0;
  float flexR3 = R_DIV * (VCC / flexV3 - 1.0);

  float flexV4 = flexADC4 * VCC / 1024.0;
  float flexR4 = R_DIV * (VCC / flexV4 - 1.0);

  float flexV5 = flexADC5 * VCC / 1024.0;
  float flexR5 = R_DIV * (VCC / flexV5 - 1.0);

  float flexV6 = flexADC6 * VCC / 1024.0;
  float flexR6 = R_DIV * (VCC / flexV6 - 1.0);

  float flexV7 = flexADC7 * VCC / 1024.0;
  float flexR7 = R_DIV * (VCC / flexV7 - 1.0);

  float flexV8 = flexADC8 * VCC / 1024.0;
  float flexR8 = R_DIV * (VCC / flexV8 - 1.0);

  float flexV9 = flexADC9 * VCC / 1024.0;
  float flexR9 = R_DIV * (VCC / flexV9 - 1.0);

  float flexV10 = flexADC10 * VCC / 1024.0;
  float flexR10 = R_DIV * (VCC / flexV10 - 1.0);
  
  float flexV11 = flexADC11 * VCC / 1024.0;
  float flexR11 = R_DIV_Comfort * (VCC / flexV11 - 1.0);

  Serial.println("R1: " + String(flexR1) + " R2: " + String(flexR2) +  " R3: " + String(flexR3)+  " R4: " + String(flexR4)+  " R5: " + String(flexR5)+  " R6: " + String(flexR6)+  " R7: " + String(flexR7)+  " R8: " + String(flexR8)+  " R9: " + String(flexR9)+  " R10: " + String(flexR10));
  
  
  float angle1 = map(flexR1, STRAIGHT_RESISTANCE1, BEND_RESISTANCE1, 0, 90.0);
  float angle2 = map(flexR2, STRAIGHT_RESISTANCE2, BEND_RESISTANCE2, 0, 90.0);
  float angle3 = map(flexR3, STRAIGHT_RESISTANCE3, BEND_RESISTANCE3, 0, 90.0);
  float angle4 = map(flexR4, STRAIGHT_RESISTANCE4, BEND_RESISTANCE4, 0, 90.0);
  float angle5 = map(flexR5, STRAIGHT_RESISTANCE5, BEND_RESISTANCE5, 0, 90.0);
  float angle6 = map(flexR6, STRAIGHT_RESISTANCE6, BEND_RESISTANCE6, 0, 90.0);
  float angle7 = map(flexR7, STRAIGHT_RESISTANCE7, BEND_RESISTANCE7, 0, 90.0);
  float angle8 = map(flexR8, STRAIGHT_RESISTANCE8, BEND_RESISTANCE8, 0, 90.0);
  float angle9 = map(flexR9, STRAIGHT_RESISTANCE9, BEND_RESISTANCE9, 0, 90.0);
  float angle10 = map(flexR10, STRAIGHT_RESISTANCE10, BEND_RESISTANCE10, 0, 90.0);
  
  Serial.println("B1: " + String(angle1) + " B2: " + String(angle2) +" B3: " + String(angle3)+" B4: " + String(angle4)+" B5: " + String(angle5)+" B6: " + String(angle6)+" B7: " + String(angle7)+" B8: " + String(angle8)+" B9: " + String(angle9)+" B10: " + String(angle10)+" C: " + String(flexV11));
  Serial.println(" C: " + String(flexV11));
}
