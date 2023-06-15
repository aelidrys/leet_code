/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelidrys <aelidrys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 16:40:54 by aelidrys          #+#    #+#             */
/*   Updated: 2023/06/08 09:02:58 by aelidrys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "leetcode_problem.h"

ListN    *New_list(int a)
{
     ListN *p;
    p = malloc(sizeof(ListN));
    p->val = a;
    p->next = NULL;
    return (p);
}

void    add_back(ListN **L, ListN *new){
 	ListN *p = NULL;
    if (L && new){
        if (*L){
            p = *L;
            while (p->next){
               p = p->next;
            }
            p->next = new;
        }
        else if (new)
            *L = new;
    }
}

ListN	*mergeTwoLists(ListN* l1, ListN* l2)
{
    ListN *l = NULL;
    while(l1 && l2){
        if (l1->val > l2->val){
            add_back(&l, New_list(l2->val));
            l2 = l2->next;
        }
        else{
            add_back(&l, New_list(l1->val));
            l1 = l1->next;
        }
    }
    while (l1){
        add_back(&l, New_list(l1->val));
        l1 = l1->next;
    }
    while (l2){
        add_back(&l, New_list(l2->val));
        l2 = l2->next;
    }
    return(l);
}
