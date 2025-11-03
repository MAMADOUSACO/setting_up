/*
** EPITECH PROJECT, 2025
** setting_up
** File description:
** A function to free a malloc for a board
*/

#include "./../../include/setting_up.h"

void free_board(char **board)
{
    for (int i = 0; board[i] != 0; i++) {
        free(board[i]);
    }
    free(board);
}