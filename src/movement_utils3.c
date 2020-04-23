#include "env.h"
#include "collision.h"

void	animations(t_env *env)
{
	double	slope;
	t_v3	pos;

	pos.x = env->player.pos.x;
	pos.y = env->player.pos.y;
	slope = get_floor_at_pos(&env->sectors[env->player.highest_sect], pos, env);
	if ((env->player.pos.z > slope || env->player.state.fall
	  	|| env->player.state.jump) && !env->player.state.climb
		&& !env->player.state.drop && !env->player.state.fly)
		gravity(env);
	if ((env->inputs.space || env->player.state.jump)
			&& !env->player.state.climb && !env->player.state.drop)
		jump(env);
	if (((env->inputs.ctrl && env->player.eyesight > 3)
	|| env->player.state.crouch) && !env->editor.in_game)
		crouch(env);
	env->player.camera.pos.z = env->player.head_z;
	if (!env->player.state.jump && !env->player.state.fall
		&& !env->player.state.climb && !env->player.state.drop
		&& !env->player.state.fall && !env->player.state.fly)
		update_player_z(env);
}


int		check_blocage2(t_env *env, t_motion motion, double speed, int index)
{
  	t_v3	move;
	int		nb;

	nb = 0;
	if (index != 3)
	{
		move = check_collision(env, new_v3(env->player.camera.angle_cos
			* -speed, env->player.camera.angle_sin * -speed, 0), motion);
		if (move.x == 0 && move.y == 0)
			nb++;
	}
	if (index != 4)
	{
		move = check_collision(env, new_v3(env->player.camera.angle_cos
			* -speed, env->player.camera.angle_sin * -speed, 0), motion);
		if (move.x == 0 && move.y == 0)
			nb++;
	}
	return (nb);
}

/*
**	Handles player movements
**	TODO Protection / return values??
*/

void	check_blocage(t_env *env, t_motion motion, double speed, int index)
{
	int		nb;
	t_v3	move;

	nb = 0;
	if (index != 1)
	{
		move = check_collision(env, new_v3(env->player.camera.angle_cos
			* speed, env->player.camera.angle_sin * speed, 0), motion);
		if (move.x == 0 && move.y == 0)
			nb++;
	}
	if (index != 2)
	{
		move = check_collision(env, new_v3(env->player.camera.angle_cos
			* speed, env->player.camera.angle_sin * -speed, 0), motion);
		if (move.x == 0 && move.y == 0)
			nb++;
	}
	nb += check_blocage2(env, motion, speed, index);
	if (nb == 3)
	{
		ft_printf("stuck\n");
		env->player.stuck = 1;
	}
}

void	update_player_pos2(int new_sector, t_env *env)
{
	env->player.camera.pos = env->player.pos;
	env->player.camera.pos.z = env->player.head_z;
	if (((get_floor_at_pos(&env->sectors[env->player.highest_sect],
	  	env->player.pos, env) > env->player.pos.z
		&& get_floor_at_pos(&env->sectors[env->player.highest_sect],
		env->player.pos, env) - env->player.pos.z <= 2
		&& env->player.highest_sect != new_sector && !env->player.state.fly)
		|| (env->player.state.climb)) && !env->player.state.drop
		&& !env->player.state.jump && !env->player.state.fly)
		climb(env);
	else if ((((get_floor_at_pos(&env->sectors[env->player.highest_sect],
	  	env->player.pos, env) < env->player.pos.z
		&& env->player.pos.z - get_floor_at_pos(&env->sectors[env->player.
		highest_sect], env->player.pos, env) <= 2) || env->player.state.drop)
		&& !env->player.state.jump && !env->player.state.fall
		&& !env->player.state.climb) && env->player.drop_flag
		&& !env->player.state.fly)
		drop(env);
	env->player.sector = new_sector;
	env->player.camera.pos = env->player.pos;
	env->player.head_z = env->player.pos.z + env->player.eyesight;
	env->player.camera.pos.z = env->player.head_z;
	update_camera_position(&env->player.camera);
}

void	update_player_pos(t_env *env)
{
	int			new_sector;
	t_motion	motion;
	int			prev_highest_sect;

	new_sector = get_sector_no_z_origin(env,
		env->player.pos, env->player.sector);
	motion = new_motion(new_sector, env->player.size_2d,
	env->player.eyesight, env->player.pos);
	if (new_sector != env->player.sector)
	{
		env->player.old_sector = env->player.sector;
		env->player.changed_sector = 1;
	}
	prev_highest_sect = env->player.highest_sect;
	env->player.highest_sect = find_highest_sector(env, motion);
	if (prev_highest_sect != env->player.highest_sect
		&& get_floor_at_pos(&env->sectors[env->player.highest_sect],
		env->player.pos, env) < get_floor_at_pos(
		&env->sectors[prev_highest_sect], env->player.pos, env)
		&& !env->player.state.fly)
		env->player.drop_flag = 1;
	update_player_pos2(new_sector, env);
}
