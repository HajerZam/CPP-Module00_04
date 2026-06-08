NAME    = megaphone
CXX     = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

$(NAME): megaphone.cpp
	$(CXX) $(CXXFLAGS) megaphone.cpp -o $(NAME)

clean:
	rm -f $(NAME)

fclean: clean

re: fclean $(NAME)