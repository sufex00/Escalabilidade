#include"sensor.h"

void TMI_init_sensor()
{
    sensor_count = 0;
}

void TMI_add_sensor(sensor_t s)
{
    arr_sensor[s.gpio] = s;
    printf("name = %s\n", arr_sensor[sensor_count].name);
    TMI_rule_verif[s.gpio] = SENS_ADD;
    sensor_count++;
    gpio_enable(s.gpio, GPIO_INPUT);

}

void TMI_list_sensor()
{
    for(int i = 0 ; i < SENSOR_SIZE_MAX ; i++)
    {
        printf("sensor[%13s]= %10s- gpio %d\n", arr_sensor[i].name, TMI_print_sensor_state(TMI_rule_verif[i]), i);
    }
}

char* TMI_print_sensor_state(uint8_t state)
{
  if(state == SENS_EMPTY)
    return "Not found!";

  if(state == SENS_ADD)
    return "Ativate!";

  if(state == SENS_ON)
    return "OK!";

  if(state == SENS_OFF)
    return "Error, check your rules!";
  return " ";
}
