/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   largest_palin_numb.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelidrys <aelidrys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 11:09:56 by aelidrys          #+#    #+#             */
/*   Updated: 2023/06/08 09:02:24 by aelidrys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "leetcode_problem.h"

typedef struct b_palindrom
{
    int                 a;
    int                 c;
    struct b_palindrom  *next;
}   a_palindrom;

a_palindrom *new_node(int a1, int c1)
{
    a_palindrom *new;
    new = (a_palindrom *)malloc(sizeof(a_palindrom));
    new->a = a1;
    new->c = c1;
    new->next = NULL;
    return new;
}

void    add_back(a_palindrom **pal, a_palindrom *new)
{
    a_palindrom *tmp;

    if (pal && new)
    {
        if (*pal)
        {
            tmp = *pal;
            while (tmp->next)
                tmp = tmp->next;
            tmp->next = new;
        }
        else
            *pal = new;
    }
}

void    sort_list(a_palindrom *pal)
{
    a_palindrom *pal1;
    int         a1;
    int         c1;
    int         s;

    s = 1;
    if (!pal)
        return ;
    while (s)
    {
        s = 0;
        pal1 = pal;
        while (pal1->next)
        {
            if (pal1->c > pal1->next->c)
            {
                s = 1;
                a1 = pal1->next->a;
                c1 = pal1->next->c;
                pal1->next->a = pal1->a;
                pal1->next->c = pal1->c;
                pal1->a = a1;
                pal1->c = c1;
            }
            pal1 = pal1->next;
        }
    }
}

a_palindrom *r_sort_list(a_palindrom *pal1)
{
    a_palindrom *pal = NULL;
    int         a1;
    int         c1;
    int         s;

    s = 1;
    while (pal1)
    {
        if (pal1->a > 1)
            add_back(&pal,new_node(pal1->a, pal1->c));
        pal1 = pal1->next;
    }
    if (!pal)
        return 0;
    while (s)
    {
        s = 0;
        pal1 = pal;
        while (pal1->next)
        {
            if (pal1->c < pal1->next->c)
            {
                s = 1;
                a1 = pal1->next->a;
                c1 = pal1->next->c;
                pal1->next->a = pal1->a;
                pal1->next->c = pal1->c;
                pal1->a = a1;
                pal1->c = c1;
            }
            pal1 = pal1->next;
        }
    }
    return pal;
}


char    *max_num_palin(a_palindrom *head, char *s, int n)
{
    int x = 0;
    int c1 = 0;
    if (!head)
        return 0;
    a_palindrom *head1;
    s = malloc(n + 1 * sizeof(char));
    sort_list(head);
    head1 = r_sort_list(head);
    while (head1)
    {
        if (head1->a > 1)
            while ((x > 0 || head1->c != 48) && head1->a)
            {
                s[x++] = head1->c;
                head1->a -= 2;
            }
        head1 = head1->next;
    }
	head1 = head;
    while (head1)
    {
        if (head1->a == 1 && head1->c > c1)
            c1 = head1->c;
		head1 = head1->next;
    }
    if (c1 != 0)
        s[x++] = c1;
    c1 = 0;
    head1 = head;
    while (head1)
    {
        if (head1->a > 1 && head1->c > c1)
            c1 = head1->c;
		head1 = head1->next;
    }
    while (head)
    {
        if (head->a > 1)
            while (head->a)
            {
                if (head->c != 48 || c1 != 48)
                    s[x++] = head->c;
                head->a -= 2;
            }
        head = head->next;
    }
    s[x] = '\0';
    return s;
}


char    *largestPalindromic(char *num)
{
    a_palindrom *palin = NULL;
    int         x;
    int         y;
    int         i;

    x = 0;
    if (!num)
        return 0;
    while (num[x + 1])
    {
    	i = 1;
        y = x + 1;
        while (num[y])
		{
            if (num[x] == num[y] && num[y] != 'a')
            {
                num[y] = 'a';
                i++;
            }
			y++;
		}
        if (num[x] != 'a' && i % 2 == 0)
            add_back(&palin, new_node(i, num[x]));
        else if (num[x] != 'a')
        {
			if (i > 1)
            	add_back(&palin, new_node(i - 1, num[x]));
            add_back(&palin, new_node(1, num[x]));
        }
        x++;
    }
	if (num[x] != 'a')
            add_back(&palin, new_node(1, num[x]));
	return max_num_palin(palin, NULL, strlen(num));
}

int main()
{
	char s[] = "444947137";
	printf("%s", largestPalindromic(s));
}