#ifndef SETTING_UP_H_
    #define SETTING_UP_H_

    #include <stdbool.h>
    #include <stdlib.h>
    #include <stdio.h>
    #include <unistd.h>
    #include <stdint.h>
    #include <fcntl.h>

// DEBUG FUNCTIONS
int print_help(void);
int print_error_msg(int enum_code);

// STR FUNCTIONS
int str_len(const char *str);
int str_cmp(const char *str1, const char *str2);
int str_to_int(const char *str);

// MEMORY FUNCTIONS
void free_board(char **setting_up);

// MAIN FUNCTIONS
char **generate_setting_up(int dimension, char *pattern);
int *find_biggest_square(char **board);

#endif