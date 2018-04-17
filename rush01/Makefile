.PHONY: clean fclean re r
CC = clang++
CFLAGS = -Wall -Wextra -Werror
FFLAGS = -lncurses -F ~/Library/Frameworks -framework SDL2 -framework SDL2_ttf
ODIR = objs/
SDIR = srcs/
IDIR = includes/
NAME = ft_FKrellM
FILES = GetData.cpp Monitor.cpp TextMonitor.cpp main.cpp GraphicalMonitor.cpp
OBJS = $(FILES:.cpp=.o)

all: $(NAME)

$(NAME):
	@echo "\x1b[34m\nCompiling $@\x1b[0m"
	@$(CC) $(CFLAGS) $(FFLAGS) -I$(IDIR) -o $@ $(addprefix $(SDIR), $(FILES))

# $(NAME): $(addprefix $(ODIR), $(OBJS))
# 	@echo "\x1b[34m\nCompiling $@\x1b[0m"
# 	@$(CC) $(CFLAGS) $(FFALGS) -I$(IDIR) -o $@ $^

$(addprefix $(ODIR), %.o): $(addprefix $(SDIR), %.cpp)
	@printf "."
	@$(CC) $(CFLAGS) -I$(IDIR) -c -o $@ $<

clean:
	@echo "\x1b[31mRemoving the object files of $(NAME)\x1b[0m"
	@rm -f $(addprefix $(ODIR), $(OBJS))

fclean: clean
	@echo "\x1b[31mRemoving the $(NAME)\x1b[0m"
	@rm -rf $(NAME) $(NAME).dSYM

re:
	@$(MAKE) fclean
	@$(MAKE)

r: $(NAME)
	@echo "\x1b[32m\nRunning $(NAME)\n\x1b[0m"
	@./$<
