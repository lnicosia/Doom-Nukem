#include "events_parser.h"

void	write_fixed_event(int fd, t_event event)
{
	if (event.type == DOUBLE)
		ft_dprintf(fd, "%.*f %.*f]",
		ft_min(5, get_decimal_len(event.goal)), event.goal,
		ft_min(5, get_decimal_len(event.speed)), event.speed);
	else if (event.type == INT)
		ft_dprintf(fd, "%d %.*f]", (int)event.goal,
		ft_min(5, get_decimal_len(event.speed)), event.speed);
	else if (event.type == UINT32)
		ft_dprintf(fd, "%X %.*f]", (Uint32)event.goal,
		ft_min(5, get_decimal_len(event.speed)), event.speed);
}

void	write_incr_event(int fd, t_event event)
{
	if (event.type == DOUBLE)
		ft_dprintf(fd, "%.*f %.*f]",
		ft_min(5, get_decimal_len(event.start_incr)), event.start_incr,
		ft_min(5, get_decimal_len(event.speed)), event.speed);
	else if (event.type == INT)
		ft_dprintf(fd, "%d %.*f]", (int)event.start_incr,
		ft_min(5, get_decimal_len(event.speed)), event.speed);
	else if (event.type == UINT32)
		ft_dprintf(fd, "%X %.*f]", (Uint32)event.start_incr,
		ft_min(5, get_decimal_len(event.speed)), event.speed);
}

void	write_event(int fd, t_event event, void (*writers[])(int, t_event))
{
	writers[event.target_index](fd, event);
	if (event.target_index >= MAX_REAL_TARGET_TYPES)
	{
		ft_dprintf(fd, "][0 0 0]");
		write_event_conditions(fd, event);
		ft_dprintf(fd, "[%d %d]\n", (int)event.delay, event.max_uses);
		return ;
	}
	ft_dprintf(fd, "]");
	ft_dprintf(fd, "[%d ", event.mod_type);
	if (event.mod_type == FIXED)
	  	write_fixed_event(fd, event);
	else if (event.mod_type == INCR)
	  	write_incr_event(fd, event);
	write_event_conditions(fd, event);
	ft_dprintf(fd, "[%d %d]\n", (int)event.delay, event.max_uses);
}

void	write_sector_events(int fd, int num, t_sector sector,
		void (*writers[])(int, t_event))
{
	size_t	i;

	i = 0;
	while (i < sector.nb_stand_events)
	{
		ft_dprintf(fd, "[3 (%d)][%d", num, sector.stand_events[i].target_index);
		write_event(fd, sector.stand_events[i], writers);
		i++;
	}
	i = 0;
	while (i < sector.nb_walk_in_events)
	{
		ft_dprintf(fd, "[4 (%d)][%d", num,
				sector.walk_in_events[i].target_index);
		write_event(fd, sector.walk_in_events[i], writers);
		i++;
	}
	i = 0;
	while (i < sector.nb_walk_out_events)
	{
		ft_dprintf(fd, "[5 (%d)][%d", num,
				sector.walk_out_events[i].target_index);
		write_event(fd, sector.walk_out_events[i], writers);
		i++;
	}
}

void	write_current_wall_sprites_events(int fd, t_sector sector,
		void (*writers[])(int, t_event), int i)
{
	int		j;
	size_t	k;

	j = 0;
	while (j < sector.wall_sprites[i].nb_sprites)
	{
		k = 0;
		while (k < sector.wall_sprites[i].nb_press_events[j])
		{
			ft_dprintf(fd, "[1 (%d %d %d)][%d", sector.num, i, j,
			sector.wall_sprites[i].press_events[j][k].target_index);
			write_event(fd, sector.wall_sprites[i].press_events[j][k],
			writers);
			k++;
		}
		k = 0;
		while (k < sector.wall_sprites[i].nb_shoot_events[j])
		{
			ft_dprintf(fd, "[2 (%d %d %d)][%d", sector.num, i, j,
			sector.wall_sprites[i].shoot_events[j][k].target_index);
			write_event(fd, sector.wall_sprites[i].shoot_events[j][k],
			writers);
			k++;
		}
		j++;
	}
}
