/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 11:01:13 by lnicosia          #+#    #+#             */
/*   Updated: 2019/03/08 11:01:42 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H

# define LIBFT_H
# include <unistd.h>
# include <stdlib.h>
# include <string.h>

typedef struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;

void			ft_putchar(char c);
void			ft_putstr(char const *s);
void			ft_putendl(char const *s);
size_t			ft_strlen(const char *str);
char			*ft_strcat(char *s1, const char *s2);
char			*ft_strcpy(char *dst, const char *src);
char			*ft_strncpy(char *dst, const char *src, size_t len);
void			ft_putnbr(int nb);
char			*ft_strdup(const char *s1);
int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);
void			*ft_memset(void *b, int c, size_t len);
void			ft_bzero(void *s, size_t n);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memccpy(void *dst, const void *src, int c, size_t n);
void			*ft_memchr(const void *s, int c, size_t n);
void			*ft_memalloc(size_t size);
char			*ft_strnew(size_t size);
char			*ft_strtrim(char const *s);
char			**ft_strsplit(char const *str, char charset);
char			*ft_strjoin(char const *s1, char const *s2);
int				ft_strnequ(char const *s1, char const *s2, size_t n);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
int				ft_strequ(char const *s1, char const *s2);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char			*ft_strmap(char const *s, char (*f)(char));
void			ft_striteri(char *s, void (*f)(unsigned int, char*));
void			ft_striter(char *s, void (*f)(char *));
void			ft_strdel(char **as);
void			ft_memdel(void **ap);
void			*ft_memset(void *b, int c, size_t len);
int				ft_tolower(int c);
int				ft_toupper(int c);
int				ft_atoi(const char *str);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
char			*ft_strncpy(char *dst, char const *src, size_t len);
int				ft_strcmp(const char *s1, const char *s2);
char			*ft_strnstr(const char *haystack,
				const char *needle, size_t len);
void			ft_strclr(char *s);
char			*ft_strstr(const char *haystack, const char *needle);
char			*ft_strnstr(const char *haystack,
				const char *needle, size_t len);
char			*ft_strrchr(const char *s, int c);
char			*ft_strchr(const char *s, int c);
size_t			ft_strlcat(char *dst, const char *src, size_t size);
char			*ft_strncat(char *dest, const char *src, size_t n);
void			*ft_memmove(void *dst, const void *src, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char const *s, int fd);
void			ft_putendl_fd(char const *s, int fd);
void			ft_putnbr_fd(int n, int fd);
char			*ft_itoa(int nbr);
t_list			*ft_lstnew(void const *content, size_t content_size);
void			ft_lstdelone(t_list **alst, void (*del)(void*, size_t));
void			ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void			ft_lstadd(t_list **alst, t_list *new);
void			ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
int				ft_lstlen(t_list *lst);
void			ft_lstpushback(t_list **alst, t_list *new);
int				ft_abs(int	nb);
int				ft_clamp(int nb, int min, int max);
int				ft_min(int nb1, int nb2);
int				ft_max(int nb1, int nb2);
double			ft_fabs(double nb);
double			ft_fclamp(double nb, double min, double max);
double			ft_fmin(double nb1, double nb2);
double			ft_fmax(double nb1, double nb2);
char			*ft_strjoin_free(char *s1, const char *s2);
int				get_next_line(int fd, char **line);
int				ft_count(int nb);
int				ft_atoi_base(char *str, char *base);
int				ft_dprintf(int fd, const char *restrict format, ...);
int				ft_printf(const char *restrict format, ...);

#endif
