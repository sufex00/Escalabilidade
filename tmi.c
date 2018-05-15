#include "tmi.h"

void TMI_a_init_lib()
{
    TMI_init_sensor();
    memset(TMI_rule_verif, SENS_EMPTY, TMI_RULE_SIZE_MAX);
    CMD_init_func();
}

static void TMI_t_print_rule(void *pvParameters)
{
    int count = 0;
    while(1)
    {
      printf("Sensor : \n\n");
      TMI_list_sensor();
      printf("##############################################\n");
      printf("Rules : (%d) \n", count_rules);
      TMI_list_rules();
      printf("\n--------------------------------------------\n" );
      vTaskDelay( TMI_rule_check_delay * 1000 / portTICK_PERIOD_MS );
    }
}
