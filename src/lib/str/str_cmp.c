/*
** EPITECH PROJECT, 2025
** setting_up
** File description:
** A function to compare two strings.
*/

int str_cmp(const char *str1, const char *str2)
{
    for (; *str1 != 0 && *str1 == *str2; str1++, str2++);
    return *str1 - *str2;
}