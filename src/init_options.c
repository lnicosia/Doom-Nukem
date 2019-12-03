#include "env.h"

void	init_options(t_env *env)
{
	ft_printf("Initializing options..\n");
	env->options.contouring = 0;
	env->options.render_sectors = 1;
	env->options.lighting = 1;
	env->options.show_minimap = 1;
	env->options.wall_lover = 0;
	env->options.show_fps = 1;
	env->options.color_clipping = 0;
	env->options.wall_color = 1;
	env->options.test = 0;
	env->options.minimap_scale = 2.5;
	env->options.clipping = 1;
	env->option = 0;
	env->options.gamma_filter = 1;
	env->options.show_ennemies = 1;
	env->options.zbuffer = 0;
	env->options.p = 1;
	env->options.animations = 1;
	env->options.mipmapping = 1;
	env->minimap_size = new_point(300, 300);
	env->minimap_pos = new_point(env->w - env->minimap_size.x / 2 - 20,
	env->minimap_size.y / 2 + 20);
	env->crosshair_pos = new_point(env->h_w, env->h_h);
	env->options.max_floor_sprites = 5;
	env->options.max_wall_sprites = 3;
}
