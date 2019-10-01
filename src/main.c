/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiego <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 14:28:47 by sdiego            #+#    #+#             */
/*   Updated: 2019/09/30 13:22:40 by sdiego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"

int		main(int argc, char **argv)
{
	char	*memory;
	int		fd;
	t_tet	*tet;

	if (argc != 2)
	{
		ft_putendl("map not found | use ./fillit 'filename'");
		return (0);
	}
	fd = open(argv[1], O_RDONLY);
	if (!(memory = ft_read_file(fd)))
		return (0);
	if (!ft_check_str(memory))
	{
		ft_putendl("error");
		return (0);
	}
	close(fd);
	tet = ft_tetri_lists(memory);
	ft_solve(tet);
	free(tet);
	free(memory);
	return (0);
}
