#include "env.h"

t_explosion_data	new_explosion_data(t_v3 pos, double radius, int damage,
int sprite)
{
	t_explosion_data	new;

	new.pos = pos;
	new.radius = radius;
	new.damage = damage;
	new.sprite = sprite;
	return (new);
}

int		create_explosion(t_env *env, t_explosion_data data, int centered_sprite)
{
	t_list		*new;

	if (!(new = ft_lstnew(&env->explosion, sizeof(t_explosion))))
		return (ft_printf("Error when creating explosion\n"));
	ft_lstpushback(&env->explosions, new);
	((t_explosion*)new->content)->sprite = data.sprite;
	((t_explosion*)new->content)->damage = data.damage;
	((t_explosion*)new->content)->radius = data.radius;
	((t_explosion*)new->content)->pos = data.pos;
	((t_explosion*)new->content)->damage_burst = -1;
	((t_explosion*)new->content)->scale = data.radius;
	((t_explosion*)new->content)->explosion_anim.start = 0;
	((t_explosion*)new->content)->centered_sprite = centered_sprite;
	return (0);
}

void	activate_explosions(t_env *env)
{
	t_list	*tmp;

	tmp = env->explosions;
	while (tmp)
	{
		if (((t_explosion*)tmp->content)->damage_burst == -1)
			((t_explosion*)tmp->content)->damage_burst = 1;
		tmp = tmp->next;
	}
}

void	explosion_collision_enemy(t_explosion *explosion, int i, t_env *env)
{
	double	distance;
	int		damage;

	if (explosion->damage_burst == 1 && env->enemies[i].health > 0)
	{
		distance = distance_two_points_3d(new_v3(env->enemies[i].pos.x,
		env->enemies[i].pos.y, env->enemies[i].pos.z), explosion->pos);
		if (distance < explosion->radius && explosion->damage_burst)
		{
			damage = aoe_damage(distance, explosion->radius, explosion->damage);
			env->enemies[i].health -= damage;
			env->enemies[i].hit = 1;
		}
	}
}

int		explosion_collision_enemies(t_env *env)
{
	t_list *tmp;
	int		i;

	tmp = env->explosions;
	while (tmp)
	{
		i = 0;
		while (i < env->nb_enemies)
		{
		  	explosion_collision_enemy(((t_explosion*)tmp->content), i, env);
			i++;
		}
		tmp = tmp->next;
	}
	return (0);
}
