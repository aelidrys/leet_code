/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   divide.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelidrys <aelidrys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 08:26:01 by aelidrys          #+#    #+#             */
/*   Updated: 2023/06/03 11:00:03 by aelidrys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../leetcode_problem.h"

int fun1(char *s, char c1, char c2, int *x)
{
    int a = -1;
    int n1 = 0;
    int n2 = 0;
    while (s[++a] == c1)
        n1++;
    if (s[a] == '\0'){
        *x += a;
        return (0);
    }
    while (s[a++] == c2)
        n2++;
    *x += n1;
    if (n1 < n2)
        return (2 * n1);
    return (2 * n2);
}

int findTheLongestBalancedSubstring(char * s){
    int a = 0;
    int b = 0;
    int x = 0;
    int max = -1;
    char c1,c2;

    c1 = '0';
    if (s[0] == '1')
        c1 = '1';
    c2 = '0';
    if (c1 == '0')
        c2 = '1';
    while (s[a] == c1)
        a++;
    if (!s[a])
        return (-1);
    a = 0;
    b = strlen(s);
    while (a < b){
        x = fun1(s + a, c1, c2, &a);
        if (x > max)
            max = x;
        if (a >= b)
            break;
        x = fun1(s + a, c2, c1, &a);
        if (x > max)
            max = x;
    }
    return (max);

}
