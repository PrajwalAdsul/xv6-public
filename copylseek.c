#include"user.h"
#include"stat.h"
#include"fcntl.h"
int main(int argc, char *argv[]) {
	int fd1, fd2, i, off, len = -1;
	if(argc < 2) {
		printf(1, "provide more arguments i.e ./test2 filename\n");
		exit();
	}

	fd1 = open(argv[1], O_RDONLY);
	while(lseek(fd1, 1) != -1)
		len++;
	close(fd1);
	
	off = len / 9;
	char s[len + 1];

	fd2 = open("copy", O_CREATE | O_WRONLY);
	fd1 = open(argv[1], O_RDONLY);
	for(i = 0; i < 9; i++) {
		read(fd1, s, off);
		write(fd2, s, off);
	}
	off = len % 9;
	read(fd1, s, off);
	write(fd2, s, off);
	close(fd1);
	close(fd2);
	exit();
}
