#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include<windows.h>
#include<time.h>
#include<iomanip>
#include<ctype.h>
#define max 50
using namespace std;

int num=0;
void intro();
void login();
void menu();
void insert();
void edit();
void editmenu();
void editname(int);
void editcode(int);
void editdes(int);
void editexp(int);
void editage(int);
void editsalary(int);
void list();
void deletes();
void search();
void setWindowSize(int,int);
void saverecords();
void getrecords();
bool isFilePresent();
void displayPayslip();


class employee
{
public:
    char name[20];
    int code;
    char designation[20];
    int exp;
    int age;
    int salary;
    char AnyLoan;

    int HRA;
    int PF;
    int tax;
    int MealAllowance;
    int TransportAllowance;
    int MedicalAllowance;
    int LoanBalance;
    int LoanDebit;
    int grosspay;
    int workingHours;
    int DA;

};
employee emp[max],tempemp[max];


void getrecords()
{
    FILE *fp;
    fp = fopen("Records.txt","r");
    int c=0;
    if(fp!=NULL)
    {
        while(feof(fp)==0)
        {
            fscanf(fp,"%s\t%d\t%s\t%d\t%d\t%d\t%c\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n",&emp[c].name,&emp[c].code,&emp[c].designation,&emp[c].exp,&emp[c].age,&emp[c].salary,&emp[c].AnyLoan,&emp[c].HRA,&emp[c].PF,&emp[c].tax,&emp[c].MealAllowance,&emp[c].TransportAllowance,&emp[c].MedicalAllowance,&emp[c].LoanBalance,&emp[c].LoanDebit,&emp[c].grosspay,&emp[c].workingHours,&emp[c].DA);
            c++;
        }
        num=c;
    }
    fclose(fp);
}

void saverecords()
{
    system("cls");
    if(num==0)
    {
        system("del Records.txt");
    }
    else
    {
        FILE *fp;
        fp = fopen("Records.txt","w");
        for(int i=0; i<num; i++)
        {
            fprintf(fp,"%s\t%d\t%s\t%d\t%d\t%d\t%c\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n",emp[i].name,emp[i].code,emp[i].designation,emp[i].exp,emp[i].age,emp[i].salary,emp[i].AnyLoan,emp[i].HRA,emp[i].PF,emp[i].tax,emp[i].MealAllowance,emp[i].TransportAllowance,emp[i].MedicalAllowance,emp[i].LoanBalance,emp[i].LoanDebit,emp[i].grosspay,emp[i].workingHours,emp[i].DA);
        }
        fclose(fp);
    }
}
bool isFilePresent()
{
    FILE *fp;
    fp = fopen("Records.txt","r");
    if(fp==NULL)
        return false;
    else
        return true;
}
void login()
{

    char UserName[30],Password[30],ch;
    int i=0;
    printf("Enter UserName : ");

    cin>>UserName;
    cout<<endl<<"Enter Password : ";
    while(1)
    {
        ch = getch();
        if(ch==13)
            break;
        if(ch==32||ch==9)
            continue;
        if(ch==8)
        {
            if(i>0)
            {
                i--;
                printf("\b \b");
            }
        }
        else
        {
            cout<<"*";
            Password[i]=ch;
            i++;
        }
    }
    Password[i] = '\0';
    if(strcmp(UserName,"admin")==0 && strcmp(Password,"password")==0)
    {
        system("cls");

        cout<<"Login Success!!!"<<endl;
    }
    else
    {
        system("cls");
        printf("Access Denied!!!\a");
        cout<<"Will be redirected in 3 Seconds...";
        cout<<"\b \b2";
        cout<<"\b \b1";
        system("cls");
        login();
    }
}
void insert()
{
    system("cls");
    int i=num;
    int sal,PF,TAX,HRA,MealA,MedicalA,TransportA,LoanBal,LoanDeb,h,DA;
    char loan;
    num+=1;
    printf("Insert New Record\n");
    cout<<"Name : ";
    cin.getline(emp[i].name,sizeof(emp[i].name));
    cin>>emp[i].name;
    cout<<"\nCode : ";
    cin>>emp[i].code;
    cout<<"\nDesignation : ";
    cin>>emp[i].designation;
    cout<<"\nYears of Experience : ";
    cin>>emp[i].exp;
    cout<<"\nAge : ";
    cin>>emp[i].age;
    cout<<"\nEnter Working Hours : ";
    cin>>h;
    sal = h*300;
    emp[i].workingHours = h;
    do
    {
        cout<<"\nAny Loan (Y/N) ?: \b \b";
        loan=getche();
        if(loan=='Y'|| loan == 'y' || loan =='n' || loan == 'N')
            break;
    }
    while(1);
    if(loan=='y'|| loan=='Y')
    {
        cout<<"\nEnter Loan Balance : ";
        cin>>LoanBal;
    }
    else
    {
        LoanBal=0;
    }
    cout<<"\nRecorded Succesfully...!!!\n";


    TAX =  0.04 * sal;
    DA = 1.20 * sal;
    PF = 0.12 * sal;
    HRA = sal * 0.27;
    MealA = 300;
    MedicalA = 300;
    TransportA = 300;
    LoanDeb = sal * 0.09;
    if(LoanDeb > LoanBal)
    {
        LoanBal = 0;
        LoanDeb = LoanBal;
    }
    emp[i].salary = sal;
    emp[i].DA = DA;
    emp[i].tax=TAX;
    emp[i].PF = PF;
    emp[i].HRA = HRA;
    emp[i].MealAllowance = MealA;
    emp[i].MedicalAllowance = MedicalA;
    emp[i].TransportAllowance = TransportA;
    emp[i].LoanBalance = LoanBal-LoanDeb;
    emp[i].AnyLoan = loan;
    emp[i].LoanDebit = LoanDeb;
    emp[i].grosspay = (sal+MealA+MedicalA+TransportA+HRA+DA)-(PF+TAX+LoanDeb) ;
    getch();
}

void intro()
{
    printf("PAYROLL MANAGEMENT SYSTEM\n");
    printf("Press Any key to continue...\n");
    getch();

}

void  list()
{
    system("cls");
    printf("       ******** List of the Employees ********\n");
    cout<<"Name\tCode\tDesignation\tYears(EXP)\tAge\tSalary "<<endl;
    cout<<"------------------------------------------------------------------"<<endl;
    for(int i=0,j=8; i<=num-1; i++,j++)
    {
        cout<<emp[i].name<<"\t";
        cout<<emp[i].code<<"\t";
        cout<<emp[i].designation<<"\t";
        cout<<emp[i].exp<<"\t";
        cout<<emp[i].age<<"\t";
        cout<<emp[i].grosspay<<"\t";
    }
    getch();
}


void menu()
{

    cout<<"*****  Payroll Management System 1.0 ***** \n";
    cout<<"Press  i ----> Insert New Record."<<endl;
    cout<<"Press  e ----> Edit a Record."<<endl;
    cout<<"Press  d ----> Delete a Record."<<endl;
    cout<<"Press  s ----> Search a Record."<<endl;
    cout<<"Press  l ----> List The Employee Table."<<endl;
    cout<<"Press  p ----> Print Employee PaySlip."<<endl;
    cout<<"Press  q ----> Quit Program."<<endl;
    cout<<"Select Your Option ====> ";
}

void deletes()
{
    system("cls");
    for(int i=0; i<num; i++)
    {
        tempemp[i]=emp[i];
    }
    int code;
    int check=-1;
    printf("Delete a Record\n");
    cout<<"Enter the JobCode To Delete That Record  :";
    cin>>code;
    int i,j;
    for(i=0; i<=num-1; i++)
    {
        if(emp[i].code==code)
        {
            check=i;
        }
    }
    if(check!=-1)
    {
        for(i=0,j=0; i<=num-1; i++,j++)
        {
            if(i==check)
            {
                i++;
            }
            emp[j]=tempemp[i];
        }
        num--;
    }
}

void search()
{
    system("cls");
    int jobcode;
    bool found = false;
    cout<<"You can Search only through the Jobcode of an Employee"<<endl;
    cout<<"Enter Code Of the Employee : ";
    cin>>jobcode;
    for(int i=0; i<=num-1; i++)
    {
        if(emp[i].code==jobcode)
        {
            cout<<"Name\tCode\tDesignation\tYears(EXP)\tAge\tSalary "<<endl;
            cout<<"------------------------------------------------------------------"<<endl;
            cout<<emp[i].name<<"\t";
            cout<<emp[i].code<<"\t";
            cout<<emp[i].designation<<"\t";
            cout<<emp[i].exp<<"\t";
            cout<<emp[i].age<<"\t";
            cout<<emp[i].grosspay<<"\t"<<endl;
            found = true;
        }
    }
    if(!found)
    {
        cout<<"No records Found...!!!\a"<<endl;
    }
    getch();
}



void editmenu()
{
    printf("Edit An Entry\n");
    cout<<"What Do You Want To edit\n";
    cout<<"n ---------> Name \n";
    cout<<"c ---------> Code \n";
    cout<<"d ---------> Designation\n";
    cout<<"e ---------> Experience \n";
    cout<<"a ---------> Age\n";
    cout<<"s ---------> Salary\n";
    cout<<"q ---------> QUIT\n";
    cout<<"Enter Choice ---->>>  ";
}

void editname(int i)
{
    cout<<"Enter New Name----->  ";
    cin>>emp[i].name;
}

void editcode(int i)
{
    cout<<"Enter New Job Code----->  ";
    cin>>emp[i].code;
}
void editdes(int i)
{
    cout<<"enter new designation----->  ";
    cin>>emp[i].designation;
}

void editexp(int i)
{
    cout<<"Enter new Years of Experience";
    cin>>emp[i].exp;
}
void editage(int i)
{
    cout<<"Enter new Age ";
    cin>>emp[i].age;
}


void editsalary(int i)
{
    int sal,PF,TAX,HRA,MealA,MedicalA,TransportA,LoanBal=emp[i].LoanBalance,LoanDeb,DA;
    char loan;
    cout<<"Enter new Salary : ";
    cin>>sal;
    DA = 1.20 * sal;
    TAX =  0.04 * sal;
    PF = 0.12 * sal;
    HRA = 4000;
    MealA = 300;
    MedicalA = 300;
    TransportA = 300;
    LoanDeb = sal * 0.09;
    if(LoanDeb > LoanBal)
    {
        LoanBal = 0;
        LoanDeb = LoanBal;
    }
    emp[i].salary = sal;
    emp[i].tax=TAX;
    emp[i].PF = PF;
    emp[i].HRA = HRA;
    emp[i].MealAllowance = MealA;
    emp[i].MedicalAllowance = MedicalA;
    emp[i].TransportAllowance = TransportA;
    emp[i].LoanBalance = LoanBal;
    emp[i].AnyLoan = loan;
    emp[i].LoanDebit = LoanDeb;
    emp[i].grosspay = (sal+MealA+MedicalA+TransportA+HRA+DA)-(PF+TAX+LoanDeb) ;
}

void edit()
{
    system("cls");
    int jobcode;
    printf("Edit a Record");
    int i;
    char option;
    cout<<"Enter the jobcode To Edit : ";
    cin>>jobcode;
    editmenu();
    for(i=0; i<=num-1; i++)
    {
        if(emp[i].code==jobcode)
        {
            while((option=cin.get())!='q')
            {
                switch(option)
                {
                case 'n':
                    editname(i);
                    break;
                case 'c':
                    editcode(i);
                    break;
                case 'd':
                    editdes(i);
                    break;
                case 'e':
                    editexp(i);
                    break;
                case 'a':
                    editage(i);
                    break;
                case 's':
                    editsalary(i);
                    break;
                }
                editmenu();
            }
        }
    }
}


void displayPayslip()
{
    system("cls");
    int code,i;
    cout<<"Enter Employee Job Code :";
    cin>>code;
    for(i=0; i<=num-1; i++)
    {
        if(emp[i].code==code)
        {
            cout<<"Name : "<<emp[i].name;
            cout<<"Working Hours : "<<emp[i].workingHours<<" Hrs";
            cout<<"Earnings :-";
            cout<<"Basic Pay : "<<emp[i].salary<<endl;
            cout<<"HRA(27% of Basic): "<<emp[i].HRA<<endl;
            cout<<"DA (120% of Basic):"<<emp[i].DA;
            cout<<"Meal Allowance : "<<emp[i].MealAllowance<<endl;
            cout<<"Medical Alowance : "<<emp[i].MedicalAllowance<<endl;
            cout<<"Transport Allowance : "<<emp[i].TransportAllowance<<endl;
            cout<<"Deductions :- "<<endl<<endl;
            cout<<"PF : "<<emp[i].PF<<endl;
            cout<<"Tax : "<<emp[i].tax<<endl;
            int l = emp[i].AnyLoan;
            char l2 = toupper(l);
            cout<<"Loan Status : "<<l2<<endl;
            cout<<"Loan Debit This Month : "<<emp[i].LoanDebit<<endl;
            cout<<"Loan Balance : "<<emp[i].LoanBalance<<endl;
            cout<<"Total Gross Pay : "<<emp[i].grosspay;
        }
    }
    getch();
}

int main()
{
    intro();
    login();
    menu();
    getrecords();
    char option;
    if(emp[0].code==0 && isFilePresent())
        num--;
    while(1)
    {
        option=getch();
        switch(option)
        {
        case 'l':
            list();
            break;
        case 'i':
            insert();
            break;
        case 'd':
            deletes();
            break;
        case 'e':
            edit();
            break;
        case 's':
            search();
            break;
        case 'p':
            displayPayslip();
            break;
        case 'q':
            saverecords();
            exit(0);
        }
        menu();
    }
    return 0;
}
