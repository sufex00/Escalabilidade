#ifndef SENSOR_H
#define SENSOR_H

#include"prototype.c"

typedef struct
{
    uint8_t gpio;
    char name[20];
}sensor_t;

int sensor_count;

sensor_t arr_sensor[SENSOR_SIZE_MAX];

static uint8_t TMI_rule_verif[TMI_RULE_SIZE_MAX];

void TMI_init_sensor();

void TMI_add_sensor(sensor_t s);

void TMI_list_sensor();

char* TMI_print_sensor_state(uint8_t state);


#endif // SENSOR_H
