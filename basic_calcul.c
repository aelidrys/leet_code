/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_calcul.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelidrys <aelidrys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 13:54:45 by aelidrys          #+#    #+#             */
/*   Updated: 2023/02/02 12:30:45 by aelidrys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "leetcode_problem.h"

size_t    sk_space(char *p)
{
    size_t   q = 0;

    while (p[q] == ' ')
        q++;
    return (q);
}

int add_N(int n, char c)
{
    if (c == '-')
        return (-n);
    return (n);
}

int mini_calcul(char *s, size_t *x)
{
    size_t i = 1;
    char c = ' ';
    int R = 0;
    size_t a = 0;

    i += sk_space(s);
    while (s[i] >= 48 && s[i] <= 58 && s[i])
        R = R * 10 + (s[i++] - 48);
    while (s[i])
    {
        if (s[i] == ')'){
            i++;
            break ;
        }
        if (s[i] == '(' && c == '-'){
            R += mini_calcul(s + i, &a) * -1;
            i += a;
        }
		else if (s[i] == '(' && c == '+'){
            R += mini_calcul(s + i, &a);
            i += a;
        }
        int num2 = 0;
        i += sk_space(s + i);
        if (s[i] == '+' || s[i] == '-')
            c = s[i++];
       i += sk_space(s + i);
        while (s[i] >= 48 && s[i] <= 58 && s[i])
            num2 = num2 * 10 + (s[i++] - 48);
            R += add_N(num2, c);
    }
    *x = i;
    return (R);
}


int calculater(char *s)
{
    size_t i = 0;
    char c = ' ';
    int res = 0;

    s += sk_space(s);
    while (*s >= 48 && *s <= 58 && *s)
        res = res * 10 + (*(s++) - 48);
    while (*s)
    {
        int num2 = 0;
        s += sk_space(s);
        if (*s == '+' || *s == '-')
            c = *(s++);
       s += sk_space(s);
        while (*s >= 48 && *s <= 58 && *s)
            num2 = num2 * 10 + (*(s++) - 48);
        res += add_N(num2, c);
        if (*s == '('){
                res += add_N(mini_calcul(s, &i), c);
                s += i;
        }
    }
    return (res);
}
