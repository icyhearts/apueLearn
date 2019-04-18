#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<errno.h>
#include<fcntl.h>
#include<aio.h>
#include<stdlib.h>
#include<strings.h>

#define BUFSIZE   256

int main(int argc, char **argv)
{
    struct aiocb    cbp;
    int             fd,ret;
    int             i = 0;
	if(argc !=2 ){
		printf("./bin/c14n6_aioread.elf inputfile\n");
	}

    fd = open(argv[1],O_RDONLY);

    if(fd < 0)
    {
        perror("open error\n");
    }

    //填充struct aiocb 结构体 
    bzero(&cbp,sizeof(cbp));
    //指定缓冲区
    cbp.aio_buf = (volatile void*)malloc(BUFSIZE+1);
    //请求读取的字节数
    cbp.aio_nbytes = BUFSIZE;
    //文件偏移
    cbp.aio_offset = 0;
    //读取的文件描述符
    cbp.aio_fildes = fd;
    //发起读请求
    ret = aio_read(&cbp);//看到发起一个异步请求时，Linux实际上是创建了一个线程去处理，当请求完成后结束线程。
    if(ret < 0)
    {
        perror("aio_read error\n");
        exit(1);
    }

    //查看异步读取的状态，直到读取请求完成//
	//如果注释掉异步读的状态检查： 发现什么都没输出，这是因为程序结束的时候，异步读请求还没完成，所以buf缓冲区还没有读进去数据。
    for(i = 1;aio_error(&cbp) == EINPROGRESS;i++)
    {
        printf("No.%3d\n",i);
    }
    //读取返回值
    ret = aio_return(&cbp);
    printf("return %d\n",ret);

//    sleep(1);   //如果将上面代码中的 sleep 的注释去掉，让异步请求发起后，程序等待1秒后再输出，就会发现成功读取到了数据
    printf("%s\n",(char*)cbp.aio_buf);
    close(fd);
    return 0;
}

