/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Valid_Parentheses.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelidrys <aelidrys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 15:51:52 by aelidrys          #+#    #+#             */
/*   Updated: 2023/06/03 11:02:16 by aelidrys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../leetcode_problem.h"

int isValid(char *s){
    int a = 0;
    int x = -1;
    char *p;
	p = malloc(strlen(s) * sizeof(char));
    if (!s)
        return (0);
    while (s[a]){
        if ((s[a] == ')' || s[a] == '}' || s[a] == ']') && x == -1)
            return (0);
        if (s[a] == '(' || s[a] == '{' || s[a] == '['){
			x++;
            p[x] = s[a];
		}
		if (s[a] == ')' && x != -1 && p[x] != '(')
			return (0);
		if (s[a] == ')' && x != -1 && p[x] == '(')
			x--;
		if (s[a] == '}' && x != -1 && p[x] != '{')
			return (0);
		if (s[a] == '}' && x != -1 && p[x] == '{')
			x--;
		if (s[a] == ']' && x != -1 && p[x] != '[')
			return (0);
		if (s[a] == ']' && x != -1 && p[x] == '[')
			x--;
		a++;
    }
    if (x != -1)
        return (0);
    return (1);
}
