/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   leetcode_problem.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelidrys <aelidrys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 10:01:23 by aelidrys          #+#    #+#             */
/*   Updated: 2023/06/03 10:54:55 by aelidrys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef leetcode_problem_h
#define leetcode_problem_h

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <wchar.h>
#include <locale.h>
#include <pthread.h>

typedef struct ListNode{
	int val;
	struct ListNode *next;
}	ListN;

int*	twoSum(int* tab, int size_of_tab, int target, int* rsize);
int		**fourSum(int* nm, int n, int x, int *r, int** Tab);
char	*longestCommonPrefix(char ** strs, int strsSize);
int 	removeElement(int* nums, int nsize, int val);
ListN	*addTwoNumbers(ListN *l1, ListN *l2);
ListN	*mergeTwoLists(ListN* l1, ListN* l2);
int		lengthOfLongestSubstring(char *s);
int		mini_calcul(char *s, size_t *x);
int 	calculater(char *s);
int		isPalindrome(int x);
int		romanToInt(char *s);
int		addDigits(int num);
char	*intToRoman(int x);
ListN	*New_list(int a);
int		isValid(char *s);
int		reverse(int nb);
int		isUgly(int n);

#endif