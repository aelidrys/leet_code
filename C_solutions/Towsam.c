/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Towsam.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelidrys <aelidrys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 07:05:47 by aelidrys          #+#    #+#             */
/*   Updated: 2023/06/08 09:03:01 by aelidrys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "leetcode_problem.h"

int* twoSum(int* nums, int numsSize, int target, int* returnSize)
{
    int i = 0;
    int x;
    short int s = 0;
    int *tab = (int *)malloc(2 * sizeof(int));
    *returnSize = 2;
    while (i < numsSize - 1){
        x = i + 1;
        while (x < numsSize)
            if (nums[i] == target - nums[x++]){
                s = 1;
                break;
        }
        if (s)
            break;
        i++;
    }
    tab[0] = i;
    tab[1] = x - 1;
    return (tab);
}