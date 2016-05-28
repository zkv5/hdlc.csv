#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <dirent.h>
#include <unistd.h>

int main(int argv, char ** args)
{
	DIR * dir;
	FILE * fp;
	char str[128];
	struct dirent * ptr;
	int i = 0;

	fp = fopen("/tmp/hdlc.csv", "w");
	if (fp==NULL){
		printf("Fail to open file\n");
		return 1;
	}
	fputs("num,name,type,reclen,\n", fp);
	dir = opendir(args[1]);
	while((ptr = readdir(dir)) != NULL)
	{
		sprintf(str, "%u,%s,%2d,%6u,\n",
			++i,
			ptr->d_name,
			ptr->d_type,
			ptr->d_reclen);
		fputs(str, fp);
	}
	closedir(dir);
	fclose(fp);

	return 0;
}

