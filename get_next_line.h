/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jphonyia <phonyiam.jirayut@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 16:17:59 by jphonyia          #+#    #+#             */
/*   Updated: 2023/05/10 21:53:39 by jphonyia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# define BYTE 1

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

char	*get_next_line(int fd);
char	*read_file_line(int fd, char *str);
char	*get_one_line(char *str);
char	*delete_one_line(char *str);
char	*append_to_str(char *str, char *buff);
int		ft_strlen(const char *s, char c);
int		is_newline(char *str);
void	*ft_calloc(size_t count, size_t size);

#endif
