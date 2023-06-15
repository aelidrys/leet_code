/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RomanTOint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelidrys <aelidrys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 11:33:06 by aelidrys          #+#    #+#             */
/*   Updated: 2023/06/08 09:02:52 by aelidrys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "leetcode_problem.h"

int a_lent(char *s){
    int i;

    i = 0;
    if (!s)
        return (0);
    while (s[i])
        i++;
    return (i);
}

int     *rom_int(char *s){
    int x;
    int i;
    int *tab;

    i = a_lent(s);
    x = 0;
    tab = malloc(i + 1 * sizeof(int));
    while(s[x]){
        if (s[x] == 'I')
            tab[x++] = 1;
        if (s[x] == 'V')
            tab[x++] = 5;
        if (s[x] == 'X')
            tab[x++] = 10;
        if (s[x] == 'L')
            tab[x++] = 50;
        if (s[x] == 'C')
            tab[x++] = 100;
        if (s[x] == 'D')
            tab[x++] = 500;
        if (s[x] == 'M')
            tab[x++] = 1000;
    }
    tab[x] = 0;
    return (tab);
}

int romanToInt(char * s){
    int i;
    int x;
    int *tab;
    int res;

    x = 0;
    res = 0;
    i = a_lent(s);
    tab = rom_int(s);
    while (x < i){
        if (tab[x] >= tab[x + 1])
            res += tab[x];
        if (tab[x] < tab[x + 1]){
            res += tab[x + 1] - tab[x];
            x += 2;
        }
        else
            x++;
    }
    return (res);
}
