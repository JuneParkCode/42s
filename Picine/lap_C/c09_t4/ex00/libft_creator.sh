# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    libft_creator.sh                                   :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sungjpar <sungjpar@student.42seoul.>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/22 17:36:27 by sungjpar          #+#    #+#              #
#    Updated: 2022/02/22 18:45:31 by sungjpar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

 gcc -c -Wall -Wextra -Werror ft_putchar.c ft_swap.c ft_putstr.c ft_strlen.c ft_strcmp.c
 ar rc libft.a ft_putchar.o ft_swap.o ft_putstr.o ft_strlen.o ft_strcmp.o
