const float Kp=5;
const float Kd=0; //( Note: Kp < Kd)
    #define M 240
    #define Bturn 120
    #define B 120
    #define samples 20     
     byte flft=0;
     byte fstr=0;
     byte frit=0;
     byte fbak=0;  
     byte fend=0;     
    unsigned int w_u_1[samples],w_u_8[samples],w_u_3[samples],w_u_4[samples],w_u_10[samples],w_u_5[samples],w_u_6[samples],w_u_12[samples],w_u_7[samples],w_u_11[samples],w_u_9[samples],
                 b_u_1[samples],b_u_8[samples],b_u_3[samples],b_u_4[samples],b_u_10[samples],b_u_5[samples],b_u_6[samples],b_u_12[samples],b_u_7[samples],b_u_11[samples],b_u_9[samples],km;
byte a=1,b=0,x=1,y=0;
float e,S,ot,nt;
float le=0;
int l,rS,lS,;
byte u1=A14,u3=A12,u6=A11,u4=A10,u_8=A13,u10=A9,u5=A8,u12=A15,u7=A7,u11=A6,u9=A5;
int qr1,qr2,qr3,qr4,qr5;
int wu1,wu12,wu3,wu4,wu5,wu6,wu7,wu8,wu9,wu10,wu11,bu1,bu12,bu3,bu4,bu5,bu6,bu7,bu8,bu9,bu10,bu11; 
    // ,au1,au12,au3,au4,au5,au6,au7,au8,au9,au10,au11;
int k,i,k1,k2,k3,k4,k5,p,q,r1,r2,r3,r4,r5,r6,r7;
char path[100] = "",pl = 0;
unsigned int inverse_delay;
 
void setup() {
pinMode(42,OUTPUT);
pinMode(43,OUTPUT);
pinMode(44,OUTPUT);
pinMode(38,OUTPUT);
pinMode(40,OUTPUT);
pinMode(41,OUTPUT);
pinMode(45,OUTPUT);
pinMode(50,OUTPUT);
pinMode(51,OUTPUT);
pinMode(13,OUTPUT);
pinMode(52,INPUT_PULLUP);
pinMode(53,INPUT_PULLUP);
    
    delay(500);
    Serial.begin(9600);
    digitalWrite(13,0);
    calibrate_qre();
    in_delay(); 
    interval_delay();     
    delay(300);

 /*   while(1){
      qr1=read_qr1();
      qr2=read_qr2();
      qr4=read_qr4();
      qr5=read_qr5();
      qr3=read_qr3();
      k1=read_qr_left();
      k2=read_qr_right();
      k3=read_qr_bl();
      k4=read_qr_br();
  Serial.println(qr1); 
  Serial.println(qr2);  
  Serial.println(qr3); 
  Serial.println(qr4);  
  Serial.println(qr5);
  Serial.println(k1); 
  Serial.println(k2);  
  Serial.println(k3); 
  Serial.println(k4);  
  Serial.println();
  delay(500);
    }
/*    
      qr3=read_qr3();
      qr1=read_qr1();
      qr2=read_qr2();
      qr4=read_qr4();
      qr5=read_qr5();
   r1 = read_qr_left();  
   r2 = read_qr_right();
   r3 = read_qr_bl();
   r4 = read_qr_br() ;
 //  r5 = read_qr_leftenc();
 //  r6 = read_qr_rightenc(); 
   if(qr1<32&&qr2<32&&qr3<32&&qr4<32&&qr5<32)      //w
   if(qr1>80&&qr2>80&&r3>80&&r4>80&&r1>80&&r2>80&&qr4>80&&qr5>80)    //b
    */  }
  
void loop() { 

  /*   while(1){ in_delay();  Serial.println(inverse_delay);  delay(50);}
  /*  Serial.println(l); 
  Serial.println(S); 
  Serial.println(lS); 
  Serial.println(rS); 
  Serial.println();
  delay(100);
 /*   i=read_qr_right();
    if(i >90){
    digitalWrite(50,1);}
    else
    digitalWrite(50,0);
    i=read_qr_left();
    if(i > 90){
    digitalWrite(51,1);}
    else
    digitalWrite(51,0);
 /**/  
 
  while(1){
  le = 0;
  while(1){
  follow_line();      
     flft=0;
     fstr=0;
     frit=0;
     fbak=0;
     fend=0;
     i=0;
    i=read_qr_right();
    if(i > 90){
    frit = 1;
    break;  }
    i=0;
    i=read_qr_left();
    if(i > 90){
    flft =1;
    break;  }
 /*     qr1=read_qr1();
      qr2=read_qr2();
      qr3=read_qr3();
      qr4=read_qr4();
      qr5=read_qr5();
    if(qr1<32&&qr2<32&&qr3<32&&qr4<32&&qr5<32){
    digitalWrite(50,1);   
    delay(30); 
    digitalWrite(50,0);   
       fbak=1;
       break; }    /**/
   qr3=read_qr3();
   if(qr3<40){
   ot=millis();
  
  while(1){
  digitalWrite(30,1);
  forward();
  read_all();
               if(qr1>75&&r2>75&&qr3>75&&r1>75&&qr5>75){
  while(1){
  ot=millis();
  forward();
  digitalWrite(50,1);
  digitalWrite(51,1); 
  digitalWrite(28,1); 
  nt=millis();
  if(nt-ot>q){
  digitalWrite(50,0);
  digitalWrite(51,0);
  digitalWrite(28,0);
  break;  }}
  break;
  }
              if(qr1<40&&qr2<40&&qr3<40&&qr4<40&&qr5<40){
    digitalWrite(50,1);   
    delay(20); 
    digitalWrite(51,0);   
       fbak=1;
       break; }               /**/
              if(qr1>75&&r2>75&&qr3<40&&r1>75&&qr5>75){
  flft=1;
  break;
  }
              if(qr1>75&&r1>75&&qr3<40){
  flft=1;
  break;
  }
              if(qr3<40&&r2>75&&qr5>75){
  frit=1;
  break;}
  nt=millis();
  if(nt-ot>q)
  break;
  
}digitalWrite(30,0);}
     if(flft==1||frit==1||fbak==1)    break;
    }
   
  unsigned char dir 
  = tktrn(flft, fstr, frit,fbak);
    
    turn(dir);
    if (fend==1) break;
    path[pl] = dir;
    pl ++;
    simplify_path();
  }
  while(1){
  ww();
  digitalWrite(27,1);     delay(500);
  digitalWrite(27,0);     delay(500);
  digitalWrite(27,1);     delay(500);
  digitalWrite(27,0);     delay(500);
  digitalWrite(27,1);     delay(500);
  digitalWrite(27,0);     delay(500);
  
  
  while(digitalRead(53)==1){; 
               if(digitalRead(53)==0)  break;}
               break;
  { delay(2000);
    for(i=0;i<pl;i++)
    { follow_line();
     
      turn(path[i]); }
      follow_line();
    }      }             /**/    }      

void turn(char dir)
{ switch(dir)
{ case 'L':    
      left();       break;
  case 'R':        
      right();      break;
  case 'B':   
      back();       break;
  case 'S': 
                    break;  }}

char tktrn(unsigned char flft,unsigned char fstr, unsigned char frit,unsigned char fbak)
{      if(flft)   return 'L';
  else if(fstr)   return 'S';
  else if(frit)   return 'R';
  else if(fbak)   return 'B';   }    

void ff(){a=1; b=0; x=1; y=0;}
void left(){while(1){
     bitforward();
     read_all();
     if(qr1>80&&qr2>80&&r3>80&&r4>80&&qr4>80&&qr5>80){
     ww(); fend=1; break;}  /**/
     a=0; b=1; x=1; y=0;
     lS=Bturn;rS=Bturn;
     write_speed();
     delay(4*inverse_delay/3);
     fend=0;
     break;
     }}
void right(){while(1){
     bitforward();
     read_all();
     if(qr1>80&&qr2>80&&r3>80&&r4>80&&qr4>80&&qr5>80){
     ww(); fend=1; break;}  /**/
     a=1; b=0; x=0; y=1;
     lS=Bturn;rS=Bturn;
     write_speed();
     delay(4*inverse_delay/3);
     fend=0;
     break;
     }}
void back(){
     a=1; b=0; x=0; y=1;
     lS=Bturn;rS=Bturn;
     write_speed();
     delay(8*inverse_delay/3);
     }
void ww(){a=0; b=0; x=0; y=0;lS=0;rS=0;
     write_speed(); }
void bitforward(){
     ff();lS=Bturn;rS=Bturn;
     write_speed();
     delay(inverse_delay);}    
void forward(){
     ff();lS=Bturn;rS=Bturn;
     write_speed();}         
void in_delay(){
     p=analogRead(A4);
     p=p*10-3500;
     if(p>4000)p=4000;
     if(p<0)p=0;
     inverse_delay=p;     }
void interval_delay(){
     q =analogRead(A3);
     q=q*3-600;
     if(q>1000)q=1000;
     if(q<0)q=0;
     inverse_delay=q;     }     

void read_all(){
      qr3=read_qr3();
      qr1=read_qr1();
      qr2=read_qr2();
      qr4=read_qr4();
      qr5=read_qr5();
   r1 = read_qr_left();  
   r2 = read_qr_right();
   r3 = read_qr_bl();
   r4 = read_qr_br() ;
 //  r5 = read_qr_leftenc();
 //  r6 = read_qr_rightenc();
 }
     
void simplify_path()
{if(pl < 3 || path[pl-2] != 'B')
    return;
    int total_angle = 0;
    for(i=1;i<=3;i++)
    { switch(path[pl-i])
    { case 'R':
 total_angle += 90;  break;
      case 'L':
 total_angle += 270;   break;
      case 'B':
 total_angle += 180;  break;   } }
 total_angle = total_angle % 360;
    
    switch(total_angle)
  { case 0:
  path[pl - 3]='S';   break;
    case 90:
  path[pl - 3]='R';   break;
    case 180:
  path[pl- 3]='B';    break;
    case 270:
  path[pl- 3]='L';    break;   }
  pl -= 2;}     

void follow_line(){
    l=line_reading();
    e = l - 50;  
    S = Kp * e + Kd * (e - le); 
    S = constrain(S,-B/2,B/2);
    le = e;                                              
    rS = B + S;
    lS = B - S; 
    ff();
    write_speed();    }

void write_speed(){
      digitalWrite(38, 1);
      digitalWrite(41, a);
      digitalWrite(40, b);
      analogWrite(45, rS);
      digitalWrite(43, x);
      digitalWrite(42, y);
      analogWrite(44, lS);}
      
int line_reading(){
      qr1=read_qr1();
      qr2=read_qr2();
      qr4=read_qr4();
      qr5=read_qr5();
//    qr3=read_qr3();
    k1=qr1+33*qr2+66*qr4+99*qr5;
    k2=qr1+qr2+qr4+qr5;
    k3=k1/k2;
    k4 = constrain(k3,0,100);
    return(k4);}

void calibrate_qre(){
    while(digitalRead(53)==1); 
    read_u6_black();
    while(digitalRead(53)==1); 
    read_u6_white();
    while(digitalRead(53)==1);
    read_bl_br_black();
 //   while(digitalRead(53)==1);
 //   read_enc_black();
    delay(50);
    cal_min_max_avg();
    while(digitalRead(53)==1);
    delay(200);}
          
void check_push(){
if(digitalRead(53)==0){
    analogWrite(44,0);   
    analogWrite(45,0);    
    delay(1000);
    while(digitalRead(53)==1); 
    delay(1000);}}

void read_u6_black(){
    for(int i=0;i<samples;i++){
    digitalWrite(50,1);    digitalWrite(51,1);
    delay(20);   
    w_u_1[i]=analogRead(u1);    w_u_8[i]=analogRead(u_8);    w_u_3[i]=analogRead(u3);    w_u_4[i]=analogRead(u4);    w_u_10[i]=analogRead(u10);    w_u_5[i]=analogRead(u5);
    b_u_6[i]=analogRead(u6);    }
    digitalWrite(50,0);    digitalWrite(51,0);}
    
void read_u6_white(){
    for(int i=0;i<samples;i++){
    digitalWrite(50,1);    digitalWrite(51,1);
    delay(20);   
    w_u_12[i]=analogRead(u12);    w_u_7[i]=analogRead(u7);        w_u_6[i]=analogRead(u6);
    b_u_1[i]=analogRead(u1);    b_u_8[i]=analogRead(u_8);       b_u_3[i]=analogRead(u3);    b_u_4[i]=analogRead(u4);    b_u_10[i]=analogRead(u10);    b_u_5[i]=analogRead(u5);     }
    digitalWrite(50,0);    digitalWrite(51,0);}

void read_bl_br_black(){
    for(int i=0;i<samples;i++){
    digitalWrite(50,1);    digitalWrite(51,1);
    delay(20);   
    b_u_12[i]=analogRead(u12);    b_u_7[i]=analogRead(u7);
    w_u_11[i]=analogRead(u11);    w_u_9[i]=analogRead(u9);  }
    digitalWrite(50,0);    digitalWrite(51,0);}

void read_enc_black(){
    for(int i=0;i<samples;i++){
    digitalWrite(50,1);    digitalWrite(51,1);
    delay(20);   
    b_u_11[i]=analogRead(u11);    b_u_9[i]=analogRead(u9);  }
    digitalWrite(50,0);    digitalWrite(51,0);}    
    
    int w_avg_u8(){    km=w_u_8[0];    for(k=1;k<samples;k++)    km=km+w_u_8[k];    km=km/samples;    return(km);}
    int w_avg_u3(){    km=w_u_3[0];    for(k=1;k<samples;k++)    km=km+w_u_3[k];    km=km/samples;    return(km);}
    int w_avg_u4(){    km=w_u_4[0];    for(k=1;k<samples;k++)    km=km+w_u_4[k];    km=km/samples;    return(km);}
    int w_avg_u6(){    km=w_u_6[0];    for(k=1;k<samples;k++)    km=km+w_u_6[k];    km=km/samples;    return(km);}
    int w_avg_u1(){    km=w_u_1[0];    for(k=1;k<samples;k++)    km=km+w_u_1[k];    km=km/samples;    return(km);}
    int w_avg_u5(){    km=w_u_5[0];    for(k=1;k<samples;k++)    km=km+w_u_5[k];    km=km/samples;    return(km);}
    int w_avg_u12(){    km=w_u_12[0];    for(k=1;k<samples;k++)    km=km+w_u_12[k];    km=km/samples;    return(km);}
    int w_avg_u7(){    km=w_u_7[0];    for(k=1;k<samples;k++)    km=km+w_u_7[k];    km=km/samples;    return(km);}
    int w_avg_u10(){    km=w_u_10[0];    for(k=1;k<samples;k++)    km=km+w_u_10[k];    km=km/samples;    return(km);}
    int w_avg_u11(){    km=w_u_11[0];    for(k=1;k<samples;k++)    km=km+w_u_11[k];    km=km/samples;    return(km);}
    int w_avg_u9(){    km=w_u_9[0];    for(k=1;k<samples;k++)    km=km+w_u_9[k];    km=km/samples;    return(km);}

    int b_avg_u8(){    km=b_u_8[0];    for(k=1;k<samples;k++)    km=km+b_u_8[k];    km=km/samples;    return(km);}
    int b_avg_u3(){    km=b_u_3[0];    for(k=1;k<samples;k++)    km=km+b_u_3[k];    km=km/samples;    return(km);}
    int b_avg_u4(){    km=b_u_4[0];    for(k=1;k<samples;k++)    km=km+b_u_4[k];    km=km/samples;    return(km);}
    int b_avg_u6(){    km=b_u_6[0];    for(k=1;k<samples;k++)    km=km+b_u_6[k];    km=km/samples;    return(km);}
    int b_avg_u10(){    km=b_u_10[0];    for(k=1;k<samples;k++)    km=km+b_u_10[k];    km=km/samples;    return(km);}
    int b_avg_u1(){    km=b_u_1[0];    for(k=1;k<samples;k++)    km=km+b_u_1[k];    km=km/samples;    return(km);}
    int b_avg_u5(){    km=b_u_5[0];    for(k=1;k<samples;k++)    km=km+b_u_5[k];    km=km/samples;    return(km);}
    int b_avg_u12(){    km=b_u_12[0];    for(k=1;k<samples;k++)    km=km+b_u_12[k];    km=km/samples;    return(km);}
    int b_avg_u7(){    km=b_u_7[0];    for(k=1;k<samples;k++)    km=km+b_u_7[k];    km=km/samples;    return(km);}
    int b_avg_u11(){    km=b_u_11[0];    for(k=1;k<samples;k++)    km=km+b_u_11[k];    km=km/samples;    return(km);}
    int b_avg_u9(){    km=b_u_9[0];    for(k=1;k<samples;k++)    km=km+b_u_9[k];    km=km/samples;    return(km);}

void cal_min_max_avg(){
  wu3=w_avg_u3();  wu4=w_avg_u4();  wu6=w_avg_u6();  wu8=w_avg_u8();  wu10=w_avg_u10();  wu1=w_avg_u1();
  wu5=w_avg_u5();  wu12=w_avg_u12();  wu7=w_avg_u7();  wu11=w_avg_u11();  wu9=w_avg_u9();
  
  bu3=b_avg_u3();  bu4=b_avg_u4();  bu6=b_avg_u6();  bu8=b_avg_u8();  bu10=b_avg_u10();  bu1=b_avg_u1();
  bu5=b_avg_u5();  bu12=b_avg_u12();  bu7=b_avg_u7();  bu11=b_avg_u11();  bu9=b_avg_u9();
  /* au1=(wu1+bu1)/2;  au3=(wu3+bu3)/2;  au4=(wu4+bu4)/2;  au5=(wu5+bu5)/2;  au6=(wu6+bu6)/2;  au7=(wu7+bu7)/2;  au8=(wu8+bu8)/2;  au10=(wu10+bu10)/2;  au12=(wu12+bu12)/2; */
}

int read_qr1(){    k=analogRead(u_8);    k=map(k,bu8,wu8,100,0);    k = constrain(k,0,100);    return(k);}
int read_qr2(){    k=analogRead(u3);    k=map(k,bu3,wu3,100,0);    k = constrain(k,0,100);    return(k);}
int read_qr3(){    k=analogRead(u6);    k=map(k,bu6,wu6,100,0);    k = constrain(k,0,100);    return(k);}
int read_qr4(){    k=analogRead(u4);    k=map(k,bu4,wu4,100,0);    k = constrain(k,0,100);    return(k);}    
int read_qr5(){    k=analogRead(u10);    k=map(k,bu10,wu10,100,0);    k = constrain(k,0,100);    return(k);}
int read_qr_left(){    k=analogRead(u1);    k=map(k,bu1,wu1,100,0);    k = constrain(k,0,100);    return(k);}
int read_qr_right(){    k=analogRead(u5);    k=map(k,bu5,wu5,100,0);    k = constrain(k,0,100);    return(k);}
int read_qr_bl(){    k=analogRead(u12);      k=map(k,bu12,wu12,100,0);    k = constrain(k,0,100);    return(k);}
int read_qr_br(){    k=analogRead(u7);        k=map(k,bu7,wu7,100,0);      k = constrain(k,0,100);    return(k);}    
int read_qr_leftenc(){    k=analogRead(u11);    k=map(k,bu11,wu11,100,0);    k = constrain(k,0,100);    return(k);}
int read_qr_rightenc(){    k=analogRead(u9);     k=map(k,bu9,wu9,100,0);      k = constrain(k,0,100);     return(k);}
