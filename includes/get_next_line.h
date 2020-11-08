/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roalvare <roalvare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 16:47:32 by roalvare          #+#    #+#             */
/*   Updated: 2020/11/08 18:39:34 by roalvare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct	s_list
{
	char			content;
	struct s_list	*next;
}				t_list;

typedef struct	s_file
{
	int				fd;
	char			buf[BUFFER_SIZE + 1];
	char			*crs;
	struct s_file	*next;
}				t_file;

int				get_next_line(int fd, char **line);
t_list			*line_to_list(t_file *f, int *brk, int *count);
void			*list_to_str(t_list *list, char **line, int len);
int				ft_lstnew_back(t_list **alst, char c);
void			*free_list(t_list *list);
t_file			*get_file(int fd, t_file **file);
int				del_file(int fd, t_file **file);

#endif
