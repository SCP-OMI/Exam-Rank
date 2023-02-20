#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>

char *get_next_line(int fd)
{
	if(BUFFER_SIZE < 1 || fd < 0)
		return 0;

	char *str  = malloc (100000);
	char *temp = str;

	if (BUFFER_SIZE == 1)
	{
		while(read(fd, temp, BUFFER_SIZE) > 0 && *temp++ != '\n');
		if(temp > str)
		{
			*temp = 0;
			return str;
		}
		else
			{
				free(str);
				return NULL;
			}
	}
	else
	{
		while(read(fd, temp, 1) > 0 && *temp++ != '\n');
		if(temp > str)
		{
			*temp = 0;
			return str;
		}
		else
			{
				free(str);
				return NULL;
			}
	}
    return(str);
}
