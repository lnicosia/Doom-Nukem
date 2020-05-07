#include "env.h"

void	print_hfov_value(t_env *env)
{
	int w;
	int h;

	TTF_SizeText(env->sdl.fonts.lato30, "FOV", &w, &h);
	print_text(new_point(env->h_h - env->h_h / 4 +
		env->fov_increase.size_down.y, env->h_w - w / 2),
		new_printable_text("FOV", env->sdl.fonts.lato30,
		0x222222FF, 30), env);
	ft_snprintf(env->snprintf, 4, "%.f",
		env->player.camera.hfov);
	TTF_SizeText(env->sdl.fonts.lato30, env->snprintf, &w, &h);
	print_text(new_point(env->h_h - env->h_h / 4 +
		env->fov_increase.size_down.y + 35, env->h_w - w / 2),
		new_printable_text(env->snprintf, env->sdl.fonts.lato30,
		0x222222FF, 30), env);
}

int		fov_increase(void *target)
{
	t_env		*env;
	t_camera	*camera;

	env = (t_env*)target;
	camera = &env->player.camera;
	if (camera->hfov <= 115)
	{
		camera->hfov += 5;
		set_camera(camera, env);
	}
	return (0);
}

int		fov_increase_button(t_env *env)
{
	env->fov_increase = new_next_button(ON_RELEASE,
		&fov_increase, env, env);
	env->fov_increase.pos = new_point(env->h_w + env->h_w / 4,
		env->h_h - env->h_h / 4 + env->fov_increase.size_down.y);
	return (0);
}

int		fov_decrease(void *target)
{
	t_env		*env;
	t_camera	*camera;

	env = (t_env*)target;
	camera = &env->player.camera;
	if (camera->hfov >= 65)
	{
		camera->hfov -= 5;
		set_camera(camera, env);
	}
	return (0);
}

int		fov_decrease_button(t_env *env)
{
	env->fov_decrease = new_previous_button(ON_RELEASE,
		&fov_decrease, env, env);
	env->fov_decrease.pos = new_point(env->h_w - env->h_w / 4,
		env->h_h - env->h_h / 4 + env->fov_decrease.size_down.y);
	return (0);
}