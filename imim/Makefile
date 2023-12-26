NAME = solong.a
SRC = cleaning.c map_chek_mssgdisplay.c player_positiong_map.c player_position_file.c read_from_file.c make_string_in_array.c
OBJS = $(SRC:.c=.o)
CC = cc 
CFLAGS = -Wall -Wextra -Werror
check = Check

all : $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME) : $(OBJS)
	ar rcs $@ $^

$(check) : $(OBJS) mapchek.h
	$(CC) $(CFLAGS) -o $(check) $(OBJS)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME) $(check)

re: fclean all

.PHONY: all clean fclean re
