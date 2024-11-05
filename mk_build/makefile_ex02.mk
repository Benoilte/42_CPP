# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile_ex02.mk                                   :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/05 15:17:31 by bebrandt          #+#    #+#              #
#    Updated: 2024/11/05 15:17:32 by bebrandt         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

EX_02_DIR		= 	ex02/
TEST_EX_02_DIR	= 	spec/ex02/

ex02:
	@make -C $(EX_02_DIR) $(MAKEFLAGS)
	@[ ! -f $(EX_02_DIR)$(EX_02_NAME) ] || mv $(EX_02_DIR)$(EX_02_NAME) .

fclean_ex02:
	@make fclean -C $(EX_02_DIR) $(MAKEFLAGS)
	@rm $(EX_02_NAME)

re_ex02: fclean_ex02 ex02

test_ex02:
	@make -C $(TEST_EX_02_DIR) $(MAKEFLAGS)
	@[ ! -f $(TEST_EX_02_DIR)$(TEST_EX_02_NAME) ] || mv $(TEST_EX_02_DIR)$(TEST_EX_02_NAME) .

fclean_test_ex02:
	@make fclean -C $(TEST_EX_02_DIR) $(MAKEFLAGS)
	@rm $(TEST_EX_02_NAME)

re_test_ex02: fclean_test_ex02 test_ex02

all_ex02: ex02 test_ex02

fclean_all_ex02: fclean_ex02 fclean_test_ex02

re_all_ex02: re_ex02 re_test_ex02

.PHONY:		ex02 fclean_ex02 re_ex02 \
			test_ex02 fclean_test_ex02 re_test_ex02 \
			all_ex02 fclean_all_ex02 re_all_ex02
