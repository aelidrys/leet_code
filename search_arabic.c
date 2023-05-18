/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelidrys <aelidrys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 12:19:51 by aelidrys          #+#    #+#             */
/*   Updated: 2023/05/18 11:44:48 by aelidrys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "leetcode_problem.h"
#include <fcntl.h>

int		a_search_arabic(wchar_t *p, wchar_t c)
{	int a;

	a = 0;
	if (!p)
		return(0);
	while (p[a])
		if(p[a++] == c)
			return(1);
	return(0);

}
