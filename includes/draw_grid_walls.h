#ifndef DRAW_GRID_WALLS_H
# define DRAW_GRID_WALLS_H

typedef struct	s_grid_wall_drawer
{
	t_point		v[3];
	t_point		center;
	t_point		text_size;
	t_sector	*sector;
	Uint32		color;
  	int			i;
	int			nb_angles;
	int			font_size;

}				t_grid_wall_drawer;

#endif
