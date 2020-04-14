#include "env.h"

int		selection_tabs_keyup(t_env *env)
{
	int	i;

	i = 0;

	if (env->editor.draw_texture_tab)
	{
		i = 0;
		while (i < MAX_WALL_TEXTURE)
		{
			if (button_keyup(&env->editor.textures[i], env))
				return (-1);
			i++;
		}
		i = 0;
		while (i < MAX_SKYBOX)
		{
			if (button_keyup(&env->editor.skyboxes[i], env))
				return (-1);
			i++;
		}
	}
	if (env->editor.draw_sprite_tab)
	{
		i = 0;
		while (i < MAX_OBJECTS)
		{
			if (button_keyup(&env->editor.sprite_selection[i], env))
				return (-1);
			i++;
		}
	}
	if (env->editor.draw_object_tab)
	{
		i = 0;
		while (i < MAX_OBJECTS)
		{
			if (button_keyup(&env->editor.object_tab[i], env))
				return (-1);
			i++;
		}
	}
	if (env->editor.draw_enemy_tab)
	{
		i = 0;
		while (i < MAX_ENEMIES)
		{
			if (button_keyup(&env->editor.enemy_tab[i], env))
				return (-1);
			i++;
		}
	}
	return (0);
}
