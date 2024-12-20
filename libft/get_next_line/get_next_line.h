/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fidrandr <fidrandr@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 12:53:18 by fidrandr          #+#    #+#             */
/*   Updated: 2024/10/17 22:07:40 by fidrandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

int		gnl_strlen(char *str, char c);
char	*gnl_strdup(char *s);
char	*gnl_strjoin(char *s1, char *s2);

int		check_line(char *line);
char	*read_file(int fd, char *stock);
char	*extract_line(char *stock_fd);
char	*next_line_free(char *stock_fd);
char	*get_next_line(int fd);
int		get_len(char *stock_fd);

#endif
