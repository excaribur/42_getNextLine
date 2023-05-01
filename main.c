/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jphonyia <phonyiam.jirayut@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 16:40:22 by jphonyia          #+#    #+#             */
/*   Updated: 2023/05/01 18:18:19 by jphonyia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <stdio.h>
#include "get_next_line.h"

int ft(char **ptr)
{
	char *s = "BKK42";
	*ptr = s;
	return (0);
}


int	main()
{
	int fd = open("a.x", O_RDONLY);
	if (fd == -1)
	{
		printf("Error Number\n");
	}

	int s = 1;
	char *str = get_next_line(fd);
	printf("%s--\n", str);
	while (s && str)
	{
		//printf("%i--:while (s)\n", fd);
		s = printf("%s",str);
		str = get_next_line(fd);
		if (str)
			free(str);
	}


	// char *str = "HELLO";
	// printf("%s\n", str);
	// ft(&str);
	// printf("%s\n", str);


	return (0);
}
