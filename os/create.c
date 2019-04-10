#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>

int main()
{
  int id;
  if ((id=creat("temp.txt", 777))==-1){
      printf("Cannot create file\n");
      exit(1);
  }
  else{
      printf("File is created\n");
  }
  return 0;
}
