//CLIENT

#include<unistd.h>
#include<stdio.h>
#include<sys/time.h>
#include<string.h>
#include<fcntl.h>

int main(){
    int wrfd=open("/home/student/Desktop/sanjitha/pffo1",O_WRONLY);
    int rdfd=open("/home/student/Desktop/sanjitha/pffo2",O_RDONLY);
    char buf[100];
    printf("Enter the message to be read from client\n");
    scanf("%s",buf);
    char numread[100];
    write(wrfd,buf,sizeof(buf));
    read(rdfd,numread,100);
    printf("Full Duplex Client: Read from the pipe: \n");
    printf("The message read is %s\n",numread );
    return 0;
}

//First execute server process then execute client simultaneously in 2 terminals. Also, after each execution a fifo file will be created in the path given. Ideally delete the fifo files after each execution.Otherwise you might get an error saying fifo: file exists

/* simpler version

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main()
{
	int wrfd;
	char msg[100];
	wrfd=open("/home/ubuntu/Desktop/sanjitha/pffo1",O_WRONLY);
	printf("Enter the message to be written to the fifo file\n");
	scanf("%s", msg);
	write(wrfd,msg,100);
	return 0;
}

*/
