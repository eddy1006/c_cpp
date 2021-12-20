#include<stdio.h>
#include<stdlib.h>

int main(){
    FILE *fptr;
    fptr = fopen("file1.dat","w+");
    fprintf(fptr,"%s","This is the sixth file program");
    rewind(fptr);
    char ch ;
    while(ch != EOF){
        ch = fgetc(fptr);
        printf("%c\n",ch);
    }
    fclose(fptr);
    return 0;
}