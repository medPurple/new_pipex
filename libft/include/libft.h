/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmessmer <wmessmer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 17:22:58 by wmessmer          #+#    #+#             */
/*   Updated: 2023/01/24 17:00:59 by wmessmer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

/*declaration*/
# include <unistd.h>
# include <stdio.h>
# include <stddef.h>
# include <stdlib.h>
# include <string.h>
# include <stdint.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdarg.h>
# include <stddef.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

/*libft - base*/

int			ft_isalpha(int c);
int			ft_isdigit(int a);
int			ft_isalnum(int c);
int			ft_isprint(int c);
int			ft_isascii(int c);
size_t		ft_strlen(const char *s);
int			ft_toupper(int c);
int			ft_tolower(int c);
/* libft - fonctions */

char		*ft_strchr(char *s, int c);
char		*ft_strrchr(const char *str, int dest);
char		*ft_strnstr(const char *s1, const char *s2, size_t n);
int			ft_atoi(const char *str);
size_t		ft_strlcpy(char *dest, char *src, size_t size);
size_t		ft_strlcat(char *dest, char *src, size_t size);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
char		*ft_itoa(int n);
int			ft_putchar_fd(int c);
int			ft_putendl_fd(char *s);
int			ft_putnbr_fd(int n);
int			ft_putstr_fd(char *s);

/* libft - memory*/
void		*ft_memset(void *s, int c, size_t n);
void		ft_bzero(void *s, size_t n);
void		*ft_memcpy( void *dest, const void *src, size_t size );
void		*ft_memmove(void *dst, const void *src, size_t len);
void		*ft_memchr(const void *mb, int sc, size_t size);
int			ft_memcmp(const void *p1, const void *p2, size_t size );
void		*ft_calloc( size_t count, size_t size);
char		*ft_strdup(const char *src);
char		*ft_substr(char const *s, unsigned int start, size_t n);
char		*ft_strjoin(char *s1, char *s2);
char		*ft_strtrim(char const *s, char const *set);
char		**ft_split(char const *s, char c);
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void		ft_striteri(char *s, void (*f)(unsigned int, char*));
/*libft - liste chainee*/

t_list		*ft_lstnew(void *content);
void		ft_lstadd_front(t_list **lst, t_list *list);
int			ft_lstsize(t_list *lst);
void		ft_lstadd_back(t_list **lst, t_list *list);
void		ft_lstdelone(t_list *lst, void (*del)(void*));
void		ft_lstclear(t_list **lst, void (*del)(void*));
void		ft_lstiter(t_list *lst, void (*f)(void *));
t_list		*ft_lstmap(t_list *lst, void *(*f)(void*), void (*del)(void *));
t_list		*ft_lstlast(t_list *lst);

/*gnl*/

char		*get_next_line(int fd);
char		*ft_line_read(int fd, char *backup);
char		*ft_get_line(char *backup);
char		*ft_backup(char *backup);

/*printf*/

int			ft_printf(const char *s, ...);
int			ft_put_di(unsigned int i);
int			void_to_hexa(unsigned long long p);
int			put_x(void);
int			nb_to_hexa(unsigned int a, const char type);
int			exe_flags(const char a, va_list s);
int			hexa_len(unsigned int num);
int			ft_print_hex(unsigned int a, const char type);
void		ft_print_hexavoid(uintptr_t a);
int			hexavoid_len(uintptr_t a);
size_t		nblen(int n);
char		*ft_itoa(int n);
char		*ft_unsigned_itoa(unsigned int i);
int			ft_put_u(unsigned int i);
int			ft_len_u(unsigned int u);

/*ajout perso*/
void		send_error(char *s);
int			ft_strcmp(char *s1, char *s2);

#endif
