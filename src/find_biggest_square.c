/*
** EPITECH PROJECT, 2025
** setting_up
** File description:
** Finds the biggest squares and returns it's two opposite corners.
*/

#include "./include/setting_up.h"

static void prepare_board(char **board)
{
    for (int i = 0; board[i] != 0; i++) {
        if (board[i][0] == '.')
            board[i][0] = 12;
        if (board[i][0] == 'o')
            board[i][0] = 11;
    }
    for (int i = 0; board[0][i] != 0; i++) {
        if (board[0][i] == '.')
            board[0][i] = 12;
        if (board[0][i] == 'o')
            board[0][i] = 11;
    }
}

static char set_single_value(char **board, int y, int x)
{
    char min;

    if (y == 0 || x == 0)
        return board[y][x];
    if (board[y][x] == 'o')
        return 11;
    min = board[y - 1][x];
    min = (board[y][x - 1] < min) ? board[y][x - 1] : min;
    min = (board[y - 1][x - 1] < min) ? board[y - 1][x - 1] : min;
    return min + 1;
}

static int get_biggest_number_pos(char **board)
{
    char max = 0;
    char len = str_len(board[0]);
    int x = 0;
    int y = 0;

    for (int i = 0; board[i] != 0; i++) {
        for (int j = 0; board[i][j] != '\n'; j++) {
            y = (board[i][j] > max) ? i : y;
            x = (board[i][j] > max) ? j : x;
            max = (board[i][j] > max) ? board[i][j] : max;
        }
    }
    return y * len + x;
}

// RETURN FORMAT : {y1, y2, x1, x2}
int *find_biggest_square(char **board)
{
    int pos = 0;
    int biggest = 0;
    int len = str_len(board[0]);
    int *result = malloc(sizeof(int) * 4);

    prepare_board(board);
    for (int i = 0; board[i] != 0; i++) {
        for (int j = 0; board[i][j] != '\n'; j++) {
            board[i][j] = set_single_value(board, i, j);
        }
    }
    pos = get_biggest_number_pos(board);
    biggest = board[pos / len][pos % len] - 11;
    result[0] = (pos / len) - biggest + 1;
    result[1] = (pos / len);
    result[2] = (pos % len) - biggest + 1;
    result[3] = (pos % len);
    return result;
}