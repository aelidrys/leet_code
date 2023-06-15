/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_num.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelidrys <aelidrys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 08:30:36 by aelidrys          #+#    #+#             */
/*   Updated: 2023/06/08 09:02:05 by aelidrys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "leetcode_problem.h"

int addDigits(int num){
    int res = 0;
    while (num > 0){
       res += num % 10;
        num /= 10;
    }
	if (res >= 10)
        return(addDigits(res));
        return (res);
}
