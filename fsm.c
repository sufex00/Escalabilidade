#include "fsm.h"

void FSM_init()
{
    fsm_state = state_init;
}

void FSM(char str[30])
{
    if(fsm_state == state_init)
    {
      if (str[0] == FSM_add)
          fsm_state = state_wait_name;

      if (str[0] == FSM_rule)
          fsm_state = state_rule_learn;
    }

    else if(fsm_state == state_wait_name)
    {
        exec_cmd(str); // máquina de Mealy
        fsm_state = state_wait_gpio;
    }

    else if(fsm_state == state_wait_gpio)
    {
        if(str[0] >= '0' && str[0] <= '9')
        {
            exec_cmd(str); // máquina de Mealy
            fsm_state = state_init;
        }
    }
    else if(fsm_state == state_rule_learn)
    {
        if(str[0] == TMI_equal ||  str[0] == TMI_diff)
        {
            exec_cmd(str); // máquina de Mealy
            fsm_state = state_wait_value;

        }
    }
    else if(fsm_state == state_wait_value)
    {
      if(str[1] >= '0' && str[1] <= '9')
      {
          if(str[0] >= '0' && str[0] <= '9')
          {
              exec_cmd(str); // máquina de Mealy
              fsm_state = state_wait_id;
        }
      }
    }
    else if(fsm_state == state_wait_id)
    {
      if(str[0] >= '0' && str[0] <= '9')
      {
          exec_cmd(str); // máquina de Mealy
          fsm_state = state_init;
      }
    }
}

void exec_cmd(char str[30])
{
    sensor_t s;
    strcpy(s.name, aux_sensor.name);
    if (fsm_state == state_wait_name)
    {
        strcpy(aux_sensor.name, str);
    }

    if(fsm_state == state_wait_gpio)
    {
        uint8_t gpio_ = str[0]-'0';  //convert char -> int
        s.gpio = gpio_;
        TMI_add_sensor(s);
    }

    if(fsm_state == state_rule_learn)
    {
      if(str[0] == TMI_equal)
        aux_rules.rule = equal;

      else if(str[0] == TMI_diff)
        aux_rules.rule = diff;
    }
    if(fsm_state == state_wait_value)
    {
      aux_rules.value = (str[0]-'0') * 10 + (str[1]-'0');
    }

    if(fsm_state == state_wait_id)
    {
        aux_rules.gpio = str[0] - '0';
        TMI_add_rules(aux_rules);
    }
}

uint8_t isGPIO(uint8_t gpio)
{
	int isReturn = -1;
	for (int i=0 ; i < sensor_count ; i++)
	{
		if(arr_sensor[i].gpio == gpio)
		{
			isReturn = i;
		}
	}
	return isReturn;
}

void FSM_print()
{
  printf("state = %d\n", fsm_state);
}
