#include<stdio.h>

char *arry="41ABCDEFAB00047008020101";
 int is_digit(unsigned char w)
 {
	if(w>='0' && w <= '9')
	{
		return 1;
	}
	else
		return 0;
 }
  unsigned char is_upper(unsigned char w)
 {
 	if(w>='A' && w <= 'Z')
	{
		return 1;
	}
	else
		return 0;
 }
   unsigned char is_lower(unsigned char w)
 {
 	if(w>='a' && w <= 'z')
	{
		return 1;
	}
	else
		return 0;
 }
 void deal(unsigned char *w)
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
int main(int argc ,char**argv)
{

        char*arry;
	static unsigned int temp=0,sum=0;
	static unsigned char hi,lo;

	printf("argv=%s\n",*(argv+1));

	if(*(argv+1))
	{
    	    arry = *(argv+1);
	    while(*arry != '\0')
            {
	       hi = *arry++;
		lo = *arry++;
		deal(&hi);
		deal(&lo);
		temp = (hi<<4)+(lo&0x0f);
		sum += temp;
		//printf("temp=%d,sum=%x",temp,sum);
	    }
	}
	else
	    printf("no args!!!\n");
	printf("sum=%x\n",sum);

}

