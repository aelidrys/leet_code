OBJ = C_solutions/4sum.o C_solutions/RomanTOint.o C_solutions/basic_calcul.o\
C_solutions/len_str_without_rep.o C_solutions/Sort_list.o           C_solutions/isPalindrome.o\
C_solutions/Valid_Parentheses.o   C_solutions/longestCommonPrefix.o C_solutions/Towsam.o\
C_solutions/add_TO_numbers.o      C_solutions/basic_calcul.o        C_solutions/largest_palin_numb.o\
C_solutions/reverse_int.o         C_solutions/IntTO_Roman.o         C_solutions/add_num.o\
C_solutions/Remove_element.o      C_solutions/2Sort_list.o          C_solutions/Sort_list.o\


CFLAGS = -Wall -Wextra -Werror

LEET = leet.a

build = $(LEET)

run : build clean

build : $(LEET)

$(LEET) : $(OBJ)
	ar -rc $(LEET) $?

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(LEET)

re: fclean build

PHONY: clean build
