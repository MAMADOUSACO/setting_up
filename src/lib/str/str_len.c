/*
** EPITECH PROJECT, 2025
** setting_up
** File description:
** A function to get the length of a string.
*/

int str_len(const char *str)
{
    int i = 0;
    
    for (; str[i] != 0; i++);
    return i;
}