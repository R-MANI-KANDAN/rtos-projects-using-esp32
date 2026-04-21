#if CONFIG_FREERTOS_UNITCORE
static const BaseType_t app_cpu=0;
#else 
static const BaseType_t app_cpu=1;
#endif

const char message[] = "welcome to embedded class";
static TaskHandle_t task_1 = NULL;
static TaskHandle_t task_2 = NULL;


void string_length(void *parameter){
while(1){
  for(int i =0;i<strlen(message);i++){
    Serial.print(message[i]);
  }
      Serial.println();
  vTaskDelay(1000/portTICK_PERIOD_MS);

}
}

void display_char(void *parameter){
  while(1){
    Serial.println("*");
    vTaskDelay(100/portTICK_PERIOD_MS);

  }
}

void setup(){
  Serial.begin(300);
  vTaskDelay(1000/portTICK_PERIOD_MS);
  Serial.println("FreeRTOS demo");
  Serial.print("Setup and loop task");
  Serial.print(xPortGetCoreID());
  Serial.println("with priority");
  Serial.print(uxTaskPriorityGet(NULL));

   xTaskCreatePinnedToCore (
  string_length, 
  "string_length", 
  1024,//stack size
  NULL,//parameter
  1,//priority of the task 
  &task_1,//task handler
  app_cpu); // tells the esp32 to run which code 

xTaskCreatePinnedToCore (
  display_char, 
  "display_char",
  1024,
  NULL,//parameter
  2,//priority of the task 
  &task_2,//task handler
  app_cpu); // tells the esp32 to run which code 

}


void loop(){
  for(int j =0 ; j<3;j++){
    vTaskSuspend(task_2);
    vTaskDelay(2000/portTICK_PERIOD_MS);
    vTaskResume(task_2);
    vTaskDelay(2000/portTICK_PERIOD_MS);
  }
if(task_1 != NULL){
  vTaskDelete(task_1);
  task_1 = NULL;
}

  }
