#include "get_next_line.h"
int main (void)
{
	while ((line = get_next_line(fd)))
	{
    	printf("%s", line);
    	free(line);
	}
}
