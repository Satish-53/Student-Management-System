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
    float attendance;
    float totalFee;
    float paidFee;
};

char getGrade(float marks) {
    if (marks >= 90)
        return 'A';
    else if (marks >= 80)
        return 'B';
    else if (marks >= 70)
        return 'C';
    else if (marks >= 60)
        return 'D';
    else if (marks >= 50)
        return 'E';
    else
        return 'F';
}
void saveData(struct Student students[], int count) {

    FILE *file = fopen("students.dat", "wb");

    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }

    fwrite(&count, sizeof(int), 1, file);

    fwrite(students,
           sizeof(struct Student),
           count,
           file);

    fclose(file);
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
        printf("\n8. Student Profile");
        printf("\n9. Sort Students by Marks");
        printf("\n10. Exit");

        printf("\n\nEnter your choice: ");
        scanf("%d", &choice);


        // =========================
        // ADD STUDENT
        // =========================

if (choice == 1) {

    int rollExists = 0;

    printf("Enter Full Name: ");
    scanf(" %[^\n]", students[count].name);

    printf("Enter Course: ");
    scanf(" %[^\n]", students[count].course);

    printf("Enter Semester: ");
    scanf("%d", &students[count].semester);

    printf("Enter Roll Number: ");
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

    printf("Enter Email: ");
    scanf("%s", students[count].email);

    printf("Enter Age: ");
    scanf("%d", &students[count].age);

    // Attendance
    do {
        printf("Enter Attendance (0-100): ");
        scanf("%f", &students[count].attendance);

        if (students[count].attendance < 0 ||
            students[count].attendance > 100) {

            printf("Invalid attendance! Please enter 0 to 100.\n");
        }

    } while (students[count].attendance < 0 ||
             students[count].attendance > 100);


    // Marks
    do {
        printf("Enter Marks (0-100): ");
        scanf("%f", &students[count].marks);

        if (students[count].marks < 0 ||
            students[count].marks > 100) {

            printf("Invalid marks! Please enter 0 to 100.\n");
        }

    } while (students[count].marks < 0 ||
             students[count].marks > 100);


    // Fee
    printf("Enter Total Fee: ");
    scanf("%f", &students[count].totalFee);

    printf("Enter Paid Fee: ");
    scanf("%f", &students[count].paidFee);


    // Check fee values
    if (students[count].totalFee < 0 ||
        students[count].paidFee < 0 ||
        students[count].paidFee > students[count].totalFee) {

        printf("\nInvalid fee amount!\n");
        printf("Paid Fee cannot be greater than Total Fee.\n");
        continue;
    }


    // Increase count AFTER entering all student information
    count++;

    // Save data
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
                printf("\n--------- Student Records ---------\n");
                for (int i = 0; i < count; i++) {
                    printf("\nName: %s\n", students[i].name);
                    printf("Course: %s\n", students[i].course);
                    printf("Semester: %d\n", students[i].semester);
                    printf("Roll Number: %d\n", students[i].roll);
                    printf("Email: %s\n", students[i].email);
                    printf("Age: %d\n", students[i].age);
                    printf("Attendance: %.2f%%\n", students[i].attendance);
                    printf("Marks: %.2f\n", students[i].marks);
                    printf("Grade: %c\n", getGrade(students[i].marks));
                    printf("Result: %s\n",students[i].marks >= 50 ? "PASS" : "FAIL");
                    printf("Total Fee: %.2f\n", students[i].totalFee);
                    printf("Paid Fee: %.2f\n", students[i].paidFee);
                    printf("Due Fee: %.2f\n",students[i].totalFee - students[i].paidFee);
                    if (students[i].paidFee >= students[i].totalFee) {
                        printf("Fee Status: PAID\n");
                    } else {
                        printf("Fee Status: DUE\n");
                        }
                    }
            }
            printf("\nStudent view successfully!\n");
        }


// ================================
// SEARCH STUDENT BY ROLL NUMBER
// ================================

else if (choice == 3) {

    int searchRoll;
    int found = 0;

    printf("\nEnter Roll Number to Search: ");
    scanf("%d", &searchRoll);

    for (int i = 0; i < count; i++) {

        if (students[i].roll == searchRoll) {

           printf("\n--------- Student Record ---------\n");

            printf("Name: %s\n", students[i].name);
            printf("Course: %s\n", students[i].course);
            printf("Semester: %d\n", students[i].semester);
            printf("Roll Number: %d\n", students[i].roll);
            printf("Email: %s\n", students[i].email);
            printf("Age: %d\n", students[i].age);
            printf("Attendance: %.2f%%\n", students[i].attendance);
            printf("Marks: %.2f\n", students[i].marks);
            printf("Grade: %c\n", getGrade(students[i].marks));
            printf("Result: %s\n",students[i].marks >= 50 ? "PASS" : "FAIL");
            printf("Total Fee: %.2f\n", students[i].totalFee);
            printf("Paid Fee: %.2f\n", students[i].paidFee);
            printf("Due Fee: %.2f\n",students[i].totalFee - students[i].paidFee);

            if (students[i].paidFee >= students[i].totalFee) {
                printf("Fee Status: PAID\n");
            } else {
                printf("Fee Status: DUE\n");
            }
            printf("---------------------------------\n");

            found = 1;
            break;
        }
    }

    if (!found) {
        printf("\nStudent not found!\n");
    }
    printf("\nStudent searching by roll number successfully!\n");
}


        // =========================
       // SEARCH STUDENT BY NAME
      // ===========================

else if (choice == 4) {

    char searchName[50];
    int found = 0;

    printf("\nEnter Student Name to Search: ");
    scanf(" %[^\n]", searchName);

    for (int i = 0; i < count; i++) {

        if (strcmp(students[i].name, searchName) == 0) {

            printf("\n--------- Student Record ---------\n");

            printf("Name: %s\n", students[i].name);
            printf("Course: %s\n", students[i].course);
            printf("Semester: %d\n", students[i].semester);
            printf("Roll Number: %d\n", students[i].roll);
            printf("Email: %s\n", students[i].email);
            printf("Age: %d\n", students[i].age);
            printf("Attendance: %.2f%%\n", students[i].attendance);
            printf("Marks: %.2f\n", students[i].marks);
            printf("Grade: %c\n", getGrade(students[i].marks));
            printf("Result: %s\n",students[i].marks >= 50 ? "PASS" : "FAIL");
            printf("Total Fee: %.2f\n", students[i].totalFee);
            printf("Paid Fee: %.2f\n", students[i].paidFee);
            printf("Due Fee: %.2f\n",students[i].totalFee - students[i].paidFee);

            if (students[i].paidFee >= students[i].totalFee) {
                printf("Fee Status: PAID\n");
            } else {
                printf("Fee Status: DUE\n");
            }

            printf("---------------------------------\n");

            found = 1;
            break;
        }
    }

    if (!found) {
        printf("\nStudent not found!\n");
    }
    printf("\nStudent searching by name successfully!\n");
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

                    printf("\n--------- Update Student ---------\n");

            printf("Enter New Full Name: ");
            scanf(" %[^\n]", students[i].name);

            printf("Enter New Course: ");
            scanf(" %[^\n]", students[i].course);

            printf("Enter New Semester: ");
            scanf("%d", &students[i].semester);

            printf("Enter New Roll Number: ");
            scanf("%d", &students[i].roll);

            printf("Enter New Email: ");
            scanf("%s", students[i].email);

            printf("Enter New Age: ");
            scanf("%d", &students[i].age);


            // Attendance
            do {
                printf("Enter New Attendance (0-100): ");
                scanf("%f", &students[i].attendance);

                if (students[i].attendance < 0 ||
                    students[i].attendance > 100) {

                    printf("Invalid attendance! Please enter 0 to 100.\n");
                }

            } while (students[i].attendance < 0 ||
                     students[i].attendance > 100);


            // Marks
            do {
                printf("Enter New Marks (0-100): ");
                scanf("%f", &students[i].marks);

                if (students[i].marks < 0 ||
                    students[i].marks > 100) {

                    printf("Invalid marks! Please enter 0 to 100.\n");
                }

            } while (students[i].marks < 0 ||
                     students[i].marks > 100);


            // Fee
            printf("Enter New Total Fee: ");
            scanf("%f", &students[i].totalFee);

            printf("Enter New Paid Fee: ");
            scanf("%f", &students[i].paidFee);


            // Fee validation
            if (students[i].totalFee < 0 ||
                students[i].paidFee < 0 ||
                students[i].paidFee > students[i].totalFee) {

                printf("\nInvalid fee amount!\n");
                printf("Paid Fee cannot be greater than Total Fee.\n");
                break;
            }
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

    int roll;
    int found = 0;

    printf("\nEnter Roll Number to Delete: ");
    scanf("%d", &roll);

    for (int i = 0; i < count; i++) {

        if (students[i].roll == roll) {

            printf("\n--------- Student Found ---------\n");

            printf("Name: %s\n", students[i].name);
            printf("Course: %s\n", students[i].course);
            printf("Semester: %d\n", students[i].semester);
            printf("Roll Number: %d\n", students[i].roll);
            printf("Email: %s\n", students[i].email);
            printf("Age: %d\n", students[i].age);
            printf("Attendance: %.2f%%\n", students[i].attendance);
            printf("Marks: %.2f\n", students[i].marks);
            printf("Grade: %c\n", getGrade(students[i].marks));

            printf("Result: %s\n",
                   students[i].marks >= 50 ? "PASS" : "FAIL");

            printf("Total Fee: %.2f\n", students[i].totalFee);
            printf("Paid Fee: %.2f\n", students[i].paidFee);
            printf("Due Fee: %.2f\n",
                   students[i].totalFee - students[i].paidFee);

            if (students[i].paidFee >= students[i].totalFee) {
                printf("Fee Status: PAID\n");
            } else {
                printf("Fee Status: DUE\n");
            }

            printf("---------------------------------\n");

            // Delete student
            for (int j = i; j < count - 1; j++) {
                students[j] = students[j + 1];
            }

            count--;

            saveData(students, count);

            printf("\nStudent deleted successfully!\n");

            found = 1;
            break;
        }
    }

    if (!found) {
        printf("\nStudent not found!\n");
    }
}

// =================================
// Student Statistics
// =================================

else if (choice == 7) {

    if (count == 0) {
        printf("\nNo students available!\n");
    }
    else {

        float totalMarks = 0;
        float highest = students[0].marks;
        float lowest = students[0].marks;

        float totalFee = 0;
        float paidFee = 0;

        int pass = 0;
        int fail = 0;

        int lowAttendance = 0;

        for (int i = 0; i < count; i++) {

            totalMarks += students[i].marks;

            totalFee += students[i].totalFee;
            paidFee += students[i].paidFee;

            if (students[i].marks > highest) {
                highest = students[i].marks;
            }

            if (students[i].marks < lowest) {
                lowest = students[i].marks;
            }

            if (students[i].marks >= 50) {
                pass++;
            }
            else {
                fail++;
            }

            if (students[i].attendance < 75) {
                lowAttendance++;
            }
        }

        float average = totalMarks / count;
        float pendingFee = totalFee - paidFee;

        printf("\n=================================\n");
        printf("       STUDENT STATISTICS\n");
        printf("=================================\n");

        printf("Total Students : %d\n", count);
        printf("Average Marks  : %.2f\n", average);
        printf("Highest Marks  : %.2f\n", highest);
        printf("Lowest Marks   : %.2f\n", lowest);

        printf("---------------------------------\n");

        printf("Passed Students: %d\n", pass);
        printf("Failed Students: %d\n", fail);

        printf("---------------------------------\n");

        printf("Total Fee      : %.2f\n", totalFee);
        printf("Paid Fee       : %.2f\n", paidFee);
        printf("Pending Fee    : %.2f\n", pendingFee);

        printf("---------------------------------\n");

        printf("Low Attendance : %d\n", lowAttendance);

        printf("=================================\n");
    }
    printf("\nStudent statistics successfully!\n");
}


// =========================
// STUDENT PROFILE
// =========================

else if (choice == 8) {

    int roll;
    int found = 0;

    printf("\nEnter Roll Number: ");
    scanf("%d", &roll);

    for (int i = 0; i < count; i++) {

        if (students[i].roll == roll) {

            printf("\n=================================\n");
            printf("         STUDENT PROFILE\n");
            printf("=================================\n");

            printf("Name        : %s\n", students[i].name);
            printf("Course      : %s\n", students[i].course);
            printf("Semester    : %d\n", students[i].semester);
            printf("Roll Number : %d\n", students[i].roll);
            printf("Email       : %s\n", students[i].email);
            printf("Age         : %d\n", students[i].age);
            printf("Attendance  : %.2f%%\n", students[i].attendance);
            printf("Marks       : %.2f\n", students[i].marks);
            printf("Grade       : %c\n", getGrade(students[i].marks));

            printf("Result      : %s\n",
                   students[i].marks >= 50 ? "PASS" : "FAIL");

            printf("Total Fee   : %.2f\n", students[i].totalFee);
            printf("Paid Fee    : %.2f\n", students[i].paidFee);
            printf("Due Fee     : %.2f\n",
                   students[i].totalFee - students[i].paidFee);

            if (students[i].paidFee >= students[i].totalFee) {
                printf("Fee Status  : PAID\n");
            }
            else {
                printf("Fee Status  : DUE\n");
            }

            printf("=================================\n");

            found = 1;
            break;
        }
    }

    if (!found) {
        printf("\nStudent not found!\n");
    }
    printf("\nStudent profile successfully!\n");
}

// =============================
//Sort Students by Marks
// =============================

else if (choice == 9) {

    if (count == 0) {
        printf("\nNo students available!\n");
    }
    else {

        struct Student temp;

        // Sort by marks - highest to lowest
        for (int i = 0; i < count - 1; i++) {

            for (int j = 0; j < count - i - 1; j++) {

                if (students[j].marks < students[j + 1].marks) {

                    temp = students[j];
                    students[j] = students[j + 1];
                    students[j + 1] = temp;
                }
            }
        }

        printf("\n=================================\n");
        printf("      STUDENTS SORTED BY MARKS\n");
        printf("=================================\n");

        for (int i = 0; i < count; i++) {

            printf("\nName        : %s\n", students[i].name);
            printf("Course      : %s\n", students[i].course);
            printf("Semester    : %d\n", students[i].semester);
            printf("Roll Number : %d\n", students[i].roll);
            printf("Email       : %s\n", students[i].email);
            printf("Age         : %d\n", students[i].age);
            printf("Attendance  : %.2f%%\n", students[i].attendance);
            printf("Marks       : %.2f\n", students[i].marks);
            printf("Grade       : %c\n", getGrade(students[i].marks));

            printf("Result      : %s\n",
                   students[i].marks >= 50 ? "PASS" : "FAIL");

            printf("Total Fee   : %.2f\n", students[i].totalFee);
            printf("Paid Fee    : %.2f\n", students[i].paidFee);
            printf("Due Fee     : %.2f\n",
                   students[i].totalFee - students[i].paidFee);

            if (students[i].paidFee >= students[i].totalFee) {
                printf("Fee Status  : PAID\n");
            }
            else {
                printf("Fee Status  : DUE\n");
            }

            printf("---------------------------------\n");
        }
    }
    printf("\nStudent shorted by their marks successfully!\n");
}


// ==========================
// Exit
// ==========================
else if (choice == 10) {

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