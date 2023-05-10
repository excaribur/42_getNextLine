/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jphonyia <phonyiam.jirayut@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 17:51:13 by jphonyia          #+#    #+#             */
/*   Updated: 2023/05/10 21:52:14 by jphonyia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/**
 *  @overview: allocate memmory and set each block to '\0'
 *
 *	@params: count is the number of block.
 *	@params: size is the size of each block.
 *
 * 	@return: pointer with allocated memory (count * size)
 *
*/

void	*ft_calloc(size_t count, size_t size)
{
	void			*ptr;
	unsigned char	*cpy_ptr;
	size_t			n;

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
 *  @overview: This function finds the length of a string
 * 			by counting until it finds the specific character or null-terminate.
 *
 *	@params: s is string.
 *	@params: c is the specific character.
 *
 * 	@return: length
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
 *  @overview: The function checks whether the string includes a newline or not.
 *
 *	@params: str is string
 *
 * 	@return: 1 when it found a newline.
 * 			0 when not found.
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
 *  @overview: The function appends content that is read from
 * 			a file (fd) to a string.
 *
 *	@params: str is string
 *	@params: buff is buffer string that is read from a file (fd)
 *
 * 	@return: New string that has already been appended.
 * 			NULL, when buffer is NULL.
 * 			NULL, when it cannot allocate memory.
 *
*/
char	*append_to_str(char *str, char *buff)
{
	int		len_total;
	int		i;
	int		j;
	char	*str_new;

	if (!buff)
		return (NULL);
	len_total = ft_strlen(str, 0) + ft_strlen(buff, 0);
	str_new = ft_calloc(len_total + 1, sizeof(char));
	if (!str_new)
		return (NULL);
	i = 0;
	while (str && str[i])
	{
		str_new[i] = str[i];
		i++;
	}
	j = 0;
	while (buff && buff[j])
		str_new[i++] = buff[j++];
	free(str);
	return (str_new);
}
