#include "env.h"

void	set_zbuffer_pixel_color(int x, int y, double max_z, t_env *env)
{
	double	alpha;

	alpha = 1 - env->zbuffer[x + env->w * y] / max_z;
	if (env->zbuffer[x + env->w * y] >= 0 && alpha >= 0 && alpha <= 1)
		env->sdl.texture_pixels[x + env->w * y] = (int)(alpha * 0xFF) << 24
			| (int)(alpha * 0xFF) << 16
			| (int)(alpha * 0xFF) << 8
			| (int)(alpha * 0xFF);
	else if (env->zbuffer[x + env->w * y] == 100000000)
		env->sdl.texture_pixels[x + env->w * y] = 0xFFAA0000;
	else
		env->sdl.texture_pixels[x + env->w * y] = 0;
}

/*
**	Give every pixel a shade according to the zbuffer
*/

void	set_zbuffer_colors(t_env *env)
{
	double	max_z;
	int		y;
	int		x;

	max_z = 30;
	y = 0;
	while (y < env->h)
	{
		if (env->editor.tab)
			x = 400;
		else
			x = 0;
		while (x < env->w)
		{
			if ((y <= 300 && x < env->w - 300) || y > 300
			  	|| env->editor.in_game || !env->options.show_minimap)
		  		set_zbuffer_pixel_color(x, y, max_z, env);
			x++;
		}
		y++;
	}
}

/*
**	Show Zbuffer
*/

void	update_screen_zbuffer(t_env *env)
{
	set_zbuffer_colors(env);
	if (SDL_UpdateTexture(env->sdl.texture, NULL, env->sdl.texture_pixels,
	  	env->w * sizeof(Uint32)))
	{
		ft_printf("Failed to update screen: %s\n", SDL_GetError());
		return ;
	}
	SDL_RenderCopy(env->sdl.renderer, env->sdl.texture, NULL, NULL);
	SDL_RenderPresent(env->sdl.renderer);
}