/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   len_str_without_rep.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelidrys <aelidrys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 07:12:32 by aelidrys          #+#    #+#             */
/*   Updated: 2023/01/28 12:40:47 by aelidrys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "leetcode_problem.h"

int     a_chr(char *p, char c){
    int x = 0;
    if (!p)
        return (0);
    while (p[x]){
        if (p[x++] == c)
            return (1);
    }
    return (0);
}

int lengthOfLongestSubstring(char * s)
{
    char *p;
    int x = 0;
    int y = 0;
    int z = 0;
    int n = 0;
	if (!s)
		return (0);
    p = malloc (strlen(s) * sizeof(char));
    while (s[x]){
        y = x;
        z = 0;
        while (s[y]){
            if (a_chr(p, s[y]))
                break;
            p[z++] = s[y++];
        }
        y = 0;
        while (p[y]){
            p[y++] = '\0';
        }
        if (z > n)
            n = z;
        x++;
    }
	free(p);
    return (n);
}
