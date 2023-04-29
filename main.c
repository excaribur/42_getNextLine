#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <errno.h>
#include <stdio.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{
	int fd = open("foo.txt", O_CREAT);

	printf("fd = %d\n", fd);

	char buff[1];
	int iread = 1;
	while (iread)
	{
		 iread = read(fd, buff, 6);
		 write (1, buff, 6);
		 printf("read: %i\n", iread);
	}


	if (fd ==-1)
	{
		// print which type of error have in a code
		printf("Error Number");
	}
	return 0;
}
