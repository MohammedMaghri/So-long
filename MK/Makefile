NAME = minitalk.a
SERVER = server.c 
CLIENT = client.c convertV.c 
FT_PRINTF = Printf/libftprintf.a
OBJS1 = $(CLIENT:.c=.o)
OBJS2 = $(SERVER:.c=.o)
cl = client
Sr = server
CC = cc 
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

RED=\033[0;91m
BGRN=\033[1;32m
WHITE=\033[1;97m
NC=\033[0m


all : $(cl) $(Sr)

$(cl) : $(OBJS1) minitalk.h $(FT_PRINTF)
	@echo "$(BGRN) | ON |" "$(WHITE) ****{ SERVER }****"
	@echo "$(BGRN) | ON |" "$(WHITE) ****{ CLIENT }****"
	@$(CC) $(CFLAGS) -o $(cl) $(OBJS1) $(FT_PRINTF)

$(Sr) : $(OBJS2) $(FT_PRINTF)
	@$(CC) $(CFLAGS) -o $(Sr) $(OBJS2) $(FT_PRINTF)

$(FT_PRINTF) : 
	@make -C Printf

%.o: %.c minitalk.h
	@echo "$(BGRN) | COMPILING |" "$(WHITE) ****{ $< }****"
	@$(CC) $(CFLAGS) -c $< -o $@
 
clean :
	@echo "$(RED)| X |" "$(WHITE) ** [ DELETING ]!! ** "
	@rm -rf $(OBJS1) $(OBJS2)
	@make clean -C Printf

re : fclean all 

fclean : clean
	@rm -rf $(NAME) $(Sr) $(cl)
	@make fclean -C Printf