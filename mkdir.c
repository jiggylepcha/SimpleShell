#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(int argc, char *argv[])
{
	int flag1 = 0;
	int flag2 = 0;
	int ch;
	while((ch = getopt(argc, argv, "vm")) != -1) {
		switch(ch) {
			case 'v':
				flag1 = 1;
				break;
			case 'm':
				flag2 = 1;
				break;
		}		
	}
	argc -= optind;
	argv += optind;
	if (argc) {
		if (flag1 == 0 && flag2 == 0){
			if(mkdir(argv[0], 0777)) {
				printf("Could not crete directory\n");
			}
		}
		else if (flag1 == 1 && flag2 == 0){
			if(mkdir(argv[0], 0777)) {
				printf("Could not crete directory\n");
			}
			else {
				printf("Created directory: %s\n", argv[0]);
			}
		}
		else if (flag1 == 0 && flag2 == 1){
			//printf("%s\n", "mcbc");
			//printf("%s %s %s\n", argv[0], argv[1], argv[2]);
			char *eptr;
			long value = strtoul(argv[0], &eptr, 8);
			umask(0);
			mkdir(argv[1], value);
			umask(0022);
		}
		else {
			// Both flags are passed
			char *eptr;
			long value = strtoul(argv[0], &eptr, 8);
			umask(0);
			mkdir(argv[1], value);
			umask(0022);
			printf("%s %s\n", "Directory Created:", argv[1]);
		}
	}
	else {
		printf("No file is mentioned\n");
	}
	return 0;
}