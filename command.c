#include "command.h"

void CMD_init_func()
{
    cmd_function[cmd_list_sensor].func_t = TMI_list_sensor;
    cmd_function[cmd_add_sensor].func_t = TMI_add_sensor;
}

void CMD_link_func(command_enum c, void* func_t)
{
    cmd_function[c].func_t = func_t;
}
