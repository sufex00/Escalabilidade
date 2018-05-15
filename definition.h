#include<string.h>

#include "definition_fsm.h"

#define TMI_RULE_SIZE_MAX 10
#define TMI_rule_check_delay 10

#define SENSOR_SIZE_MAX 10

typedef enum
{
    cmd_add_sensor,
    cmd_list_sensor,
    cmd_size
}command_enum;

typedef enum
{
  state_init,
  state_wait_name,
  state_wait_gpio,
  state_replace,
  state_rule,
  state_rule_learn,
  state_wait_value,
  state_wait_id
}state_t;

#define SENS_EMPTY   255
#define SENS_ADD      0
#define SENS_ON       1
#define SENS_OFF      2
