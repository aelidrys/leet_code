/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   longest_palindromic_substring.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelidrys <aelidrys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 07:47:19 by aelidrys          #+#    #+#             */
/*   Updated: 2023/05/05 09:04:21 by aelidrys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "leetcode_problem.h"

 typedef struct s_arry{
     int    len;
     char   *str;
     struct s_arry *next;
}   t_arry;

t_arry *ft_new_arry(char *str)
{
    t_arry  *new_arry;

    new_arry = malloc(sizeof(t_arry));
    new_arry->str = str;
    new_arry->len = strlen(str);
    new_arry->next = NULL;
    return (new_arry);
}

void    ft_add_arry(t_arry **list, t_arry *new_arry)
{
    t_arry  *tmp = NULL;

    if (list && new_arry)
    {
        tmp = *list;
        if (tmp)
        {
            while (tmp->next)
                tmp = tmp->next;
            tmp->next = new_arry;
        }
        else
            *list = new_arry;
    }
}

char    *ft_long_palindrom_str(char *s, int i)
{
    int a = i - 1;
    int b = i + 1;
    if (s[b] == s[a]){
        printf("enter0\n");
        while (s[b] && a >= 0 && s[b] == s[a]){
            a--;
            b++;
        }
    }
    else if (s[b] == s[i]){
        printf("enter1\n");
        while (s[b] == s[i])
            b++;
    }
    else if (s[a] == s[i]){
        printf("enter\n");
        while (a >= 0 && s[a] == s[i])
            a--;
    }
    int x = 0;
    char *str = malloc (1000);
    printf("i = %d -- a = %d -- b = %d\n",i, a, b);
    while (++a < b)
        str[x++] = s[a];
    str[x] = '\0';
    printf("str == %s\n\n\n", str);
    return (str);
}

char * longestPalindrome(char * s){
    t_arry  *arry = NULL;
    char    *str = "tree";
    int i = 1;
    int long_len = 0;
    int len = 0;

    while (s[i])
    {
        str = ft_long_palindrom_str(s, i++);
        len = strlen(str);
        if (len > long_len)
            long_len = len;
        ft_add_arry(&arry, ft_new_arry(str));
    }
    if (long_len == 1)
    {
        char *s1 = malloc(2);
        s1[0] = s[0];
        s1[1] = '\0';
        return (s1);
    }
    while (arry)
    {
        if (long_len == arry->len)
            return (arry->str);
        arry = arry->next;
    }
    arry = arry->next;
    return (NULL);
}

int main()
{
    char *str;
    str = strdup("babad");
    printf("%s\n",longestPalindrome(str));
}
