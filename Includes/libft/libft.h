/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysebban <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 11:09:41 by ysebban           #+#    #+#             */
/*   Updated: 2023/02/22 01:04:27 by ysebban          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H

# define LIBFT_H

# include "unistd.h"
# include "stdlib.h"
# include "stddef.h"
# include "stdarg.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4
# endif

typedef struct s_list
{
	int				content;
	int				ar_moove;
	int				br_moove;
	int				arr_moove;
	int				brr_moove;
	int				all_r_moove;
	int				all_rr_moove;
	int				all_moove;
	struct s_list	*next;
}	t_list;

int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
int		ft_strlen(const char *str);
void	*ft_memset(void *str, int c, size_t n);
void	*ft_bzero(void *str, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t count);
void	*ft_memmove(void *dest, const void *src, size_t n);
size_t	ft_strlcpy(char *dest, const char *src, size_t n);
char	*ft_strcpy(char *dest, char *src);
size_t	ft_strlcat(char *dest, const char *src, size_t n);
int		ft_tolower(int c);
int		ft_toupper(int c);
char	*ft_strdup(char *src);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
char	*ft_strnstr(const char *str, const char *tofind, size_t n);
int		ft_atoi(const char *str);
void	*ft_calloc(size_t n, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);
char	*ft_itoa(int n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
int		ft_printf(const char *str, ...);
int		sort_type(va_list a_voir, char c);
int		my_putnbr_base(int nbr, char *base);
int		my_unsigned_putnbr(unsigned int nb);
int		my_putchar(char c);
int		my_putstr(char *str);
int		my_putnbr(int nb);
int		my_put_p(unsigned long long nbr, char *base);
int		useless(unsigned long long nbr);
char	*get_next_line(int fd);
char	*get_till_end(int fd, char *all);
char	*get_leftover(char *all);
char	*trim_line(char *all);
void	red(void);
void	green(void);
void	yellow(void);
void	blue(void);
void	reset_col(void);
t_list	*ft_lstnew(int content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
int		ft_str_is_numeric(char *str);
int		ft_abs(int val);
int		ft_val_abs(int ref, int val);
char	*my_strjoin(char *all, char *line_read);
int     ft_strcmp(char *s1, char *s2);
char	**ft_double_split(char const *s, char c, char d);
#endif  
