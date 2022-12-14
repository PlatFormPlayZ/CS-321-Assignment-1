#include <sys/types.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

#define MODE 0666
#define BUF_SIZE 8192

void main(int argc, char *argv[])
{
	int src, dst, in, out;
	char buf[BUF_SIZE];
	if(argc != 3)
	{
		printf("Incorrect Number of Parameters: Expecting source and destination. \n");
		exit(1); 
	}	
	src = open(argv[1], O_RDONLY);
	if(src < 0) 
	{ 
		printf("Error: Could Not Access Source File (be sure it exists). \n");
		exit(2);
	}
	dst = creat(argv[2], MODE);
	if(dst < 0)
	{
		printf("Error: Could Not Access Destination File. \n");
		exit(3);
	}
	
	while(1)
	{
		in = read(src, buf, BUF_SIZE);
		if(in <= 0)
		{
			break;
		}
		out = write(dst, buf, in);
		if(out <= 0)
		{
			break;
		}
	}
	close(src);
	close(dst);
	printf("File successfully copied! \n");
	exit(0);
}
