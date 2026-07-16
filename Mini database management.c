#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student
{
    int id;
    char name[50];
    int age;
    char gender[10];
    char department[30];
    char address[100];
    long long phone;
    char email[50];
    float marks;
    float attendance;
};

// Function Prototypes
void insertRecord();
void displayRecord();
void searchRecord();
void searchByName();
void updateRecord();
void deleteRecord();
void countRecords();
void averageMarks();
void displayTopper();
void passedStudents();
void failedStudents();
void departmentWiseDisplay();
void backupDatabase();

int main()
{
    int choice;

    while (1)
    {
        printf("\n=========================================");
        printf("\n      STUDENT DATABASE MANAGEMENT");
        printf("\n=========================================");
        printf("\n1. Insert Record");
        printf("\n2. Display Records");
        printf("\n3. Search by ID");
        printf("\n4. Search by Name");
        printf("\n5. Update Record");
        printf("\n6. Delete Record");
        printf("\n7. Count Records");
        printf("\n8. Average Marks");
        printf("\n9. Display Topper");
        printf("\n10. Passed Students");
        printf("\n11. Failed Students");
        printf("\n12. Department-wise Display");
        printf("\n13. Backup Database");
        printf("\n14. Exit");

        printf("\n\nEnter Choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                insertRecord();
                break;

            case 2:
                displayRecord();
                break;

            case 3:
                searchRecord();
                break;

            case 4:
                searchByName();
                break;

            case 5:
                updateRecord();
                break;

            case 6:
                deleteRecord();
                break;

            case 7:
                countRecords();
                break;

            case 8:
                averageMarks();
                break;

            case 9:
                displayTopper();
                break;

            case 10:
                passedStudents();
                break;

            case 11:
                failedStudents();
                break;

            case 12:
                departmentWiseDisplay();
                break;

            case 13:
                backupDatabase();
                break;

            case 14:
                printf("\nThank You!\n");
                exit(0);

            default:
                printf("\nInvalid Choice!\n");
        }
    }

    return 0;
}

/*--------------------------------------------------*/
/* INSERT RECORD */
/*--------------------------------------------------*/

void insertRecord()
{
    FILE *fp;
    struct Student s;

    fp = fopen("database.dat","ab");

    if(fp == NULL)
    {
        printf("\nFile Error!");
        return;
    }

    printf("\nEnter Student ID : ");
    scanf("%d",&s.id);

    printf("Enter Name : ");
    scanf("%s",s.name);

    printf("Enter Age : ");
    scanf("%d",&s.age);

    printf("Enter Gender : ");
    scanf("%s",s.gender);

    printf("Enter Department : ");
    scanf("%s",s.department);

    printf("Enter Address : ");
    scanf(" %[^\n]",s.address);

    printf("Enter Phone Number : ");
    scanf("%lld",&s.phone);

    printf("Enter Email : ");
    scanf("%s",s.email);

    printf("Enter Marks : ");
    scanf("%f",&s.marks);

    printf("Enter Attendance (%%): ");
    scanf("%f",&s.attendance);

    fwrite(&s,sizeof(struct Student),1,fp);

    fclose(fp);

    printf("\nRecord Inserted Successfully.\n");
}

/*--------------------------------------------------*/
/* DISPLAY RECORDS */
/*--------------------------------------------------*/

void displayRecord()
{
    FILE *fp;
    struct Student s;

    fp = fopen("database.dat","rb");

    if(fp == NULL)
    {
        printf("\nNo Records Found.\n");
        return;
    }

    printf("\n==============================================================================================");
    printf("\nID  Name        Age Gender Dept        Phone         Marks Attendance");
    printf("\n==============================================================================================");

    while(fread(&s,sizeof(struct Student),1,fp))
    {
        printf("\n%-3d %-12s %-3d %-7s %-10s %-13lld %-6.2f %-6.2f%%",
               s.id,
               s.name,
               s.age,
               s.gender,
               s.department,
               s.phone,
               s.marks,
               s.attendance);
    }

    printf("\n==============================================================================================\n");

    fclose(fp);
}
/*--------------------------------------------------*/
/* SEARCH RECORD BY ID */
/*--------------------------------------------------*/

void searchRecord()
{
    FILE *fp;
    struct Student s;
    int id, found = 0;

    fp = fopen("database.dat", "rb");

    if(fp == NULL)
    {
        printf("\nNo Records Found.\n");
        return;
    }

    printf("\nEnter Student ID to Search: ");
    scanf("%d", &id);

    while(fread(&s, sizeof(struct Student), 1, fp))
    {
        if(s.id == id)
        {
            printf("\n=========== RECORD FOUND ===========");
            printf("\nID         : %d", s.id);
            printf("\nName       : %s", s.name);
            printf("\nAge        : %d", s.age);
            printf("\nGender     : %s", s.gender);
            printf("\nDepartment : %s", s.department);
            printf("\nAddress    : %s", s.address);
            printf("\nPhone      : %lld", s.phone);
            printf("\nEmail      : %s", s.email);
            printf("\nMarks      : %.2f", s.marks);
            printf("\nAttendance : %.2f%%", s.attendance);

            found = 1;
            break;
        }
    }

    if(!found)
        printf("\nRecord Not Found.");

    fclose(fp);
}

/*--------------------------------------------------*/
/* SEARCH RECORD BY NAME */
/*--------------------------------------------------*/

void searchByName()
{
    FILE *fp;
    struct Student s;
    char name[50];
    int found = 0;

    fp = fopen("database.dat", "rb");

    if(fp == NULL)
    {
        printf("\nNo Records Found.");
        return;
    }

    printf("\nEnter Student Name: ");
    scanf("%s", name);

    while(fread(&s, sizeof(struct Student), 1, fp))
    {
        if(strcmp(s.name, name) == 0)
        {
            printf("\n=========== RECORD FOUND ===========");
            printf("\nID         : %d", s.id);
            printf("\nName       : %s", s.name);
            printf("\nAge        : %d", s.age);
            printf("\nGender     : %s", s.gender);
            printf("\nDepartment : %s", s.department);
            printf("\nAddress    : %s", s.address);
            printf("\nPhone      : %lld", s.phone);
            printf("\nEmail      : %s", s.email);
            printf("\nMarks      : %.2f", s.marks);
            printf("\nAttendance : %.2f%%", s.attendance);

            found = 1;
        }
    }

    if(!found)
        printf("\nRecord Not Found.");

    fclose(fp);
}

/*--------------------------------------------------*/
/* UPDATE RECORD */
/*--------------------------------------------------*/

void updateRecord()
{
    FILE *fp;
    struct Student s;
    int id, found = 0;

    fp = fopen("database.dat", "rb+");

    if(fp == NULL)
    {
        printf("\nNo Records Found.");
        return;
    }

    printf("\nEnter Student ID to Update: ");
    scanf("%d", &id);

    while(fread(&s, sizeof(struct Student), 1, fp))
    {
        if(s.id == id)
        {
            printf("\nEnter New Name: ");
            scanf("%s", s.name);

            printf("Enter New Age: ");
            scanf("%d", &s.age);

            printf("Enter Gender: ");
            scanf("%s", s.gender);

            printf("Enter Department: ");
            scanf("%s", s.department);

            printf("Enter Address: ");
            scanf(" %[^\n]", s.address);

            printf("Enter Phone: ");
            scanf("%lld", &s.phone);

            printf("Enter Email: ");
            scanf("%s", s.email);

            printf("Enter Marks: ");
            scanf("%f", &s.marks);

            printf("Enter Attendance: ");
            scanf("%f", &s.attendance);

            fseek(fp, -(long)sizeof(struct Student), SEEK_CUR);
            fwrite(&s, sizeof(struct Student), 1, fp);

            printf("\nRecord Updated Successfully.");

            found = 1;
            break;
        }
    }

    if(!found)
        printf("\nRecord Not Found.");

    fclose(fp);
}

/*--------------------------------------------------*/
/* DELETE RECORD */
/*--------------------------------------------------*/

void deleteRecord()
{
    FILE *fp, *temp;
    struct Student s;
    int id, found = 0;

    fp = fopen("database.dat", "rb");

    if(fp == NULL)
    {
        printf("\nNo Records Found.");
        return;
    }

    temp = fopen("temp.dat", "wb");

    printf("\nEnter Student ID to Delete: ");
    scanf("%d", &id);

    while(fread(&s, sizeof(struct Student), 1, fp))
    {
        if(s.id == id)
        {
            found = 1;
        }
        else
        {
            fwrite(&s, sizeof(struct Student), 1, temp);
        }
    }

    fclose(fp);
    fclose(temp);

    remove("database.dat");
    rename("temp.dat", "database.dat");

    if(found)
        printf("\nRecord Deleted Successfully.");
    else
        printf("\nRecord Not Found.");
}
/*--------------------------------------------------*/
/* COUNT RECORDS */
/*--------------------------------------------------*/

void countRecords()
{
    FILE *fp;
    struct Student s;
    int count = 0;

    fp = fopen("database.dat","rb");

    if(fp == NULL)
    {
        printf("\nNo Records Found.\n");
        return;
    }

    while(fread(&s,sizeof(struct Student),1,fp))
    {
        count++;
    }

    fclose(fp);

    printf("\nTotal Number of Students = %d\n", count);
}

/*--------------------------------------------------*/
/* AVERAGE MARKS */
/*--------------------------------------------------*/

void averageMarks()
{
    FILE *fp;
    struct Student s;
    float total = 0;
    int count = 0;

    fp = fopen("database.dat","rb");

    if(fp == NULL)
    {
        printf("\nNo Records Found.\n");
        return;
    }

    while(fread(&s,sizeof(struct Student),1,fp))
    {
        total += s.marks;
        count++;
    }

    fclose(fp);

    if(count == 0)
    {
        printf("\nNo Records Found.\n");
    }
    else
    {
        printf("\nAverage Marks = %.2f\n", total / count);
    }
}

/*--------------------------------------------------*/
/* DISPLAY TOPPER */
/*--------------------------------------------------*/

void displayTopper()
{
    FILE *fp;
    struct Student s, topper;
    int found = 0;

    fp = fopen("database.dat","rb");

    if(fp == NULL)
    {
        printf("\nNo Records Found.\n");
        return;
    }

    if(fread(&topper,sizeof(struct Student),1,fp))
    {
        found = 1;

        while(fread(&s,sizeof(struct Student),1,fp))
        {
            if(s.marks > topper.marks)
            {
                topper = s;
            }
        }
    }

    fclose(fp);

    if(found)
    {
        printf("\n========== TOPPER ==========");
        printf("\nID         : %d", topper.id);
        printf("\nName       : %s", topper.name);
        printf("\nDepartment : %s", topper.department);
        printf("\nMarks      : %.2f", topper.marks);
        printf("\nAttendance : %.2f%%\n", topper.attendance);
    }
}

/*--------------------------------------------------*/
/* PASSED STUDENTS */
/*--------------------------------------------------*/

void passedStudents()
{
    FILE *fp;
    struct Student s;
    int found = 0;

    fp = fopen("database.dat","rb");

    if(fp == NULL)
    {
        printf("\nNo Records Found.\n");
        return;
    }

    printf("\n============= PASSED STUDENTS =============");
    printf("\nID\tName\t\tMarks");

    while(fread(&s,sizeof(struct Student),1,fp))
    {
        if(s.marks >= 40)
        {
            printf("\n%d\t%-10s\t%.2f",
                   s.id,
                   s.name,
                   s.marks);
            found = 1;
        }
    }

    if(!found)
        printf("\nNo Passed Students.");

    fclose(fp);
}

/*--------------------------------------------------*/
/* FAILED STUDENTS */
/*--------------------------------------------------*/

void failedStudents()
{
    FILE *fp;
    struct Student s;
    int found = 0;

    fp = fopen("database.dat","rb");

    if(fp == NULL)
    {
        printf("\nNo Records Found.\n");
        return;
    }

    printf("\n============= FAILED STUDENTS =============");
    printf("\nID\tName\t\tMarks");

    while(fread(&s,sizeof(struct Student),1,fp))
    {
        if(s.marks < 40)
        {
            printf("\n%d\t%-10s\t%.2f",
                   s.id,
                   s.name,
                   s.marks);
            found = 1;
        }
    }

    if(!found)
        printf("\nNo Failed Students.");

    fclose(fp);
}

/*--------------------------------------------------*/
/* DEPARTMENT-WISE DISPLAY */
/*--------------------------------------------------*/

void departmentWiseDisplay()
{
    FILE *fp;
    struct Student s;
    char dept[30];
    int found = 0;

    fp = fopen("database.dat","rb");

    if(fp == NULL)
    {
        printf("\nNo Records Found.\n");
        return;
    }

    printf("\nEnter Department: ");
    scanf("%s", dept);

    printf("\nStudents in %s Department", dept);
    printf("\n--------------------------------------------");

    while(fread(&s,sizeof(struct Student),1,fp))
    {
        if(strcmp(s.department, dept) == 0)
        {
            printf("\nID:%d  Name:%s  Marks:%.2f",
                   s.id,
                   s.name,
                   s.marks);

            found = 1;
        }
    }

    if(!found)
        printf("\nNo Students Found.");

    fclose(fp);
}

/*--------------------------------------------------*/
/* BACKUP DATABASE */
/*--------------------------------------------------*/

void backupDatabase()
{
    FILE *source, *backup;
    char ch;

    source = fopen("database.dat","rb");

    if(source == NULL)
    {
        printf("\nNo Database Found.\n");
        return;
    }

    backup = fopen("backup.dat","wb");

    while(fread(&ch,sizeof(char),1,source))
    {
        fwrite(&ch,sizeof(char),1,backup);
    }

    fclose(source);
    fclose(backup);

    printf("\nDatabase Backup Created Successfully.");
}
