#include <Keypad.h>

int ledRed = 13;
int ledGreen = 12;

int Code[4] = {0,0,0,0};
int GivenCode[4] = {0,0,0,0};

const byte ROWS = 4;
const byte COLS = 3;
char keys[ROWS][COLS] = {
  {'1','2','3'},
  {'4','5','6'},
  {'7','8','9'},
  {'*','0','#'}
};
/*
int ones = (input_number%10);
int tens = ((input_number/10)%10);
int hundreds = ((input_number/100)%10);
int thousands = (input_number/1000);
*/
byte rowPins[ROWS] = {2,3,4,5};
byte colPins[COLS] = {6,7,8};

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

void setup(){
  Serial.begin(9600);
  pinMode(ledRed, OUTPUT);
  pinMode(ledGreen, OUTPUT);
}

void loop(){
  Serial.println("Type in your 4 Number code");
  int i = 0;
  while (i < 4){
    
    char key = keypad.getKey();
    if (key){
    //Serial.print(key);
    GivenCode[i] = GivenCode[i] * 10 + (key - '0');
    Serial.println(GivenCode[i]);
    i++;
   }
  }
  
  if (GivenCode[0] == Code[0] && GivenCode[1] == Code[1] && GivenCode[2] == Code[2] && GivenCode[3] == Code[3]) {
    Serial.println("You got the code");
    digitalWrite(ledGreen, HIGH);
    Serial.println("You can now change to code via the keyboard");
    while (Serial.available()==0) { }
    int NewCode = Serial.parseInt();
    Code[3] = (NewCode%10);
    Code[2] = ((NewCode/10)%10);
    Code[1] = ((NewCode/100)%10);
    Code[0] = (NewCode/1000);
    for(int i = 0; i < 4; i++)
{
  Serial.println(Code[i]);
}
  } else {
    Serial.println("Wrong, try again");
    digitalWrite(ledRed, HIGH);
    delay(4000);
    digitalWrite(ledRed, LOW);
    for (i= 0; i<4;i++) {
      GivenCode[i] = 0;
    }
  }
}
