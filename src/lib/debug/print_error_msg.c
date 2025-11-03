/*
** EPITECH PROJECT, 2025
** setting_up
** File description:
** A function to print error messages.
*/

#include "./../../include/setting_up.h"

int print_error_msg(const int enum_code)
{
    char *ERROR_MSGS[6] = {
        "No arguments provided!",
        "Dimension can't be 0!",
        "No pattern provided!",
        "File couldn't be opened!",
        "Pattern isn't correct!",
        NULL,
    };

    write(2, ERROR_MSGS[enum_code], str_len(ERROR_MSGS[enum_code]));
    write(2, "\n", 1);
    return 84;
}