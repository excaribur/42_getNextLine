#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <errno.h>
#include <stdio.h>
#include <fcntl.h>





int main(int argc, char *argv[])
{
	int fd = open("foo.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("Error Number");
	}

	static int arr_fd[10];

	arr_fd[0] = fd;
	printf("fd = %d\n", arr_fd[0]);

	char buff[1];
	int iread = 1;

	iread = read(arr_fd[0], buff, 2);
	printf("\n%s: %i\n", buff, iread);
	iread = read(arr_fd[0], buff, 2);
	printf("\n%s: %i\n", buff, iread);
	// while (iread)
	// {
	// 	 iread = read(arr_fd[0], buff, 6);
	// 	 write (1, buff, 6);
	// 	 printf("\nread: %i\n", iread);
	// }



	return 0;
}
