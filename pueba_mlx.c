//cc -o so_long pueba_mlx.c -Imlx -Lmlx -lmlx -lX11 -lXext -lm

# include "so_long.h"

#define	WINDOW_WIDTH 1920
#define WINDOW_HEIGHT 1080


typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

void	ft_put_pixel(t_data *data, int x, int y, int color)
{
    char *pxl;

    if (x >= 0 && x < WINDOW_WIDTH && y >= 0 && y < WINDOW_HEIGHT)
    {
        pxl = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
        *(unsigned int *)pxl = color;
    }
}

void	load_all_sprites(t_img *img, void *mlx)
{
	img->p_idle = mlx_xpm_file_to_image(mlx, "sprites/gold_down_idle.xpm", &img->width, &img->height);
	img->p_up_1 = mlx_xpm_file_to_image(mlx, "sprites/gold_up1.xpm", &img->width, &img->height);
	img->p_up_2 = mlx_xpm_file_to_image(mlx, "sprites/gold_up2.xpm", &img->width, &img->height);
	img->p_down_1 = mlx_xpm_file_to_image(mlx, "sprites/gold_down1.xpm", &img->width, &img->height);
	img->p_down_2 = mlx_xpm_file_to_image(mlx, "sprites/gold_down2.xpm", &img->width, &img->height);
	img->p_left = mlx_xpm_file_to_image(mlx, "sprites/gold_left.xpm", &img->width, &img->height);
	img->p_right = mlx_xpm_file_to_image(mlx, "sprites/gold_right.xpm", &img->width, &img->height);
	img->floor = mlx_xpm_file_to_image(mlx, "sprites/ground.xpm", &img->width, &img->height);
	img->wall = mlx_xpm_file_to_image(mlx, "sprites/wall1.xpm", &img->width, &img->height);
	img->coin = mlx_xpm_file_to_image(mlx, "sprites/collectable.xpm", &img->width, &img->height);
	img->exit_0 = mlx_xpm_file_to_image(mlx, "sprites/exit_0.xpm", &img->width, &img->height);
	img->exit_25 = mlx_xpm_file_to_image(mlx, "sprites/exit_25.xpm", &img->width, &img->height);
	img->exit_50 = mlx_xpm_file_to_image(mlx, "sprites/exit_50.xpm", &img->width, &img->height);
	img->exit_75 = mlx_xpm_file_to_image(mlx, "sprites/exit_75.xpm", &img->width, &img->height);
	img->exit_100 = mlx_xpm_file_to_image(mlx, "sprites/exit_100.xpm", &img->width, &img->height);
}

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_img	img;
	//void	*img;
	//void	*img2;
	//int		i;
	//int		j;
	//int		img_width;
	//int		img_height;
	
	//i = WINDOW_HEIGHT/2 - 50;
	
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	//img.img = mlx_new_image(mlx, 1920, 1080);
	//img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	/*
	while (i <= WINDOW_HEIGHT/2 + 50)
	{
		j = WINDOW_WIDTH/2 - 50;
		while (j <= WINDOW_WIDTH/2 + 50)
		{
			if (i < WINDOW_HEIGHT/2 + 10)
				ft_put_pixel(&img, j, i, 0xFFFFFF);
			else if (i < WINDOW_HEIGHT/2 + 20)
				ft_put_pixel(&img, j, i, 0x000000);
			else if (i < WINDOW_HEIGHT/2 + 30)
				ft_put_pixel(&img, j, i, 0xFF0000);
			else if (i < WINDOW_HEIGHT/2 + 40)
				ft_put_pixel(&img, j, i, 0x00FF00);
			else
				ft_put_pixel(&img, j, i, 0x0000FF);
			j++;
		}
		i++;
	}
	*/
	//ft_put_pixel(&img, WINDOW_WIDTH/2, WINDOW_HEIGHT/2, 0xFFFFFF);
	
	
	//img.floor = mlx_xpm_file_to_image(mlx, "sprites/ground.xpm", &img_width, &img_height);
	
	//img.p_down_1 = mlx_xpm_file_to_image(mlx, "sprites/gold_down1.xpm", &img_width, &img_height);
	
	load_all_sprites(&img, mlx);
	
	mlx_put_image_to_window(mlx, mlx_win, img.floor, 0, 0);
	
	mlx_put_image_to_window(mlx, mlx_win, img.p_idle, 64, 0);
	
	
	mlx_loop(mlx);
}
