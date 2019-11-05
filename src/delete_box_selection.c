#include "env.h"

int	delete_box_selection(t_input_box *box)
{
	char	*res;
	char	*s1;
	char	*s2;
	size_t	start;
	size_t	end;

	if (box->select_start > box->select_end)
	{
		start = box->select_end;
		end = box->select_start;
	}
	else {
		start = box->select_start;
		end = box->select_end;
	}
	s1 = ft_strsub(box->str, 0, start);
	s2 = ft_strsub(box->str, end, ft_strlen(box->str) - end);
	if (!(res = ft_strnew(ft_strlen(box->str) - (end - start))))
		return (-1);
	res = ft_strcpy(res, s1);
	res = ft_strcat(res, s2);
	if (s1)
		ft_strdel(&s1);
	if (s2)
		ft_strdel(&s2);
	if (box->str)
		ft_strdel(&box->str);
	box->str = res;
	box->select_start = 0;
	box->select_end = 0;
	box->selecting = 0;
	box->cursor = start;
	return (0);
}
