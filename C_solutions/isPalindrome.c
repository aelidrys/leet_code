/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isPalindrome.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelidrys <aelidrys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 06:47:46 by aelidrys          #+#    #+#             */
/*   Updated: 2023/06/03 11:00:43 by aelidrys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

 #include "../leetcode_problem.h"

 int     a_lent(int x)
{
    int l;

    l = 0;
    if (x == 0)
        return (2);
    while (x > 0){
        x /= 10;
        l++;
    }
    return (l);
}

char    *s_diarect(int x)
{
    int     i;
    char    *p;

    i = a_lent(x);
	p = malloc(i * sizeof(char));
    p[i--] = '\0';
    while (i >= 0){
        p[i--] = "0123456789"[x % 10];
        x /= 10;
    }
    return (p);

}

int     is_same(char *s, char *p)
{
    int i;

    i = 0;
    while (s[i] || p[i]){
        if (s[i] != p[i])
            return (0);
        i++;
    }
    return (1);
}

int isPalindrome(int x)
{
    char    *s;
    int i;
	int	y;

	y = x;
    i = 0;
    if (x < 0)
        return (0);
	s = malloc (a_lent(x) * sizeof(char));
   while (x > 0){
        s[i++] = (x % 10 + 48);
        x /= 10;
    }
    s[i++] = '\0';
    if (is_same(s, s_diarect(y)))
        return(1);
    return (0);

}
