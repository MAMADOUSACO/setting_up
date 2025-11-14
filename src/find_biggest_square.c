/*
** EPITECH PROJECT, 2025
** setting_up
** File description:
** Finds the biggest squares and returns it's two opposite corners.
*/

#include "./include/setting_up.h"

static int **create_data_table(char **board)
{
    int height = 0;
    int width = str_len(board[0]) - 1;
    int **data;

    for (int i = 0; board[i] != 0; i++)
        height++;
    data = malloc(sizeof(int *) * height);
    for (int i = 0; i < height; i++) {
        data[i] = malloc(sizeof(int) * width);
        for (int j = 0; j < width; j++)
            data[i][j] = 0;
    }
    return data;
}

static void free_data_table(int **data, char **board)
{
    for (int i = 0; board[i] != 0; i++)
        free(data[i]);
    free(data);
}

static void initialize_data(int **data, char **board)
{
    int width = str_len(board[0]) - 1;

    for (int i = 0; board[i] != 0; i++) {
        if (board[i][0] == '.')
            data[i][0] = 1;
        else
            data[i][0] = 0;
    }
    for (int j = 0; j < width; j++) {
        if (board[0][j] == '.')
            data[0][j] = 1;
        else
            data[0][j] = 0;
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

static int get_biggest_square_pos(int **data, char **board)
{
    int max = 0;
    int width = str_len(board[0]) - 1;
    int pos_y = 0;
    int pos_x = 0;

    for (int i = 0; board[i] != 0; i++) {
        for (int j = 0; j < width; j++) {
            pos_y = (data[i][j] > max) ? i : pos_y;
            pos_x = (data[i][j] > max) ? j : pos_x;
            max = (data[i][j] > max) ? data[i][j] : max;
        }
    }
    return pos_y * width + pos_x;
}

static void fill_data_table(int **data, char **board)
{
    int width = str_len(board[0]) - 1;

    for (int i = 1; board[i] != 0; i++) {
        for (int j = 1; j < width; j++) {
            data[i][j] = (board[i][j] == 'o') ? 0 : min3(
                data[i - 1][j],
                data[i][j - 1],
                data[i - 1][j - 1]) + 1;
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
    int **data = create_data_table(board);
    int width = str_len(board[0]) - 1;
    int pos;
    int biggest;
    int *result;

    initialize_data(data, board);
    fill_data_table(data, board);
    pos = get_biggest_square_pos(data, board);
    biggest = data[pos / width][pos % width];
    result = calculate_corners(pos, width, biggest);
    free_data_table(data, board);
    return result;
}
