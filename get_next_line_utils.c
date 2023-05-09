/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jphonyia <phonyiam.jirayut@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 17:51:13 by jphonyia          #+#    #+#             */
/*   Updated: 2023/05/09 22:12:06 by jphonyia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/**
 *  @overview: allocate memmory and set each block to '\0'
 *
 *	@params:
 *
 *
 *
 * 	@return:
 *
*/

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

/**
 *  @overview: to find the length of string by counting until specific
 * 				character or nul-terminate
 *
 *	@params:
 *
 *
 *
 * 	@return:
 *
*/

int	ft_strlen(const char *s, char c)
{
	int	i;

	i = 0;
	if (!s)
		return (i);
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

/**
 *  @overview: To check the string includes '\n' newline or not
 *
 *	@params:
 *
 *
 *
 * 	@return:
 *
*/

int	is_newline(char *str)
{
	char	newline;
	int		i;

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

/**
 *  @overview: to append string from buffer that just read from a file
 *
 *	@params:
 *
 *
 *
 * 	@return:
 *
*/

char	*append_to_str(char *str, char *buff)
{
	int		len_total;
	int		i;
	int		j;
	char	*temp;


	if (!buff)
		return (NULL);
	len_total = ft_strlen(str, 0) + ft_strlen(buff, 0);
	temp = ft_calloc(len_total + 1, sizeof(char));
	if (!temp)
		return (NULL);
	i = 0;
	while (str && str[i])
	{
		temp[i] = str[i];
		i++;
	}
	j = 0;
	while (buff && buff[j])
		temp[i++] = buff[j++];
	free(str);
	return (temp);
}
