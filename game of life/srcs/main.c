/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpinson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 20:51:39 by mpinson           #+#    #+#             */
/*   Updated: 2017/04/10 20:51:43 by mpinson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gol.h"
#include "limits.h"

char	**ft_get_maps(char *str, t_env *e)
{
	char	**map;
	int		i;
	int		fd;
	char	tab[999999];

	i = 0;
	if ((fd = open(str, O_RDONLY)) == -1)
		return (NULL);
	if (read(fd, tab, INT_MAX) == -1)
		return (NULL);
	map = ft_strsplit(tab, '\n');
	while (map[i] != NULL)
	{
		ft_putstr(map[i]);
		ft_putchar('\n');
		i++;
	}
	system("clear");
	if (!(e->etats = (int *)malloc(sizeof(int) *
		(ft_strlen_tab(map) * ft_strlen(map[0])))))
		return (NULL);
	e->leng = ft_strlen_tab(map) * ft_strlen(map[0]);
	return (map);
}

int		get_etats(char **map, int x, int y)
{
	int adj;

	adj = 0;
	x + 1 < ft_strlen_tab(map) && map[x + 1][y] == '#' ? adj++ : 0;
	if (x - 1 >= 0 && map[x - 1][y] == '#')
		adj++;
	if (y + 1 < (int)ft_strlen(map[0]) && map[x][y + 1] == '#')
		adj++;
	if (y - 1 >= 0 && map[x][y - 1] == '#')
		adj++;
	if (x + 1 < ft_strlen_tab(map) && y + 1 <
		(int)ft_strlen(map[0]) && map[x + 1][y + 1] == '#')
		adj++;
	if (x - 1 >= 0 && y - 1 >= 0 && map[x - 1][y - 1] == '#')
		adj++;
	if (y + 1 < (int)ft_strlen(map[0]) &&
		x - 1 >= 0 && map[x - 1][y + 1] == '#')
		adj++;
	if (y - 1 >= 0 && x + 1 < ft_strlen_tab(map) && map[x + 1][y - 1] == '#')
		adj++;
	if (adj == 3)
		return (1);
	if (adj == 2)
		return (2);
	return (0);
}

void	modif_map(char **map, t_env *e)
{
	int x;
	int y;
	int i;

	x = 0;
	y = 0;
	i = 0;
	while (x < ft_strlen_tab(map))
	{
		y = 0;
		while (y < (int)strlen(map[x]))
		{
			if (e->etats[i] == 1)
			{
				map[x][y] = '#';
			}
			if (e->etats[i] == 0)
			{
				map[x][y] = '.';
			}
			if(map[x][y] == '.')
				write(1, "\e[0;30m", 8);
			else
				write(1, "\e[0;32m", 8);
			ft_putchar(map[x][y]);
			i++;
			y++;
		}
		ft_putchar('\n');
		x++;
	}
}

void	ft_gol(char **map, t_env *e)
{
	int x;
	int y;
	int i;

	x = 0;
	y = 0;
	i = 0;
	while (1)
	{
		i = 0;
		x = -1;
		while (++x < ft_strlen_tab(map))
		{
			y = -1;
			while (++y < (int)strlen(map[x]))
			{
				e->etats[i] = get_etats(map, x, y);
				i++;
			}
		}
		modif_map(map, e);
		usleep(10000);
		write(1, "\033[H\033[2", 12);
	//	write(1, "\e[0;32m", 8);
	}
}

int		main(int argc, char **argv)
{
	t_env	e;
	char	**map;

	if (argc != 2)
		return (0);
	if ((map = ft_get_maps(argv[1], &e)) == NULL)
		return (0);
	ft_gol(map, &e);
	return (0);
}
