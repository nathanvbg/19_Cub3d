/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nverbrug <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 15:16:00 by nverbrug          #+#    #+#             */
/*   Updated: 2021/04/21 15:53:11 by nverbrug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nverbrug <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 15:35:05 by nverbrug          #+#    #+#             */
/*   Updated: 2021/04/14 15:15:26 by nverbrug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	check_args(t_idx *c, int argc, char **argv)
{
	c->save = 0;
	if (argc == 1 || argc > 3)
		ft_exit(c, "Error\nArguments error\n");
	if (argc == 3)
	{
		if (strncmp(argv[2], "--save\0", 7) == 0)
			c->save = 1;
		else
			ft_exit(c, "Error\nThird argument is not '--save'");
	}
	if (ft_strncmp(&argv[1][ft_strlen(argv[1]) - 4], ".cub", 4) != 0)
		ft_exit(c, "Error\nWrong extention\n");
}

void	init_mlx(t_idx *c)
{
	c->mlx_ptr = mlx_init();
	if (c->mlx_ptr == NULL)
		ft_exit(c, "Error\nmlx error\n");
	c->win_ptr = mlx_new_window(c->mlx_ptr, c->ds.screen.x,
			c->ds.screen.y, "cub3D");
	if (c->win_ptr == NULL)
		ft_exit(c, "Error\nmlx error\n");
	c->img.ptr = mlx_new_image(c->mlx_ptr, c->ds.screen.x, c->ds.screen.y);
	if (c->img.ptr == NULL)
		ft_exit(c, "Error\nmlx error\n");
	c->img.addr = (int *)mlx_get_data_addr(c->img.ptr, &c->img.bbp,
			&c->img.size_l, &c->img.endian);
	if (c->img.addr == NULL)
		ft_exit(c, "Error\nmlx error\n");
	init_texture(c);
	malloc_sprites(c);
	algo(c);
	mlx_hook(c->win_ptr, 2, 1L << 1, command_vertical, c);
	mlx_hook(c->win_ptr, 17, 1L << 17, red_cross, c);
	mlx_loop(c->mlx_ptr);
}

void	algo(t_idx *c)
{
	int		x;
	t_img	*text_img;

	x = 0;
	while (x < c->ds.screen.x)
	{
		c->dda.hit = 0;
		init_map_var1(c, x);
		init_map_var2(c);
		dda(c);
		line_height(c);
		text_img = get_texture_img(c);
		draw_line(text_img, c, x);
		c->spr.zbuffer[x] = c->dda.wallperp;
		x++;
	}
	manage_sprites(c);
	if (c->save == 1)
	{
		bmp(c);
		ft_exit(c, "\nbmp créé\n");
	}
	else
		mlx_put_image_to_window(c->img.ptr, c->win_ptr, c->img.ptr, 0, 0);
}

int	main(int argc, char **argv)
{
	t_idx	c;

	init(&c);
	check_args(&c, argc, argv);
	parsing(&c, argv[1]);
	init_mlx(&c);
	return (0);
}
