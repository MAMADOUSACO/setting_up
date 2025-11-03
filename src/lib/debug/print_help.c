/*
** EPITECH PROJECT, 2025
** setting_up
** File description:
** A function to print the help.
*/

#include "./../../include/setting_up.h"

int print_help(void)
{
    write(1, "USAGE :\n", 8);
    write(1, "CASE 1 : ./setting_up [FILE]\n", 29);
    write(1, "CASE 2 : ./setting_up [DIMENSION] [PATTERN]\n", 44);
    return 0;
}