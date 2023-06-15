/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copmress.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelidrys <aelidrys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 09:29:31 by aelidrys          #+#    #+#             */
/*   Updated: 2023/06/09 10:15:21 by aelidrys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "leetcode_problem.h"

int compress(char *s, int size){
    char *s2 = calloc(size+1, 1);
    char *s3 = calloc((size * 2) + 2, 1);
    int i = 0;
    int j;
    int k;
    int a = 0;
    while (i < size)
    {
        k = 1;
        j = i + 1;
        if (!strchr(s2,s[i])){
            while (j < size)
                if (s[i] == s[j++])
                    k++;
			char c1 = s[i];
            s3[a++] = c1;
            printf("s--%c--\n", s[i]);
            while (k != 0){
                char c = (k % 10) + 48;
                printf("convert = %c\n",c);
                s3[a++] = c;
				printf("s3[%d] = %c\n",a - 1,s3[a - 1]);
                if (k == 0)
                    break ;
                k = k / 10;
            }
        }
        s2[i] = s[i];
        i++;
    }
	printf("a = %d\n", a);
    s3[a] = '\0';
	s = s3;
	printf("s3 = %s\n", s3);
    for (int i = 0; i < a; i++)
        s[i] = s3[i];
	s[a] = '\0';
	printf("s = %s\n", s);
    return (a);

}

int main(){
	char s[8] = "aabbccc";
	compress(s, 8);
	printf("res = %s\n",s);
}
