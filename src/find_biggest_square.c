/*
** EPITECH PROJECT, 2025
** setting_up
** File description:
** Finds the biggest squares and returns it's two opposite corners.
*/

#include "./include/setting_up.h"

static int **create_dp_table(char **board)
{
    int height = 0;
    int width = str_len(board[0]) - 1;
    int **dp;

    for (int i = 0; board[i] != 0; i++)
        height++;
    dp = malloc(sizeof(int *) * height);
    for (int i = 0; i < height; i++) {
        dp[i] = malloc(sizeof(int) * width);
        for (int j = 0; j < width; j++)
            dp[i][j] = 0;
    }
    return dp;
}

static void free_dp_table(int **dp, char **board)
{
    for (int i = 0; board[i] != 0; i++)
        free(dp[i]);
    free(dp);
}

static void initialize_dp(int **dp, char **board)
{
    int width = str_len(board[0]) - 1;

    for (int i = 0; board[i] != 0; i++) {
        if (board[i][0] == '.')
            dp[i][0] = 1;
        else
            dp[i][0] = 0;
    }
    for (int j = 0; j < width; j++) {
        if (board[0][j] == '.')
            dp[0][j] = 1;
        else
            dp[0][j] = 0;
    }
}

static int min3(int a, int b, int c)
{
    int min = a;

    if (b < min)
        min = b;
    if (c < min)
        min = c;
    return min;
}

static int get_biggest_square_pos(int **dp, char **board)
{
    int max = 0;
    int width = str_len(board[0]) - 1;
    int pos_y = 0;
    int pos_x = 0;

    for (int i = 0; board[i] != 0; i++) {
        for (int j = 0; j < width; j++) {
            if (dp[i][j] > max) {
                max = dp[i][j];
                pos_y = i;
                pos_x = j;
            }
        }
    }
    return pos_y * width + pos_x;
}

static void fill_dp_table(int **dp, char **board)
{
    int width = str_len(board[0]) - 1;

    for (int i = 1; board[i] != 0; i++) {
        for (int j = 1; j < width; j++) {
            if (board[i][j] == 'o') {
                dp[i][j] = 0;
            } else {
                dp[i][j] = min3(dp[i - 1][j], dp[i][j - 1],
                    dp[i - 1][j - 1]) + 1;
            }
        }
    }
}

static int *calculate_corners(int pos, int width, int biggest)
{
    int *result = malloc(sizeof(int) * 4);

    result[0] = (pos / width) - biggest + 1;
    result[1] = (pos / width);
    result[2] = (pos % width) - biggest + 1;
    result[3] = (pos % width);
    return result;
}

// RETURN FORMAT : {y1, y2, x1, x2}
int *find_biggest_square(char **board)
{
    int **dp = create_dp_table(board);
    int width = str_len(board[0]) - 1;
    int pos, biggest;
    int *result;

    initialize_dp(dp, board);
    fill_dp_table(dp, board);
    pos = get_biggest_square_pos(dp, board);
    biggest = dp[pos / width][pos % width];
    result = calculate_corners(pos, width, biggest);
    free_dp_table(dp, board);
    return result;
}