/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-ihi <aait-ihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 15:19:49 by aait-ihi          #+#    #+#             */
/*   Updated: 2020/11/07 20:34:25 by aait-ihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <string.h>
# include <stdlib.h>
# include <stdbool.h>
# include <unistd.h>
# include "printf.h"
# include "get_next_line.h"
# include "bigint.h"
# include "hash_table.h"
# define MALLOC ft_promalloc

typedef struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
	struct s_list	*last;
}				t_list;

int				ft_isalpha(int c);
int				ft_isalnum(int c);
int				ft_isnalnum(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);
int				ft_isunprint(int c);
int				ft_iswhitespace(int c);
int				ft_toupper(int c);
int				ft_tolower(int c);

int				ft_between(long long v, long long v1, long long v2);
long long		ft_abs(long long v);
long double		ft_fabs(long double v);
int				ft_sign(long long v);
int				ft_fsign(long double v);
void			buble_sort(int *t, size_t size, bool asc);
bool			ft_find_int(int *t, int n, size_t size, size_t *index);
int				ft_declen(long long int s);
char			*ft_itoa(long long nb);
char			*ft_itoa_base(long long n, int base);
int				ft_isdigit(int c);
char			*ft_uitoa(unsigned long long n);
char			*ft_uitoa_base(unsigned long long n, int base);
int				ft_int_min(int *table, size_t size);
int				ft_max(int a, int b);
int				ft_min(int a, int b);
int				ft_int_max(int *table, size_t size);
long long		ft_pow(long long n, int p);
int				ft_sqrt(int s);
bool			ft_swap(int *a, int *b);
bool			ft_isnbr(const char *s);
bool			ft_isdouble(const char *s);
bool			is_sorted_desc(int *t, size_t size);
bool			is_sorted_asc(int *t, size_t size);
bool			int_rrot(int *t, size_t size);
bool			int_rot(int *t, size_t size);

void			*ft_promalloc(size_t size);
void			*ft_memset(void *b, int c, size_t len);
void			ft_bzero(void *s, size_t n);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memccpy(void *dst, const void *src, int c, size_t n);
void			*ft_memmove(void *dst, const void *src, size_t len);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
void			*ft_memalloc(size_t size);
void			ft_memdel(void **ap);
void			**ft_malloc2d(int rows, int size, void*(*alloc)(size_t));
char			*ft_realloc(void *str, size_t size, size_t new_size);

long long		ft_atoi(const char *s);
long long		ft_atoi_base(const char *s, const char *s_base, int base);
double			ft_atof(const char *str);
int				ft_isinstr(char c, const char *s);
void			ft_putchar(char c);
void			ft_putstr(char const *s);
void			ft_putendl(char const *s);
void			ft_putnbr(int n);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char const *s, int fd);
void			ft_putendl_fd(char const *s, int fd);
void			ft_putnbr_fd(int n, int fd);
size_t			ft_strlen(const char *s);
char			*ft_strdup(const char *s1);
char			*ft_strcpy(char *dst, const char *src);
char			*ft_strncpy(char *dst, const char *src, size_t n);
char			*ft_strcat(char *s1, const char *s2);
char			*ft_strncat(char *dest, const char *src, size_t nb);
size_t			ft_strlcat(char *dst, const char *src, size_t size);
char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);
char			*ft_strstr(const char *std, const char *tofind);
char			*ft_strnstr(const char *s1, const char *s2, size_t n);
int				ft_strcmp(const char *s1, const char *s2);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
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
char			**ft_strsplit(char const *s, char *cmp);
char			*ft_strtoupper(char *str);
char			*ft_skipchr(const char *s, char c);
char			*ft_skipnchr(const char *s, int i);
char			*ft_skip_chars(const char *str, const char *cmp, int (*f)(int));
char			*ft_rskip_chars(const char *str, const char *cmp,
														int (*f)(int), int i);
char			*ft_skip_unitl_char(const char *str, const char *compare,
																int (*f)(int));
char			*ft_rskip_unitl_char(const char *str, const char *compare,
														int (*f)(int), int i);
int				ft_strindexof(const char *s, char c);
char			*ft_strreplace(char *str, char find, char replace);
int				ft_str_occurence(char *str, char c);
void			ft_strreplaceall(char *str, char find, char replace);
int				ft_wordcount(const char *str, char *cmp);
char			*ft_strnjoin(char	**strings, int n);
char			*ft_translate(char *str, const char *from, const char *to);
_Bool			ft_str_in_arr(char *str, char **table);
void			ft_free_2d_tab(char **table);
int				ft_str_match(char *str, int (*fun)(int));

t_list			*ft_lstnew(void const *content, size_t content_size);
void			ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void			ft_lstdel(t_list **alst);
void			ft_lstdel_s(t_list **alst, void (*del)(void **));
t_list			*ft_lstenqueue(t_list **list, t_list *new);
void			ft_lstdequeue(t_list **list, void (*del)(void **));
void			ft_lstdelfn(void *obj, size_t size);
void			ft_lstadd(t_list **alst, t_list *new);
void			ft_lstpush(t_list **alst, t_list *new);
t_list			*ft_lstpop(t_list **lst);
void			ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
t_list			**ft_lstfind(t_list **lst, const char *needle, size_t size);
t_list			*ft_lstdup(t_list **lst);
int				ft_lstsize(t_list *begin, int all);
t_list			*ft_lstpushback(t_list **blst, void const *content,
														size_t content_size);

void			ft_printbit(size_t n, int size);
__uint64_t		ft_reverse_bits(__uint64_t n, int size);

int				get_next_line(const int fd, char **line);
void			ft_die(const char *message, int error_nb);

int				ft_printf(const char *restrict fmt, ...);
_Bool			ft_is_dir(const char *file_name);

char			ft_set_flags(const char *str, _Bool *flags,
								const char *acpt_flgs, void (*f)(char, _Bool*));
void			ft_unset_flags(int c, _Bool *flags);

_Bool			ft_flag_active(int c, _Bool *flags);

#endif
