/*
** EPITECH PROJECT, 2025
** setting_up
** File description:
** Generates a char ** for setting up given arguments.
*/

#include "./include/setting_up.h"

static int read_line_count(int fd)
{
    char buffer[10];
    char current_char;
    int i = 0;
    int read_result = read(fd, &current_char, 1);

    while (read_result == 1) {
        if (current_char == '\n')
            break;
        if (current_char < '0' || current_char > '9')
            return -1;
        if (i >= 9)
            return -1;
        buffer[i] = current_char;
        i++;
        read_result = read(fd, &current_char, 1);
    }
    if (read_result != 1 || i == 0)
        return -1;
    buffer[i] = 0;
    return str_to_int(buffer);
}

static char *read_first_line(int fd)
{
    char *line = malloc(sizeof(char) * 10000);
    char buffer;
    int i = 0;

    if (line == NULL)
        return NULL;
    while (read(fd, &buffer, 1) == 1) {
        if (buffer != '.' && buffer != 'o' && buffer != '\n') {
            free(line);
            return NULL;
        }
        line[i] = buffer;
        i++;
        if (buffer == '\n') {
            line[i] = 0;
            return line;
        }
    }
    free(line);
    return NULL;
}

static char *read_single_line(int fd, int expected_len)
{
    char *line = malloc(sizeof(char) * (expected_len + 1));

    if (line == NULL)
        return NULL;
    if (read(fd, line, expected_len) < expected_len) {
        free(line);
        return NULL;
    }
    if (line[expected_len - 1] != '\n') {
        free(line);
        return NULL;
    }
    line[expected_len] = 0;
    for (int i = 0; i < expected_len - 1; i++) {
        if (line[i] != '.' && line[i] != 'o') {
            free(line);
            return NULL;
        }
    }
    return line;
}

static char **allocate_board(int line_count)
{
    char **board = malloc(sizeof(char *) * (line_count + 1));

    if (board == NULL)
        return NULL;
    board[line_count] = NULL;
    return board;
}

static char **read_board_lines(int fd, char **board,
    int line_count, int expected_len)
{
    char end_buff;

    for (int i = 1; i < line_count; i++) {
        board[i] = read_single_line(fd, expected_len);
        if (board[i] == NULL) {
            free_board(board);
            return NULL;
        }
        if (str_len(board[i]) != expected_len) {
            free_board(board);
            return NULL;
        }
    }
    if (read(fd, &end_buff, 1) == 1) {
        free_board(board);
        return NULL;
    }
    return board;
}

char **process_setting_up(int fd)
{
    int line_count = read_line_count(fd);
    char **board;

    if (line_count <= 0)
        return NULL;
    board = allocate_board(line_count);
    if (board == NULL)
        return NULL;
    board[0] = read_first_line(fd);
    if (board[0] == NULL) {
        free(board);
        return NULL;
    }
    return read_board_lines(fd, board, line_count, str_len(board[0]));
}
