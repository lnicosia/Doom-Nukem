/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render2.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 14:41:44 by lnicosia          #+#    #+#             */
/*   Updated: 2019/09/10 15:05:54 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER2_H
# define RENDER2_H
#include "env.h"

typedef struct	s_render2
{
	int			sector;
	int			selected;
	int			xmin;
	int			xmax;
	int			xstart;
	int			xend;
}				t_render2;

void		render_sector2(t_render2 render, t_env *env);

#endif
