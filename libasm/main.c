/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhyeon <dhyeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 18:18:23 by dhyeon            #+#    #+#             */
/*   Updated: 2021/03/01 23:19:38 by dhyeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>

int _ft_strlen(const char*);
int _ft_write(int fd, const void *buf, size_t byte);

int main(void)
{
	printf("==========[ ft_strlen ]==========");
	int a = _ft_strlen("hello world\n");
	printf("%d\n", a);


	printf("==========[ ft_write ]===========");

	errno = 0;
	printf("write     : %zd  | errno : %d\n", write(1, "Hello", 3), errno);
	errno = 0;
	printf("ft_write  : %zd  | errno : %d\n", write(1, "Hello", 3), errno);
	errno = 0;
	printf("write     : %zd  | errno : %d\n", write(1, "Hello", 5), errno);
	errno = 0;
	printf("ft_write  : %zd  | errno : %d\n", write(1, "Hello", 5), errno);

}
