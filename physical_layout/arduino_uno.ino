unsigned long led_1_t;
unsigned long led_2_t;
unsigned long led_3_t;

void setup()
{ 
  pinMode(3, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(9, OUTPUT);
}

//Frequency set
void toggle_1(){
  analogWrite(3, 2); 
  delay(5);
}
void toggle_2(){
  analogWrite(5, 2);
  delay(5);
}
void toggle_3(){
  analogWrite(9, 5); 
  delay(5); 
}

void loop()
{
  while(1)
  {
     toggle_1();
     analogWrite(3, 0); 
     delay(0.5);

     toggle_2();
     analogWrite(5, 0);
     delay(1.5);
     
     toggle_3();
     analogWrite(9, 0);
     delay(2);  
  }
}
