#include <LiquidCrystal.h>
LiquidCrystal lcd(A0,A1,A2,A3,A4,A5);
#define sw 7
String IncomingData;
int surf=0;
int jam=0;
int shampoo=0;
int brush=0;
int paste=0;
int vim = 0;
int count=0;
int a=0,b=0,c=0,d=0,e=0,f=0;
int balance =1400;
void setup() {
  pinMode(sw,INPUT_PULLUP);
  lcd.begin(16, 2);
  lcd.setCursor(0,0);  lcd.print("SMART TROLLEY"); 
  Serial.begin(9600);  
  pinMode(13, OUTPUT); 
  delay(5000);
}

void loop() {  
  if(Serial.available()){
    IncomingData = Serial.readString();
    Serial.println(IncomingData.substring(0,11));
    if(IncomingData.substring(0,11) == "1E00CBA5D8A"){ //DONE
      surf = 1;
      Serial.println("SURF EXCEL");
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("SURF EXCEL");
      lcd.setCursor(12,0);
      lcd.print("100");
      if(digitalRead(sw)==LOW){
        a=a-1;            
        count = count-100;
        lcd.setCursor(0,1);
        lcd.print("TOTAL ");
        lcd.setCursor(8,1);
        lcd.print(count);
        }
       else{
           a=a+1;
           count = count+100;
           lcd.setCursor(0,1);
           lcd.print("TOTAL ");
           lcd.setCursor(8,1);
           lcd.print(count);
        } 
      }   
         
    if(IncomingData.substring(0,11) == "1000D24EC44"){  //DONE
      vim = 1;
      Serial.println("VIM");
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("VIM");
      lcd.setCursor(7,0);
      lcd.print("50");
      if(digitalRead(sw)==LOW){
        b=b-1;            
        count = count-50;
        lcd.setCursor(0,1);
        lcd.print("TOTAL ");
        lcd.setCursor(8,1);
        lcd.print(count);
        }
       else{
           b=b+1;
           count = count+50;
           lcd.setCursor(0,1);
           lcd.print("TOTAL ");
           lcd.setCursor(8,1);
           lcd.print(count);
        }  
      }
      
    if(IncomingData.substring(0,11) == "0800ABF6F4A"){  //DONE
      Serial.println("COLGATE PASTE");
      paste = 1;
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("COLGATE PASTE");
      lcd.setCursor(14,0);
      lcd.print("35");
      if(digitalRead(sw)==LOW){
        f=f-1;            
        count = count-35;
        lcd.setCursor(0,1);
        lcd.print("TOTAL ");
        lcd.setCursor(8,1);
        lcd.print(count);
        }
       else{
           f=f+1;
           count = count+35;
           lcd.setCursor(0,1);
           lcd.print("TOTAL ");
           lcd.setCursor(8,1);
           lcd.print(count);
        } 
     }
     
    if(IncomingData.substring(0,11) == "0800A93028B"){  //DONE 
      Serial.println("CLINIC PLUS");
      shampoo = 1; 
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("CLINIC PLUS");
      lcd.setCursor(12,0);
      lcd.print("200");
      if(digitalRead(sw)==LOW){
        d=d-1;            
        count = count-200;
        lcd.setCursor(0,1);
        lcd.print("TOTAL ");
        lcd.setCursor(8,1);
        lcd.print(count);
        }
       else{
        d = d+1;
           count = count+200;
           lcd.setCursor(0,1);
           lcd.print("TOTAL ");
           lcd.setCursor(8,1);
           lcd.print(count);
        } 
      }
      
    if(IncomingData.substring(0,11) == "1E006F64445"){ //DONE
      Serial.println("KISSAN JAM");
      jam = 1; 
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("KISSAN JAM");
      lcd.setCursor(12,0);
      lcd.print("85");
      if(digitalRead(sw)==LOW){ 
        e=e-1;           
        count = count-85;
        lcd.setCursor(0,1);
        lcd.print("TOTAL ");
        lcd.setCursor(8,1);
        lcd.print(count);
        }
       else{
        e=e+1;
           count = count+85;
           lcd.setCursor(0,1);
           lcd.print("TOTAL ");
           lcd.setCursor(8,1);
           lcd.print(count);
        } 
      }
      
      if(IncomingData.substring(0,11) == ""){ 
        Serial.println("MONEY CARD");
        lcd.clear();
        lcd.setCursor(0,0); lcd.print("MONEY CARD");
        balance = (balance-count);
        lcd.setCursor(0,1); lcd.print("AVL BAL");
        lcd.setCursor(9,1); lcd.print(balance);         
      } 
      //---------------------------------------------------//
  }  
}
