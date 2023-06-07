/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IntTO_Roman.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelidrys <aelidrys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 07:14:00 by aelidrys          #+#    #+#             */
/*   Updated: 2023/06/03 11:00:38 by aelidrys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../leetcode_problem.h"

int     *int_roman1(int x, int *Y)
{
    int a,b,c,y;
    int *tab = malloc(100 * sizeof(int));
    c = 1;
    b = 0;
    a = 1000;
    while (a > x)
    {
        if (c){
            a /= 2;
            c = 0;
        }
        else{
            a /= 5;
            c = 1;
        }
    }
    while (x){
        y = x / a;
        if(y == 4){
            tab[b++] = a;
            tab[b++] = (y + 1) * a;
            x -= y * a;
        }
        else if (x == 9 || (x >= 90 && x <= 99) || (x >= 900 && x <= 999)){
            tab[b++] = a / 5;
            tab[b++] = a * 2;
            x -= 9 * (a / 5);
        }
        else{
            tab[b++] = a;
            x -= a;
        }
        while (a > x){
            if (c){
                a /= 2;
                c = 0;
            }
            else{
                a /= 5;
                c = 1;
            }
        }
    }
    *Y = b;
    return (tab);
}

char    *intToRoman(int x){
    int *p;
    int i,y,z;
    char d[8] = "MDCLXVI";
    int  t[7] = {1000, 500, 100, 50, 10, 5, 1};
    char *s = malloc(20 * sizeof(char));

    i = 0;
    p = int_roman1(x, &y);
    while (i < y){
        z = 0;
        while (z < 7){
            if (p[i] == t[z])
                s[i] = d[z];
            z++;
        }
        i++;
    }
    s[i] = '\0';
    return (s);
}
