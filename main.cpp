#include<iostream>
#include<stdio.h>//standard input output
#include<fstream>
#include<conio.h>//console input output
#include<string.h>
#include<windows.h> //for sleep
#include<iomanip>//manipulate the output of C++
#include<time.h>//manipulte date and time info
#define num_of_vaccine 100 

using namespace std;
int password();         //(FUNCTION DECLARATION)
void menu();             //(FUNCTION DECLARATION)
void show();              //(FUNCTION DECLARATION)
class Vaccine                //(CLASS DECLARATION)
{
	int age;                //(VARIABLES DECLARATION) PRIVATE BY DEFAULT
	char gender;
	char name[100];
	char citizenship[100];
	char address[100];
	char mobileNumber[100];
	char vaccine[100];
	public:
		void setData();//1           //(FUNCTION DECLARATION) 
		void addNew();//2
		void showData();//3
		void showList();//4
		void searchData();//6
		void viewVaccine();//5
		void search_by_citizenship();//6.1
    	void search_by_age();//6.2
    	void search_by_gender();//6.4
    	void search_by_vaccine();//6.5
    	void view_all();//6.6
};
//----------------------------------------
void Vaccine::setData()//1               //(FUCNTION DEFINITION) 
{
    cout<<"\n\n\t\t\xB3\xB2=\xB2=\xB2-\xB3 VACCINE MANAGEMENT SYSTEM  \xB3\xB2=\xB2=\xB2-\xB3\n\n"<<endl;
    cout<<"\n\t\t\t**********************************************************\n";
    cout<<"\t\t\t\t ENTER THE DETAILS ";
    cout<<"\n\t\t\t**********************************************************\n\n";
    fflush(stdin);                           //
        cout<<"\n\t\t Enter your Name :-  ";
        gets(name);           
        cout<<"\n\t\t Enter your Aadhar no :-  ";
        gets(citizenship);
        cout<<"\n\t\t Enter your Gender (M|F) :-  ";
        cin>>gender;
        cout<<"\n\t\t Enter your Age:- ";
        cin>>age;
        fflush(stdin);
        cout<<"\n\t\t Enter your Permanent address :-  ";
        gets(address);
        cout<<"\n\t\t Enter your Mobile number :- ";
        gets(mobileNumber);
        cout<<"\n\t\t Enter the vaccine injected :- ";
        gets(vaccine);
}
//------------------------------------------------------
void Vaccine::addNew()//2         //(FUCNTION DEFINITION) 
{
    fstream outin;    
    outin.open("vaccinetrial.txt",ios::app|ios::out);
    setData();
    outin.write((char*)this,sizeof(Vaccine));
    cout<<"YOUR DATA HAS BEEN SUCCESSFULLY INSERTED "<<endl;
    getch();    
    outin.close();
}
//---------------------------------------------
void Vaccine::showData()//3               //(FUNCTION DEFINITON)
{
    cout<<"\n\n\t\t\xB3\xB2=\xB2=\xB2-\xB3 VACCINE MANAGEMENT SYSTEM  \xB3\xB2=\xB2=\xB2-\xB3\n\n"<<endl;
    cout<<"\n\t\t\t**********************************************************\n";
    cout<<"\t\t\t\t DETAILS  ";
    cout<<"\n\t\t\t**********************************************************\n\n";
  	cout<<"\t\t Name is: "<<name<<endl;
   	cout<<"\t\t Aadhar number is: "<<citizenship<<endl;
    cout<<"\t\t Your age is "<<age<<endl;
    cout<<"\t\t Gender is : "<<gender<<endl;
    cout<<"\t\t Address is "<<address<<endl;
    cout<<"\t\t Mobile number is: "<<mobileNumber<<endl;
    cout<<"\n\t\t Vaccine injected : "<<vaccine<<endl;
    
}
//------------------------------------------
void Vaccine::showList()//4              //(FUNCTION DEFINITION)
{
    cout<<"\n";
    cout<<setw(15)<<setiosflags(ios::left)<<name;
    cout<<setw(15)<<citizenship;
    cout<<setw(15)<<age;
    cout<<setw(15)<<gender;
    cout<<setw(15)<<mobileNumber;
    cout<<setw(15)<<address;
    cout<<setw(15)<<vaccine<<endl;
    
    
}
//-----------------------------------------
void Vaccine ::viewVaccine()//5           //(FUNCTION DEFINITION)
{
    ifstream ind;           
    int i=0;
    ind.open("vaccinetrial.txt");
    ind.seekg(0,ios::beg);
    while(ind.read((char*)this,sizeof(Vaccine)))
    {
        i++;
    }
    ind.close();
    int ch;
    int s=num_of_vaccine-i;
       cout<<"\n\n\t\t\xB3\xB2=\xB2=\xB2-\xB3 VACCINE MANAGEMENT SYSTEM  \xB3\xB2=\xB2=\xB2-\xB3\n\n"<<endl;
    cout<<"\n\t\t\t**********************************************************\n";
    cout<<"\t\t\t\tVACCINE STATISTICS";
    cout<<"\n\t\t\t**********************************************************\n\n";
    cout<<"\t\t\t 1. Add more        \t\t\t2.View available \t\t\t3. Back"<<endl;
    cin>>ch;
    int f_var=0;
    fstream file("count.txt",ios::in);
    file>>f_var;
    file.close();
    switch(ch)
    {
    case 1:
        int m;
        cout<<"\t Enter number of vaccines you want to add :"<<endl;
        cin>>m;
        f_var=f_var+m;
        file.open("count.txt",ios::out);
        file.seekg(0);
        file<<f_var;
        cout<<"\t\t Now total number of vaccines are : "<<f_var+s;
        file.close();
        break;
    case 2:
    	file.open("count.txt",ios::in);
        cout<<"\n\nAvailable number of vaccines are : "<<s+f_var;
        file.close();
        break;
    case 3:
        system("cls");
        menu();
    default:
        system("cls");
        cout<<"\nEnter valid option "<<endl;
        menu();
    }
    file.close();
    getch();
}

void Vaccine::searchData()//6
{
    Vaccine item;
    cout<<"\n\n\t\t\xB3\xB2=\xB2=\xB2-\xB3 VACCINE MANAGEMENT SYSTEM  \xB3\xB2=\xB2=\xB2-\xB3\n\n"<<endl;
    cout<<"\n\t\t\t**********************************************************\n";
    cout<<"\t\t\t\tSEARCHING STATISTICS";
    cout<<"\n\t\t\t**********************************************************\n\n";
    cout<<"From which option you want to perform searching "<<endl;
    cout<<"\n\t\t 1. By Citizenship No. \t\t\t 2. By Age "<<endl;
    cout<<"\n\t\t 3. By Gender \t\t\t 4. By Vaccine"<<endl;
    cout<<"\n\t\t 5.  Back to Main Menu "<<endl;
    cout<<"\n\n\t\tEnter your choice : ";
    int ch;
    cin>>ch;
    switch(ch)
    {
    case 1:
        system("cls");
        search_by_citizenship();
        getch();
        break;
    case 2:
        system("cls");
        search_by_age();
        getch();
        break;
    case 3:
        system("cls");
        search_by_gender();
        getch();
        break;
    case 4:
        system("cls");
        search_by_vaccine();
        getch();
        break;
    case 5:
    	system("cls");
        menu();
        break;
    default:
        system("cls");
        cout<<"ENTER VALID OPTION"<<endl;
        menu();
    }
}

void Vaccine::search_by_citizenship()//6.1
{
    ifstream in;
	in.open("vaccinetrial.txt");
	int flag,p =0;
    char cs[100];
     cout<<"\n\n\t\t\xB3\xB2=\xB2=\xB2-\xB3 VACCINE MANAGEMENT SYSTEM  \xB3\xB2=\xB2=\xB2-\xB3\n\n"<<endl;
    cout<<"\n\t\t\t**********************************************************\n";
    cout<<"\t\t\t\t Aadhar SEARCHING ";
    cout<<"\n\t\t\t**********************************************************\n\n";
    cout<<"Enter your Aadhar number "<<endl;
  	fflush(stdin);
    gets(cs);
    show();
    while(!in.eof())
	{
	if(in.read(reinterpret_cast<char*>(this),sizeof(*this))){

        if(strcmp(cs,citizenship)==0)
        {
            showList();
            flag=1;
            p++;
			
        }
		}
    }
    if(flag=0)
    {
    	    cout<<"Aadhar you entered doesnot exist";
	}
	cout<<"\n\n\n\nNO of people vaccinated  by this age: "<<p;
    in.close();

}

void Vaccine::search_by_age()//6.2
{
   ifstream in;
   in.open("vaccinetrial.txt");
    int flag =0;
    int a,p=0;
     cout<<"\n\n\t\t\xB3\xB2=\xB2=\xB2-\xB3 VACCINE MANAGEMENT SYSTEM  \xB3\xB2=\xB2=\xB2-\xB3\n\n"<<endl;
    cout<<"\n\t\t\t**********************************************************\n";
    cout<<"\t\t\t\t AGE SEARCHING ";
    cout<<"\n\t\t\t**********************************************************\n\n";
    cout<<"Enter Age by which you want to search:  "<<endl;
    cin>>a;
    show();
   while(!in.eof())
	{
	if(in.read(reinterpret_cast<char*>(this),sizeof(*this))){

        if(a==this->age)
        {
            showList();
            flag=1;
            p++;
			
            
        }
		}
    }
    if(flag==0)
    {
    cout<<"Age you entered is not found"<<endl;
    }
    cout<<"\n\n\n\nNO of people vaccinated  by this age: "<<p;
    in.close();

}

void Vaccine::search_by_gender()//6.4
{
    ifstream in("vaccinetrial.txt");
    int flag =0;
    char g;
    int p=0;
     cout<<"\n\n\t\t\xB3\xB2=\xB2=\xB2-\xB3 VACCINE MANAGEMENT SYSTEM  \xB3\xB2=\xB2=\xB2-\xB3\n\n"<<endl;
    cout<<"\n\t\t\t**********************************************************\n";
    cout<<"\t\t\t\t GENDER SEARCHING ";
    cout<<"\n\t\t\t**********************************************************\n\n";
    cout<<"Enter gender by which you want to search "<<endl;
    cin>>g;
    show();
    while(!in.eof())
	{
	if(in.read(reinterpret_cast<char*>(this),sizeof(*this))){

        if(g==this->gender)
        {
            showList();
            flag=1;
            p++;
			
        }
		}
    }
    if(flag==0)
    {
    cout<<"SORRY!! No people by this Gender is vaccinated."<<endl;
    }
    cout<<"\n\n\n NO. of people vaccinated by this gender: "<<p<<endl;
    in.close();
}

void Vaccine::search_by_vaccine()//6.5
{
    ifstream in;
	in.open("vaccinetrial.txt");
    int flag =0;
    int p=0;
    char pf[100];
     cout<<"\n\n\t\t\xB3\xB2=\xB2=\xB2-\xB3 VACCINE MANAGEMENT SYSTEM  \xB3\xB2=\xB2=\xB2-\xB3\n\n"<<endl;
    cout<<"\n\t\t\t**********************************************************\n";
    cout<<"\t\t\t\t VACCINE SEARCHING ";
    cout<<"\n\t\t\t**********************************************************\n\n";
    cout<<"Enter Vaccine to search: ";
    fflush(stdin);
    gets(pf);
    show();
   while(!in.eof())
	{
	if(in.read(reinterpret_cast<char*>(this),sizeof(*this))>0){

        if(strcmp(pf,vaccine)==0)
        {
            showList();
            flag=1;
            p++;
            return;   
        }
		}
    }
    if(flag==0)
    {
    cout<<"SORRY!! No people by this vaccine is vaccinated."<<endl;
    }
    cout<<"\n\n\n No of people vaccinated by this vaccine: "<<p<<endl;
    in.close();
}

void show()//a
{
	cout<<"\n\n\n";
    cout<<setw(15)<<setiosflags(ios::left)<<"Name ";
    cout<<setw(15)<<"Aadhar No.";
    cout<<setw(15)<<"Age";
    cout<<setw(15)<<"gender";
    cout<<setw(15)<<"Mobile No.";
    cout<<setw(15)<<"Address";
    cout<<setw(15)<<"Vaccine"<<endl;
}

void Vaccine::view_all(){
			fstream outfile;
			outfile.open("vaccinetrial.txt",ios::binary|ios::in);
			if(!outfile){
				cout<<"File doesnot exist";
			}
			cout<<"\n\n\t\t\xB3\xB2=\xB2=\xB2-\xB3 VACCINE MANAGEMENT SYSTEM  \xB3\xB2=\xB2=\xB2-\xB3\n\n"<<endl;
    		cout<<"\n\t\t\t**********************************************************\n";
    		cout<<"\t\t\t\t\tALL DATA ";
    		cout<<"\n\t\t\t**********************************************************\n\n";
			show();
			while(!outfile.eof()){
				if(outfile.read(reinterpret_cast<char*>(this),sizeof(*this))>0){
					showList();
				}
				
			}
			getch();
			outfile.close();
}
int password()//b
{
    char cname[30],pass[20];
    int ch, i=0,cap=0,capt=0;
    cout<<"\n\n\n\n\t\t\t\t\tUSER NAME:  ";
    fflush(stdin);
    gets(cname);
    cout<<"\n\t\t\t\t\tPASSWORD:    ";
    while((ch=getch()) != 13)
    {
        cout<<"*";
        pass[i]=ch;
        i++;
    }
    pass[i] = '\0';
    srand(time(0));
    cap=rand();
    cout<<"\n\n\t\t\t\t\tCAPTURE:-> "<<cap<<endl;
    cout<<" Please enter the valid capture :-   ";
    cin>>capt;
    if( (strcmp(cname,"vrms")==0) && (strcmp(pass,"b3")==0) && cap==capt)
        return 1;
    else
        return 0;
}

void menu()//c
{
    system("cls");
    cout<<"\n\n\t\t\t\xB3\xB2=\xB2=\xB2-\xB3 VACCINE MANAGEMENT SYSTEM  \xB3\xB2=\xB2=\xB2-\xB3\n\n"<<endl;
    cout<<"\n\t\t\t**********************************************************\n";
    cout<<"\t\t\t\t WELCOME TO THE MAIN MENU";
    cout<<"\n\t\t\t**********************************************************\n";
    cout<<"\n\t\t1: Add NEW Record\t\t\t 2: View VACCINE DATA"<<endl;
    cout<<"\n\t\t3: Search   \t\t\t\t 4: View All Data"<<endl;
    cout<<"\n\t\t5: Exit"<<endl;
}

int main()
 {
     Vaccine obj;
     int k=3;
     int num_vac;
    cout<<"\n\n\t\t\xB3\xB2=\xB2=\xB2-\xB3 VACCINE MANAGEMENT SYSTEM  \xB3\xB2=\xB2=\xB2-\xB3\n\n"<<endl;

    cout<<"\t\n\n Press any key to continue.............  "<<endl;
    getch();
    B:
    system("cls");
    cout<<"  \n\n\t\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2   WELCOME TO LOGIN PAGE   \xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
    cout<<"\n\n\t\t\t\t**********************************************************";
    cout<<"\n\t\t\t\t\tEnter User name and Password\n";
    cout<<"\t\t\t\t**********************************************************\n";
    while(k>=1)
    {
    int c = password();
    if(c==1)
        break;
    else
        cout<<"\n\n\t\t Wrong Password Or User Name \n\n\t\t You Can try Only "<<k-1<<" times more";
    k--;
    if(k<1)
        {
            for(int i=59; i>=0; i--)
            {
              system("cls");
              cout<<"\n\n\n\n\n\n\n\n\t\t\t\t\tYOU ARE BLOCKED FOR 1 MINUTE!!";
              cout<<"\n\n\n\n\n\n\t\t\t\t\tTRY AFTER "<<i<<" SECONDS.....";
              Sleep(1000);
            }
              k=3;
              goto B;
        }
    }
      int ch;
      do{
            cout<<"\n\n\t\t\xB3\xB2=\xB2=\xB2-\xB3 VACCINE MANAGEMENT SYSTEM  \xB3\xB2=\xB2=\xB2-\xB3\n\n"<<endl;
            
            menu();
            cout<<"\n\t\n\tChoose according to your need : ";
            cin>>ch;
             Vaccine v1;
      switch(ch)
       {
         case 1: system("cls");
	             obj.addNew();
                 break;
         case 2: system("cls");
       	   	  	obj.viewVaccine();
                 break;
         case 3:system("cls");
            	obj.searchData();
                break;
          case 4:system("cls");
            	obj.view_all();
                break;
        
         case 5:  system("cls");
                    exit(0);
         default: system("cls");
                  cout<<"\n\n\n\n\n\n\n\n\t\t\t\t\t\tTHANK YOU!!";
                  cout<<"\n\n\t\t\t\t\t**HAVE A NICE DAY*";
                  Sleep(3000);
                  exit(0);
       }
      }while(ch!=0);

      return 0;
}

