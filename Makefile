# Compilation
TARGET := setting_up
CC := clang
FLAGS := -Wall -Wextra -Wno-implicit-function-declaration -g3

# Sources
MAIN_FILES := ./src/setting_up.c ./src/generate_setting_up.c ./src/find_biggest_square.c ./src/process_setting_up_file.c
STR_LIB := ./src/lib/str/str_len.c ./src/lib/str/str_to_int.c ./src/lib/str/str_cmp.c
MEMORY_LIB := ./src/lib/memory/free_board.c
DEBUG_LIB := ./src/lib/debug/print_error_msg.c ./src/lib/debug/print_help.c
TESTS := ./tests/str_tests.c

# Data
SRC := $(MAIN_FILES) $(STR_LIB) $(MEMORY_LIB) $(DEBUG_LIB)
OBJ := $(SRC:.c=.o)
HDR := ./src/include/setting_up.h

all: $(TARGET) clean

$(TARGET): $(OBJ)
	$(CC) $(FLAGS) $(SRC) -o $(TARGET)

clean:
	rm -f $(shell find . -name '*.o')
	rm -f $(shell find . -name '*.c~')
	rm -f $(shell find . -name '*.h~')
	rm -f $(shell find . -name '*#*')
	rm -f $(shell find . -name '*.pch')
	rm -f $(shell find . -name '*.out')
	rm -f $(shell find . -name '*~')

fclean: clean
	rm -f $(shell find . -name '$(TARGET)')

re: fclean $(TARGET)

print_src:
	$(info $(shell find . -name '*.c'))

epiclang_all:
	epiclang $(SRC) $(HDR)