# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile_ex00.mk                                   :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/05 14:13:37 by bebrandt          #+#    #+#              #
#    Updated: 2024/11/05 15:15:21 by bebrandt         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

EX_00_DIR		= 	ex00/
TEST_EX_00_DIR	= 	spec/ex00/

ex00:
	@make -C $(EX_00_DIR) $(MAKEFLAGS)
	@[ ! -f $(EX_00_DIR)$(EX_00_NAME) ] || mv $(EX_00_DIR)$(EX_00_NAME) .

fclean_ex00:
	@make fclean -C $(EX_00_DIR) $(MAKEFLAGS)
	@rm $(EX_00_NAME)

re_ex00: fclean_ex00 ex00

test_ex00:
	@make -C $(TEST_EX_00_DIR) $(MAKEFLAGS)
	@[ ! -f $(TEST_EX_00_DIR)$(TEST_EX_00_NAME) ] || mv $(TEST_EX_00_DIR)$(TEST_EX_00_NAME) .

fclean_test_ex00:
	@make fclean -C $(TEST_EX_00_DIR) $(MAKEFLAGS)
	@rm $(TEST_EX_00_NAME)

re_test_ex00: fclean_test_ex00 test_ex00

all_ex00: ex00 test_ex00

fclean_all_ex00: fclean_ex00 fclean_test_ex00

re_all_ex00: re_ex00 re_test_ex00

.PHONY:		ex00 fclean_ex00 re_ex00 \
			test_ex00 fclean_test_ex00 re_test_ex00 \
			all_ex00 fclean_all_ex00 re_all_ex00
