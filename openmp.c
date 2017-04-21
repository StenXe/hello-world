#include<stdio.h>
#include<omp.h>
#include<string.h>
int main(int argc, char **argv)
{
#pragma omp parallel
{
int tid=omp_get_thread_num();
char inst[100];
strcpy(inst,"./yacc_file ");
strcat(inst,argv[tid+1]);
system(inst);
}
}
