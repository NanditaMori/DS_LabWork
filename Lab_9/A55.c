// 55.WAP to define a C structure named Student (roll_no, name, branch and batch_no) and also to access the structure members using Pointer.
#include <stdio.h>
#include <stdlib.h>
struct student
{
    int roll_no;
    char name[50];
    char branch[50];
    int batch_no;
};
void main()
{
    struct student *ptr = (struct student *)malloc(sizeof(struct student));
    ptr->roll_no = 101;
    int i;
    char name[] = "abc";
    char branch[] = "xyz";

    for (i = 0; name[i] != '\0'; i++)
        ptr->name[i] = name[i];
    ptr->name[i] = '\0';

    for (i = 0; branch[i] != '\0'; i++)
        ptr->branch[i] = branch[i];
    ptr->branch[i] = '\0';

    ptr->batch_no = 100;
    printf("%d\n", ptr->roll_no);
    printf("%s\n", ptr->name);
    printf("%s\n", ptr->branch);
    printf("%d\n", ptr->batch_no);
}