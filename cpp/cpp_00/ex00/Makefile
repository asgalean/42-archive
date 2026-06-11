CXX			= c++
CXXFLAGS	= -Wall -Wextra -Werror -std=c++98

# Program name
NAME		= megaphone

# Source files
SRCS		= megaphone.cpp

# Object files
OBJS		= $(SRCS:.cpp=.o)

# Colors for pretty output
GREEN		= \033[0;32m
RED			= \033[0;31m
RESET		= \033[0m

# Default rule
all: $(NAME)

# Link object files to create executable
$(NAME): $(OBJS)
	@echo "$(GREEN)Linking $(NAME)...$(RESET)"
	@$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)
	@echo "$(GREEN)Build complete!$(RESET)"

# Compile source files to object files
%.o: %.cpp
	@echo "$(GREEN)Compiling $<...$(RESET)"
	@$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean object files
clean:
	@echo "$(RED)Removing object files...$(RESET)"
	@rm -f $(OBJS)

# Clean everything (objects and executable)
fclean: clean
	@echo "$(RED)Removing $(NAME)...$(RESET)"
	@rm -f $(NAME)

# Rebuild everything
re: fclean all

# Phony targets (not actual files)
.PHONY: all clean fclean re
