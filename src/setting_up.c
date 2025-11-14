/*
** EPITECH PROJECT, 2025
** setting_up
** File description:
** Main function for setting up.
*/

#include "./include/setting_up.h"

static bool is_in_corners(int y, int x, int *corners)
{
    if (y < corners[0])
        return false;
    if (y > corners[1])
        return false;
    if (x < corners[2])
        return false;
    if (x > corners[3])
        return false;
    return true;
}

static void print_final_board(char **board, int *corners)
{
    for (int i = 0; board[i] != 0; i++) {
        for (int j = 0; board[i][j] != 0; j++) {
            write(1, (is_in_corners(i, j, corners) == true)? "x" : &board[i][j], 1);
        }
    }
}

static int setting_up_generating(int dimension, char *pattern)
{
    char **board = generate_setting_up(dimension, pattern);
    int *corners;

    if (board == NULL)
        return print_error_msg(4);
    corners = find_biggest_square(board);
    print_final_board(board, corners);
    free_board(board);
    free(corners);
    return 0;
}

static char **load_board(char *path)
{
    int fd = open(path, O_RDONLY);
    char **board;

    if (fd == -1)
        return NULL;
    board = process_setting_up(fd);
    close(fd);
    return board;
}

static int setting_up_file(char *path)
{
    char **board;
    int *corners;

    board = load_board(path);
    if (board == NULL)
        return print_error_msg(5);
    corners = find_biggest_square(board);
    print_final_board(board, corners);
    free_board(board);
    free(corners);
    return 0;
}

int main(int argc, char **argv)
{
    int first_arg = 0;

    if (argc == 1)
        return print_error_msg(0);
    if (str_cmp(argv[1], "-h") == 0)
        return print_help();
    first_arg = str_to_int(argv[1]);
    if (first_arg == 0)
        return print_error_msg(1);
    if (first_arg != -1) {
        if (argc == 2)
            return print_error_msg(2);
        return setting_up_generating(first_arg, argv[2]);
    } else {
        return setting_up_file(argv[1]);
    }
}