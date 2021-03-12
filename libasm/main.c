/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhyeon <dhyeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 18:18:23 by dhyeon            #+#    #+#             */
/*   Updated: 2021/03/03 20:12:08 by dhyeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>

#define BUFFUR_SIZE 1024

int ft_strlen(const char*);
int ft_write(int fd, const void *buf, size_t byte);
char *ft_strcpy(char *dst, const char *src);
int ft_strcmp(const char *s1, const char *s2);
int ft_read(int fd, void *buf, size_t byte);
char *ft_strdup(const char *s1);

int main(void)
{
	printf("==========[ ft_strlen ]==========\n");
	char *str1 = "Hello World";
	int a = ft_strlen(str1);
	printf("%-30s : %3d\n", str1, a);

	char *str = "asdfasdfasdfasdfasdf";
	a = ft_strlen(str);
	printf("%-30s : %3d\n", str, a);
	printf("\n");

	printf("==========[ ft_write ]===========\n");
	char *str2 = "Hello";
	
	printf("str : %s\n\n", str2);
	printf(" write    ret : %zd  | errno : %d\n", write(1, str2, 3), errno);
	errno = 0;
	printf(" ft_write ret : %d  | errno : %d\n", ft_write(1, str2, 3), errno);
	errno = 0;
	printf(" write    ret : %zd  | errno : %d\n", write(2, str2, 5), errno);
	errno = 0;
	printf(" ft_write ret : %d  | errno : %d\n", ft_write(2, str2, 5), errno);
	errno = 0;
	printf("write    ret : %zd  | errno : %d\n", write(-1, str2, 5), errno);
	errno = 0;
	printf("ft_write ret : %d  | errno : %d\n", ft_write(-1, str2, 5), errno);
	printf("\n");

	printf("==========[ ft_strcpy ]===========\n");
	char dst1[] = "Hello World";
	char src1[] = "1234567890";
	printf("dst : %s\nsrc : %s\n\n", dst1, src1);
	printf("ft_strcpy : %s\n", ft_strcpy(dst1, src1));
	char dst2[] = "Hello World";
	char src2[] = "1234567890";
	printf("strcpy    : %s\n", strcpy(dst2, src2));
	printf("\n");

	printf("==========[ ft_strcmp ]===========\n");
	char dst3[] = "";
	char src3[] = "ABBB";

	printf("strcmp    : %d\n", strcmp(dst3, src3));
	printf("ft_strcmp : %d\n", ft_strcmp(dst3, src3));

	char dst4[] = "ABCDE";
	char src4[] = "ABCDE";

	printf("strcmp    : %d\n", strcmp(dst4, src4));
	printf("ft_strcmp : %d\n", ft_strcmp(dst4, src4));
	printf("\n");

	printf("==========[ ft_read ]===========\n");
	char *s1 = (char *)malloc(sizeof(char) * (BUFFUR_SIZE + 1));
	char *s2 = (char *)malloc(sizeof(char) * (BUFFUR_SIZE + 1));
	int fd1, fd2;

	fd1 = open("test1.txt", O_RDONLY);
	fd2 = open("test1.txt", O_RDONLY);
	errno = 0;
	printf("read    : %zd\n", read(fd1, s1, BUFFUR_SIZE));
	printf("     fd : %d  errno : %d\n", fd1, errno);
	printf("ft_read : %d\n", ft_read(fd2, s2, BUFFUR_SIZE));
	printf("     fd : %d  errno : %d\n", fd2, errno);
	printf("\n");
	close(fd1);
	close(fd2);

	fd1 = open("test2.txt", O_RDONLY);
	fd2 = open("test2.txt", O_RDONLY);
	errno = 0;
	printf("read    : %zd\n", read(fd1, s1, BUFFUR_SIZE));
	printf("     fd : %d  errno : %d\n", fd1, errno);
	errno = 0;
	printf("ft_read : %d\n", ft_read(fd2, s2, BUFFUR_SIZE));
	printf("     fd : %d  errno : %d\n", fd2, errno);
	printf("\n");
	close(fd1);
	close(fd2);

	fd1 = open("test1.txt", O_RDONLY);
	fd2 = open("test1.txt", O_RDONLY);
	errno = 0;
	printf("read    : %zd\n", read(fd1, NULL, BUFFUR_SIZE));
	printf("     fd : %d  errno : %d\n", fd1, errno);
	errno = 0;
	printf("ft_read : %d\n", ft_read(fd2, NULL, BUFFUR_SIZE));
	printf("     fd : %d  errno : %d\n", fd2, errno);
	printf("\n");
	close(fd1);
	close(fd2);
	printf("\n");

	printf("==========[ ft_strdup ]===========\n");
	char s3[] = "dhyeon";
	char *dup1 = strdup(s3);
	printf("strdup    : %s\n", dup1);
	char *dup2 = ft_strdup(s3);
	printf("ft_strdup : %s\n", dup2);
	
}
