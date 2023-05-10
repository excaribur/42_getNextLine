/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jphonyia <phonyiam.jirayut@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 16:40:22 by jphonyia          #+#    #+#             */
/*   Updated: 2023/05/10 21:15:05 by jphonyia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <stdio.h>
// #include "get_next_line.h"

// int ft(char **ptr)
// {
// 	char *s = "BKK42";
// 	*ptr = s;
// 	return (0);
// }


int	main()
{
	//printf("=====hello========\n");
	int fd = open("tester.txt", O_RDONLY);
	// //int fd = open("41_no_nl", O_RDONLY);
	// if (fd == -1)
	// {
	// 	printf("Cannot open file\n");
	// }
	printf("=====fd========%d\n",fd);
	char buff[11111111];
	int byte = read(fd, buff, 1);
	printf("=====hello========\n");
	printf("=====byte========%d\n",byte);

	// char *str = get_next_line(fd);
	// printf("%s",str);
	// printf("%s",get_next_line(fd));
	//printf("%s",get_next_line(fd));

	// printf("%s--\n", str);
	// while (1)
	// {
	// 	//printf("%i--:while (s)\n", fd);
	// 	char *str = get_next_line(fd);
	// 	if (!str)
	// 		break ;
	// 	printf("%s",str);
	// }


	//char *str = "HELLO";
	//printf("%s\n", str);
	// ft(&str);
	// printf("%s\n", str);


	return (0);
}
