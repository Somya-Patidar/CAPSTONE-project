#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include <conio.h>

void gotoxy(int, int);
int person();
void cond1();
void cond2();
int menu1();
void add();
void tdetail();
void addstu();
void sdetail();
int menu2();
int menu3();

typedef struct teacher
{
    char name[20];
    char subject[20];
    int section;

} teacher;
typedef struct student
{
    int section;
    char name[20];
    char rollno[20];

} student;
typedef struct sec1
{

    char rollno[20];
    int maths;
    int english;
    int chemistry;

} sec1;
typedef struct sec2
{

    char rollno[20];
    int mechanics;
    int physics;
    int electrical;

} sec2;
int main()
{
    gotoxy(15, 8);
    printf("<--:Attendance Management System:-->");

    person();
    return 0;
}

int person()
{
    int ch1;
    printf("\n1. login as admin");
    printf("\n2. login as teacher");
    printf("\n3. login as student");
    printf("\n4. Exit");
    printf("\nEnter your choice-->\t");
    scanf("%d", &ch1);
    // return (ch1);
    switch (ch1)
    {
    case 1:
        cond1();
        break;
    case 2:
        cond2();
        break;
    case 3:
        menu3();
        break;
    case 4:
        exit(1);
        break;
    default:
        person();
        break;
    }
}
void cond1()
{
    char id[20];
    char pass[20];
    printf("enter the username: ");
    gets(id);
    scanf("%s", id);
    printf("enter password: ");
    gets(pass);
    scanf("%s", pass);
    if (strcmp(id, "admin") == 0 && strcmp(pass, "abc") == 0)
    {
         system("cls");

        printf("\n\tsuccessfully LOGGED IN\n");
        menu1();
    }
    else
    {
         system("cls");
        printf("\nwrong ID or Password\n   ");
        printf("\npress any key to continue-->");
        getch();
        person();
    }
}
int menu1()
{
    int choice1;
    printf("\n**********Main Menu***********\n");

    printf("1. add a teacher\n");
    printf("2. display teacher detail\n");
    printf("3. add student\n");
    printf("4. display student detail\n");
    printf("5. Exit\n");

    scanf("%d", &choice1);

    switch (choice1)
    {
    case 1:
        add();
        break;
    case 2:
        tdetail();
        break;
    case 3:
        addstu();
        break;
    case 4:
        sdetail();
        break;
    case 5:
        exit(1);
        break;
    default:
        person();
        break;
    }
}
void add()
{
    struct teacher t;
    char another = 'y';
    system("cls");
    FILE *fp = fopen("teacher.txt", "a");
    if (fp == NULL)
    {

        printf("Error opening file");
        exit(1);
    }
    fflush(stdin);
    while (another == 'y')
    {
        printf("<--:ADD RECORD:-->");

        printf("Enter details of Teacher.");

        printf("\nEnter Name : ");
        gets(t.name);

        printf("\nEnter Subject : ");
        gets(t.subject);

        printf("\nEnter section : ");
        scanf("%d", &t.section);
        fwrite(&t, sizeof(teacher), 1, fp);
        printf("\nWant to add of another record? Then press 'y' else 'n'.");
        fflush(stdin);

        another = getch();
        system("cls");
        fflush(stdin);
    }

    fclose(fp);
    printf("\nPress any key to continue.");
    getch();
    int n1;
    printf("\nEnter 1. to log out or 2. to continue--> ");
    scanf("%d", &n1);
    if (n1 == 1)
    {
        person();
    }
    else
    {
        menu1();
    }
}
void tdetail()
{
    teacher teach;
    int i = 1;
    FILE *fp = fopen("teacher.txt", "r");
    printf("\n<--:VIEW RECORD:-->");
    printf("\nS.No   Name of Teacher        Subject        Section");
    printf("\n-------------------------------------------------------------------------------------------");
    fflush(stdin);
    while (fread(&teach, sizeof(teach), 1, fp))
    {
        printf("\n%-5d%-25s%-18s%-5d", i, teach.name, teach.subject, teach.section);
        i++;
    }
    fclose(fp);

    printf("\n\nPress any key to continue.\n");
    getch();
    int n2;
    printf("\nEnter 1. to log out or 2. to continue--> ");
    scanf("%d", &n2);
    if (n2 == 1)
    {
        person();
    }
    else
    {
        menu1();
    }
}

void addstu()
{
    struct student s;
    char another = 'y';
    system("cls");
    FILE *fp1 = fopen("student.txt", "a+");

    if (fp1 == NULL)
    {

        printf("Error opening file");
        exit(1);
    }
    fflush(stdin);
    while (another == 'y')
    {
        char name[50];
        char roll[20];
        int section;
        printf("<--:ADD RECORD:-->");

        printf("\nEnter details of Students.");

        printf("\nEnter Name : ");
        gets(s.name);
        printf("\nEnter Roll NO : ");
        scanf("%s", &s.rollno);
        fflush(stdin);
        printf("\nEnter section : ");
        scanf("%d", &s.section);

        if (s.section == 1)
        {
            struct sec1 seca;
            FILE *pf1;

            pf1 = fopen("section1.txt", "a");
            if (pf1 == NULL)
            {
                printf("Error opening file!\n");
                menu1();
            }
            printf("\nEnter Roll NO for confirmation : ");
            scanf("%s", &seca.rollno);
            fflush(stdin);

            seca.maths = 0;
            seca.english = 0;
            seca.chemistry = 0;
            fwrite(&seca, sizeof(seca), 1, pf1);
            printf("succesfully entered");

            fclose(pf1);
        }
        else if (s.section == 2)
        {
            struct sec2 secb;
            FILE *pf2;

            pf2 = fopen("section2.txt", "a");
            if (pf2 == NULL)
            {
                printf("Error opening file!\n");
                menu1();
            }
            printf("\nEnter Roll NO for confirmation : ");
            scanf("%s", &secb.rollno);
            fflush(stdin);

            secb.mechanics = 0;
            secb.physics = 0;
            secb.electrical = 0;
            fwrite(&secb, sizeof(secb), 1, pf2);
            printf("succesfully entered");

            fclose(pf2);
        }
        else{
            system("cls");
            printf("\nthis section is not available\n");
            addstu();
        }
        fwrite(&s, sizeof(student), 1, fp1);
        // fclose(fp1);

        printf("\nWant to add of another record? Then press 'y' else 'n'.");
        fflush(stdin);

        another = getch();
        system("cls");
        fflush(stdin);
    }

    fclose(fp1);
    printf("\nPress any key to continue.");
    getch();
    int n3;
    printf("\nEnter 1. to log out or 2. to continue--> ");
    scanf("%d", &n3);
    if (n3 == 1)
    {
        person();
    }
    else
    {
        menu1();
    }
}
void sdetail()
{
    student std;
    int i = 1;
    FILE *fp1 = fopen("student.txt", "r");
    printf("\n<--:VIEW RECORD:-->");
    printf("\nS.No   Name of Student         Roll No        Section");
    printf("\n-------------------------------------------------------------------------------------------");
    while (fread(&std, sizeof(std), 1, fp1))
    {
        printf("\n%-5d%-28s%-18s%-5d", i, std.name, std.rollno, std.section);
        i++;
    }
    fclose(fp1);

    printf("\n\nPress any key to continue.\n");
    getch();
    int n4;
    printf("\nEnter 1. to log out or 2. to continue--> ");
    scanf("%d", &n4);
    if (n4 == 1)
    {
        person();
    }
    else
    {
        menu1();
    }
}
void cond2()
{
    char id[20];
    char pass[20];
    printf("enter the username: ");
    gets(id);
    scanf("%s", id);
    printf("enter password: ");
    gets(pass);
    scanf("%s", pass);
    if (strcmp(id, "teach") == 0 && strcmp(pass, "xyz") == 0)
    {
        system("cls");
        printf("\n\tsuccessfully LOGGED IN\n");
        menu2();
    }
    else
    {
        system("cls");
        printf("\nwrong ID or Password\n   ");
        printf("\npress any key to continue-->");
        getch();
        person();
    }
}

int menu2()
{
    char roll[20];
    int sec;
    printf("Enter the section- ");
    scanf("%d", &sec);
    if (sec == 1)
    {
        char sub[20];
        printf("Enter the subject- ");
        scanf("%s", sub);

        if (strcmp(sub, "maths") == 0)
        {
            struct sec1 sc1;
            long int resize;
            resize = sizeof(sc1);
            FILE *fp1 = fopen("section1.txt", "r+");
           
            if (fp1 == NULL)
            {
                fprintf(stderr, "error opening the file");
                exit(1);
            }

            fflush(stdin);
            while (fread(&sc1, sizeof(sc1), 1, fp1))
            {
                char att;
                printf("enter P for present and A for absent");
                printf("\n%-30s", sc1.rollno);
                fflush(stdin);
                scanf("%c", &att);

                if (att == 'p' || att == 'P')
                {
                    sc1.maths += 1;
                    fseek(fp1, -resize, SEEK_CUR);
                    fwrite(&sc1, resize, 1, fp1);
                    fflush(fp1);
                    continue;
                }
            }
            printf("\nATTENDANCE DONE!!");
            fflush(stdin);
            fclose(fp1);
        }
        else if (strcmp(sub, "english") == 0)
        {
            struct sec1 sc1;
            long int resize;
            resize = sizeof(sc1);
            FILE *fp1 = fopen("section1.txt", "r+");
            
            if (fp1 == NULL)
            {
                fprintf(stderr, "error opening the file");
                exit(1);
            }

            fflush(stdin);
            while (fread(&sc1, sizeof(sc1), 1, fp1))
            {
                char att;
                printf("enter P for present and A for absent");
                printf("\n%-30s", sc1.rollno);
                fflush(stdin);
                scanf("%c", &att);

                if (att == 'p' || att == 'P')
                {
                    sc1.english += 1;
                    fseek(fp1, -resize, SEEK_CUR);
                    fwrite(&sc1, resize, 1, fp1);
                    fflush(fp1);
                    continue;
                }
            }
            printf("\nATTENDANCE DONE!!");
            fflush(stdin);
            fclose(fp1);
        }
            else if (strcmp(sub, "chemistry") == 0)
            {
                struct sec1 sc1;
                long int resize;
                resize = sizeof(sc1);
                FILE *fp1 = fopen("section1.txt", "r+");
                
                if (fp1 == NULL)
                {
                    fprintf(stderr, "error opening the file");
                    exit(1);
                }

                fflush(stdin);
                while (fread(&sc1, sizeof(sc1), 1, fp1))
                {
                    char att;
                    printf("enter P for present and A for absent");
                    printf("\n%-30s", sc1.rollno);
                    fflush(stdin);
                    scanf("%c", &att);

                    if (att == 'p' || att == 'P')
                    {
                        sc1.chemistry += 1;
                        fseek(fp1, -resize, SEEK_CUR);
                        fwrite(&sc1, resize, 1, fp1);
                        fflush(fp1);
                        continue;
                    }
                    printf("\nATTENDANCE DONE!!");
                    fflush(stdin);
                    fclose(fp1);
                }
            }
            else{
                
                 printf("\nthis subject is not alloted for section 1\n");
                 printf("\n\nPress any key to continue.\n");
                 getch();
                 printf("\n");
                menu2();
            }
    }
    else if (sec == 2)
    {
        char sub[20];
        printf("Enter the subject- ");
        scanf("%s", sub);

        if (strcmp(sub, "mechanics") == 0)
        {
            struct sec2 sc2;
            long int resize;
            resize = sizeof(sc2);
            FILE *fp2 = fopen("section2.txt", "r+");
            
            if (fp2 == NULL)
            {
                fprintf(stderr, "error opening the file");
                person();
                
            }

            fflush(stdin);
            while (fread(&sc2, sizeof(sc2), 1, fp2))
            {
                char att;
                printf("enter P for present and A for absent");
                printf("\n%-30s", sc2.rollno);
                fflush(stdin);
                scanf("%c", &att);

                if (att == 'p' || att == 'P')
                {
                    sc2.mechanics += 1;
                    fseek(fp2, -resize, SEEK_CUR);
                    fwrite(&sc2, resize, 1, fp2);
                    fflush(fp2);
                    continue;
                }
            }
            printf("\nATTENDANCE DONE!!");
            fflush(stdin);
            fclose(fp2);
        }
        else if (strcmp(sub, "physics") == 0)
        {
            struct sec2 sc2;
            long int resize;
            resize = sizeof(sc2);
            FILE *fp2 = fopen("section2.txt", "r+");
            
            if (fp2 == NULL)
            {
                fprintf(stderr, "error opening the file");
                person();
            }

            fflush(stdin);
            while (fread(&sc2, sizeof(sc2), 1, fp2))
            {
                char att;
                printf("enter P for present and A for absent");
                printf("\n%-30s", sc2.rollno);
                fflush(stdin);
                scanf("%c", &att);

                if (att == 'p' || att == 'P')
                {
                    sc2.physics += 1;
                    fseek(fp2, -resize, SEEK_CUR);
                    fwrite(&sc2, resize, 1, fp2);
                    fflush(fp2);
                    continue;
                }
            }
            printf("\nATTENDANCE DONE!!");
            fflush(stdin);
            fclose(fp2);
        }
            else if (strcmp(sub, "electrical") == 0)
            {
                struct sec2 sc2;
                long int resize;
                resize = sizeof(sc2);
                FILE *fp2 = fopen("section2.txt", "r+");
                
                if (fp2 == NULL)
                {
                    fprintf(stderr, "error opening the file");
                    person();
                }

                fflush(stdin);
                while (fread(&sc2, sizeof(sc2), 1, fp2))
                {
                    char att;
                    printf("enter P for present and A for absent");
                    printf("\n%-30s", sc2.rollno);
                    fflush(stdin);
                    scanf("%c", &att);

                    if (att == 'p' || att == 'P')
                    {
                        sc2.electrical += 1;
                        fseek(fp2, -resize, SEEK_CUR);
                        fwrite(&sc2, resize, 1, fp2);
                        fflush(fp2);
                        continue;
                    }
                    printf("\nATTENDANCE DONE!!");
                    fflush(stdin);
                    fclose(fp2);
                }
            }
            else{
                
                 printf("\nthis subject is not alloted for section 1\n");
                 printf("\n\nPress any key to continue.\n");
                 getch();
                 printf("\n");
                 menu2();
            }
    }
    else{
        printf("\nthis section is not available");
        printf("\n\nPress any key to continue.\n");
        getch();
        menu2();
    }
                    int n5;
                    printf("\nEnter 1. to log out or 2. to take attendance of another class > ");
                    scanf("%d", &n5);
                    if (n5 == 2)
                    {
                        menu2();
                    }
                    else
                    {
                        person();
                    }
}
        
        
        int menu3()
        {
            system("cls");
            int sec;
            printf("Enter the section- ");
            scanf("%d", &sec);
            if (sec == 1)
            {
                sec1 sc1;
                int i = 1;
                FILE *fp1 = fopen("section1.txt", "r");
                char sub[20];
                printf("Enter the subject- ");

                scanf("%s", sub);
                printf("RollNO\t\t\tAttendance");
                printf("\n----------------------------------------");
                while (fread(&sc1, sizeof(sc1), 1, fp1))
                {
                    if (strcmp(sub, "maths") == 0)
                    {
                        
                        printf("\n%-30s", sc1.rollno);
                        fflush(stdin);
                        printf("%d", sc1.maths);
                    }
                    else if (strcmp(sub, "english") == 0)
                    {
                       
                        printf("\n%-30s", sc1.rollno);
                        fflush(stdin);
                        printf("%d", sc1.english);
                    }
                    else if (strcmp(sub, "chemistry") == 0)
                    {
                        
                        printf("\n%-30s", sc1.rollno);
                        fflush(stdin);
                        printf("%d", sc1.chemistry);
                    }
                    else
                    {
                        
                        printf("\nthis subject is not alloted for section 1\n");
                        printf("\n\nPress any key to continue.\n");
                         getch();
                        printf("\n\n");
                        menu3();
                    }
                }
                fclose(fp1);
            }
            else if (sec == 2)
            {
                sec2 sc2;
                
                FILE *fp2 = fopen("section2.txt", "r");
                char sub[20];
                printf("Enter the subject- ");

                scanf("%s", sub);
                printf("RollNO\t\t\tAttendance");
                printf("\n----------------------------------------");
                while (fread(&sc2, sizeof(sc2), 1, fp2))
                {
                    if (strcmp(sub, "mechanics") == 0)
                    {
                        
                        printf("\n%-30s", sc2.rollno);
                        fflush(stdin);
                        printf("%d", sc2.mechanics);
                    }
                    else if (strcmp(sub, "physics") == 0)
                    {
                       
                        printf("\n%-30s", sc2.rollno);
                        fflush(stdin);
                        printf("%d", sc2.physics);
                    }
                    else if (strcmp(sub, "electrical") == 0)
                    {
                        
                        printf("\n%-30s", sc2.rollno);
                        fflush(stdin);
                        printf("%d", sc2.electrical);
                    }
                    else
                    {
                        
                        printf("\n\nthis subject is not alloted for section 2\n");
                        printf("\n\nPress any key to continue.\n");
                        getch();
                        printf("\n\n");
                        menu3();
                    }
                }
                fclose(fp2);
            }
            else{
                
                printf("\n\nthis section is not available\n");
                printf("\n\nPress any key to continue.\n");
                getch();
                menu3();
            }

            int n6;
            printf("\nEnter 1. to log out or 2. to check attendance for another section/subject--> ");
            scanf("%d", &n6);
            if (n6 == 1)
            {
                printf("\n\n");
                person();
            }
            else
            {
                printf("\n");
                menu3();
            }
            
        }
        void gotoxy(int x, int y)
        {
            COORD c;
            c.X = x;
            c.Y = y;
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
        }
