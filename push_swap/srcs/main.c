/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhyeon <dhyeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 02:36:05 by dhyeon            #+#    #+#             */
/*   Updated: 2021/05/22 21:49:08 by dhyeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		main(int argc, char **argv)
{
	t_info	info;

	if (!check_arg(argc, argv))
		print_error();
	init_stack(argc, argv, &info);
	test(&info);
	solve(&info);
	test(&info);

	return (0);
}
