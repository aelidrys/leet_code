/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_TO_numbers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelidrys <aelidrys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 08:18:06 by aelidrys          #+#    #+#             */
/*   Updated: 2023/05/18 11:46:16 by aelidrys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "leetcode_problem.h"

ListN   *list_new(int x){
    ListN *p;
    p = (ListN *)malloc(sizeof(ListN));
    p->val = x;
    p->next = NULL;
    return (p);
}

void	add_back(ListN **lst, ListN *new)
{
	ListN	*node;

	if (lst && new)
	{
		if (*lst)
		{
			node = *lst;
			while (node->next)
				node = node->next;
			node->next = new;
		}
		else if (new)
			*lst = new;
	}
}

ListN   *addTwoNumbers(ListN *l1, ListN *l2){
    unsigned long      x;
    unsigned long      y;

    x = 0;
    y = 0;
    ListN   *l3 = NULL;
    while (l1 && l2){
        x += l1->val + l2->val;
        if (x > 9){
            add_back(&l3, list_new(x - 10));
            if (x)
                x = 1;
            else
                x = 0;
        }
        else{
            add_back(&l3, list_new(x));
            x = 0;
        }
        l1 = l1->next;
        l2 = l2->next;
    }
    while (l1){
        if (x == 1){
            add_back(&l3, list_new(l1->val));
            x = 0;
        }
        else
            add_back(&l3, list_new(l1->val));
        l1 = l1->next;
    }
    while (l2){
        if (x == 1){
            add_back(&l3, list_new(l2->val));
            x = 0;
        }
        else
            add_back(&l3, list_new(l2->val));
        l2 = l2->next;
    }
    return (l3);
}
