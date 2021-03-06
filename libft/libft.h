/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kradoste <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 16:16:35 by kradoste          #+#    #+#             */
/*   Updated: 2019/10/07 16:58:05 by kradoste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdint.h>
# include <stdarg.h>
# include <stdbool.h>

# define BUFF_SIZE 32
# define UNS(x) (x == 'u' || x == 'U')
# define INT(x) (x == 'i' || x == 'd' || x == 'D')
# define HEO(x) (x == 'x' || x == 'X' || x == 'o' || x == 'O')
# define NUM(x) (UNS(x) || HEO(x) || INT(x))
# define LET(x) (x == 'c' || x == 'S' || x == 's' || x == 'C')

typedef struct	s_printf
{
	va_list	ap;
	char	*buf;
	int		god;
	int		len;
	int		width;
	int		hash;
	int		plus;
	int		zero;
	int		pre;
	int		dot;
	int		space;
	int		key;
}				t_printf;

typedef struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;

typedef struct	s_md5
{
	unsigned int	a0;
	unsigned int	b0;
	unsigned int	c0;
	unsigned int	d0;
	unsigned int	a;
	unsigned int	b;
	unsigned int	c;
	unsigned int	d;
	unsigned int	x;
	unsigned int	y;
	unsigned int	out_len;
	long long		len;
	unsigned int	f;
	unsigned int	g;
	unsigned char	*out;
	unsigned int	var[16];
}				t_md5;

typedef struct	s_sha256
{
	unsigned int	ao;
	unsigned int	bo;
	unsigned int	co;
	unsigned int	doo;
	unsigned int	eo;
	unsigned int	fo;
	unsigned int	go;
	unsigned int	ho;
	unsigned int	i;
	long long		len;
	unsigned int	out_len;
	unsigned char	*out;
	unsigned int	x;
	unsigned int	s0;
	unsigned int	s1;
	unsigned int	ch;
	unsigned int	maj;
	unsigned int	tmp1;
	unsigned int	tmp2;
	unsigned int	a;
	unsigned int	b;
	unsigned int	c;
	unsigned int	d;
	unsigned int	e;
	unsigned int	f;
	unsigned int	g;
	unsigned int	h;
	unsigned int	j;
}				t_sha256;
/*
**------------------------>LIST FUNCTIONS<------------------------------**
*/
void			ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
t_list			*ft_lstnew(void const *content, size_t content_size);
void			ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void			ft_lstadd(t_list **alst, t_list *new);
void			ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
/*
**------------------------>STRING FUNCTIONS<----------------------------**
*/
void			ft_putchar(char c);
void			ft_putstr(char const *s);
void			ft_putendl(char const *s);
void			ft_putnbr(int n);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char const *s, int fd);
void			ft_putendl_fd(char const *s, int fd);
void			ft_putnbr_fd(int n, int fd);
size_t			ft_strlen(const char *str);
char			*ft_strdup(const char *s1);
char			*ft_strcpy(char *dst, const char *src);
char			*ft_strncpy(char *dst, const char *src, size_t len);
char			*ft_strstr(const char *haystack, const char *needle);
char			*ft_strnstr(const char *haystack, const char *needle,
size_t len);
int				ft_strcmp(const char *s1, const char *s2);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
char			*ft_strcat(char *s1, const char *s2);
char			*ft_strncat(char *s1, const char *s2, size_t n);
size_t			ft_strlcat(char *dst, const char *src, size_t size);
char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);
/*
**---------------------->NUMBER AND ASCII<-----------------------------**
*/
int				ft_digitlen(int x);
int				ft_wordcountfix(const char *str, char c);
int				ft_wordcount(const char *str);
int				ft_isspace(char c);
int				ft_power(int x, int base);
int				ft_abs(int x);
int				ft_atoi(const char *str);
int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);
int				ft_toupper(int c);
int				ft_tolower(int c);
/*
**------------------------->MEMORY MANIPULATIONS<------------------------**
*/
void			*ft_memset(void *b, int c, size_t len);
void			ft_bzero(void *s, size_t n);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memccpy(void *dst, const void *src, int c, size_t n);
void			*ft_memmove(void *dst, const void *src, size_t len);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
void			*ft_memalloc(size_t size);
void			ft_memdel(void **ap);
/*
**-------------------------->MEMORY IN STRINGS<---------------------------**
*/
char			*ft_strnew(size_t size);
void			ft_strdel(char **as);
void			ft_strclr(char *s);
void			ft_striter(char *s, void (*f)(char *));
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
char			*ft_strmap(char const *s, char (*f)(char));
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int				ft_strequ(char const *s1, char const *s2);
int				ft_strnequ(char const *s1, char const *s2, size_t n);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s);
char			**ft_strsplit(char const *s, char c);
char			*ft_itoa(int n);
/*
**----------------------------->FAVORITE FUNCS<---------------------------**
*/
int				get_next_line(const int fd, char **line);
char			*str_append(char *s1, char *s2, int f1, int f2);
char			*str_appendneg(char *s1, char *s2);
int				ft_printf(const char *format, ...);
/*
**----------------------------->PRINTF<-----------------------------------**
*/
void			initialize_vars(t_printf *p);
uintmax_t		get_unumber(va_list arg, int len, int large);
intmax_t		get_number(va_list arg, int len, int large);
char			*ft_itoa_base(intmax_t n);
char			*ft_itoa_ubase(uintmax_t value, int base, int key);
void			parse_lag(t_printf *p);
void			print_str(char *str, t_printf *p);
void			print_char(char c, t_printf *p);
void			store_buffer2(t_printf *p, char *spec);
void			store_buffer(t_printf *p, char *spec);
int				parse_length(char *str, int max);
char			*ft_alloc(char *buf, char *str);
char			*ctos(char c);
void			parse_width(char *str, t_printf *p, int max);
void			parse_all(char *str, t_printf *p, int max);
char			*og_str(char c, int len);
char			*str_cut(char *s1, int len);
void			precision_completion(char *str, t_printf *p, int m);
void			flags_completion(char *str, t_printf *p, int m);
void			plus_completion(char *str, t_printf *p, int m);
/*
**-------------------------------->HASH<----------------------------------**
*/
void			ft_sha256(unsigned char *str);
void			ft_md5(unsigned char *str);
int				find_length(unsigned char *str);
int				swap_end(int n);
/*
**--------------------------------->QUEUE<---------------------------------**
*/
typedef struct	s_node
{
	void			*content;
	struct s_node	*next;
}				t_node;

typedef struct	s_queue
{
	t_node	*first;
	t_node	*last;
}				t_queue;

t_queue			*queue_init(void);
void			*dequeue(t_queue *queue);
void			enqueue(t_queue *queue, void *message);
void			*peek(t_queue *queue);
bool			is_empty(t_queue *queue);

#endif
