/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2Sort_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelidrys <aelidrys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 08:24:01 by aelidrys          #+#    #+#             */
/*   Updated: 2023/06/03 11:00:14 by aelidrys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../leetcode_problem.h"

ListN     *lst_new(int a)
{
    ListN *p;
    p = malloc(sizeof(ListN));
    p->val = a;
    p->next = NULL;
    return (p);

}

void    add_back(ListN **l1, ListN *new)
{
    ListN *p;
    if(l1 && new)
    {
        if(*l1)
        {
            p = *l1;
            while (p->next)
                p = p->next;
            p->next = new;
        }
        else
            *l1 = new;
    }
}

ListN	*mergeKLists(ListN** lists, int k){
    long a = 0;
    long x = 0;
    long b,y,z = 0;
  ListN *p;
  ListN *L;
    int *tab = malloc (1000000 * sizeof(int));
	if(!lists)
		return(0);
	if(!*lists)
		return(0);
    while(a < k){
        p = lists[a];
        while(p){
            tab[x++] = p->val;
            p = p->next;
        }
        a++;
    }
    a = 0;
    while (a + 1 < x)
    {
        y = tab[a];
        b = a + 1;
        while (b < x)
        {
            if (y > tab[b])
            {
                y = tab[b];
                z = b;
            }
            b++;
        }
        if (y < tab[a])
        {
            tab[z] = tab[a];
            tab[a] = y;
        }
        a++;
    }
    a = 0;
    while(a < x)
        add_back(&L, lst_new(tab[a++]));
    return (L);
}
