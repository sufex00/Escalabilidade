#ifndef FSM_H
#define FSM_H

#include<stdio.h>

#include "sensor.c"

state_t fsm_state;
sensor_t aux_sensor;
rules_t aux_rules;

void FSM_init();

void FSM(char str[30]);

void exec_cmd(char str[30]);

void FSM_print();

#endif // FSM_H
