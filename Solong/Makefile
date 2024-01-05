NAME = solong.a
SRC = graphic_part.c number_to_str.c move_player.c render_wind.c read_map_file.c read_string_to_array.c check_valid.c merge_chek.c display_mssg.c player_array_position.c mlx_failed.c
OBJS = $(SRC:.c=.o)
var = so_long 
bonus = so_long_bonus
CC = cc 
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
LDFLAGS = -L /usr/local/lib
LDLIBS = -lmlx -framework OpenGL -framework AppKit

all : $(var)

bonus : $(bonus)

$(var): $(OBJS) mapchek.h
	$(CC) $(CFLAGS) $(LDFLAGS) $(LDLIBS) -o $(var) $(OBJS)

$(bonus): $(OBJS) mapchek.h
	$(CC) $(CFLAGS) $(LDFLAGS) $(LDLIBS) -o $(bonus) $(OBJS)

%.o: %.c mapchek.h
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	$(RM) $(OBJS)

re: fclean  all

fclean : clean
	$(RM) $(var) $(bonus)

.PHONY : clean fclean re all
