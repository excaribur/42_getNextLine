/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jphonyia <phonyiam.jirayut@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 17:51:13 by jphonyia          #+#    #+#             */
/*   Updated: 2023/05/01 18:26:38 by jphonyia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;
	unsigned char	*cpy_ptr;
	size_t	n;

	if (size == SIZE_MAX || count == SIZE_MAX)
		return (NULL);
	n = count * size;
	ptr = (void *)malloc(count * size);
	if (!ptr)
		return (NULL);
	cpy_ptr = (unsigned char *)ptr;
	while (n-- > 0)
	{
		*(cpy_ptr++) = '\0';
	}
	return (ptr);
}

size_t	ft_strlen(const char *s, char c)
{
	size_t	i;

	i = 0;
	if (!s)
		return (i);
	while (s[i] != c)
		i++;
	return (i);
}

int	is_newline(char *str)
{
	char	newline;
	size_t	i;

	newline = '\n';
	i = 0;
	while (str[i])
	{
		if (str[i] == newline)
			return (1);
		i++;
	}
	return (0);
}

char	*get_one_line(char **str, char *line)
{
	size_t	len_line;
	size_t	start;
	size_t	j;
	char	*new_buff;

	start = 0;
	if (!(*str))
		return (NULL);
	len_line = ft_strlen(*str, '\n');
	line = ft_calloc(len_line + 2, sizeof(char));
	new_buff = ft_calloc(ft_strlen(*str, 0) + len_line + 1, sizeof(char));
	if (!line || !new_buff)
		return (NULL);
	line = make_line(str, line, &start);
	j = 0;
	while (str[0][start])
		new_buff[j++] = str[0][start++];
	if_free(*str);
	*str = new_buff;
	return (line);
}

char	*make_line(char **str, char *line, size_t *start)
{
	size_t	i;

	i = 0;
	while (str[0][i] != '\n')
	{
		line[i] = str[0][i];
		i++;
	}
	line[i++] = '\n';
	*start = i;
	return (line);
}



