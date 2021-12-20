#include <stdio.h>
#include <stdlib.h>
struct address{
    char st_name[20];
    union{
        char locality[20];
        int pincode;
    };
};

struct employee{
    char name[20];
    int id;
    struct address add;
};

int main(){
    int choice;
    printf("Enter value between 0-9:\n");
    scanf("%d",&choice);
    int n;
    printf("Number of Employees\n");
    scanf("%d",&n);
    struct employee* emp = (struct employee*)malloc(n * sizeof(struct employee));
    #if choice <= 5 
    for(int i =1;i<=n;i++){
        printf("Enter the details of Employee no %d\n",i);
        scanf("%s",emp[i].name);
        scanf("%d",&emp[i].id);
        scanf("%s",emp[i].add.st_name);
        scanf("%s",emp[i].add.locality);
    }
    for(int i = 1;i<=n;i++){
        FILE *fptr;
        if(i == 1)
        fptr = fopen("file1.txt","w");
        else
        fptr = fopen("file1.txt","a");
        fprintf(fptr,"%s %d %s %s",emp[i].name,emp[i].id,emp[i].add.st_name,emp[i].add.locality);
        fclose(fptr);
        printf("%s\n",emp[i].add.locality);
    }
    #elif choice >5
    for(int i =1;i<=n;i++){
        printf("Enter the details of Employee no %d\n",i);
        scanf("%s",&emp[i].name);
        scanf("%d",&emp[i].id);
        scanf("%s",&emp[i].add.st_name);
        scanf("%d",&emp[i].add.pincode);
    }
    for(int i = 1;i<=n;i++){
        FILE *fptr;
        if(i == 1)
        fptr = fopen("file2.txt","w");
        else
        fptr = fopen("file2.txt","a");
        fprintf(fptr,"%s %d %s %d",emp[i].name,emp[i].id,emp[i].add.st_name,emp[i].add.locality);
        fclose(fptr);
        printf("%d\n",emp[i].add.pincode);
    }
    #else 
    printf("zero");
    #endif
    return 0;
}
