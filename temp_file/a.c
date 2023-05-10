
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

int	main()
{

	int fd = open("tester.txt", O_RDONLY);
	//int fd = open("41_no_nl", O_RDONLY);
	printf("=====fd========%d\n", fd);
	// if (fd == -1)
	// {
	// 	printf("Cannot open file\n");
	// }

	char buff[100];
	//int byte = read(fd, buff, 100);
	int byte = read(-1, buff, 0);
	printf("=====byte========%d\n",byte);
	// byte = read(fd, buff, 1);
	// printf("=====byte========%d\n",byte);
	// byte = read(fd, buff, 1);
	// printf("=====byte========%d\n",byte);
	return (0);
}
