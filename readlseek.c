#include"user.h"
#include"stat.h"
#include"fcntl.h"
int main(int argc, char *argv[]) {
	int fd, off, len;
	if(argc < 5) {
		printf(1, "provide more arguments i.e - ./test1 filename offset length string\n");
		exit();
	}
	fd = open(argv[1], O_RDONLY);
	off = atoi(argv[2]);
	len = atoi(argv[3]);
	lseek(fd, off);
	char s[len + 1];
	read(fd, s, len);
	if(!strcmp(s, argv[4])) {
		printf(1, "equal strings\n");
	}
	else {
		printf(1, "non-equal strings\n");
	}
	close(fd);
	exit();
}
