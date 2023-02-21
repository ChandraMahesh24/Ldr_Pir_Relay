int LED=  9 ; // choose the pin for the RELAY
int PIR =3  ; // choose the input pin (for PIR sensor) 
int pirState = LOW;   
int value_pir=LOW;              
void setup()
{    
Serial.begin(9600);
  pinMode( LED , OUTPUT); // declare led as output
  pinMode(PIR,INPUT); // declare sensor as input  
}                                                                                                                          
void loop() 
{
    
  int value_ldr = analogRead(A0); // read LDR value
  value_pir = digitalRead(PIR); // read input value
  Serial.println(value_ldr);
  Serial.println(value_pir);
//  delay(500);
  if(700<value_ldr){ 
      if( value_pir==HIGH){
          digitalWrite(LED,HIGH);  // Turn ON the light
          if(pirState == LOW){
              value_pir==LOW;
          }  
      } 
      else {
          digitalWrite(LED,LOW); // Turn OFF the light
          if(pirState == HIGH){
              pirState = LOW;       
          }  
      } 
  }
  else{
    digitalWrite(LED,LOW);
  }
}
