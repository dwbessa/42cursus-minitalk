# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dbessa <dbessa@student.42.rio>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/23 21:45:07 by vde-vasc          #+#    #+#              #
#    Updated: 2024/01/02 13:25:30 by dbessa           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	minitalk
NAMELIB	=	libft.a
CLIENT	=	client
SERVER	= 	server
LIBFT	=	libft/libft.a

all: $(CLIENT) $(SERVER) $(NAMELIB)

$(NAMELIB):
	$(MAKE) -C libft/.
	cp $(LIBFT) ./ 

$(CLIENT): $(NAMELIB)
	gcc -Wall -Wextra -Werror client.c $(NAMELIB) -o $(CLIENT)

$(SERVER): $(NAMELIB)
	gcc -Wall -Wextra -Werror server.c $(NAMELIB) -o $(SERVER)

clean:
	@$(MAKE) fclean -C ./libft

fclean: clean
	@rm -rf $(SERVER)
	@rm -rf $(CLIENT)
	@rm -rf $(NAMELIB)

re: fclean all