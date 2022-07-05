/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib42.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alambert <alambert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 18:45:00 by alambert          #+#    #+#             */
/*   Updated: 2022/07/05 21:12:37 by alambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB42_H
# define LIB42_H

# include<stdlib.h>
# include<unistd.h>
# include<limits.h>
# include <float.h>
# include <errno.h>

long long	ft_absll(long long i);
long		ft_absl(long i);
int			ft_absi(int i);
char		ft_absc(char i);
long double	ft_absld(long double i);
double		ft_absd(double i);
float		ft_absf(float i);
int			ft_atoi(const char *str);
void		ft_bzero(void *s, size_t n);
void		*ft_calloc(size_t n, size_t size);
char		*ft_free(char **str);
int			ft_isalnum(int c);
int			ft_isalpha(int c);
int			ft_isascii(int c);
int			ft_iscntrl(char c);
int			ft_isdigit(int c);
int			ft_islower(int c);
int			ft_isprint(int c);
int			ft_isspace(int c);
int			ft_isupper(int c);
char		*ft_itoa(int n);
void		ft_itoav(int i, char buf[12]);
char		*ft_malgets(int buf);
char		*ft_malmove(const char *dest, const char *src, int len1, int len2);
void		*ft_memchr(const void *s, int c, size_t n);
int			ft_memcmp(const void *s1, const void *s2, size_t n);
void		*ft_memcpy(void *dst, const void *scr, size_t n);
void		*ft_memmove(void *dst, const void *src, size_t len);
void		*ft_memset(void *ptr, int c, size_t len);
void		ft_putchar_fd(char c, int fd);
void		ft_putchar(char c);
void		ft_putendl_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);
void		ft_putnbr(int nb);
void		ft_putstr_fd(char *s, int fd);
void		ft_putstr(char *str);
double		ft_sad(double a, double b);
float		ft_saf(float a, float b);
long double	ft_sald(long double a, long double b);
double		ft_sdd(double a, double b);
float		ft_sdf(float a, float b);
long double	ft_sdld(long double a, long double b);
double		ft_smd(double a, double b);
float		ft_smf(float a, float b);
long double	ft_smld(long double a, long double b);
char		**ft_split(char const *s, char c);
char		*ft_strcat(char *dst, const char *src);
char		*ft_strchr(const char *str, int c);
char		*ft_strcpy(char *dst, const char *src);
char		*ft_strdup(const char *str);
void		ft_striteri(char *s, void (*f)(unsigned int, char*));
char		*ft_strjoin(char *s1, char *s2);
size_t		ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize);
char		*ft_strncat(char *s1, const char *s2, size_t n);
size_t		ft_strlen(const char *str);
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int			ft_strncmp(const char *s1, const char *s2, size_t n);
char		*ft_strncpy(char *dst, const char *src, size_t maxlen);
size_t		ft_strnlen(const char *s, size_t maxlen);
char		*ft_strnstr(const char *str, const char *to_find, size_t n);
char		*ft_strpbrk(const char *str, const char *set);
char		*ft_strrchr(const char *str, int c);
int			ft_strspncspn(const char *str, const char *set, int gear);
int			ft_strspnfb(const char *str, const char *set, int gear);
char		*ft_strtok_r(char *str, const char *sep, char **saveptr);
long		ft_strtol(const char *str, char **endptr, int base);
char		*ft_strtrim(char const *s1, char const *set);
char		*ft_substr(char const *s, unsigned int start, size_t len);
int			ft_tolower(int c);
int			ft_toupper(int c);
char		*get_next_line(int fd);

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}			t_list;

void		ft_lstadd_back(t_list **alst, t_list *new);
void		ft_lstadd_front(t_list **alst, t_list *new);
void		ft_lstclear(t_list **lst, void (*del)(void *));
void		ft_lstdelone(t_list *lst, void (*del)(void *));
void		ft_lstiter(t_list *lst, void (*f)(void *));
t_list		*ft_lstlast(t_list *lst);
t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
t_list		*ft_lstnew(void *content);
int			ft_lstsize(t_list *lst);

#endif
