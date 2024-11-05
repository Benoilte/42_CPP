# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile_ex01.mk                                   :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/05 14:16:21 by bebrandt          #+#    #+#              #
#    Updated: 2024/11/05 14:17:00 by bebrandt         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

EX_01_DIR		= 	ex01/
EX_01_NAME		=	megaphone
TEST_EX_01_DIR	= 	spec/ex01/
TEST_EX_01_NAME	=	test_megaphone

ex01:
	@make -C $(EX_01_DIR) $(MAKEFLAGS)
	@[ ! -f $(EX_01_DIR)$(EX_01_NAME) ] || mv $(EX_01_DIR)$(EX_01_NAME) .

fclean_ex01:
	@make fclean -C $(EX_01_DIR) $(MAKEFLAGS)
	@rm $(EX_01_NAME)

re_ex01: fclean_ex01 ex01

test_ex01:
	@make -C $(TEST_EX_01_DIR) $(MAKEFLAGS)
	@[ ! -f $(TEST_EX_01_DIR)$(TEST_EX_01_NAME) ] || mv $(TEST_EX_01_DIR)$(TEST_EX_01_NAME) .

fclean_test_ex01:
	@make fclean -C $(TEST_EX_01_DIR) $(MAKEFLAGS)
	@rm $(TEST_EX_01_NAME)

re_test_ex01: fclean_test_ex01 test_ex01

all_ex01: ex01 test_ex01

fclean_all_ex01: fclean_ex01 fclean_test_ex01

re_all_ex01: re_ex01 re_test_ex01

.PHONY:		ex01 fclean_ex01 re_ex01 \
			test_ex01 fclean_test_ex01 re_test_ex01 \
			all_ex01 fclean_all_ex01 re_all_ex01
