/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   microshell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhyeon <dhyeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 19:15:51 by dhyeon            #+#    #+#             */
/*   Updated: 2021/07/06 02:06:55 by dhyeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// 구현해야하는 부분
// cd, execve, ;, |, 
// 인자로 명령어를 받음
// 환경변수 처리할필요 x, execve는 절대경로로 들어옴
// cd 잘못된 인자수 => error: cd: bad arguments\n
//	  실패시 => error: cd: cannnot change directory to [path_to_change]\n
// execve 실패시 => error: cannnot execute [executable_that_failed]\n
// execve, cd 를 제외한 오류일경우 => error: fatal\n
// 허용함수
// malloc, free, write, close, fork, waitpid, signal, kill, 
// exit, chdir, execve, dup, dup2, pipe, strcmp, strncmp

// #include "microshell.h"
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


int		ft_strlen(char *str)
{
	int i = 0;
	while (str[i])
		i++;
	return (i);
}

void	print_error(int flag, t_cmd *cmd)
{
	if (flag == FATAL)
	{
		write(2, "error: fatal\n", 13);
		exit (1);
	}
	else if (flag == CD_ERR)
	{
		write(2, "error: cd: cannot change directory to ", 38);
		write(2, cmd->cmds[1], ft_strlen(cmd->cmds[1]));
		write(2, "\n", 1);
	}
	else if (flag == CD_ARG_ERR)
		write(2, "error: cd: bad arguments\n", 25);
	else if (flag == EXECVE_ERR)
	{
		write(2, "error: cannot execute ", 22);
		write(2, cmd->cmd, ft_strlen(cmd->cmd));
		write(2, "\n", 1);
	}
}

char	*ft_strdup(char *str)
{
	int	i;
	int len;
	char *ret;

	len = ft_strlen(str);
	ret = (char *)malloc(sizeof(char) * (len + 1));
	if (!ret)
		print_error(FATAL, 0);
	i = 0;
	while (str[i])
	{
		ret[i] = str[i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}

void	*ft_memset(void *ptr, int val, size_t n)
{
	unsigned char	*tmp_ptr;
	unsigned char	tmp_val;
	size_t			i;

	tmp_ptr = ptr;
	tmp_val = val;
	i = 0;
	while (i < n)
	{
		tmp_ptr[i] = tmp_val;
		i++;
	}
	return (ptr);
}

void	init_info(char **av, int ac, char **env, t_info *info)
{
	ft_memset(info, 0, sizeof(t_info));
	info->av = av;
	info->ac = ac;
	info->env = env;
}

t_cmd	*new_cmd(t_info *info)
{
	t_cmd	*new;
	t_cmd	*tmp;

	if (!(new = malloc(sizeof(t_cmd))))
		print_error(FATAL, 0);
	ft_memset(new, 0, sizeof(t_cmd));
	if (info->cmd == 0)
	{
		info->cmd = new;
	}
	else
	{
		tmp = info->cmd;
		while (tmp->next)
			tmp = tmp->next;
		new->prev = tmp;
		tmp->next = new;
	}
	return (new);
}

t_cmd	*make_cmd(t_cmd *new, char **av, int *i)
{
	int j;
	int z;

	new->cmd = av[*i];
	j = *i;
	while (av[j] && (strcmp(av[j], ";") != 0 && strcmp(av[j], "|") != 0))
		j++;
	if (!(new->cmds = (char **)malloc(sizeof(char *) * (j - (*i) + 1))))
		print_error(FATAL, 0);
	z = 0;
	while (*i < j)
	{
		while (av[*i] && strcmp(av[*i], ";") == 0)
			(*i)++;
		if (!av[*i])
			break ;
		new->cmds[z] = av[*i];
		new->num++;
		(*i)++;
		z++;
	}
	new->cmds[z] = 0;
	(*i)--;
	return (new);
}

void	test_cmd(t_cmd *cmd)
{
	printf("===cmd===\n");
	printf("cmd = %s\n", cmd->cmd);
	for (int i = 0; cmd->cmds[i]; i++)
		printf("%d : %s\n", i, cmd->cmds[i]);
	printf("num = %d\n", cmd->num);
	printf("status = %d\n", cmd->status);
}

void	parsing(char **av, int ac, t_info *info)
{
	t_cmd	*new;
	int	i = 0;
	
	while (++i < ac)
	{
		// printf("i : %d : %s\n", i, av[i]);
		if (i == 1 || strcmp(av[i], ";") == 0 || strcmp(av[i], "|") == 0)
			new = new_cmd(info);
		if (strcmp(av[i], ";") == 0)
			new->status = SEMI;
		else if (strcmp(av[i], "|") == 0)
			new->status = PIPE;
		else
			new = make_cmd(new, av, &i);
		// if (!(strcmp(av[i], ";") == 0 || strcmp(av[i], "|") == 0))
		// 	test_cmd(new);
	}
}

void	set_pipe(t_cmd *cmd)
{
	if (cmd->status != PIPE) // 현재는 SEMI, next가 PIPE 일때 write 만 열어줌
		dup2(cmd->pipe[1], 1);
	else if (cmd->next == 0 || cmd->next->num == 0 || cmd->next->status == SEMI) // next 가 없거나, next 가 SEMI 인경우 이전 read 만 열어줌
		dup2(cmd->prev->pipe[0], 0);
	else
	{
		dup2(cmd->prev->pipe[0], 0);
		dup2(cmd->pipe[1], 1);
	}
}

char	*find_env_val(char **env, char *key)
{
	int	i = -1;
	char *tmp;

	while (env[++i])
	{
		if (strncmp(env[i], key, 5) == 0)
		{
			tmp = env[i];
			tmp += 5;
			return (tmp);
		}
	}
	return (0);
}

int		change_dir(t_info *info, char *path)
{
	char	*buf;
	int		ret;

	if (strcmp(path, "~") == 0)
		buf = ft_strdup(find_env_val(info->env, "HOME="));
	else
		buf = ft_strdup(path);
	ret = chdir(buf);
	free(buf);
	return (ret);
}

void	ft_cd(t_info *info, t_cmd *cmd)
{
	if (cmd->num != 2)
		print_error(CD_ARG_ERR, cmd);
	else if (change_dir(info, cmd->cmds[1]) == -1)
		print_error(CD_ERR, cmd);
}

void	close_pipe(t_cmd *cmd, int *stin, int *stout)
{
	if (cmd->prev != 0)
		close(cmd->prev->pipe[0]);
	close(cmd->pipe[1]);
	if (cmd->next == 0 || cmd->next->cmd == 0)
		close(cmd->pipe[0]);
	// dup2(*stin, 0);
	// dup2(*stout, 1);
	// close(*stin);
	// close(*stout);
}


void	execute(t_info *info, t_cmd *cmd)
{
	pid_t	pid;

	pid = fork();
	if (pid < 0)
		print_error(FATAL, 0);
	if (pid == 0)
	{
		if (cmd->status == PIPE || (cmd->next && cmd->next->status == PIPE))
			set_pipe(cmd);
		if (execve(cmd->cmd, cmd->cmds, info->env) < 0)
			print_error(EXECVE_ERR, cmd);
	}
	else
	{
		close(cmd->pipe[1]);
		waitpid(pid, 0, 0);
	}
}

void	all_free(t_info *info)
{
	t_cmd *cmd = info->cmd;
	t_cmd *tmp;

	while (cmd)
	{
		if (cmd->cmds != 0)
			free(cmd->cmds);
		cmd = cmd->next;
	}
	while (info->cmd)
	{
		tmp = info->cmd;
		info->cmd = info->cmd->next;
		free(tmp);
		tmp = 0;
	}
}

int	main(int argc, char **argv, char **envp)
{
	t_info	info;
	t_cmd	*cmd;
	int stin, stout;

	if (argc == 1)
		return (0);
	init_info(argv, argc, envp, &info);
	parsing(argv, argc, &info);
	cmd = info.cmd;
	while (cmd)
	{
		pipe(cmd->pipe);
		// stin = dup(0);
		// stout = dup(1);
		if (cmd->num == 0)
			;
		else if (strcmp(cmd->cmd, "cd") == 0)
			ft_cd(&info, cmd);
		else
			execute(&info, cmd);
		close_pipe(cmd, &stin, &stout);
		cmd = cmd->next;
	}
	all_free(&info);
	// while (1) ;
	// return (0);
}