/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   longestCommonPrefix.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelidrys <aelidrys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 08:59:30 by aelidrys          #+#    #+#             */
/*   Updated: 2023/06/03 11:01:43 by aelidrys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../leetcode_problem.h"

char    *prifixcpy(char *s1, char *s2, int j){
    int     a;
    int     b;
    char    *p;

    a = 0;
    b = 0;
    if (!s1 || !s2){
        if (j)
            free(s1);
        return (NULL);
    }
    if (s1[a] != s2[a]){
        if (j)
            free(s1);
        return (NULL);
    }
    while (s1[a] == s2[a] && s1[a] && s2[a]){
        a++;
        b++;
    }
    p = malloc (b + 1 * sizeof(char));
    a = 0;
    while (a < b){
        p[a] = s1[a];
        a++;
    }
    if (j)
        free(s1);
    p[a] = '\0';
    return (p);
}

char * longestCommonPrefix(char ** strs, int strsSize){
    int     i;
    char    *p;

    i = 0;
    p = prifixcpy(strs[i], strs[i], 0);
    if (!p)
        return (strdup(""));
    i++;
    while (i < strsSize){
        p = prifixcpy(p, strs[i++], 1);
        if (!p)
        return (strdup(""));
    }
    return (p);
}