/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jphonyia <phonyiam.jirayut@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 16:40:22 by jphonyia          #+#    #+#             */
/*   Updated: 2023/05/01 17:16:01 by jphonyia         ###   ########.fr       */
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
	int fd = open("tester.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("Error Number");
	}

	int s = 1;
	while (s)
	{
		char *str = get_next_line(fd);
		s = printf("%s",str);
		if (str)
			free(str);
	}


	// char *str = "HELLO";
	// printf("%s\n", str);
	// ft(&str);
	// printf("%s\n", str);


	return (0);
}
