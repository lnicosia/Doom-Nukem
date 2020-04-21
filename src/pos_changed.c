#include "env.h"

int		pos_changed_sector(t_env *env, t_sector *sector, t_point data,
		t_v3 pos)
{
	int	prec;
	int	new;

	prec = get_sector_no_z(env, pos);
	if (((new = get_sector_no_z_origin(env, pos, prec)) == -1)
		|| (new != prec && new != sector->neighbors[data.y]
		&& new != sector->neighbors[data.x]&& new != sector->num))
		return (1);
	return (0);
}

int		player_changed_sector(t_env *env, t_sector *sector, t_point data,
		t_v3 pos)
{
	int	prec;
	int	new;

	prec = env->player.sector;
	if (((new = get_sector_no_z_origin(env, pos, prec)) == -1)
		|| (new != prec && new != sector->neighbors[data.y]
		&& new != sector->neighbors[data.x] && new != sector->num))
		return (1);
	return (0);
}
