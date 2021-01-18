//First version will only do a high/low voltage test for wire map. Eventually plan to transmit unique bits


/*
 * Dual ethernet breakout board pinout: pins 1-18
 * Ethernet A: Pin 1: shield/ground
 *             Pin 2-9: T-568B network cable
 *             
 * Ethernet B: Pin 10: shield/ground
 *             Pin 11-18: T-568B network cable
 */

int ethernetA[] = {22, 24, 26, 28, 30, 32, 34, 36, 38};
int ethernetB[] = {23, 25, 27, 29, 31, 33, 35, 37, 39};

int pinCount(9);

int connectedPin[9];


void setup() {

Serial.begin(9600);

  
  //Initialize Send Pins
for(int i(0); i < pinCount; ++i){
  pinMode(ethernetA[i], OUTPUT);
  digitalWrite(ethernetA[i], LOW);
}


  //Initalize Recieve Pins
for(int j(0); j < pinCount; ++j){
  pinMode(ethernetB[j], INPUT);
}

//Run the wire map program once
wireMap();
}



void loop() {
  // put your main code here, to run repeatedly:

}




//Runs a wire map on the cable
void wireMap(){

for(int i(0); i < pinCount; ++i){
digitalWrite(ethernetA[i], HIGH);
  for(int j(0); j < pinCount; ++j){
      if(digitalRead(ethernetB[j]) == HIGH){
         connectedPin[i] = j;
           Serial.print(i + " equals " + j);
       }else{
           //do nothin'
           connectedPin[i] = -1;
       }
    
  }
}

if(connectedPin[0] == -1){
  //This either means UTP cable or open on the shield of STP
  Serial.print("Ground is open. Not a problem if UTP.");
}
  
}
