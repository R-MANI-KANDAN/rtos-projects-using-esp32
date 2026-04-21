#if CONFIG_FREERTOS_UNITCORE
static const BaseType_t app_cpu=0;
#else 
static const BaseType_t app_cpu=1;
#endif

long int blink_rate = 1000 ;
int led = 2;


// TASK 1
void LED_BLINK (void *parameter){
while(1){
  digitalWrite(led , HIGH);
  vTaskDelay(blink_rate/portTICK_PERIOD_MS);
  digitalWrite(led , LOW);
  vTaskDelay(blink_rate/portTICK_PERIOD_MS);
}
}

//TASK 2 

void CONTROL_LED_BLINK(void *parameter){
while(1){
  if(Serial.available() != 0){
  Serial.println("ENTER THE BLINK RATE = ");
  String new_blink_rate =  Serial.readStringUntil('\n');
  blink_rate = new_blink_rate.toInt() ;
  Serial.println(blink_rate);
  vTaskDelay(1000 / portTICK_PERIOD_MS);  

  }
}

}

void setup(){
  Serial.begin(115200);
  Serial.println("SERIAL MONITOR ON ");
  Serial.println("ENTER THE BLINK RATE = ");
  pinMode(led,OUTPUT);
  xTaskCreatePinnedToCore(
    LED_BLINK,
    "LED_BLINK",
    1024,
    NULL,
    1,
    NULL,
    app_cpu
  );

  xTaskCreatePinnedToCore(
    CONTROL_LED_BLINK,
    "CONTROL_LED_BLINK",
    1024,
    NULL,
    1,
    NULL,
    app_cpu
  );

}

void loop (){}


