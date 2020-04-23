#include "env.h"
#include "collision.h"

void	projectile_coord(t_v3 pos, t_projectile *projectile,
t_projectile_data_2 data2, double height)
{
	projectile->pos.x = (data2.radius + 2.5) * cos(projectile->angle) + pos.x;
	projectile->pos.y = (data2.radius + 2.5) * sin(projectile->angle) + pos.y;
	projectile->pos.z = (data2.radius + 2.5) * -data2.angle_z + pos.z + height;
	projectile->dest.x = 100000000 * cos(projectile->angle)
	+ projectile->pos.x;
	projectile->dest.y = 100000000 * sin(projectile->angle)
	+ projectile->pos.y;
	projectile->dest.z = 100000000 * -data2.angle_z + projectile->pos.z;
}

int		create_projectile(t_env *env, t_projectile_data data,
t_projectile_stats stats, t_projectile_data_2 data2)
{
	t_list	*new;

	if (!(new = ft_lstnew(&env->projectile, sizeof(t_projectile))))
		return (ft_printf("Error when creating new projectile\n"));
	ft_lstpushback(&env->projectiles, new);
	((t_projectile*)new->content)->sprite = data.sprite;
	((t_projectile*)new->content)->speed = stats.speed;
	((t_projectile*)new->content)->angle = data.angle;
	projectile_coord(data.pos, ((t_projectile*)new->content), data2,
	stats.height);
	((t_projectile*)new->content)->scale = data.scale;
	((t_projectile*)new->content)->damage = stats.damage;
	((t_projectile*)new->content)->size_2d = stats.size_2d;
	((t_projectile*)new->content)->exists = 1;
	((t_projectile*)new->content)->sector = get_sector_no_z(env,
	((t_projectile*)new->content)->pos);
	((t_projectile*)new->content)->angle = data.angle * CONVERT_DEGREES;
	return (0);
}

int		projectile_hits_player(t_projectile *projectile, t_list **tmp,
t_env *env)
{
	if (!env->player.invincible)
	{
		env->player.hit = 1;
		env->player.health -= ft_clamp(projectile->damage
		- env->player.armor, 0, projectile->damage);
		env->player.armor -= ft_clamp(projectile->damage,
		0, env->player.armor);
	}
	*tmp = ft_lstdelnode(&env->projectiles, *tmp);
	return (0);
}

int		projectile_hits_object(t_projectile *projectile, t_list **tmp,
t_env *env)
{
	if (create_explosion(env, new_explosion_data(projectile->pos, 7,
	  	projectile->damage,
		env->object_sprites[projectile->sprite].death_counterpart), 1))
	  	return (-1);
	env->nb_explosions++;
	*tmp = ft_lstdelnode(&env->projectiles, *tmp);
	return (0);
}

int		projectile_hits_enemy(int nb, t_projectile *projectile, t_list **tmp,
t_env *env)
{
	env->enemies[nb].health -= projectile->damage;
	env->enemies[nb].hit = 1;
	if (create_explosion(env, new_explosion_data(projectile->pos, 7,
	  	projectile->damage,
		env->object_sprites[projectile->sprite].death_counterpart), 1))
	  	return (-1);
	env->nb_explosions++;
	*tmp = ft_lstdelnode(&env->projectiles, *tmp);
	if (env->enemies[nb].health <= 0)
	{
		env->player.killed++;
		if (env->enemies[nb].nb_death_events > 0
			&& env->enemies[nb].death_events
			&& start_event(&env->enemies[nb].death_events,
			&env->enemies[nb].nb_death_events, env))
			return (-1);
	}
	return (0);
}
