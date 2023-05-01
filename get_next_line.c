/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jphonyia <phonyiam.jirayut@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 15:44:14 by jphonyia          #+#    #+#             */
/*   Updated: 2023/05/01 18:32:23 by jphonyia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "get_next_line.h"

/**
 * Step:	1) Loop read
 *			2) Read one byte
 *			3) Append to static str
 *			4) Found \n return str
 *
*/
char	*get_next_line(int fd)
{
	static char	*str;
	char		*line;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	line = read_file_line(fd, &str, line);
	return (line);
}


/**
 * To do: Read file per Kilobyte(2^10 = 1024 bytes) is defualt value
 * Error:
*/
char	*read_file_line(int fd, char **str, char *line)
{
	int		byte;
	char	*buff;

	byte = BYTE;
	buff = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buff)
		return (NULL);
	while (byte > 0)
	{
		byte = read(fd, buff, BUFFER_SIZE);
		if (byte <= 0)
			break ;
		buff[byte] = 0;
		*str = append_to_str(str, buff);
		if (!str)
			break ;
		if (is_newline(buff))
			break ;
	}
	if_free(buff);
	return (get_one_line(str, line));
}

char	*append_to_str(char **str, char *buff)
{
	size_t	len_total;
	char	*temp;
	size_t	i;
	size_t	j;

	if (!buff[0])
		return (NULL);
	len_total = ft_strlen(*str, 0) + ft_strlen(buff, 0);
	temp = ft_calloc(len_total + 1, sizeof(char));
	if (!temp)
	{
		if_free(buff);
		return (NULL);
	}
	i = 0;
	while (*str && str[0][i])
	{
		temp[i] = str[0][i];
		i++;
	}
	j = 0;
	while (buff[j])
		temp[i++] = buff[j++];
	if_free(*str);
	return (temp);
}

void	if_free(void *ptr)
{
	if (ptr)
		free(ptr);
}
