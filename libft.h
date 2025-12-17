#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>


int	ft_atoi(const char *ptr);
int	ft_isdigit(int c);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
char	**ft_split(char const *s, char c);
char	*ft_strdup( const char *source );
int	    ft_abs(int num);
size_t	ft_strlen(const char *str);
int ft_strncmp(const char *s1, const char *s2, size_t n);

#endif
