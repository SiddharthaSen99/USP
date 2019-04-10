// SERVER


#include<unistd.h>
#include<stdio.h>
#include<sys/time.h>
#include<string.h>
#include<fcntl.h>

int main(){
    char *np1="/home/student/Desktop/sanjitha/pffo1";
    int r;
    r=mkfifo(np1,0777);
    if(r<0){
        perror("fifo");
        return 0;
    }
    char *np2="/home/student/Desktop/sanjitha/pffo2";
    r=mkfifo(np2,0777);
    if(r<0){
        perror("fifo");
        return 0;
    }
    int rdfd, wrfd;
    rdfd=open(np1, O_RDONLY);
    wrfd=open(np2, O_WRONLY);
    char numread[100];
    int i;
    read(rdfd,numread,100);
    printf("The content read from buffer is %s\n",numread);
    printf("Full duplex server: Read from the pipe\n" );
    for(i=0;i<strlen(numread);i++){
        numread[i]=numread[i]-32;
    }
    write(wrfd, numread, 100);
    return 0;
}



/*simpler version

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main()
{
	int r;
	char *np1="/home/ubuntu/Desktop/sanjitha/pffo1";
	char mesg[100];
	r=mkfifo(np1,0777);
	int rdfd;
	rdfd=open(np1,O_RDONLY);
	read(rdfd,mesg,100);
	printf("The message read is %s\n",mesg);
	return 0;
}
*/
