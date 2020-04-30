#include "env.h"

int			check_sector_convexity2(t_v2 *p, int len, int *res)
{
	int		i;
	int		straight;

	straight = 0;
	p[len - 2] = p[0];
	p[len - 1] = p[1];
	i = 0;
	while (i < len - 2)
	{
		*res = check_all_angles(p, *res, i, straight);
			if (!*res)
			straight++;
		else
			straight = 0;
		i++;
	}
	free(p);
	if (*res != -(len - 2) && *res != len - 2 && *res)
		return (1);
	return (0);
}

int			check_sector_convexity(t_env *env, t_list *tmp, int len, int *res)
{
	t_v2	*p;
	int		i;

	i = 0;
	len += 3;
	if (!(p = (t_v2*)ft_memalloc(sizeof(t_v2) * (len))))
		return (-1);
	p[len - 3].x = round((env->sdl.mx - env->editor.center.x)
	/ env->editor.scale);
	p[len - 3].y = round((env->sdl.my - env->editor.center.y)
	/ env->editor.scale);
	while (tmp)
	{
		p[i].x = ((t_vertex*)tmp->content)->x;
		p[i].y = ((t_vertex*)tmp->content)->y;
		tmp = tmp->next;
		i++;
	}
	return (check_sector_convexity2(p, len, res));
}

int			is_new_sector_convex(t_env *env, t_list *tmp)
{
	int		len;
	int		res;
	int		ret;

	res = 0;
	len = ft_lstlen(env->editor.current_vertices);
	tmp = env->editor.current_vertices;
	if (len > 2)
	{
	  	ret = check_sector_convexity(env, tmp, len, &res);
		if (ret == -1)
			return (-1);
		else if (ret == 1)
			return (0);
	}
	if (!res)
		env->sector_is_straight = 1;
	else
		env->sector_is_straight = 0;
	return (1);
}
