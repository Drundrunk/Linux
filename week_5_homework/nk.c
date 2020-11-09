#include "head.h"

int main(int args, char* argvs){
   int fd = fopen(argvs[1],"r");
   char lenth[4];
   fread(lenth,sizeof(char),4,fd);
   int n = lenth;
   int k = 0;
   scanf("%d",&k);
   int len = 0;
   int pre = 0;
   for(int i=0; i<k;i++)
   {
   fread(lenth,sizeof(char),4,fd);
   pre += lenth;
   }
   fread(lenth,sizeof(char),4,fd);
   len = lenth;
   fseek(fd,pre + (n+1)*4,SEEK_SET );
   char out[100];
   fread(out,sizeof(char),len,fd);
   printf("%s",out);

   return 0;
}
