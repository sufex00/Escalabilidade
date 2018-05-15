#ifndef PROTOTYPE_H
#define PROTOTYPE_H

#include "definition.h"

typedef struct
{
    rule_learn rule;
    uint8_t value;
    uint8_t gpio;
}rules_t;

rules_t arr_rules[TMI_RULE_SIZE_MAX];

uint8_t count_rules;

void TMI_rule_init();

void TMI_add_rules(rules_t r);

void TMI_list_rules();

char* TMI_print_rule_state(rules_t r);

uint8_t TMI_read_gpio(uint8_t gpio); 

#endif // PROTOTYPE_H
