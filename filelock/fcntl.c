#include<stdio.h>
#include<fcntl.h>

#define read_lock(fd,offset,whence,len) lock_register((fd),F_SETLK,F_RDLCK,(offset),(whence),(len))
#define readw_lock(fd,offset,whence,len) lock_register((fd),F_SETLKW,F_RDLCK,(offset),(whence),(len))
#define write_lock(fd,offset,whence,len) lock_register((fd),F_SETLK,F_WRLCK,(offset),(whence),(len))
#define writew_lock(fd,offset,whence,len) lock_register((fd),F_SETLKW,F_WRLCK,(offset),(whence),(len))
#define un_lock(fd, offset, whence, len) lock_register((fd), F_SETLK, F_UNLCK, (offset), (whence), (len))

int lock_register(int fd,int cmd,int type,off_t offset,int whence,off_t len);
int main(int argc, char * argv[])
{
    int fd ;
    int val;
    int val1;
    pid_t pid;
    fd= open("./tmp/truncate.c",O_RDWR);
    pid = fork();
    if(pid < 0)/*fork error,and exit.*/
    {
        printf("fork error./n");
        exit(1);
    }
    if(pid == 0)/*In the child, try read lock.*/
    {
       printf("In the child try to retain read lock ");
        val1 =  read_lock(fd,0,SEEK_SET,0);
        if(val ==0)
        {
            printf("success,pid is %d./n",getpid());
        }
        else
        {
            printf("failed,pid is %d./n",getpid());
        }
    }
    else
    {/*In the parent,sets write lock to prevent others to read/write*/
        printf("Parent sets write lock,pid is %d./n",getpid());
        val = write_lock(fd,0,SEEK_SET,0);
        sleep(1);
    }

    return 0;
}
/*register read/write lock*/
int lock_register(int fd,int cmd,int type,off_t offset,int whence,off_t len)
{
    int val = 0;
    struct flock lock;
    lock.l_type = type;
    lock.l_start = offset;
    lock.l_whence  = whence;
    lock.l_len = len;
    val = fcntl(fd,cmd,&lock);
}
