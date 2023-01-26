#include<stdio.h>
#include<unistd.h>

uint32_t lastbit(uint32_t n){
 uint32_t result= n & (uint32_t)1;
 if(result==0)
   return (uint32_t)0;
 else
   return (uint32_t)1;
}

int STACK[100];
int stack_ptr=0;

void cnvrtToBinary(uint32_t n){
 stack_ptr=-1;
   while(n!=0){
    STACK[++stack_ptr]=lastbit(n);
    n=n>>(uint32_t)1;
  }
}

int findComplement(uint32_t n){
  cnvrtToBinary(n);
  return ~n&((uint32_t)1<<(stack_ptr+1))-1;
}

int main(){
  printf("%d\n",findComplement(5));
}
