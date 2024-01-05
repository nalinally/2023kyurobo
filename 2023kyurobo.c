#define sw1 D2
#define led1 D3
#define led2 D4
#define led3 D5
#define led4 D6
#define led5 D7
#define led6 D8
#define led7 D9
#define sw2 D10
#define step 5

int sw1_val_pre = 0, sw2_val_pre = 0;
int sw1_val = 0, sw2_val = 0;
int count = 0;
int phase = 0;  // 0 ... スタート前 

void setup() {
  pinMode(sw1, INPUT_PULLUP);
  pinMode(sw2, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {

  sw1_val_pre = sw1_val;
  sw2_val_pre = sw2_val;
  sw1_val = !digitalRead(sw1);
  sw2_val = !digitalRead(sw2);

  switch(phase){

    case 0:
      if(sw1_val && sw2_val){
        count++;
      }
      else{
        count = 0;
      }
      if(count = 0){
        setled(LOW, LOW, LOW, LOW, LOW, LOW, LOW);
      }
      if(count > 0 && count < 100){
        setled(HIGH, LOW, LOW, LOW, LOW, LOW, HIGH);
      }
      if(count >= 100 && count < 200){
        setled(LOW, HIGH, LOW, LOW, LOW, HIGH, LOW);
      }
      if(count >= 200 && count < 300){
        setled(LOW, LOW, HIGH, LOW, HIGH, LOW, LOW);
      }
      if(count >= 300){
        setled(LOW, LOW, LOW, HIGH, LOW, LOW, LOW);
        count = step * 3;
        phase = 1;
      }
      delay(10);
      break;

    case 1:
      if(!sw1_val_pre && sw1_val){
        count++;
      }
      if(!sw2_val_pre && sw2_val){
        count--;
      }
      if(count <= 0){
        setled(LOW, LOW, LOW, LOW, LOW, LOW, HIGH);
        phase = 2;
      }
      if(count > 0 && count <= step){
        setled(LOW, LOW, LOW, LOW, LOW, HIGH, LOW);
      }
      if(count > step && count <= step*2){
        setled(LOW, LOW, LOW, LOW, HIGH, LOW, LOW);
      }
      if(count > step*2 && count < step*4){
        setled(LOW, LOW, LOW, HIGH, LOW, LOW, LOW);
      }
      if(count >= step*4 && count < step*5){
        setled(LOW, LOW, HIGH, LOW, LOW, LOW, LOW);
      }
      if(count >= step*5 && count < step*6){
        setled(LOW, HIGH, LOW, LOW, LOW, LOW, LOW);
      }
      if(count >= step*6){
        setled(HIGH, LOW, LOW, LOW, LOW, LOW, LOW);
        phase = 2;
      }
      break;

    case 2:
      delay(3000);
      for(int i = 0; i < 3; i++){
        setled(LOW, LOW, LOW, LOW, LOW, LOW, LOW);
        delay(500);
        if(count <= 0){
          setled(LOW, LOW, LOW, LOW, LOW, LOW, HIGH);
        }
        if(count >= step*6){
          setled(HIGH, LOW, LOW, LOW, LOW, LOW, LOW);
        }
        delay(500);
      }
      delay(1000);
      setled(LOW, LOW, LOW, LOW, LOW, LOW, LOW);
      delay(1000);
      count = 0;
      phase = 0;
      break;

  }
}

void setled(int l1, int l2, int l3, int l4, int l5, int l6, int l7) {
  digitalWrite(led1, l1);
  digitalWrite(led2, l2);
  digitalWrite(led3, l3);
  digitalWrite(led4, l4);
  digitalWrite(led5, l5);
  digitalWrite(led6, l6);
  digitalWrite(led7, l7);
}


