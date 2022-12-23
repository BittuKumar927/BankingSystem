#include<iostream>
#include<fstream>
#include<process.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<stdio.h>
#include<conio.h>
#include<direct.h>
#include<iomanip>
using namespace std;
class Menus
{
public :
	void showmenu(void);
private :
	void closemenu(void);

};

class dispRecords
{
public:
    void addDetails(int,char name[30],char address[60],float);
    void displayCustomers(void) ;
    void deleteAccount(int) ;
    void updateBalance(int,float) ;
    void updateCustomer(void) ;
    int lastAccount(void) ;
    int accountExists(int) ;
    char *getName(int);
    char *getAddress(int) ;
    float getBalance(int) ;
    int getRecord(int) ;
    void display (int) ;
    void displayList(void) ;
    int AccountNumber ;
    char name[50], address[50] ;
    float intBalance ;

};
class accountTransactions
{
public:
    void new_account(void);
    void closeAccount(void);
    void display_account(void);
    void transaction(void);
    void addDetails(int, int, int, int, char, char type[15],float,float,float);
    void deleteAccount(int);
    int dateDiffer(int, int ,int, int , int, int);
    float getInterest(int, float);
    void display(int);
    void showAccount(int);
    int AccountNumber;
    char trantype [10];
    int dday, mmonth, yyear;
    char transactions;
    float intInterest, intAmount, intBalance;
    static float calclnterest;
    void showInterest(void);

};

void Menus::showmenu(void)
{
    char choice;
    while(1)
    {

	cout<<"\n    --Welcome to Banking System Application-      ";
	cout<<" ************************************************\n\n";
	cout<<"Choose from Options \n";
	cout<<"_________________\n";
	cout<<"     1: Open an Account\n";
	cout<<"     2: view an Account\n";
	cout<<"     3: Show all Accounts\n";
	cout<<"     4: Make a Transaction \n";
	cout<<"     5: Calculate Interest\n";
	cout<<"     6: Close an Account\n";
	cout<<"     7: Ex1t\n\n";
	cout<<"     Please select a choice :";
	choice = getche();
	if (choice == '1')
	{
	    accountTransactions objAT;
	    objAT.new_account();
	}
	else if (choice == '2')
	{
	    accountTransactions objAT;
	    objAT.display_account();
	}
	else if (choice == '3')
	{
	    dispRecords newRec;
	    newRec.displayCustomers();
	}
	else if (choice == '4')
	{
	    accountTransactions objAT;
	    objAT.transaction();

	}
	else if (choice == '5')
	{
	    accountTransactions objAT;
	    objAT.showInterest();
	}
	else if (choice == '6')
	{
	    closemenu();
	}
	else if (choice == '7')
	{
	    cout<<"\n       Thanks for using this application. Please press any key to exit.\n";
	    getch();
	    break;

	}
    }
}

void Menus::closemenu(void)
{
    char choice;
    while(1)
    {

	cout<<"     -Close Menu-\n";
	cout<<"     *****************\n";
	cout<<"     1: Close/Delete an Account\n";
	cout<<"     0: Exit from this Menu\n";
	cout<<"     Select a Choice\n";
	choice= getche();

	    if(choice ==  '1')
	    {
		accountTransactions ate;
		ate.closeAccount();
		break;
	    }
	    else if(choice=='0')
	    {
		cout<<"\n   You have entered 0 to go back to the previous Menu. \n";
		getch();
		break;
	    }
    }
}
int dispRecords::lastAccount(void)
{
    fstream filename;
    filename.open("newrecords.dat",ios::in);
    filename.seekg(0,ios::beg);
    int counte=0;
    while(filename.read((char *) this,sizeof(dispRecords)))
	counte=AccountNumber;
    filename.close();
    return counte;
}

int dispRecords::getRecord(int AccNo)
{
    fstream filename;
    filename.open("newrecords.dat",ios::in);
    filename.seekg(0,ios::beg);
    int counte=0;
    while(filename.read((char *) this,sizeof(dispRecords)))
    {
	counte++;
	if(AccNo==AccountNumber)
	    break;
    }
    filename.close();
    return counte;
}
void dispRecords::display(int AccNo)
{
    int record ;
    record = getRecord(AccNo);
    fstream filename ;
    filename.open("newrecords.dat", ios::in);
    filename.seekg(0,ios::beg);
    int location;
    location =(record) * sizeof(dispRecords);
    filename.seekp(location);
    while (filename. read ((char *)this, sizeof (dispRecords) ))
    {
	if (AccNo == AccountNumber)
	{
	    cout<<"\n ACCCUNT NO. :"<<AccountNumber ;
	    cout<<"\n Name : "<<name ;
	    cout<<"\n Address :"<<address;
	    cout<<"\n Balance :"<<intBalance ;
	    break ;
	}
    }
    filename.close() ;
}
char *dispRecords::getName(int AccNo)
{
    fstream filename;
    filename.open("newrecords.dat",ios::in);
    filename.seekg(0,ios::beg);
    char Name[30];
    while(filename.read((char *) this,sizeof(dispRecords)))
    {
	if (AccNo == AccountNumber)
	    strcpy(Name,name);
    }
    filename.close();
    return Name;
}
char *dispRecords::getAddress(int AccNo)
{
    fstream filename;
    filename.open("newrecords.dat",ios::in);
    filename.seekg(0,ios::beg);
    char Address[30];
    while(filename.read((char *) this,sizeof(dispRecords)))
    {
	if (AccNo == AccountNumber)
	    strcpy(Address,address);
    }
    filename.close();
    return Address;
}
float dispRecords::getBalance(int AccNo)
{
    fstream filename;
    filename.open("newrecords.dat",ios::in);
    filename.seekg(0,ios::beg);
    int Balance;
    while(filename.read((char *) this,sizeof(dispRecords)))
    {
	if(AccNo==AccountNumber)
	    Balance=intBalance;
    }
    filename.close();
    return Balance;
}
int dispRecords::accountExists(int AccNo)
{
    fstream filename;
    filename.open("newrecords.dat",ios::in);
    filename.seekg(0,ios::beg);
    int counte=0;
    while(filename.read((char *) this,sizeof(dispRecords)))
    {
	if(AccNo==AccountNumber)
	    {   counte=1;
		break;
	    }
    }
    filename.close();
    return counte;
}
void dispRecords::displayList()
{
    cout<<"                         \n";
    int day1, month1 , year1 ;
    struct date dateval ;
    getdate(&dateval);
    day1 = dateval.da_day ;
    month1 = dateval.da_mon ;
    year1 = dateval.da_year ;
    cout<<"\n Date: "<<day1<<"/"<<month1<<"/"<<year1<<endl;
    cout<<setw(80)<<"________________________\n";
    cout<<setw(23)<<" ACCOUNT NO.";
    cout<<setw(23)<<" NAME OF PERSON";
    cout<<setw(23)<<" BALANCE\n";
    cout<<setw(80)<<"________________________\n";
}
void dispRecords::displayCustomers(void)
{
    clrscr() ;
    int len1;
    int row=8,check ;
    fstream filename ;
    FILE * pFile;
    pFile = fopen("newrecords.dat","r");
    if (pFile == NULL)
    {
	cout<<" \n No Account exists. Please go back to the previous menu. \n";
	getch();
	return ;
    }
    else
    {
	displayList();
	filename.open("newreconds.dat" ,ios::in);
	filename.seekg(0,ios::beg);
	while(filename.read((char *) this,sizeof(dispRecords)))
	{
	    check =0 ;
	    cout. fill (' ');
	    cout<<setw(20) ;
	    cout.setf(ios::right,ios::adjustfield);
	    cout<<AccountNumber;
	    cout.fill(' ');
	    cout<<setw(25);
	    cout.setf(ios::right,ios::adjustfield);
	    cout<<name;
	    cout<<setw(23);
	    cout.setf (ios::right,ios::adjustfield);
	    cout<<intBalance<<"\n";
	    row++;
	    if (row ==23)
	    {
	    check = 1 ;
	    row = 8 ;
	    cout<<" \n Continue the Application... \n";
	    getch() ;
	    clrscr() ;
	    displayList() ;
	    }
	}
    }
    filename.close() ;
    if (!check)
    {
	cout <<"\n\n Continue the application.... \n";
	getch();
    }
}
void dispRecords::addDetails(int AccNo,char Name[30],char Address[60],float Balance)
{
    AccountNumber=AccNo;
    strcpy(name,Name) ;
    strcpy(address,Address);
    intBalance=Balance;
    fstream filename;
    filename.open("newrecords.dat",ios::in|ios::app);
    filename.write((char *) this,sizeof(dispRecords));
    filename.close();
}
void dispRecords::deleteAccount(int AccNo)
{
    fstream filename;
    filename.open("newrecords.dat",ios::in);
    fstream temp;
    temp.open("calculations.txt",ios::out);
    filename.seekg(0,ios::beg);
    while(!filename.eof())
    {
	filename.read((char *) this,sizeof(dispRecords));
	if(filename.eof())
	    break;
	if(AccountNumber!=AccNo)
	    temp.write((char *) this,sizeof(dispRecords));

    }
    filename.close();
    temp.close();
    filename.open("newrecords.dat",ios::out);
    temp.open("calculations.txt",ios::in);
    temp.seekg(0,ios::beg);
    while(!temp.eof())
    {
	temp.read((char *) this,sizeof(dispRecords));
	if(temp.eof())
	    break;
	filename.write((char *) this,sizeof(dispRecords));
    }
    filename.close();
    temp.close();
}
void dispRecords::updateBalance(int AccNo,float Balance)
{
    int record;
    record=getRecord(AccNo);
    fstream filename;
    filename.open("newrecords.dat",ios::out|ios::ate);
    intBalance=Balance;
    int location;
    location=(record-1)* sizeof(dispRecords);
    filename.seekp(location);
    filename.write((char *) this,sizeof(dispRecords));
    filename.close();
}
void accountTransactions::addDetails(int Accno,int day1,int month1,int year1,char ttran,char type[15],float interest,float amount,float Balance)
{
    fstream filename;
    filename.open("transactions.dat",ios::app);
    AccountNumber=Accno;
    dday=day1;
    mmonth=month1;
    yyear=year1;
    transactions=ttran;
    strcpy(trantype,type);
    intInterest=interest;
    intAmount=amount;
    intBalance=Balance;
    filename.write((char* ) this,sizeof(accountTransactions));
    filename.close();
}
void accountTransactions::deleteAccount(int Accno)
{
    fstream filename;
    filename.open("transactions.dat",ios::in);
    fstream temp;
    temp.open("calculations.txt",ios::out);
    filename.seekg(0,ios::beg);
    while(!filename.eof())
    {
	filename.read((char *) this,sizeof(accountTransactions));
	if(filename.eof())
	    break;
	if(AccountNumber!=Accno)
	    temp.write((char *) this,sizeof(accountTransactions));

    }
    filename.close();
    temp.close();
    filename.open("transactions.dat",ios::out);
    temp.open("calculations.txt",ios::in);
    temp.seekg(0,ios::beg);
    while(!temp.eof())
    {
	temp.read((char *) this,sizeof(accountTransactions));
	if(temp.eof())
	    break;
	filename.write((char *) this,sizeof(accountTransactions));
    }
    filename.close();
    temp.close();
}
void accountTransactions::new_account(void)
{
    char choice;
    int i,check;

    dispRecords ob;
    cout<<"      Please press 0 to go back to previous menu.\n";
    cout<<endl;
    cout<<"     -Open a New Bank Account-\n";
    cout<<"     *************************\n";
    int day1, month1 , year1 ;
    struct date dateval ;
    getdate(&dateval);
    day1 = dateval.da_day ;
    month1 = dateval.da_mon ;
    year1 = dateval.da_year ;
    int accno;
    accno=ob.lastAccount();
    accno++;
    if(accno==1)
    {
	ob.addDetails(accno,"Ravi","Delhi",1.1);
	ob.deleteAccount(accno);
	addDetails(accno,1,1,1997,'d',"default value",1.1,1.1,1.1);
	deleteAccount(accno);
    }
    char Name[30],tran[10],Address[60];
    float bal,Balance;
    cout<<"     Date:"<<day1<<"/"<<month1<<"/"<<year1<<endl;
    cout<<"     Account no. #"<<accno;
    do
    {
	cout<<"\n\n     Please enter the name of the Account Holder :";
	check=1;
	gets(Name);
    if(Name[0]=='0')
    {
	cout<<"\n\t     Invalid Customer Name.";
	getch();
	return;
    }
    strupr(Name);
    if(strlen(Name)==0||strlen(Name)>30)
	{
	    check=0;
	    cout<<"\t\n     Customer Name is either blank ot its length is greater than 30 charactwers.\n";
	    getch();
	}
    }while(!check);

    do
    {
	cout<<"\n\n     Please enter the Address of the Account Holder :";
	check=1;
	gets(Address);
    if(Address[0]=='0')
    {
	cout<<"\n\t     Invalid Customer Address.";
	getch();
	return;
    }
    strupr(Address);
    if(strlen(Address)==0||strlen(Address)>60)
	{
	    check=0;
	    cout<<"\t\n     Customer Address is either blank or its length is greater than 60 characters.\n";
	    getch();
	}
    }while(!check);
    do
    {
	char Person[30];
	cout<<"\n\n     Please enter the name of the Verifying Person of The Account Holder :";
	check=1;
	gets(Person);
    if(Person[0]=='0')
    {
	cout<<"\n\t     Invalid Verifying Person Name.";
	getch();
	return;
    }
    strupr(Person);
    if(strlen(Person)==0||strlen(Person)>30)
	{
	    check=0;
	    cout<<"\t\n     Verifying Person Name is either blank ot its length is greater than 30 characters.\n";
	    getch();
	}
    }while(!check);
    do
    {
	cout<<"\n Please enter the Deposit Amount while opening a New Account :";
	check = 1 ;
	gets(tran) ;
	bal = atof (tran);
	Balance = bal ;
	if (strlen (tran) < 1)
	{
	    cout<<"\n Invalid Transaction value. Exiting from the current Menu. \n ";
	    getch();
	    return ;
	}
	if (Balance < 1000)
	    {
	    check = 0 ;
	    cout<<"\t\n The Minimum Deposit Amount should be Rs.1000. Please try again. \n";
	    getch() ;
	    }
    } while (!check) ;

    do
    {
	cout<<"\n   Do you want to save the record ? (y/n) :";
	choice=getche();
	choice=toupper(choice);
    }while(choice!='N'||choice!='Y');
    if (choice == 'N' || choice =='Y')
    {
	cout<<"\n The Customer Account is not created.\n Please continue with the application \n";
	getch();
	return ;
    }
    float aamount, interestt;
    aamount = Balance ;
    interestt = 0.0 ;
    char t_tran , typeTransaction[10] ;
    t_tran =  'D';
    strcpy(typeTransaction," ") ;
    ob.addDetails(accno, Name, Address, Balance);
    addDetails(accno,day1,month1 ,year1 , t_tran , typeTransaction,interestt, aamount,Balance);
    cout<<" \n\n The New Account is successfully created. \n Please continue with the application\n";
    getch();
}

void accountTransactions::showAccount(int Accno)
{
    cout<<"                         \n";
    int day1, month1 , year1 ;
    struct date dateval ;
    getdate(&dateval);
    day1 = dateval.da_day ;
    month1 = dateval.da_mon ;
    year1 = dateval.da_year ;
    cout<<"\n Date: "<<day1<<"/"<<month1<<"/"<<year1<<endl;
    cout<<"Account no. "<<Accno;
    dispRecords ob;

    char Name[30],Address[60];
    strcpy(Name,ob.getName(Accno));
    strcpy(Address,ob.getAddress(Accno));

    cout<<setw(25)<<"\n Account Holder's Name : "<<Name;
    cout<<"\nAddress        :   "<<Address;
    cout<<setw(80)<<"\n__________________________\n";
    cout<<setw(10)<<"Dated";
    cout<<setw(12)<<"Details";
    cout<<setw(12)<<"Deposited";
    cout<<setw(15)<<"Withdrawn";
    cout<<setw(12)<<"       ";
    cout<<setw(10)<<"Balance";
    cout<<setw(80)<<"\n__________________________\n";

}
void accountTransactions::display_account(void)
{
    clrscr() ;
    char t_acc[10] ;
    int tran_acc, AccNo;
    dispRecords obj2;
    cout <<" Press 0 to go back to previous menu. \n" ;
    cout <<" Please enter Account No. you want to view : ";
    gets(t_acc);
    tran_acc = atoi (t_acc) ;
    AccNo = tran_acc;
    if (AccNo == 0)
    {
	cout<<"\n You have pressed 0 to exit. \n";
	getch();
	return ;
    }

    accountTransactions aa;
    int row=8, check ;
    fstream filename ;
    FILE * pFile;
    pFile = fopen( "newrecords.dat" , "r");
    if (pFile ==NULL )
    {
	cout<<"\n No such Account Exists. Please create a New Account, \n";
	getch();
	return ;
    }
    else if (!obj2.accountExists(AccNo))
    {
	cout<<" \t\n Account does not exist \n";
	getch();
	return;
    }
    else
    {
    showAccount(AccNo) ;
    filename.open("transactions.dat", ios::in);
    while(filename.read((char *) this,sizeof(accountTransactions)))
    {
	if(AccountNumber==AccNo)
	{
	    check=0;
	    cout<<setw(3)<<dday<<""<<mmonth<<"/"<<yyear;
	    cout<<setw(10)<<trantype;
	    if(transactions=='D')
	    {
		cout.setf(ios::right,ios::adjustfield);
		cout<<setw(15);
		cout<<intAmount;
		cout<<setw(20);
		cout<<" ";
	    }
	    else
	    {
		cout.setf(ios::right,ios::adjustfield);
		cout<<setw(15);
		cout<<intAmount;

		cout<<setw(20);
		cout<<" ";
	    }

	    cout<<setw(15);
	    cout.setf(ios::right,ios::adjustfield);
	    cout<<intAmount<<endl;
	    row++;
	    if(row==23)
	    {
		check=1;
		row=8;
		cout<<"\n\nPlease Continue with the application.\n";
		getch();

		showAccount(AccNo);
	    }
	}
    }
    }
    filename.close();
    if(!check)
    {
	cout<<"\n\n Press any key to continue with the application.\n";
	getch();
    }
}
int accountTransactions :: dateDiffer(int day1, int month1, int year1, int day2,int month2, int year2)
{
    static int monthArr[] = {31,28,31,30,31,30,31,31,30,31,30,31};
    int days = 0 ;
    while (day1 != day2 || month1 != month2 || year1 != year2)
    {
	days++ ;
	day1++ ;
	if (day1 > monthArr[month1-1])
	{
	    day1 = 1 ;
	    month1 ++ ;
	}
	if (month1 > 12)
	{
	    month1 = 1 ;
	    year1++ ;
	}
    }
    return days;
}
float accountTransactions :: getInterest(int AccNo, float Balance)
{
    fstream filename ;
    filename.open("transactions.dat" , ios :: in);
    dispRecords ob;
    filename.seekg(0,ios::beg);
    int day1,month1,year1, month_day;
    while (filename.read((char *) this, sizeof (accountTransactions)))
    {
	if (AccountNumber==AccNo)
        {
	    day1 = dday ;
            month1 = mmonth ;
            year1 = yyear ;
            Balance = ob.getBalance(AccNo);
            break ;
        }
    }
    int day2, month2, year2;
    struct date dateval;
    getdate(&dateval);
    day1 = dateval.da_day ;
    month1 = dateval.da_mon ;
    year1 = dateval.da_year ;
    float interest=0.0;
    int yeardiff=year2-year1;

    if ((year2<year1) || (year2==year1 && month2<month1) || (year2==year1 && month2==month1 && day2<day1))
    {
        return interest;
    }
    month_day = dateDiffer(day1,month1,year1,day2,month2,year2);
    int months;
    if (month_day >= 30)
        months = month_day/30;
    else
        months = month_day/30;

    if (interest == 0 && yeardiff == 1)
        interest =  ((Balance*0.5)/100) * (months);
    else if (yeardiff > 1 && yeardiff < 25 && interest== 0)
	interest=((Balance*0.5)/100) * (months);
    else
	interest = 0;

    filename.close();
    return interest;
}
void accountTransactions::showInterest(void)
{

    char acc[10];
    int tran, AccNo , check ;
    cout<<strupr( " \n important Information: Interest should be generated only\n once in a Year. \n\n\t If you have already generated interest for an Account \n\tplease ignore that Account. \n\t Thank you. \n" );
    cout <<"\n\ Press 0 to go back to previous menu\n" ;
    cout <<"\n To view the transaction of the Account, please enter it: ";
    gets (acc) ;
    tran = atoi(acc);
    AccNo=tran;
    if(AccNo==0)
        return;

    dispRecords ob;
    if(!ob.accountExists(AccNo))
    {
        cout<<"\t\n Account does not exist.\n";
        getch();
        return;
    }
    cout<<"     Press 0 to go back the previous menu:";
    cout<<endl;
    cout<<"\n       -Please enter the Account no. to generate interest-\n";
    cout<<"************************************************";
    int day1, month1, year1;
    struct date dateval;
    getdate(&dateval);
    day1 = dateval.da_day ;
    month1 = dateval.da_mon ;
    year1 = dateval.da_year ;
    cout<<"\n Date: "<<day1<<"/"<<month1<<"/"<<year1<<endl;
    cout<<"Account no. "<<AccNo<<endl;

    char Name[30],Address[60];
    strcpy(Name,ob.getName(AccNo));
    strcpy(Address,ob.getAddress(AccNo));
    float Balance;
    Balance = ob.getBalance(AccNo);
    cout<<"     Customer Name :     "<<Name<<endl;
    cout<<"     Customer Address:   "<<Address<<endl;
    cout<<"     Bank Balance :      "<<Balance;

    float interest;
    interest=getInterest(AccNo,Balance);
    cout<<"\n\tInterest Generated:      "<<interest;
    getch();
    Balance=Balance+interest;
    dispRecords obj;
    obj.updateBalance(AccNo,Balance);
    addDetails(AccNo,day1,month1,year1,'D',"Interest",interest,interest,Balance);
}
void accountTransactions::transaction(void)
{

    char acc[10];
    int tran, AccNo , check ;
    cout <<"\n\ Press 0 to go back to previous menu\n" ;
    cout <<"\n To view the transaction of the Account, please enter it: ";
    gets (acc) ;
    tran = atoi(acc);
    AccNo=tran;
    if(AccNo==0)
	return;

    dispRecords ob;
    if(!ob.accountExists(AccNo))
    {
	cout<<"\t\n Account does not exist.\n";
	getch();
	return;
    }
    cout<<"     Press 0 to go back the previous menu:";
    cout<<endl;
    cout<<"\n       -Make correct entry for the Transaction below-\n";
    cout<<"************************************************";
    int day1, month1, year1;
    struct date dateval;
    getdate(&dateval);
    day1 = dateval.da_day ;
    month1 = dateval.da_mon ;
    year1 = dateval.da_year ;
    cout<<"\n Date: "<<day1<<"/"<<month1<<"/"<<year1<<endl;
    cout<<"Account no. "<<AccNo<<endl;

    char Name[30],Address[60];
    strcpy(Name,ob.getName(AccNo));
    strcpy(Address,ob.getAddress(AccNo));
    float Balance;
    float interest=0.0;
    Balance = ob.getBalance(AccNo);
    cout<<"     Customer Name :     "<<Name;
    cout<<"     Customer Address:   "<<Address;
    cout<<"     Bank Balance :      "<<Balance;
    char Details, Transaction[10] , tm[10] ;
    float amount, amt ;
    do
    {
	cout <<"\n Please enter D for Deposit or W for Withdrawal of Amount : ";
	Details = getche() ;
	if (Details =='0')
	{
	    cout<<"\n\n You have pressed 0 to Exit.";
	    getch ();
	    return;
	}
	Details = toupper(Details) ;
    }while (Details != 'W' && Details != 'D') ;
    do
    {
	cout<<"\n The Transaction type is either Cash or Cheque. \n" ;
	check = 1 ;
	cout <<"     (Cash/Cheque) :";
	gets(Transaction) ;
	strupr(Transaction);
	if(Transaction[0] == '0' )
	{
	    cout<<"\n\n You have pressed 0 to Exit.";
	    getch();
	    return;
	}
	if (strlen(Transaction) < 1 || (strcmp(Transaction,"CASH") && strcmp(Transaction,"CHEQUE") ) )
	{
	    check = 0 ;
	    cout<<"\n The Transaction is invalid. Please enter either Cash or Cheque-. \n";
	    getch() ;
    }
    }while (!check);
    do
    {
	cout <<"\n Please enter the Transaction Amount : \n ";
	check = 1 ;
	cout<<" Amount : Rs. ";
	gets(tm);
	amt = atof(tm) ;
	amount = amt ;
	if (amount < 1 ||  (Details == 'w' && amount > Balance ))
	{
	    check=0;
	    cout<<"\n       Either Amount is not a numeric value or \n It is blank or \n You are trying to withdraw amount more than in the account....\n";
	    getch();
	}
    }while(!check);
    char choice;
    do
    {
	cout<<"\n       Save the changes made in the transactions details ";
	choice=getche();
	choice=toupper(choice);
    }while(choice!='N'||choice!='Y');
    if (choice=='N'||choice=='n')
    {
	cout<<"\n       The Transactions is not saved :";
	getch();
	return;
    }
    if(Details=='D')
    {
	cout<<"\n       The Amount is Deposited in The Bank :\n";
	getch();
	Balance=Balance+amount;
    }
    else
    {
	cout<<"\n       The amount is withdrawn from the Bank :\n";
	getch();
	Balance=Balance-amount;
    }
    ob.updateBalance(AccNo,Balance);
    addDetails(AccNo,day1,month1,year1,Details,Transaction,interest,amount,Balance);
}
void accountTransactions::closeAccount(void)
{
    clrscr;
    char acc[10];
    int tran,AccNo;
    cout<<"     Press 0 to go back to previous Menu :\n";
    cout<<"     Please enter the Account you want to close :\n";
    gets(acc);
    tran=atoi(acc);
    AccNo=tran;

    dispRecords ob;
    if(!ob.accountExists(AccNo))
    {
	cout<<"\t\n Account does not exist.\n";
	cout<<endl<<" Please try again\n";
	getch();
	return;
    }
    cout<<"     Press 0 to go back the previous menu:";
    cout<<endl;
    cout<<"\n       -Close this Account-\n";
    cout<<"************************************************";
    int day1, month1, year1;
    struct date dateval;
    getdate(&dateval);
    day1 = dateval.da_day ;
    month1 = dateval.da_mon ;
    year1 = dateval.da_year ;
    cout<<"\n Date: "<<dayl<<"/"<<monthl<<"/"<<year<<endl;

    char choice;
    ob.display(AccNo)
    do
    {
	cout<<"\n       Are you sure You want to Close this Account? (y/n) ";
	choice=getche();
	choice=toupper(choice);
    }while(choice!='N'||choice!='Y');
    if (choice=='N'||choice=='n')
    {
	cout<<"\n       The Account is Not Closed :";
	getch();
	return;
    }
    ob.deleteAccount(AccNo);
    deleteAccount(AccNo);
    cout<<"\t\n\n Record Deleted Successfully.\n";
    cout<<"     Please continue with the application....\n";
    getch();
}
int login (void)
{
    char name[9],ch;
    char name1[]="banking";
    int i=0;
    char a,b[9],pass[]="tatahill";
    cout<<endl<<endl;
    cout<<"\n\t Login to the Banking Application.\n";
    cout<<"     **********************************\n";
    cout<<"\n\n\tPlease enter Username :        ";
    gets(username);
    cout<<"\n\n\tPlease enter Password :    ";
    flush(stdin);
    do
    {
	ch=getch();
	if(isalnum(ch))
	{
	    b[i]=ch;
	    cout<<"*";
	    i++;
	}
	else if(ch=='\r')
	    b[i]=='\0';
	else if(ch=='\b')
	{
	    i--;
	    cout<<"\b\b";
	}
    }while(ch!='\r');
    b[i]='\0';
    fflush(stdin);

	if((strcmp(b,pass)==0)&&(strcmp(name1,name)))
	{
	    cout<<"\n\n\t   You have entered successfully\n\n";
	    return(1);
	}
	else
	{
	    cout<<"\n\n\t   Incorrect Username or Password.\n";
	    return(0);
	}
}
int main(void)
{

    int val,ch;
    a: val=login();
    if (val==0)
    {
	cout<<"\n\t     Want to try again?\n";
	cout<<"\t       1.TRY AGAIN ";
	cout<<"\n\t     2.EXIT";
	cout<<"\n\n\t   Enter tour choice and press Enter :";
	cin>>ch;
	if(ch==1)
	{

	    goto a;
	}
	else
	    exit(0);
    }
    Menus oj;
    oj.showmenu();
    return 0;
}
