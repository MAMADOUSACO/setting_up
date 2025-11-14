/*
** EPITECH PROJECT, 2025
** setting_up
** File description:
** Generates a char ** for setting up given arguments.
*/

#include "./include/setting_up.h"

static bool is_pattern_correct(char *pattern)
{
    for (int i = 0; pattern[i] != 0; i++) {
        if (pattern[i] != '.' && pattern[i] != 'o')
            return false;
    }
    return true;
}

static char **malloc_result(int dimension)
{
    char **result = malloc(sizeof(char*) * (dimension + 1));

    result[dimension] = NULL;
    for (int i = 0; i < dimension; i++) {
        result[i] = malloc(sizeof(char) * (dimension + 2));
        result[i][dimension] = '\n';
        result[i][dimension + 1] = 0;
    }
    return result;
}

char **generate_setting_up(int dimension, char *pattern)
{
    int pos = 0;
    int pattern_len = str_len(pattern);
    char **result;

    if (is_pattern_correct(pattern) == false)
        return 0;
    result = malloc_result(dimension);
    for (int i = 0; i < dimension; i++) {
        for (int j = 0; j < dimension; j++) {
            result[i][j] = pattern[pos];
            pos = (pos == pattern_len - 1) ? 0 : pos + 1;
        }
    }
    return result;
}