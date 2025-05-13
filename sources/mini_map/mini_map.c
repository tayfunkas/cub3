#include "../inc/cub3d.h"

void	draw_minimap(t_game *game)
{
	int	i;
	int	j;
	int	x;
	int	y;
	int	color;

	i = 0;
	while (i < game->map->m_height)
	{
		j = 0;
		while (j < (int)ft_strlen(game->map->data[i]))
		{
			if (game->map->data[i][j] == '1')
				color = 0xAAAAAA; // pared
			else if (game->map->data[i][j] == '0')
				color = 0x222222; // piso
			else
				color = 0x000000; // cualquier otro carácter
			y = 0;
			while (y < MIN_S)
			{
				x = 0;
				while (x < MIN_S)
				{
					my_mlx_pixel_put(game, j * MIN_S + x, i * MIN_S + y, color);
					x++;
				}
				y++;
			}
			j++;
		}
		i++;
	}
}

