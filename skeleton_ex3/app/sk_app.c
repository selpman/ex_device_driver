#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(void)
{
	int fd=0;
	
	fd = open("/dev/sk",O_RDWR);
	printf("fd = %d \n",fd);

	if(fd < 0)
	{
		perror("/dev/sk");
		exit(-1);
	}
	else 
		printf("sk file opened\n");

	getchar();
	close(fd);
	return 0;
}
