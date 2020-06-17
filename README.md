# Adding lseek sys call to xv6
Name - Prajwal Adsul

MIS - 111703046

Added lseek system call to xv6

Files changed
![MakeFile](https://github.com/PrajwalAdsul/xv6-public/blob/master/Makefile)
![user.h](https://github.com/PrajwalAdsul/xv6-public/blob/master/user.h)
![syscall.h](https://github.com/PrajwalAdsul/xv6-public/blob/master/syscall.h)
![syscall.c](https://github.com/PrajwalAdsul/xv6-public/blob/master/syscall.c)
![sysfile.c](https://github.com/PrajwalAdsul/xv6-public/blob/master/sysfile.c)

Files added
![readlseek.c](https://github.com/PrajwalAdsul/xv6-public/blob/master/readlseek.c)
![copylseek.c](https://github.com/PrajwalAdsul/xv6-public/blob/master/copylseek.c)

Diff of xv6-public and modified repo

```c
lenovo@prajwal:~/OS/git$ diff xv6-public/ xv6-submission/
Only in xv6-submission/: copylseek.c
Common subdirectories: xv6-public/.git and xv6-submission/.git
diff xv6-public/Makefile xv6-submission/Makefile
183a184,185
> 	_readlseek\
> 	_copylseek\
252a255
> 	readlseek.c copylseek.c\
Only in xv6-submission/: readlseek.c
Only in xv6-submission/: README.md
diff xv6-public/syscall.c xv6-submission/syscall.c
105a106
> extern int sys_lseek(void);
128a130
> [SYS_lseek]	sys_lseek,
diff xv6-public/syscall.h xv6-submission/syscall.h
22a23
> #define	SYS_lseek  22
diff xv6-public/sysfile.c xv6-submission/sysfile.c
444a445,480
> 
> int
> sys_lseek(void) {
>   int offset;
>   struct file *fd;
> 
>   // validating arg
>   if(argfd(0, 0, &fd) < 0)
>     return -1;
>   if(argint(1, &offset) < 0)
>     return -1;
> 
>   // lock the inode pointer before using it
>   ilock(fd->ip);
>   // if offset is going beyond file size then return -1
>   // indicating a terminal condition
>   if(fd->off + offset >= fd->ip->size)
>   {
>     // unlock the inode pointer before returning
>     iunlock(fd->ip);
>     return -1;
>   }
>   // unlock the inode pointer before,
>   // as we don't need if further in the program 
>   iunlock(fd->ip);
> 
>   // can't going on negative scale
>   if(fd -> off + offset < 0)
>     return -1;
> 
>   // increment the offset 
>   fd->off = fd->off + offset;
> 
>   // return the new offset
>   return fd->off;
> }
diff xv6-public/user.h xv6-submission/user.h
0a1
> #include"types.h"
25a27
> int lseek(int, int);
diff xv6-public/usys.S xv6-submission/usys.S
31a32,33
> SYSCALL(lseek)
> 
lenovo@prajwal:~/OS/git$

```