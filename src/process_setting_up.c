/*
** EPITECH PROJECT, 2025
** setting_up
** File description:
** Generates a char ** for setting up given arguments.
*/

#include "./include/setting_up.h"

static int confirm_amount_lines(int fd)
{
    char read_char = 0;
    int number = 0;
    int i = 0;

    read(fd, read_char, 1);
    for (; read_char >= '0' && read_char <= '9';) {
        number = (number * 10) + (lines[i] - '0');
    }
    if (read_char != '\n')
        return 0;
    return number;
}

static int is_end_line(char buffer[])
{
    for (int i = 0; i < 10; i++) {
        if (buffer[i] == '\n')
            return i;
    }
    return 0;
}

static int get_first_line_length(int fd)
{
    char buffer[10];
    int total = 0;
    int found_line_end = 10;

    while (found_line_end == 10) {
        read(fd, buffer, 10);
        found_line_end = is_end_line(buffer);
    }
}

char **process_setting_up(int fd)
{
    int lines = confirm_amount_lines(fd);
    int first_line_length = get_first_line_length(fd);
    char **test = malloc(sizeof(char*) * 2);

    return test;
}