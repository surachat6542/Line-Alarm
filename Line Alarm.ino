#include <ESP8266WiFi.h> //https://github.com/esp8266/Arduino
#include <DNSServer.h>
#include <ESP8266WebServer.h>
#include <WiFiManager.h> //https://github.com/tzapu/WiFiManager
#include <Wire.h> 
#include <time.h>


String LINE_TOKEN = "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx";   // Line Tokenen
 #define ESP_AP_NAME "xxxxxx" 
 #define WIFI_SSID1 "xxxxxx"                                   //User WIFI
 #define WIFI_PASSWORD1 "xxxxxx"                             //Password WIFI
// #define WIFI_SSID2 "xxxxxx"
// #define WIFI_PASSWORD2 "xxxxxx"


const int INPUT_channal_1 = D1 ;                       // PIN ของช่อง 1
const int INPUT_channal_2 = D2 ;                       // PIN ของช่อง 2          
const int INPUT_channal_3 = D3 ;                       // PIN ของช่อง 3          
const int INPUT_channal_4 = D4 ;                       // PIN ของช่อง 3
const int INPUT_channal_5 = D5 ;                       // PIN ของช่อง 4         
int timesend ;

int state1 , state2 , state3 , state4 , state5 = 0 ;     //เพิ่มลดช่อง แก้ตรงนี้ด้วย
int a , b , c ,d ,e;                                      //เพิ่มลดช่อง แก้ตรงนี้ด้วย

int buttonState = 0;                               // variable for reading the pushbutton status
void setup() {
    Serial.begin(9600);
  pinMode(INPUT_channal_1, INPUT);                    //  กำหนดให้เป็น  INPUT
  pinMode(INPUT_channal_2, INPUT);                    //  กำหนดให้เป็น  INPUT   
  pinMode(INPUT_channal_3, INPUT);                    //  กำหนดให้เป็น  INPUT  
  pinMode(INPUT_channal_4, INPUT);                    //  กำหนดให้เป็น  INPUT 
  pinMode(INPUT_channal_5, INPUT);                    //  กำหนดให้เป็น  INPUT 

    
               // WiFiManager wifiManager;
               // wifiManager.autoConnect(ESP_AP_NAME);   
   //connect to wifi access point
  WiFi.begin(WIFI_SSID1, WIFI_PASSWORD1);
 // WiFi.begin(WIFI_SSID2, WIFI_PASSWORD2);
  delay(500);
  Serial.println();
  Serial.print("connected: ");
  Serial.println(WiFi.localIP());

  }

void loop()   {


  timesend = timesend + 1 ;
                   if(digitalRead(INPUT_channal_1) == LOW)  state1 = 1 ;                     //เพิ่มลดช่อง แก้ตรงนี้ด้วย
                   if(digitalRead(INPUT_channal_1) == HIGH) state1 = 0 ;                          //**
                   if(digitalRead(INPUT_channal_2) == LOW)  state2 = 1 ;                          //**
                   if(digitalRead(INPUT_channal_2) == HIGH) state2 = 0 ;                          //**
                   if(digitalRead(INPUT_channal_3) == LOW)  state3 = 1 ;                          //**
                   if(digitalRead(INPUT_channal_3) == HIGH) state3 = 0 ;                          //**
                   if(digitalRead(INPUT_channal_4) == LOW)  state4 = 1 ;                          //**
                   if(digitalRead(INPUT_channal_4) == HIGH) state4 = 0 ;                          //** 
                   if(digitalRead(INPUT_channal_5) == LOW)  state5 = 1 ;                          //**
                   if(digitalRead(INPUT_channal_5) == HIGH) state5 = 0 ;                     //เพิ่มลดช่อง แก้ตรงนี้ด้วย                   

       if (state1 == 1  ){
             Line_Notify(LINE_TOKEN , "Zone1 (ชั้น1 โซน A) /ALARM" );               //ข้อความแจ้งเตอนช่อง 1
Serial.print("***");
             a = 1 ;
             delay(1000);   
          }
       if (state2 == 1  ){
             Line_Notify(LINE_TOKEN , "Zone2 (ชั้น1 โซน B) /ALARM" );           //ข้อความแจ้งเตอนช่อง 2
  Serial.print("***"); 
             b = 1 ;
             delay(1000);
          }
       if (state3 == 1  ){
             Line_Notify(LINE_TOKEN , "Zone3 (ชั้น1 โซน C) /ALARM" );                    //ข้อความแจ้งเตอนช่อง 3
 Serial.print("***");
             c = 1 ;
             delay(1000);    
          }          
       if (state4 == 1  ){
             Line_Notify(LINE_TOKEN , "Zone4 (ชั้น2 โซน  D ) /ALARM" );               //ข้อความแจ้งเตอนช่อง 4  
Serial.print("***");
             d = 1 ;
             delay(1000);      
          }  
       if (state5 == 1  ){
             Line_Notify(LINE_TOKEN , "Zone5 (ชั้น2 E ) /ALARM" );                 //ข้อความแจ้งเตอนช่อง 5  
Serial.print("***");
             d = 1 ;
             delay(1000);      
          }       
        
        
        if (timesend == 1  ){
              if(state1 == 0 && state2  == 0 && state3  == 0 && state4  == 0 && state5  == 0 )
              Line_Notify(LINE_TOKEN , "Zone1,2,3,4,5 ( สถานะปกติ-ส่งเพื่อตรวจสอบระบบการแจ้งเตือน )  /NORMAL" );            //ข้อความ ส่งเพื่อตรวจสอบระบบการแจ้งเตือน 
 
                
          }
          
if(state1 == 0 && state2  == 0 && state3  == 0  && state4  == 0 && state5  == 0 )                             //เพิ่มลดช่อง แก้ตรงนี้ด้วย  
   {
 
     if(a == 1 || b == 1 || c == 1  || d == 1 || e == 1)
       {
        Line_Notify(LINE_TOKEN , "Zone1,2,3,4,5 ( เข้าสู่สภาวะปกติ )  /NORMAL" );                                    //ข้อความ แจ้ง กลับเข้าสู่สภาวะปกติ 
        a = 0 ;                                                                                                //เพิ่มลดช่อง แก้ตรงนี้ด้วย 
        b = 0 ;                                                                                                      //**
        c = 0 ;                                                                                                      //**
        d = 0 ;                                                                                                      //**
        e = 0 ;                                                                                                //เพิ่มลดช่อง แก้ตรงนี้ด้วย  
       }
    }

  


          
       if (timesend > 7200 ) timesend = 0 ;   // เวลาในการส่งเพื่อตรวจสอบระบบการแจ้งเตือน  120=1นาที   3,600=30นาที  7,200=1ชั่วโมง  89,400=12ชั่วโมง  172,800=1วัน     -35

  Serial.println(timesend);          
  delay(500);
} // loop


void Line_Notify(String LINE_Token, String message) {
  String msg = String("message=") + message;
  WiFiClientSecure client;
  if (!client.connect("notify-api.line.me", 443)) {
    Serial.println("connection failed");
    return;
  }

  String req = "";
  req += "POST /api/notify HTTP/1.1\r\n";
  req += "Host: notify-api.line.me\r\n";
  req += "Content-Type: application/x-www-form-urlencoded\r\n";
  req += "Authorization: Bearer " + String(LINE_Token) + "\r\n";
  req += "Content-Length: " + String(msg.length()) + "\r\n";
  req += "\r\n";
  req +=  msg;

  client.print(req);

  unsigned long timeout = millis();
  while (client.available() == 0) {
    if (millis() - timeout > 5000) {
      Serial.println(">>> Client Timeout !");
      client.stop();
      return;
    }
  }

  // Read all the lines of the reply from server and print them to Serial
  while (client.available()) {
    String line = client.readStringUntil('\r');
    Serial.print(line);
  }

  Serial.println();
  Serial.println("closing connection");
}

  
