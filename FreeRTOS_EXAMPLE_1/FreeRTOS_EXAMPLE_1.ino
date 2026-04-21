#if CONFIG_FREERTOS_UNITCORE
static const BaseType_t app_cpu=0;
#else 
static const BaseType_t app_cpu=1;
#endif

static const int led_pin = 2;
      //TASK
void toggle_led(void *parameter){
  while(1){
  digitalWrite(led_pin,HIGH);
  vTaskDelay(500/portTICK_PERIOD_MS);
  digitalWrite(led_pin,LOW);
  vTaskDelay(500/portTICK_PERIOD_MS);
  }
}

void toggle_led_2(void *parameter){
  while(1){
  digitalWrite(led_pin,HIGH);
  vTaskDelay(300/portTICK_PERIOD_MS);
  digitalWrite(led_pin,LOW);
  vTaskDelay(300/portTICK_PERIOD_MS);
  }
}

void setup(){
  pinMode(led_pin,OUTPUT);

  xTaskCreatePinnedToCore (
  toggle_led , 
  "toggle_led",
  1024,
  NULL,//parameter
  1,//priority of the task 
  NULL,//task handler
  app_cpu); // tells the esp32 to run which code 


  xTaskCreatePinnedToCore (
  toggle_led_2 , 
  "toggle_led_2",
  1024,
  NULL,//parameter
  1,//priority of the task 
  NULL,//task handler
  app_cpu); // tells the esp32 to run which code 
}

void loop(){}