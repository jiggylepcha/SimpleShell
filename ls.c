#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(int argc, char *argv[])
{
	int flag1 = 0;
	int flag2 = 0;
	int ch;
	DIR *dir;
	struct dirent *d;
	struct stat s;
	while ((ch = getopt (argc, argv, "ai")) != -1){
		switch (ch){
			case 'a':
				flag1 = 1;
				//printf("took a as input\n");
				break;
			case 'i':
				flag2 = 1;
				//printf("took i as input\n");
				break;
		}
	}
	argc -= optind;
	argv += optind;
	if (argc){
		//he gave directory
		dir = opendir(argv[0]);
		while((d = readdir(dir)) != NULL)
		{
			stat(d->d_name, &s);
			if (flag1 == 0){
				if (d->d_name[0] == '.'){
					continue;
				}
			}
			if (flag2 == 1){
				printf("%lld", s.st_size);
			}
			printf("%s\n", d->d_name);
		}
		closedir(dir);
	}
	else{
		//ls .
		dir = opendir(".");
 		while((d = readdir(dir)) != NULL)
 		{
 			stat(d->d_name, &s);
 			if (flag1 == 0){
				if (d->d_name[0] == '.'){
					continue;
				}
			}
			if (flag2 == 1){
				printf("%lld\t", s.st_ino);
			}
 			printf("%s\n", d->d_name);
 		}
 		closedir(dir);

	}
	return 0;
}