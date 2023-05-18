/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_sodoko.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelidrys <aelidrys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 09:55:04 by aelidrys          #+#    #+#             */
/*   Updated: 2023/05/18 11:44:20 by aelidrys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "leetcode_problem.h"

char *copy_str1(char **s, int x)
{
    int y = 0;
    char *d = malloc(10 * sizeof(char));
    while (y < 9)
    {
        d[y] = s[x][y];
        y++;
    }
    d[y] = '\0';
    return (d);
}

char *copy_str2(char **s, int x)
{
    int y = 0;
    char *d = malloc(10 * sizeof(char));
    while (y < 9)
    {
        d[y] = s[y][x];
        y++;
    }
    d[y] = '\0';
    return (d);
}

int comp_str(char *s)
{
    int x;
    int y;

    x = -1;
    while (s[++x])
    {
        if (!(s[x] >= '1' && s[x] <= '9') && s[x] != '.')
            return (0);
        y = x;
        while (s[++y])
            if (s[x] == s[y] && s[x] != '.')
                return (0);
    }
    return (1);
}

int gr_3_3(char **s, int x, int i)
{
    char *str;
    int n = x + 3;
    int z = i + 3;
    int y = 0;

    str = malloc(10 * sizeof(char));
    while (x < n)
    {
        i = z - 3;
        while (i < z)
            str[y++] = s[x][i++];
        if (y == 9)
        {
            str[y] = '\0';
            if (!comp_str(str))
                return (0);
        }
        x++;
    }
    return (1);
}

int isValidSudoku(char** s, int Size, int* ColSize){
    int x = 0;
    while (x < Size)
        if (!comp_str(copy_str1(s, x++)))
            return (0);
    x = 0;
     while (x < Size)
        if (!comp_str(copy_str2(s, x++)))
            return (0);
    x = 0;
    while (x < 9){
        if (!gr_3_3(s, 0, x) || !gr_3_3(s, 3, x) || !gr_3_3(s, 6, x))
            return (0);
        x += 3;
    }
    return (1);
}