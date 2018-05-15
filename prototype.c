#include "prototype.h"

void TMI_rule_init()
{
    count_rules = 0;
}

void TMI_add_rules(rules_t r)
{
    arr_rules[count_rules] = r;
    count_rules ++;
}

char* TMI_print_state(rule_learn r)
{
    if(r == equal)
      return "Equal ";

    if(r == diff)
      return "Diff ";

    return " ";
}

uint8_t TMI_read_gpio(uint8_t gpio)
{
  return gpio_read(gpio);
}

char* TMI_print_rule_state(rules_t r)
{
    char str[20];
    if(r.rule == equal)
    {
        int gpio = r.gpio;
        int read_gpio = TMI_read_gpio(gpio);
        if(r.value == read_gpio)
        {
          return "OK!";
        }
        else
        {
            return "FALSE!";
        }
    }

    if(r.rule == diff)
    {
        int gpio = r.gpio;
        int read_gpio = TMI_read_gpio(gpio);
        if(r.value != read_gpio)
        {
          return "OK!";
        }
        else
        {
            return "FALSE!";
        }
    }
    return str;
}

void TMI_list_rules()
{
    printf("Rules - \n");
    for(int i=0 ; i < count_rules ; i++)
    {
        rules_t r = arr_rules[i];
        printf("\ngpio[%2d] = %10s - value = %2d - Check [%6s]", r.gpio, TMI_print_state(arr_rules[i].rule), arr_rules[i].value, TMI_print_rule_state(r));
    }
}
