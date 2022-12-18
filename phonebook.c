#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#include<windows.h>

struct contacts
{
    char name[25];
    char fname[25];
    char mname[25];
    char sex[10];
    char address[60];
    char mobileNo[11];
    char email[30];
};
void newcontact()
{
    FILE *fp;
    struct contacts con;
    char a='y';
    system("cls");

    fp = fopen("record.txt","ab+");
    if(fp == NULL){

        printf("Error opening file");
        exit(1);
    }
    fflush(stdin);
    while(a=='y')
    {

        printf("\n\t\t\t\t************************************************************************************************************");
        printf("\n\t\t\t\t*\t\t<---------------------------:  Add New Contact  :-------------------------->\t\t   *");
        printf("\n\t\t\t\t************************************************************************************************************");

        printf("\n\nEnter details of Contact.\n");

        printf("\nEnter Name : ");

        gets(con.name);

        printf("\nEnter Mobile Number : ");
        gets(con.mobileNo);

        printf("\nEnter Father name : ");
        gets(con.fname);
        fflush(stdin);

        printf("\nEnter Mother Name : ");
        gets(con.mname);

        printf("\nEnter Sex : ");
        gets(con.sex);

        printf("\nEnter E-mail : ");
        gets(con.email);

        printf("\nEnter Address : ");
        gets(con.address);
        fflush(stdin);

        fwrite(&con,sizeof(con),1,fp);
        fflush(stdin);
        printf("Press Y to add another contact.\n\nElse press any key to continue: ");
        a=getch();
        system("cls");
        fflush(stdin);
    }
    fclose(fp);
    printf("Press any key to continue.");
    getch();
    menu();
}


void list()
{
    FILE *fp;
    int i=1;
    struct contacts con;
    system("cls");
    printf("\n\t\t\t\t************************************************************************************************************");
    printf("\n\t\t\t\t*\t\t<---------------------------:  PhoneBook RECORDS  :-------------------------->\t\t   *");
    printf("\n\t\t\t\t************************************************************************************************************");

    printf("\n\n\n\t\tS.No\t\tName\t\tMobileNo\t\tFatherName\t\tMotherName\t\tSex\t\tE-mail\t\t\tAddress");

    printf("\n\t||-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------||");

    fp = fopen("record.txt","rb+");
    if(fp == NULL){

        printf("Error opening file.");
        exit(1);
    }

    while(fread(&con,sizeof(con),1,fp) == 1){

        printf("\n\t\t%d\t\t%s\t\t%s\t\t%s\t\t%s\t\t%s\t\t%s\t\t%s",i,con.name,con.mobileNo,con.fname,con.mname,con.sex,con.email,con.address);
        i++;
    }
    fclose(fp);

    printf("\n\nPress any key to continue.");
    getch();
    menu();
}

void modify()
{
    char cname[25];
    FILE *fp;
    struct contacts con;
    system("cls");
    printf("\n\t\t\t\t************************************************************************************************************");
    printf("\n\t\t\t\t*\t\t<---------------------------:  Modify RECORDS  :-------------------------->\t\t   *");
    printf("\n\t\t\t\t************************************************************************************************************");

    printf("\n\nEnter the contact name you want to modify: ");
    fflush(stdin);
    gets(cname);
    fp=fopen("record.txt","rb+");
    if(fp == NULL)
    {
        printf("\n\nError in opening the file.");
        exit(1);
    }
    while(fread(&con,sizeof(con),1,fp)==1)
    {
        if(strcmp(cname,con.name)==0)
        {
           printf("\nEnter Name : ");

        gets(con.name);

        printf("\nEnter Mobile Number : ");
        gets(con.mobileNo);

        printf("\nEnter Father name : ");
        gets(con.fname);
        fflush(stdin);

        printf("\nEnter Mother Name : ");
        gets(con.mname);

        printf("\nEnter Sex : ");
        gets(con.sex);

        printf("\nEnter E-mail : ");
        gets(con.email);
        fflush(stdin);

        printf("\nEnter Address : ");
        gets(con.address);

        fseek(fp, -sizeof(con),SEEK_CUR);
        fwrite(&con,sizeof(con),1,fp);
        printf("\n\nContact modified successfully.\n");
        break;
        }


    }
    fclose(fp);
    printf("Enter any key to continue : ");
    getch();
    menu();
}

void search()
{   system("cls");
    FILE *fp;
    char cname[25];
    struct contacts con;
    printf("\n\t\t\t\t************************************************************************************************************");
    printf("\n\t\t\t\t*\t\t<---------------------------:  Search Contact  :-------------------------->\t\t   *");
    printf("\n\t\t\t\t************************************************************************************************************\n\n");
    printf("Enter the contact name: ");
    fflush(stdin);
    gets(cname);
    fp=fopen("record.txt","rb+");
    if(fp==NULL)
    {
        printf("\nError in Opening File.");
        exit(1);
    }
    while(fread(&con,sizeof(con),1,fp)==1)
    {
        if(strcmp(cname,con.name)==0)
        {
             printf("\nContact Name : %s",con.name);

        printf("\nMobile Number : %s",con.mobileNo);

        printf("\nFather name : %s",con.fname);

        printf("\nMother Name : %s",con.mname);

        printf("\nSex : %s",con.sex);

        printf("\nE-mail : %s",con.email);

        printf("\nAddress : %s",con.address);
        }

    }
    fclose(fp);
    printf("\n\nPress any key to continue. ");
    getch();
    menu();
}

void deleter()
{
    system("cls");
    FILE *fp,*f;
    char cname[25];
    struct contacts con;
    printf("\n\t\t\t\t************************************************************************************************************");
    printf("\n\t\t\t\t*\t\t<---------------------------:  Delete Contact  :-------------------------->\t\t   *");
    printf("\n\t\t\t\t************************************************************************************************************\n\n");
    printf("Enter contact name to be deleted: ");
    fflush(stdin);
    gets(cname);
    fp=fopen("record.txt","rb+");
    if(fp==NULL)
    {
        printf("\nError in Opening File.");
        exit(1);
    }
    f=fopen("rec.txt","wb+");
    if(f==NULL)
    {
        printf("\nError in Opening File.");
        exit(1);
    }
    while(fread(&con,sizeof(con),1,fp)==1)
    {
        if(strcmp(cname,con.name)!=0)
        {
            fwrite(&con,sizeof(con),1,f);
        }

    }
    fclose(fp); fclose(f);
    printf("\n\nContact deleted successfully.\n\nPress any key to continue.");
    remove("record.txt");
    rename("rec.txt","record.txt");
    getch();
    menu();
}
void menu()
{   system("color 4f");


    system("cls");
    int choice;
    printf("\n\n\n\n\n\n");
    printf("\n\n\n\t\t\t\t\t\t\t-------------------------------------------------");
    printf("\n\t\t\t\t\t\t\t  *** Welcome to the Phone Book Application ***");
    printf("\n\t\t\t\t\t\t\t-------------------------------------------------");
    printf("\n\n\t\t\t\t\t\t\t\t\t|| MENU ||");
    printf("\n\n\t\t\t\t\t\t\t\t========================");
    printf("\n\t\t\t\t\t\t\t\t[1] Add New Contact");
    printf("\n\n\t\t\t\t\t\t\t\t[2] List of contacts");
    printf("\n\n\t\t\t\t\t\t\t\t[3] Modify contacts");
    printf("\n\n\t\t\t\t\t\t\t\t[4] Search contact record");
    printf("\n\n\t\t\t\t\t\t\t\t[5] Delete a record");
    printf("\n\n\t\t\t\t\t\t\t\t[6] EXIT");
    printf("\n\t\t\t\t\t\t\t\t========================");
    printf("\n\n\t\t\t\t\t\t\t\tEnter your Selection: ");
    scanf("%d",&choice);


    switch(choice)
    {
        case 1: newcontact(); break;
        case 2: list(); break;
        case 3: modify(); break;
        case 4: search(); break;
        case 5: deleter(); break;
        case 6: break;
        default: printf("\n\n\nPlease Enter correct selection: "); getch(); menu();
    }
}
int main()
{

    menu();
    return 0;
}

