int LED=  3 ; // choose the pin for the RELAY
int PIR =5  ; // choose the input pin (for PIR sensor)                 
void setup()
{    
Serial.begin(9600);
  pinMode( LED , OUTPUT); // declare led as output
  pinMode(PIR,INPUT); // declare sensor as input  
}                                                                                                                          
void loop() 
{
    
  int value_ldr = analogRead(A4); // read LDR value
  int value_pir = digitalRead(PIR); // read input value
  Serial.println(value_ldr);
  Serial.println(value_pir);

 if(700<value_ldr){ 
   value_pir==LOW;
    if( value_pir==HIGH){
       digitalWrite(LED,HIGH);  // Turn ON the light
       delay(3000);        
  }
 }  
 else {
  
    digitalWrite(LED,LOW); // Turn OFF the light
       
 }
  
}


