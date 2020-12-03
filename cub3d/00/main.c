/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhyeon <dhyeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 02:48:15 by dhyeon            #+#    #+#             */
/*   Updated: 2020/12/03 09:52:53 by dhyeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    print_err(int err_num)
{
	if (err_num == -1)
		ft_putstr("인자 오류\n");
	if (err_num == -2)
		ft_putstr("맵 확장자 오류\n");
	if (err_num == -3)
		ft_putstr("맵 오류");
	exit(1);
}

int     check_arg(int ac, char **av, t_config * conf)
{
	int		len;

	if (!(ac == 2 || (ac == 3 && !(ft_strncmp(av[2], "--save", 6)))))
		return (-1);
	if (ac == 3)
		conf->is_save = 1;
	len = ft_strlen(av[1]);
	if (ft_strncmp(av[1] + len - 4, ".cub", 4) != 0)
		return (-2);
	return (0);
}

int		init_new_mlx(t_cub *cub)
{
	cub->info.mlx = mlx_init();
	return (0);
}

int		parse_line(t_cub *cub, char *str)
{
	if (ft_strncmp(str, "R", 1) == 0)
		return(check_win_size(cub, str));
}

int		read_map_file(t_cub *cub, t_config *conf)
{
	int		gnl_err;
	char	*line;

	line = 0;
	while (1)
	{
		if ((gnl_err = get_next_line(conf->fd, &line)) <= 0)
			break ;
		if (parse_line(cub, line) < 0)
			return (-3);
		// printf("%s\n", line);
		free(line);
	}
	printf("%s\n", line);
	free(line);
	return (gnl_err);
}

int		set_map(t_cub *cub, t_config *conf, char *path)
{
	if ((conf->fd = open(path, O_RDONLY)) < 0)
		return (-3);
	if (read_map_file(cub, conf) != 0)
		return (-3);
	return (0);
}

int     main(int argc, char **argv)
{
	t_config    conf;
	t_cub		cub;
	int         err_num;

	if ((err_num = check_arg(argc, argv, &conf)) != 0)
		print_err(err_num);
	if ((err_num = init_new_mlx(&cub)) != 0)
		print_err(err_num);
	if ((err_num = set_map(&cub, &conf, argv[1])) != 0)
		print_err(err_num);
	return (0);
}