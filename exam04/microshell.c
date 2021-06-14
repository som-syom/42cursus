/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   microshell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhyeon <dhyeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 19:15:51 by dhyeon            #+#    #+#             */
/*   Updated: 2021/06/14 22:54:11 by dhyeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// 구현해야하는 부분
// cd, execve, ;, |, 
// 인자로 명령어를 받음
// 환경변수 처리할필요 x, execve는 절대경로로 들어옴
// cd 잘못된 인자수 => error: cd: bad arguments\n
//	  실패시 => error: cd: cannnot change directory to [path_to_change]\n
// execve 실패시 => error: cannnot execute [executable_that_failed]\n
// execve, cd 를 제외한 오류일경우 => error: facial\n
// 허용함수
// malloc, free, write, close, fork, waitpid, signal, kill, 
// exit, chdir, execve, dup, dup2, pipe, strcmp, strncmp

#include "microshell.h"

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

	if (new = malloc(sizeof(t_cmd)))
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

void	print_error(int flag, t_cmd *cmd)
{
	if (flag == FATAL)
	{
		write(2, "error: fatal\n", 13);
		exit (1);
	}
}

t_cmd	*make_cmd(t_cmd *new, char **av, int *i)
{
	int j;
	int z;

	new->cmd = av[*i];
	j = *i;
	while (av[j] && (strcmp(av[j], ";") == 0 || strcmp(av[j], "|") == 0))
		j++;
	if (!(new->cmds = (char **)malloc(sizeof(char *) * (j - (*i) + 1))))
		print_error(FATAL, 0);
	z = 0;
	while (*i < j)
	{
		// new->cmds[z] = ft_strdup(av[*i]);
		new->cmds[z] = av[*i];
		new->num++;
		(*i)++;
		z++;
	}
	new->cmds[z] = 0;
	(*i)--;
	return (new);
}

void	parsing(char **av, int ac, t_info *info)
{
	t_cmd	*new;
	int	i = 0;
	
	while (++i < ac)
	{
		if (i == 1 || strcmp(av[i], ";") == 0 || strcmp(av[i], "|") == 0)
			new = new_cmd(info);
		if (i == 1 || strcmp(av[i], ";") == 0)
			new->status = SEMI;
		else if (strcmp(av[i], "|") == 0)
			new->status = PIPE;
		else
			new = make_cmd(new, av, &i);
	}
}

void	set_pipe(t_cmd *cmd)
{
	if (cmd->status != PIPE)
		dup2(cmd->pipe[1], 1);
	else if (cmd->next == 0 || cmd->status == SEMI)
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
		if (strncmp(env[i], "HOME=", 5) == 0)
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

	if (strcmp(path, "~"))
		buf = ft_strdup(find_env_val(info->env, "HOME"));
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
	if (cmd->prev)
		close(cmd->prev->pipe[0]);
	close(cmd->pipe[1]);
	if (cmd->next == 0)
		close(cmd->pipe[0]);
	dup2(*stin, 0);
	dup2(*stout, 1);
	close(*stin);
	close(*stout);
}

int	main(int argc, char **argv, char **envp)
{
	t_info	*info;
	t_cmd	*cmd;
	int stin, stout;

	if (argc == 1)
		return (0);
	init_info(argv, argc, envp, &info);
	parsing(argv, argc, &info);
	cmd = info->cmd;
	while (cmd)
	{
		pipe(cmd->pipe);
		stin = dup(0);
		stout = dup(1);
		if (cmd->status == PIPE || (cmd->next && cmd->next->status == PIPE))
			set_pipe(cmd);
		if (strcmp(cmd->cmd, "cd") == 0)
			ft_cd(&info, cmd);
		else
			execute(cmd);
		close_pipe(cmd, &stin, &stout);
		cmd = cmd->next;
	}
	return (0);
}