#include "env.h"

int		init_skyboxes_textures2(t_env *env)
{
	if (parse_bmp_skybox_textures("images/skyboxes/nebula_front.bmp", 1, 4,
	  	env))
		return (ft_printf("Failed to load skybox\n"));
	if (parse_bmp_skybox_textures("images/skyboxes/nebula_right.bmp", 1, 5,
	  	env))
		return (ft_printf("Failed to load skybox\n"));
	if (parse_bmp_skybox_textures("images/skyboxes/bottom.bmp", 2, 0, env))
		return (ft_printf("Failed to load skybox\n"));
	if (parse_bmp_skybox_textures("images/skyboxes/top.bmp", 2, 1, env))
		return (ft_printf("Failed to load skybox\n"));
	if (parse_bmp_skybox_textures("images/skyboxes/back.bmp", 2, 2, env))
		return (ft_printf("Failed to load skybox\n"));
	if (parse_bmp_skybox_textures("images/skyboxes/left.bmp", 2, 3, env))
		return (ft_printf("Failed to load skybox\n"));
	if (parse_bmp_skybox_textures("images/skyboxes/front.bmp", 2, 4, env))
		return (ft_printf("Failed to load skybox\n"));
	if (parse_bmp_skybox_textures("images/skyboxes/right.bmp", 2, 5, env))
		return (ft_printf("Failed to load skybox\n"));
	return (0);
}

int		init_skyboxes_textures(t_env *env)
{
	if (parse_bmp_skybox_textures("images/skyboxes/night_bottom.bmp", 0, 0,
	  	env))
		return (ft_printf("Failed to load skybox\n"));
	if (parse_bmp_skybox_textures("images/skyboxes/night_top.bmp", 0, 1, env))
		return (ft_printf("Failed to load skybox\n"));
	if (parse_bmp_skybox_textures("images/skyboxes/night_back.bmp", 0, 2, env))
		return (ft_printf("Failed to load skybox\n"));
	if (parse_bmp_skybox_textures("images/skyboxes/night_left.bmp", 0, 3, env))
		return (ft_printf("Failed to load skybox\n"));
	if (parse_bmp_skybox_textures("images/skyboxes/night_front.bmp", 0, 4, env))
		return (ft_printf("Failed to load skybox\n"));
	if (parse_bmp_skybox_textures("images/skyboxes/night_right.bmp", 0, 5, env))
		return (ft_printf("Failed to load skybox\n"));
	if (parse_bmp_skybox_textures("images/skyboxes/nebula_bottom.bmp", 1, 0,
	  	env))
		return (ft_printf("Failed to load skybox\n"));
	if (parse_bmp_skybox_textures("images/skyboxes/nebula_top.bmp", 1, 1, env))
		return (ft_printf("Failed to load skybox\n"));
	if (parse_bmp_skybox_textures("images/skyboxes/nebula_back.bmp", 1, 2, env))
		return (ft_printf("Failed to load skybox\n"));
	if (parse_bmp_skybox_textures("images/skyboxes/nebula_left.bmp", 1, 3, env))
		return (ft_printf("Failed to load skybox\n"));
	return (init_skyboxes_textures2(env));
}