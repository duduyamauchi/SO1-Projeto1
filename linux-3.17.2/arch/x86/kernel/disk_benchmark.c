
#include <linux/unistd.h>
#include <linux/linkage.h>
//#include <linux/stdio.h>
//#include <linux/stdlib.h>
#include <linux/syscalls.h>
#include <linux/types.h>
//#include <stat.h>
#include <linux/fcntl.h>
#include <asm/uaccess.h>

asmlinkage long sys_disk_benchmark(int size_in_mb) {
    size_in_mb = size_in_mb*1000000;
    sys_mkdir("/home/eduardo/test/", 777);
    //syscall(SYS_chmod,"/home/eduardo/test",777);
    sys_mkdir("/home/eduardo/test/target",777);
    int fd = sys_open("/home/eduardo/file.jooj", O_CREAT,777);
    int i;
    for (i = 0; i < size_in_mb; i++){
	 sys_write(fd,1,sizeof(int));	
}
   ;
    sys_close(fd);
    //chmod("/home/eduardo/test/file.txt",777);
    //chmod("/home/eduardo/test/target",777);
    
    time_t initial = sys_time(NULL);
    sys_rename("/home/eduardo/test/file.jooj","/home/eduardo/test/target/file.jooj");
    initial = sys_time(NULL) - initial;
    sys_unlink("/home/eduardo/test/target/file.jooj");
    sys_rmdir("/home/eduardo/test/target");
    sys_rmdir("/home/eduardo/test");

    return(i);
}
