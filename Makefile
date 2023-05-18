OBJ = 4sum.o RomanTOint.o basic_calcul.o len_str_without_rep.o Sort_list.o isPalindrome.o\
Valid_Parentheses.o longestCommonPrefix.o Towsam.o add_TO_numbers.o basic_calcul.o\
largest_palin_numb reverse_int.o IntTO_Roman.o add_num.o 2Sort_list.o Sort_list.o\
Remove_element.o

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
