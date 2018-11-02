#include<stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include<string.h>
#include <fcntl.h>
char *arry="41ABCDEFAB00047008020101";
int is_hex_char( char w)
{
	if((w>='0'&&w<='9')||(w>='a'&&w<='f')||(w>='A'&&w<='F'))
	{
		return 1;
	}
	else
		return 0;
}
 int is_digit( char w)
 {
	if(w>='0' && w <= '9')
	{
		return 1;
	}
	else
		return 0;
 }
  unsigned char is_upper( char w)
 {
 	if(w>='A' && w <= 'Z')
	{
		return 1;
	}
	else
		return 0;
 }
   unsigned char is_lower( char w)
 {
 	if(w>='a' && w <= 'z')
	{
		return 1;
	}
	else
		return 0;
 }
 void deal( char *w)
 {
	if(is_digit(*w))
	{
		*w = *w - '0';
	}
	else
	{
		*w = *w - 87;
	}
		if(is_digit(*w))
	{
		*w= *w - '0';
	}
	else if(is_upper(*w))
	{
		*w= *w - 'A' + 10;
	}
	else if(is_lower(*w))
	{
		*w = *w - 'a' + 10;
	}
 }
  void acc_string(char * str)
 {
	int num;
	static unsigned int temp=0,sum=0;
	static unsigned char hi,lo;
	num = strlen(str);
	while(*str != '\0'&&*str != '\n')//判断字符的结尾
	{
		hi = *str++;
		lo = *str++;
		deal(&hi);
		deal(&lo);
		temp = (hi<<4)+(lo&0x0f);
		sum += temp;
		//printf("temp=%d,sum=%x",temp,sum);
	}
	printf("sum=%x\n",sum);
 }
 void acc_file(char *filename)
 {
	int fd,j;
	long crc=0;
	char *buf;
	unsigned char temp,hi,lo;
	int num,i=0;
	struct stat sb;
	if (stat(filename, &sb) == -1) {
	   perror("stat");
	   exit(EXIT_FAILURE);
	}

	printf("File type:                ");

	switch (sb.st_mode & S_IFMT) {
	case S_IFBLK:  printf("block device\n");            break;
	case S_IFCHR:  printf("character device\n");        break;
	case S_IFDIR:  printf("directory\n");               break;
	case S_IFIFO:  printf("FIFO/pipe\n");               break;
	case S_IFLNK:  printf("symlink\n");                 break;
	case S_IFREG:  printf("regular file\n");            break;
	case S_IFSOCK: printf("socket\n");                  break;
	default:       printf("unknown?\n");                break;
	}
	fd = open(filename,O_RDONLY);
	buf = (char *)malloc(sb.st_size);
	read(fd,buf,sb.st_size);
	acc_string(buf);
/* 	while(num = read(fd,buf,512))
	{
		//acc
		for(j=0;j<num;)
		{
			if(is_hex_char(buf[j++]))
			{
				continue;
			}
			deal(&hi);
			deal(&lo);
			temp = (hi<<4)+(lo&0x0f);
			crc+=temp;
		}	
		lseek(fd, num, i);
		i +=num;
	} */
	free(buf);
	close(fd);
 }

int main(int argc ,char**argv)
{
	int opt;
    char*arry;

	printf("argv=%s\n",*(argv+1));
	while((opt = getopt(argc,argv,"i:f:h::")) != -1)
	{
		switch(opt)
		{
			case 'i': 
				//printf("argv=%s\n",optarg);
				acc_string(optarg);
				break;
			case 'f': 
				//printf("argv=%s\n",optarg);
				acc_file(optarg);
				break;
			case 'h': 
				printf("argv=%s\n",optarg);
			default:
				printf("usage:liu_acc [-i <string>] [-f filename]\n");
				break;
		}
		
	}
	exit(0);
}

