int bt = 0;   //버튼
int ld[8] = {1,2,3,4,5,6,7,8};   //LED
int dtime = 50;  //경과시간
int ltime = 0;   //마지막 시간
int st = 0;   //상태
int cnt = 0;   //버튼누른횟수
long now = 0;

void setup() {
  pinMode(bt,INPUT_PULLUP);
  for(int i=0;i<=8;i++){
    pinMode(ld[i],OUTPUT);
  }
  Serial.begin(115200);
}


void loop() {
  now = millis();  // 현재 시점 시각 밀리세컨드 단위로 수행
  int btval = digitalRead(bt);    //버튼값 상태 확인
  if(btval==0){
      int s = swcheck();      //버튼이 눌러지면 실행
      for(int i=0;i<9;i++){
        digitalWrite(ld[i],LOW);
      }
      if(s==1) digitalWrite(ld[0],HIGH);
      else if(s==2) digitalWrite(ld[1],HIGH);
      else if(s==3) digitalWrite(ld[2],HIGH);
      else if(s==4) digitalWrite(ld[3],HIGH);
      else if(s==5) digitalWrite(ld[4],HIGH);
      else if(s==6) digitalWrite(ld[5],HIGH);
      else if(s==7) digitalWrite(ld[6],HIGH);
      else if(s==8){
          digitalWrite(ld[7],HIGH);
          cnt = 0;
      } 
  }  
}

int swcheck(){
  if((now-ltime)>dtime){
        st = !st;
        cnt++;
        Serial.println(cnt);
      }
  ltime = now;     //
  return cnt;
}

