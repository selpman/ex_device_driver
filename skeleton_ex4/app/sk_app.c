#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

typedef struct {
        pid_t pid;
        unsigned int next_fd;
	unsigned long i_inod;
}my_read;


int main(void)
{
	int fd=0;
	int ret;
	my_read reads;	

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
	
	ret = read(fd,&reads,sizeof(reads));
	printf("pid value : %d, ret value : %d \n",reads.pid,ret);
	printf("next_fd : %d\n",reads.next_fd);
	printf("i_ino : %ld\n",reads.i_inod);
	getchar();
	
	close(fd);
	return 0;
}
