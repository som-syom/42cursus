/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhyeon <dhyeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 02:48:15 by dhyeon            #+#    #+#             */
/*   Updated: 2020/12/04 06:20:43 by dhyeon           ###   ########.fr       */
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
		ft_putstr("맵 오류\n");
	perror("error message");
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

int		init_new_mlx(t_cub *cub, t_config *conf)
{
	int i;

	// cub->info.mlx = mlx_init();
	if (!(conf->tex_path = (char**)malloc(sizeof(char *) * 8)))
		return (-1);
	i = -1;
	while (++i < 8)
		conf->tex_path[i] = 0;
	conf->rgb[0] = -1;
	conf->rgb[1] = -1;
	return (0);
}



int     main(int argc, char **argv)
{
	t_config    conf;
	t_cub		cub;
	int         err_num;

	if ((err_num = check_arg(argc, argv, &conf)) != 0)
		print_err(err_num);
	if ((err_num = init_new_mlx(&cub, &conf)) != 0)
		print_err(err_num);
	if ((err_num = set_map(&cub, &conf, argv[1])) != 0)
		print_err(err_num);
	return (0);
}