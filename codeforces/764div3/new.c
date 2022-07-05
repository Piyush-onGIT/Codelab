#include <stdio.h>
#include <string.h>
struct student
{
	char name[50];
	char stid[50];
	char batch[50];
};
int main()
{
	struct student s[10];
    for (int i = 0; i < 10; i++) {
        char name[50], batch[50], id[50];
        printf("Name of student %d: ", i+1);
        gets(name);
        strcpy(s[i].name, name);
        printf("Student id of %s: ", s[i].name);
        gets(id);
        strcpy(s[i].stid, id);
        printf("Batch of %s: ", s[i].name);
        gets(batch);
        strcpy(s[i].batch, batch);
        printf("Continue?(y/n): ");
        char input[1];
        gets(input);
        if (strcmp(input, "n") == 0) break;
    }
	printf("Enter student id to get details: ");
    char id[50];
    gets(id);
    for (int i = 0; i < 10; i++) {
        if (strcmp(s[i].stid, id) == 0) {
            printf("Name: %s, Batch: %s", s[i].name, s[i].batch);
        }
    }
    printf("\n");
}