NAME = solong.a
SRC = cleaning.c map_chek_mssgdisplay.c player_positiong_map.c player_position_file.c read_from_file.c make_string_in_array.c
OBJS = $(SRC:.c=.o)
CC = cc 
CFLAGS = -Wall -Wextra -Werror
check = Check

all : $(check);
$(check) : $(OBJS) mapchek.h
	$(CC) $(CFLAGS) -o $(check) $(OBJS)
clean  : 
	rm -rf $(OBJS)
fclean : clean 
	rm -rf $(check)