/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jphonyia <phonyiam.jirayut@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 15:44:14 by jphonyia          #+#    #+#             */
/*   Updated: 2023/05/09 22:11:27 by jphonyia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/**
 *  @overview: This function reads the contents of a file descriptor
 * 				and returns a single string corresponding to one line
 * 				of the file per function call.
 *
 *	@params: fd is file descriptor that identifies an open file in
 *				a running process. It serves as a "handle"
 *				or reference to a file.
 *				0 = reserved for standard input (stdin)
 *				1 = reserved for standard output (stdout)
 *				2 = reserved for standard error (stderr)
 *
 * 	@return:  The string returned includes a newline character
 * 				(Except: No newline provides)
 *
*/
char	*get_next_line(int fd)
{
	static char	*str;
	char		*line;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	str = read_file_line(fd, str);
	if (!str)
		return (NULL);
	line = get_one_line(str);
	str = delete_one_line(str);
	return (line);
}


/**
 *  @todo: read content to buffer and adding it to static String
 *
 *	@params:
 *
 *
 * 	@return:
 *
*/
char	*read_file_line(int fd, char *str)
{
	int		byte;
	char	*buff;

	if (!str)
		str = ft_calloc(1, 1);
	byte = BYTE;
	buff = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buff)
		return (NULL);
	while (byte > 0)
	{
		byte = read(fd, buff, BUFFER_SIZE);
		if (byte < 0)
		{
			free(buff);
			return (NULL);
		}
		buff[byte] = 0;
		str = append_to_str(str, buff);
		if (!str || is_newline(buff))
			break ;
	}
	free(buff);
	return (str);
}

/**
 *  @overview: pull content in a one line from static String
 *
 *	@params:
 *
 * 	@return:
 *
*/

char	*get_one_line(char *str)
{
	char	*line;
	int		len_line;
	int		i;

	i = 0;
	if (!str[i])
		return (NULL);
	len_line = ft_strlen(str, '\n');
	line = ft_calloc(len_line + 2, sizeof(char));
	if (!line)
		return (NULL);
	while (str[i] && str[i] != '\n')
	{
		line[i] = str[i];
		i++;
	}
	if (str[i] && str[i] == '\n' )
		line[i] = '\n';
	return (line);
}

/**
 *  @overview:
 *
 *	@params:
 *
 *
 *
 * 	@return:
 *
*/

char	*delete_one_line(char *str)
{
	int		i;
	int		len_oneline;
	char	*new_str;

	i = 0;
	len_oneline = ft_strlen(str, '\n');
	if (!str[len_oneline])
	{
		free(str);
		return (NULL);
	}
	new_str = ft_calloc(ft_strlen(str, 0) - len_oneline + 1, sizeof(char));
	if (!new_str)
		return (NULL);
	len_oneline++;
	while (str[len_oneline + i])
	{
		new_str[i] = str[len_oneline + i];
		i++;
	}
	free(str);
	return (new_str);
}
