int ldr= A0; //AO is the pin, ldr is a light depending resistor  Its declared here to provide public scope
void setup() {

pinMode(ldr ,INPUT);//we have pin,thsts the ip
 Serial.begin(9600); //to start serial comm.
}

void loop() {
  // put your main code here, to run repeatedly:
int ldr_data=analogRead(ldr);//to read data 
Serial.println(ldr_data);//to print the read data
delay(1000);//to delay data output
}

//pullup and pulldown //uart  
//bit.do/mesiot
//mqtt_protocol(messenger,ibmWatson)
//publisher---mosquito(broker)--->subscriber
//components=ldr,R,nodeMCU,breadboard,datacable

