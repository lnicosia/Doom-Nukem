#ifndef POP_EVENTS_H
# define POP_EVENTS_H
# include "env.h"

typedef struct	s_events_executer
{
  	t_list		*tmp;
  	t_list		*tmp_values;
  	t_list		*prec;
  	t_list		*prec_values;
}				t_events_executer;

#endif
