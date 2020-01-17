#include "fdf.h"

static	void move1(t_mlx *mlx, int x)
{
	if (x == 5 || x == -5)
		mlx->cam.x_r += x / 5 * 0.1;
	else if (x == 6 || x == -6)
		mlx->cam.y_r += x / 6 * 0.1;
	else if (x == 7 || x == -7)
		mlx->cam.z_r += x / 7 * 0.1;
	else if (x == 8)
	{
		mlx->cam.x_r = 0;
		mlx->cam.y_r = 0;
		mlx->cam.z_r = 0;
		mlx->cam.di = 1;
		mlx->cam.x = X_START_POS;
		mlx->cam.y = Y_START_POS;
	}
}

void	move_it(t_mlx *mlx, int x)
{

	mlx_destroy_image(mlx->mlx, (*mlx).img.img_ptr);
	img_new(mlx);
	if (x == 1 || x == -1)
		mlx->cam.y += 5 * x;
	else if (x == 2 || x == -2)
		mlx->cam.x += 5 * x / 2;
	else if (x == 3 || x == -3)
		mlx->cam.di += 0.1 * x / 3;
	else if (x == 4 || x == -4)
	{
		if (x > 0 || mlx->cam.z > 0)
			mlx->cam.z += x / 4;
		if (mlx->cam.z < 1)
			mlx->cam.z = 1;
	}
	else if (x >= 5 || x <= -5)
		move1(mlx, x);
	print_map(mlx);
}