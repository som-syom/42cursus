/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   microshell.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhyeon <dhyeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 19:12:40 by dhyeon            #+#    #+#             */
/*   Updated: 2021/06/14 23:35:22 by dhyeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MICROSHELL_H
# define MICROSHELL_H

# include <unistd.h>
# include <stdlib.h>
# include <signal.h>
# include <sys/wait.h>
# include <string.h>
# include <stdio.h>
# include <dirent.h>

# define ERROR	-1
# define SEMI	0
# define PIPE	1

# define FATAL	1
# define EXECVE_ERR	2
# define CD_ERR	3
# define CD_ARG_ERR 4

typedef struct		s_cmd
{
	char			*cmd;
	char			**cmds;
	int				num;
	int				status;
	int				pipe[2];
	struct s_cmd	*next;
	struct s_cmd	*prev;
}					t_cmd;


typedef struct	s_info
{
	char		**av;
	int			ac;
	char		**env;
	t_cmd		*cmd;
}				t_info;

int		ft_strlen(char *str);
char	*ft_strdup(char *str);
void	*ft_memset(void *ptr, int val, size_t n);
void	print_error(int flag, t_cmd *cmd);

#endif