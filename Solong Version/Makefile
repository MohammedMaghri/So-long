NAME = solong.a
SRC = graphic_part.c complet_render.c render_wind.c read_map_file.c read_string_to_array.c check_valid.c merge_chek.c display_mssg.c player_array_position.c
OBJS = $(SRC:.c=.o)
var = so_long 
CC = cc 
CFLAGS = -Wall -Wextra -Werror 
RM = rm -rf 
LDFLAGS = -L /usr/local/lib
LDLIBS = -lmlx -framework OpenGL -framework AppKit

all : $(var)

$(var): $(OBJS) mapchek.h
	$(CC) $(CFLAGS) $(LDFLAGS) $(LDLIBS) -o $(var) $(OBJS)

clean : $(var)
	$(RM) $(var)
fclean : clean 
	$(RM) $(OBJS)



	