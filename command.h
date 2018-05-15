#ifndef COMMAND_H
#define COMMAND_H

#include"fsm.c"

typedef struct
{
  void* func_t;
  int idx
}arr_func;

arr_func cmd_function[cmd_size];

void CMD_init_func();

void CMD_link_func(command_enum c, void *func);

#endif // COMMAND_H
