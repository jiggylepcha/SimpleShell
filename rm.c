#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	int flag1 = 0;
	int flag2 = 0;
	int ch;
	while((ch = getopt(argc, argv, "vi")) != -1) {
		switch(ch) {
			case 'v':
				flag1 = 1;
				break;
			case 'i':
				flag2 = 1;
				break;
		}		
	}
	argc -= optind;
	argv += optind;
	if (argc) {
		if (flag1 == 0 && flag2 == 0){
			if(remove(argv[0])) {
				printf("%s\n", "Cannot be removed");
			}
		}
		else if (flag1 == 1 && flag2 == 0) {
			if(remove(argv[0])) {
				printf("%s\n", "Cannot be removed");
			}
			else {
				printf("%s\n", "Removed Directory");
			}
		}
		else if (flag1 == 0 && flag2 == 1) {
			printf("Are you sure you want delete? (y/n): ");
			char c;
			scanf("%c", &c);
			if(c == 'y') {
				if(remove(argv[0])) {
					printf("%s\n", "Cannot be removed");
				}	
			}
		}
		else {
			printf("Are you sure you want delete? (y/n): ");
			char c;
			scanf("%c", &c);
			if(c == 'y') {
				if(remove(argv[0])) {
					printf("%s\n", "Cannot be removed");
				}
				else {
					printf("%s\n", "Removed Directory");
				}
			}

		}
	}
	return 0;
}