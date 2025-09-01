#include <stdio.h>
#include <stdlib.h>

#define s 3

struct Student {
    char name[50];
    int rollNo;
    int age;
    float marks[3];
    char grade;
};

struct Student examResult[s];

void loadResults() {
    FILE *file = fopen("results.txt", "r");
    if (file == NULL) {
        printf("Error opening the file in read.");
    } else {
        printf("File opened successfully.\n");
    }
    for (int i = 0; i < s; i++) {
        fscanf(file, "%s %d %d %.2f %c",
               examResult[i].name,
               &examResult[i].rollNo,
               &examResult[i].age,
               &examResult[i].marks[0],
               &examResult[i].marks[1],
               &examResult[i].marks[2],
               &examResult[i].grade);
    }
    fclose(file);
}

void inputStudentData() {
    FILE *file = fopen("results.txt", "a");
    if (file != NULL) {
        for (int i = 0; i < s; i++) {
            printf("\nEnter Data for Student %d\n", i + 1);
            printf("Name: ");
            scanf("%s", examResult[i].name);
            printf("Roll No: ");
            scanf("%d", &examResult[i].rollNo);
            printf("Age: ");
            scanf("%d", &examResult[i].age);
            printf("Mark 1: ");
            scanf("%f", &examResult[i].marks[0]);
            printf("Mark 2: ");
            scanf("%f", &examResult[i].marks[1]);
            printf("Mark 3: ");
            scanf("%f", &examResult[i].marks[2]);
            examResult[i].grade = 'F';
        }
        fclose(file);
    }
}

void calculateGrade(struct Student *examResult) {
    for (int i = 0; i < s; i++) {
        if (examResult[i].marks[0] > 95 && examResult[i].marks[1] > 95 && examResult[i].marks[2] > 95) {
            examResult[i].grade = 'A';
        } else if (examResult[i].marks[0] > 85 && examResult[i].marks[1] > 85 && examResult[i].marks[2] > 85) {
            examResult[i].grade = 'B';
        } else if (examResult[i].marks[0] > 75 && examResult[i].marks[1] > 75 && examResult[i].marks[2] > 75) {
            examResult[i].grade = 'C';
        } else {
            printf("Student %d Needs Improvement in one or more subjects\n", i + 1);
        }
    }
}

void displayResults(struct Student *examResult) {
    for (int i = 0; i < s; i++) {
        printf("\n\n%s \t%d \t%d\t %.2f\t %.2f\t %.2f \t%c\n",
               examResult[i].name,
               examResult[i].rollNo,
               examResult[i].age,
               examResult[i].marks[0],
               examResult[i].marks[1],
               examResult[i].marks[2],
               examResult[i].grade);
    }
}

void updateAge(struct Student *examResult) {
    int update, newage;
    if (examResult->age >= 5) {
        printf("Do you want to update your age? ");
        scanf("%d", &update);
        if (update == 1) {
            printf("Enter new age: ");
            scanf("%d", &newage);
            examResult->age = newage;
        }
    }
}

int main() {
    loadResults();
    inputStudentData();
    calculateGrade(examResult);
    displayResults(examResult);
    updateAge(examResult);
    return 0;
}
