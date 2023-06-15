/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4sum.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelidrys <aelidrys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 12:55:37 by aelidrys          #+#    #+#             */
/*   Updated: 2023/06/08 09:02:00 by aelidrys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "leetcode_problem.h"
int     a_chek(int **tab, int j, int a, int b, int c, int d){
    int p[4];
    int x = 0;
    while (x < j){
        int h = 3;
        int i = 0;
        p[0] = a;
        p[1] = b;
        p[2] = c;
        p[3] = d;
        while (i < 4){
            int y = 0;
            while (y <= h){
                if (tab[x][i] == p[y] && y == h){
                    h--;
                    break;
                }
               else if (tab[x][i] == p[y] && y != h){
                    p[y] = p[h];
                    h--;
                    break;
                }
                y++;
            }
            i++;
        }
        if (h == -1)
            return (0);
        x++;
    }
    return (1);
}

int **fourSum(int* nm, int n, int x, int *r, int** Tab){
    int a,b,c,d,j,z;
    long res;
    int **tab;

    j = 0;
    z = 0;
    a = 0;
    tab = (int **)malloc(1000 * sizeof(int *));
    while (a + 3 < n){
        b = a + 1;
        while (b + 2 < n){
            c = b + 1;
            while (c + 1 < n){
                d = c + 1;
                while (d < n){
                    while (d + 1 < n && nm[d] == nm[d + 1])
                        d++;
                    res = (long)nm[a] + nm[b] + nm[c] + nm[d];
                    if (res == x){
                        tab[j] = (int *)malloc(4 * sizeof(int));
                        tab[j][0] = nm[a];
                        tab[j][1] = nm[b];
                        tab[j][2] = nm[c];
                        tab[j++][3] = nm[d];
                    }
                    d++;
                }
                while (c + 2 < n && nm[c] == nm[c + 1])
                    c++;
                c++;
            }
            while (b + 3 < n && nm[b] == nm[b + 1])
                b++;
            b++;
        }
        while (a + 4 < n && nm[a] == nm[a + 1])
            a++;
        a++;
    }
    *r = j;
    d = 0;
    tab = (int **)realloc(tab, j * sizeof(int *));
    Tab[0] = (int *)malloc(j * sizeof(int));
    while (d < j){
        Tab[0][d++] = 4;
    }
    return(tab);
}
