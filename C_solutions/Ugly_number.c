/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ugly_number.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelidrys <aelidrys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 12:30:36 by aelidrys          #+#    #+#             */
/*   Updated: 2023/06/08 09:03:04 by aelidrys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "leetcode_problem.h"

int a_isp(int n){

    if (n == 1)
        return (0);
    int i = 2;
    while (i <= n / i)
    {
        if (n % i == 0)
            return (0);
        if (n % (n / i) == 0)
            return (0);
        i++;
    }
    return (1);
}

int	isUgly(int n)
{
    int i = 2;

    if (n <= 0)
        return(0);
    if (n == 1)
        return (1);
    if (n == 2 || n == 3 || n == 5)
        return (1);
    if (a_isp(n))
        return(0);
    while (i <= n / i)
    {
        if (i % 2 != 0)
            if (n % i == 0 && a_isp(i))
                if (i != 2 && i != 3 && i != 5)
                    return (0);
        if ((n / i) % 2 != 0)
            if (n % (n / i) == 0 && a_isp(n / i))
                if ((n / i) != 2 && (n / i) != 3 && (n / i) != 5)
                    return (0);
        i++;
    }
    return (1);
}