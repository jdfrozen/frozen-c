#include <stdio.h>
#include <unistd.h>

int main()
{
	printf("process begin...\n");
	execl("/bin/ls", "ls", NULL);
	printf("process end...\n");
	return 0;
}
