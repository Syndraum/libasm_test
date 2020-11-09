#ifndef HEADER_H
# define HEADER_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <fcntl.h>
# include <errno.h>
# include "get_next_line.h"

# define TESTING "\e[94mTesting\e[39m"


typedef struct	s_cmp
{
	int			diff;
	int			line;
	char		*line1;
	char		*line2;
}				t_cmp;


size_t	ft_strlen(const char *s);
char	*ft_strcpy(char * dst, const char * src);
int		ft_strcmp(const char *s1, const char *s2);
ssize_t	ft_write(int fildes, const void *buf, size_t nbyte);
ssize_t ft_read(int fildes, void *buf, size_t nbyte);
char	*ft_strdup(const char *s1);

void	print_title(int log, char *title);
void	print_result(int n_error);

int		t_strlen(int log);
int		t_strcpy(int log);
int		t_strcmp(int log);
int		t_write(int log);
int		t_read(int log);
int		t_strdup(int log);

#endif