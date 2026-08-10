#include <stdio.h>
#include <string.h>
int login() {

    char username[30];
    char password[30];

    printf("\n=================================\n");
    printf("          ADMIN LOGIN\n");
    printf("=================================\n");

    printf("\nUsername: ");
    scanf("%s", username);

    printf("Password: ");
    scanf("%s", password);

    if (strcmp(username, "admin") == 0 &&
        strcmp(password, "1234") == 0) {

        printf("\nLogin successful!\n");
        return 1;
    }
    else {

        printf("\nInvalid username or password!\n");
        return 0;
    }
}
struct Student {
    int roll;
    char name[50];
    int age;
    char course[50];
    int semester;
    char email[100];
    float marks;
};
void saveData(struct Student students[], int count) {

    FILE *file = fopen("students.dat", "wb");

    if (file != NULL) {

        fwrite(&count, sizeof(int), 1, file);

        fwrite(students,
               sizeof(struct Student),
               count,
               file);

        fclose(file);
    }
}

int main() {

    if (!login()) {
        return 0;
    }

    struct Student students[100];
    int count = 0;
    int choice;

    // Load old data
    FILE *file = fopen("students.dat", "rb");

    if (file != NULL) {
        fread(&count, sizeof(int), 1, file);
        fread(students, sizeof(struct Student), count, file);
        fclose(file);
    }

    while (1) {

        printf("\n=================================\n");
        printf("     STUDENT MANAGEMENT SYSTEM\n");
        printf("=================================\n");

        printf("\n1. Add Student");
        printf("\n2. View Students");
        printf("\n3. Search Student by Roll Number");
        printf("\n4. Search Student by Name");
        printf("\n5. Update Student");
        printf("\n6. Delete Student");
        printf("\n7. Student Statistics");
        printf("\n8. Exit");

        printf("\n\nEnter your choice: ");
        scanf("%d", &choice);

        // =========================
        // ADD STUDENT
        // =========================
        if (choice == 1) {

            int rollExists = 0;

            printf("\nEnter Roll Number: ");
            scanf("%d", &students[count].roll);

            // Check duplicate roll number
            for (int i = 0; i < count; i++) {

                if (students[i].roll == students[count].roll) {
                    rollExists = 1;
                    break;
                }
            }

            if (rollExists) {
                printf("\nThis Roll Number already exists!\n");
                continue;
            }

            printf("Enter Full Name: ");
            scanf(" %[^\n]", students[count].name);
            printf("Enter Course: ");
            scanf(" %[^\n]", students[count].course);
            printf("Enter Semester: ");
            scanf("%d", &students[count].semester);
            printf("Enter Email: ");
            scanf("%s", students[count].email);
            printf("Enter Age: ");
            scanf("%d", &students[count].age);

            // Marks validation
            do {
                printf("Enter Marks (0-100): ");
                scanf("%f", &students[count].marks);

                if (students[count].marks < 0 ||
                    students[count].marks > 100) {

                    printf("Invalid marks! Please enter 0 to 100.\n");
                }

            } while (students[count].marks < 0 ||
                     students[count].marks > 100);

            count++;
                saveData(students, count);
                printf("\nStudent added successfully!\n");
        }

        // =========================
        // VIEW STUDENTS
        // =========================
        else if (choice == 2) {

            if (count == 0) {
                printf("\nNo students available.\n");
            }
            else {

                printf("\n--------- Student List ---------\n");

        for (int i = 0; i < count; i++) {
            printf("Roll Number: %d\n", students[i].roll);
            printf("Name: %s\n", students[i].name);
            printf("Age: %d\n", students[i].age);
            printf("Course: %s\n", students[i].course);
            printf("Semester: %d\n", students[i].semester);
            printf("Email: %s\n", students[i].email);
            printf("Marks: %.2f\n", students[i].marks);
                }
            }
        }
// =========================
// SEARCH STUDENT BY ROLL NUMBER
// =========================
else if (choice == 3) {

    int searchRoll;
    int found = 0;

    printf("\nEnter Roll Number to Search: ");
    scanf("%d", &searchRoll);

    for (int i = 0; i < count; i++) {

        if (students[i].roll == searchRoll) {

           printf("Roll Number: %d\n", students[i].roll);
           printf("Name: %s\n", students[i].name);
           printf("Age: %d\n", students[i].age);
           printf("Course: %s\n", students[i].course);
           printf("Semester: %d\n", students[i].semester);
           printf("Email: %s\n", students[i].email);
           printf("Marks: %.2f\n", students[i].marks);

            found = 1;
            break;
        }
    }

    if (!found) {
        printf("\nStudent not found!\n");
    }
}
        // =========================
       // SEARCH STUDENT BY NAME
      // =========================
else if (choice == 4) {

    char searchName[50];
    int found = 0;

    printf("\nEnter Student Name to Search: ");
    scanf(" %[^\n]", searchName);

    for (int i = 0; i < count; i++) {

        if (strcmp(students[i].name, searchName) == 0) {

            printf("Roll Number: %d\n", students[i].roll);
            printf("Name: %s\n", students[i].name);
            printf("Age: %d\n", students[i].age);
            printf("Course: %s\n", students[i].course);
            printf("Semester: %d\n", students[i].semester);
            printf("Email: %s\n", students[i].email);
            printf("Marks: %.2f\n", students[i].marks);

            found = 1;
            break;
        }
    }

    if (!found) {
        printf("\nStudent not found!\n");
    }
}

        // =========================
        // UPDATE STUDENT
        // =========================
        else if (choice == 5) {

            int updateRoll;
            int found = 0;

            printf("\nEnter Roll Number to Update: ");
            scanf("%d", &updateRoll);

            for (int i = 0; i < count; i++) {

                if (students[i].roll == updateRoll) {
                    printf("\nEnter New Full Name: ");
                    scanf(" %[^\n]", students[i].name);
                    printf("Enter New Age: ");
                    scanf("%d", &students[i].age);
                    printf("Enter New Course: ");
                    scanf(" %[^\n]", students[i].course);
                    printf("Enter New Semester: ");
                    scanf("%d", &students[i].semester);
                    printf("Enter New Email: ");
                    scanf("%s", students[i].email);
            do {
                        printf("Enter New Marks (0-100): ");
                        scanf("%f", &students[i].marks);

                        if (students[i].marks < 0 ||
                            students[i].marks > 100) {

                            printf("Invalid marks!\n");
                        }

                    } while (students[i].marks < 0 ||
                             students[i].marks > 100);
                        saveData(students, count);
                    printf("\nStudent updated successfully!\n");

                    found = 1;
                    break;
                }
            }

            if (!found) {
                printf("\nStudent not found!\n");
            }
        }

        // =========================
        // DELETE STUDENT
        // =========================
else if (choice == 6) {

    int deleteRoll;
    int found = 0;
    char confirm;

    printf("\nEnter Roll Number to Delete: ");
    scanf("%d", &deleteRoll);

    for (int i = 0; i < count; i++) {

        if (students[i].roll == deleteRoll) {

            printf("\nStudent Found:\n");
            printf("Name: %s\n", students[i].name);
            printf("Roll Number: %d\n", students[i].roll);

            printf("\nAre you sure you want to delete this student? (y/n): ");
            scanf(" %c", &confirm);

            if (confirm == 'y' || confirm == 'Y') {

                for (int j = i; j < count - 1; j++) {
                    students[j] = students[j + 1];
                }

                count--;
                    saveData(students, count);
                printf("\nStudent deleted successfully!\n");
            }
            else {
                printf("\nDelete cancelled.\n");
            }

            found = 1;
            break;
        }
    }

    if (!found) {
        printf("\nStudent not found!\n");
    }
}
// Student Statistics
else if (choice == 7) {

    if (count == 0) {
        printf("\nNo students available.\n");
    }
    else {

        float totalMarks = 0;
        float highest = students[0].marks;
        float lowest = students[0].marks;

        for (int i = 0; i < count; i++) {

            totalMarks += students[i].marks;

            if (students[i].marks > highest) {
                highest = students[i].marks;
            }

            if (students[i].marks < lowest) {
                lowest = students[i].marks;
            }
        }

        float average = totalMarks / count;

        printf("\n=================================\n");
        printf("       STUDENT STATISTICS\n");
        printf("=================================\n");

        printf("\nTotal Students : %d", count);
        printf("\nAverage Marks  : %.2f", average);
        printf("\nHighest Marks  : %.2f", highest);
        printf("\nLowest Marks   : %.2f\n", lowest);
    }
}

// Exit
else if (choice == 8) {

    file = fopen("students.dat", "wb");

    if (file != NULL) {

        fwrite(&count, sizeof(int), 1, file);
        fwrite(students,
               sizeof(struct Student),
               count,
               file);

        fclose(file);

        printf("\nData saved successfully!\n");
    }
    else {
        printf("\nError saving data!\n");
    }

    printf("Thank you!\n");
    break;
}
else {
            printf("\nInvalid choice!\n");
        }
}

    return 0;
}