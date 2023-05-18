/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Remove_element.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelidrys <aelidrys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 18:44:45 by aelidrys          #+#    #+#             */
/*   Updated: 2023/02/01 15:16:02 by aelidrys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "leetcode_problem.h"

int removeElement(int* nums, int nsize, int val)
{
    int n = 0;
    int x = 0;
    int *tab;
    while (n < nsize)
        if (nums[n++] != val)
            x++;
    n = 0;
    tab = malloc(x * sizeof(int));
    x = 0;
    while (n < nsize)
    {
        if (nums[n] != val)
            tab[x++] = nums[n];
        n++; 
    }
    n = 0;
    while (n < x)
    {
        nums[n] = tab[n];
        n++;
    }
    return (x);
}
