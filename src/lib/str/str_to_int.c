/*
** EPITECH PROJECT, 2025
** setting_up
** File description:
** A function that attempts to convert a given str to an int.
*/

int str_to_int(const char *str)
{
    int result = 0;

    for (int i = 0; str[i] != 0; i++) {
        if (str[i] < '0' || str[i] > '9')
            return -1;
        result = result * 10 + (str[i] - '0');
    }
    return result;
}
