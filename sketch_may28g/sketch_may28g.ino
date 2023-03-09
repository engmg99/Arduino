int a=9,b=2,c=4,d=5,e=6,f=8,g=7,h=3;        //to activate segment9, 2, 3, 5, 6, 8, 7, 4};

int dis1=13,dis2=12,dis3=11,dis4=10;                //for anode of display
int button1=A0;  //for minute
int button2=A1;  //for second
int button3=A2;  //for hour

int S_period=1000;

unsigned long S_time_now=0;
int A_hour=0;
int A_minute=0;
int A_second=0;
int V_minute;
int V_hour;
int hour_tenth;
int hour_once;
int minute_tenth;
int minute_once;
int tenthP=3;
int oncep=3;
int tenthmp=3;
int oncemp=3;
unsigned long timedel=0;



///////////////////////////////////////////////////

void setup()
{Serial.begin(115200);
    pinMode(a,OUTPUT);   
    pinMode(b,OUTPUT);    
    pinMode(c,OUTPUT);  
    pinMode(d,OUTPUT);
    pinMode(e,OUTPUT);
    pinMode(f,OUTPUT);
    pinMode(g,OUTPUT);  
    pinMode(h,OUTPUT);   
    pinMode(dis1,OUTPUT);
    pinMode(dis2,OUTPUT);
    pinMode(dis3,OUTPUT);
    pinMode(dis4,OUTPUT);
    pinMode(button1,INPUT_PULLUP);
    pinMode(button2,INPUT_PULLUP);
    pinMode(button3,INPUT_PULLUP);
    alloff();
    dpoff();
  //  checkno();
}
//////////////////////////////////////////////////// 
 void checkno()
{
    
    digitalWrite(dis1,1);
    digitalWrite(dis2,1);
    digitalWrite(dis3,1);
    digitalWrite(dis4,1);

   alloff();
   N0();delay(1000);
    alloff();
   N1();delay(1000);
    alloff();
   N2();delay(1000);
    alloff();
   N3();delay(1000);
    alloff();
   N4();delay(1000);
    alloff();
   N5();delay(1000);
    alloff();
   N6();delay(1000);
    alloff();
   N7();delay(1000);
    alloff();
   N8();delay(1000);
    alloff();
   N9();delay(1000);
    alloff();
  }

////////////////////////////////////////////////////
void dpoff()
{
    digitalWrite(h,1);
}

////////////////////////////////////////////////////
void dpon()
{
    digitalWrite(h,0);
}


////////////////////////////////////////////////////
void alloff()
{
    
    
    digitalWrite(a,1);
    digitalWrite(b,1);
    digitalWrite(c,1);
    digitalWrite(d,1);
    digitalWrite(e,1);
    digitalWrite(f,1);
    digitalWrite(g,1);
}
int trigger=0;
unsigned long tm=0;

void loop()
{
     if(millis()-timedel>S_period+S_time_now)
    {
        S_time_now=millis()-timedel;
        A_second=A_second+1;               // to count seconds
        BlinkLED();
        S_time_now=S_time_now-4;
    }
    Serial.println(S_time_now);
    
    if(millis()>150+tm)
    {tm=millis();
        if(trigger==0)  {trigger=1;}      //delay time for buttons
        
        if(trigger==1)  {trigger=1;}
        
    }
    
    if(A_second==60)
    {
        A_minute=A_minute+1;
    }
    if(A_minute==60)
 {
        A_hour=A_hour+1;
    }
    
    if(A_minute==60)
    {
        A_minute=0;
    }
    if(A_hour==24)
    {
        A_hour=0;
    }
    if(A_second==60)
    {
        A_second=0;
    }
       

    calc_no_to_display(A_hour,A_minute);
    Serial.print("sec=>");
    Serial.println(A_second);
    Serial.print("minute=>");
    Serial.print(A_minute);
    display_hourT();
    delay(1);
    display_hourO();
    delay(1);
    display_minT();
    delay(1);
    display_minO();
    delay(1);
   
  if(trigger==1)
  {
    if(digitalRead(button1)==0)
    {A_hour++;}
    if(digitalRead(button2)==0)
    {timedel=millis();
    S_time_now=0;
            A_second=0;
    }
    if(digitalRead(button3)==0)
    {
        A_minute++;
    }
  }
    trigger=0;
}

///////////////////////////////////////////////////
void BlinkLED()
{
    if(digitalRead(h)==0)
    {dpoff();}
    else
    {dpon();}
}

/////////////////////////////////////////////////////
void calc_no_to_display(int V_H,int V_M)
{
  float hourtenth=V_H/10;
  
  int houronce=V_H%10;  

    
  float minutetenth=V_M/10;

  int minuteonce=V_M%10;
    
  hour_tenth=hourtenth;
  hour_once=houronce;
    
  minute_tenth=minutetenth;
  minute_once=minuteonce;
    
  
}
////////////////////////////////////////////////////
void display_hourT()
  { digitalWrite(dis4,0);
    digitalWrite(dis1,1);
    switch(hour_tenth)
    {
        case 0:
        N0();
        break;
        case 1:
        N1();
        break;
        case 2:
        N2();
        break;
        case 3:
        N3();
        break;
        case 4:
        N4();
        break;
        case 5:
        N5();
        break;
        case 6:
        N6();
        break;
        case 7:
        N7();
        break;
        case 8:
        N8();
        break;
        case 9:
        N9();
        break;
        
        default:;
    }
    
    }
void display_hourO()
{digitalWrite(dis1,0);
    digitalWrite(dis2,1);
    switch(hour_once)
    {
        case 0:
        N0();
        break;
        case 1:
        N1();
        break;
        case 2:
        N2();
        break;
        case 3:
        N3();
        break;
        case 4:
        N4();
        break;
        case 5:
        N5();
        break;
        case 6:
        N6();
        break;
        case 7:
        N7();
        break;
        case 8:
        N8();
        break;
        case 9:
        N9();
        break;
        
        default:;
    }
    

  } 

///////////////////////////////////////////////////
void display_minT()
{

digitalWrite(dis2,0);
    digitalWrite(dis3,1);
    switch(minute_tenth)
    {
        case 0:
        N0();
        break;
        case 1:
        N1();
        break;
        case 2:
        N2();
        break;
        case 3:
        N3();
        break;
        case 4:
        N4();
        break;
        case 5:
        N5();
        break;
        case 6:
        N6();
        break;
        case 7:
        N7();
        break;
        case 8:
        N8();
        break;
        case 9:
        N9();
        break;
        
        default:;
    }
    
    
    }
void display_minO()
{digitalWrite(dis3,0);
    digitalWrite(dis4,1);
    switch(minute_once)
    {
        case 0:
        N0();
        break;
        case 1:
        N1();
        break;
        case 2:
        N2();
        break;
        case 3:
        N3();
        break;
        case 4:
        N4();
        break;
        case 5:
        N5();
        break;
        case 6:
        N6();
        break;
        case 7:
        N7();
        break;
        case 8:
        N8();
        break;
        case 9:
        N9();
        break;
        default:;
    } 
}
void N0()
{
    digitalWrite(a,0);
    digitalWrite(b,0);
    digitalWrite(c,0);
    digitalWrite(d,0);
    digitalWrite(e,0);
    digitalWrite(f,0);
    digitalWrite(g,1);
}
void N1()
{
    digitalWrite(a,1);
    digitalWrite(b,0);
    digitalWrite(c,0);
    digitalWrite(d,1);
    digitalWrite(e,1);
    digitalWrite(f,1);
    digitalWrite(g,1);
}
void N2()
{
    digitalWrite(a,0);
    digitalWrite(b,0);
    digitalWrite(c,1);
    digitalWrite(d,0);
    digitalWrite(e,0);
    digitalWrite(f,1);
    digitalWrite(g,0);
}
void N3()
{
    digitalWrite(a,0);
    digitalWrite(b,0);
    digitalWrite(c,0);
    digitalWrite(d,0);
    digitalWrite(e,1);
    digitalWrite(f,1);
    digitalWrite(g,0);
}
void N4()
{
    digitalWrite(a,1);
    digitalWrite(b,0);
    digitalWrite(c,0);
    digitalWrite(d,1);
    digitalWrite(e,1);
    digitalWrite(f,0);
    digitalWrite(g,0);
}
void N5()
{
    digitalWrite(a,0);
    digitalWrite(b,1);
    digitalWrite(c,0);
    digitalWrite(d,0);
    digitalWrite(e,1);
    digitalWrite(f,0);
    digitalWrite(g,0);
}
void N6()
{
    digitalWrite(a,0);
    digitalWrite(b,1);
    digitalWrite(c,0);
    digitalWrite(d,0);
    digitalWrite(e,0);
    digitalWrite(f,0);
    digitalWrite(g,0);
}
void N7()
{
    digitalWrite(a,0);
    digitalWrite(b,0);
    digitalWrite(c,0);
    digitalWrite(d,1);
    digitalWrite(e,1);
    digitalWrite(f,1);
    digitalWrite(g,1);
}
void N8()
{
    digitalWrite(a,0);
    digitalWrite(b,0);
    digitalWrite(c,0);
    digitalWrite(d,0);
    digitalWrite(e,0);
    digitalWrite(f,0);
    digitalWrite(g,0);
}
void N9()
{
    digitalWrite(a,0);
    digitalWrite(b,0);
    digitalWrite(c,0);
    digitalWrite(d,0);
    digitalWrite(e,1);
    digitalWrite(f,0);
    digitalWrite(g,0);
}
