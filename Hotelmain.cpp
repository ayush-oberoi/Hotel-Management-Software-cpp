#include<iostream>
#include<fstream>
#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<stdlib.h>
#include<iomanip>
#include<ncurses.h>

using namespace std;

void write_cus();
void disp_spcus(int);
void modify_cus(int);
void delete_cus(int);
void disp_all();
void addsubdue(int);
int admin();
int admin2();
void intro();
void intro1();
int checkdue(int);
void userorder(int);
void cleardue(int);

class Hotel
{
	char cusname[20],cusadd[50],ac;
	char single,ph[20],rpref;
	int per,roomno,due,base,k,due1;
	char rpr[20],nac[20],sd[20];

public:
        Hotel()
	{
		base=600;
		k=1;
		due=0;
		due1=0;
	}
	void getcus();
	void dispcus();
	void adddue(int);
	void subdue(int);
	void modcus();
	void report();
	int retroomno();
	int retdue();
	int retdue1();
	int retbase();
	void cldue();
};

void Hotel::getcus()
{
	cout<<"\033[12;64fName                : ";
	cout<<"\033[14;64fAddress             : ";
	cout<<"\033[16;64fPhone number        : ";
	cout<<"\033[18;64fRoom Preference     : ";
	cout<<"\033[19;65fa.CLASSIC.";
	cout<<"\033[20;65fb.SEMIDELUX.";
	cout<<"\033[21;65fc.DELUX.";
	cout<<"\033[24;64fAc/NonAc(A/N)       : ";
	cout<<"\033[27;64fSingle/Double(S/D)  : ";
	cout<<"\033[30;64fNo of persons       : ";
	cout<<"\033[10;64fRoom no              : ";
	cout<<"\033[10;88f";
	cin>>roomno;
	cout<<"\033[12;88f";
	cin>>cusname;
	cout<<"\033[14;88f";
	cin>>cusadd;
        cout<<"\033[16;88f";
	cin>>ph;
        cout<<"\033[18;88f";
	cin>>rpref;
        cout<<"\033[24;88f";
	cin>>ac;
        cout<<"\033[27;88f";
	cin>>single;
	cout<<"\033[30;88f";
	cin>>per;
	cout<<"\033[32;88f";
	due1=0;
	if(rpref=='a')
	   base=base+100;
	if(rpref=='b')
	   base=base+500;
	if(rpref=='c')
	   base=base+1000;

	if(ac=='A' || ac=='a')
		base=base+500;
	if(ac=='N' || ac=='n')
		base=base+250;
	if(single=='S' || single=='s')
		base=base+750;
	if(single=='D' || single=='d')
		base=base+1500;
	if((single=='S' || single=='s') && per==2)
		base=base+200;
	if((single=='D' || single=='d') && per==4)
		base=base+400;

	due=base+due1;


}

void Hotel::dispcus()
{
	cout<<"\033[15;64fName: ";
        cout<<"\033[16;64fAddress: ";
        cout<<"\033[17;64fPhone number: ";
        cout<<"\033[18;64fRoom Preference : ";
        cout<<"\033[19;64fAc/NonAc(A/N)  : ";
        cout<<"\033[20;64fSingle/Double(S/D)  : ";
        cout<<"\033[21;64fNo of persons : ";
	cout<<"\033[14;64fRoom no : ";
	cout<<"\033[14;88f";
	cout<<roomno;
        cout<<"\033[15;88f";
        cout<<cusname;
        cout<<"\033[16;88f";
        cout<<cusadd;
        cout<<"\033[17;88f";
        cout<<ph;
        cout<<"\033[18;88f";
				if(rpref=='a')
        cout<<"Classic";
				if(rpref=='b')
	cout<<"Semi Delux";
				if(rpref=='c')
	cout<<"Delux";
        cout<<"\033[19;88f";
				if(ac=='A' || ac=='a')
        cout<<"A/c";
				if(ac=='N' || ac=='n')
	cout<<"NON A/c";
        cout<<"\033[20;88f";
				if(single=='S' || single=='s')
        cout<<"Single";
				if(single=='D' || single=='d')
	cout<<"Double";
        cout<<"\033[21;88f";
        cout<<per;
}

void Hotel::modcus()
{
	cout<<"\033[15;60fRoom no.                    : ";
        cout<<"\033[17;60fNew Room Preference         : ";
        cout<<"\033[18;61fa.Classic.";
        cout<<"\033[19;61fb.Semi Delux.";
        cout<<"\033[20;61fc.Delux.";
        cout<<"\033[22;60fAc/NonAc(A/N)               : ";
        cout<<"\033[24;60fSingle/Double(S/D)          : ";
        cout<<"\033[26;60fNo of persons               : ";
        cout<<"\033[15;90f";
	cin>>roomno;
        cout<<"\033[17;90f";
        cin>>rpref;
        cout<<"\033[22;90f";
        cin>>ac;
        cout<<"\033[24;90f";
        cin>>single;
        cout<<"\033[26;90f";
        cin>>per;
	base=0;
	 if(rpref=='a')
           base=base+100;
        if(rpref=='b')
           base=base+500;
        if(rpref=='c')
           base=base+1000;

        if(ac=='A' || ac=='a')
                base=base+500;
        if(ac=='N' || ac=='n')
                base=base+250;
        if(single=='S' || single=='s')
                base=base+750;
        if(single=='D' || single=='d')
                base=base+1500;

        due=base+due1;

}

void Hotel::report()
{
	if(rpref=='a' || rpref=='A')
	strcpy(rpr,"Classic");
	if(rpref=='b' || rpref=='B')
	strcpy(rpr,"Semi Delux");
	if(rpref=='c' || rpref=='C')
	strcpy(rpr,"Delux");
	if(ac=='A' ||ac=='a')
	strcpy(nac,"A/C");
	if(ac=='N' || ac=='n')
	strcpy(nac,"Non A/C");
	if(single=='s' || single=='S')
	strcpy(sd,"Single");
	if(single=='d' || single=='D')
	strcpy(sd,"Double");
	cout<<setw(8)<<roomno<<setw(22)<<cusname<<setw(18)<<rpr<<setw(18)<<nac<<setw(18)<<sd<<"\n";
}

int Hotel::retroomno()
{
	return roomno;
}

int Hotel::retdue()
{
	return due;
}

int Hotel::retdue1()
{
	return due1;
}

int Hotel::retbase()
{
	return base;
}

void Hotel::adddue(int x)
{
	due1=due1+x;
}

void Hotel::subdue(int x)
{
	due=due+x;
}

void Hotel::cldue()
{
	base=0;
	due1=0;
	due=0;
}

void write_cus();
void disp_spcus(int);
void modify_cus(int);
void delete_cus(int);
void disp_all();
void addsubdue();
int admin();
int admin2();
void intro();
void intro1();

int main()
{
      int choice,a=1;
	int d;
	intro();

      do
     {

      cout<<"\033[10;64fLogin             ";
      cout<<"\033[15;64f1.Manager Login                     ";
      cout<<"\033[17;64f2.Customer Login                         ";
      cout<<"\033[19;64f3.Exit.";
      cout<<"\033[25;63f                                       ";
      cout<<"\033[25;63fChoice : ";
      cin>>choice;
      switch(choice)
      {
          case 1:
                    {

			a=admin();


			system("clear");
			intro1();
			Hotel h1;
			int ch,k=1;
			char ans;
			int rnum,l=0;
			while(1)
			{
			system("clear");
			intro1();
			cout<<"\033[10;64fManager Panel";
			cout<<"\033[14;62f1.Check In For Customer";
			cout<<"\033[16;62f2.Display Details Of Customer";
			cout<<"\033[18;62f3.Changing the room";
			cout<<"\033[20;62f4.Display All Customers in The hotel";
			cout<<"\033[22;62f5.Customer Dues";
			cout<<"\033[24;62f6.Room Check Out ";
			cout<<"\033[26;62f7.Main Login Page";
			cout<<"\033[28;62f8.Exit The Software";
			cout<<"\033[30;62fEnter your choice: ";
			cin>>ch;

			system("clear");
			intro1();
			switch(ch)
			{
				case 1:
					write_cus();
					cin.ignore();
					cin.ignore();
					break;
				case 2:
					cout<<"\033[10;30fEnter the Room no.: ";
					cin>>rnum;
					cout<<"\033[10;30f                                  ";
					disp_spcus(rnum);
					cin.ignore();
					cin.ignore();
					break;
				case 3:
					cout<<"\033[10;30fEnter the Room no.: ";
					cin>>rnum;
					modify_cus(rnum);
					cin.ignore();
					cin.ignore();
					break;
				case 4:
					cout<<"\033[3;65fRoom Database";
					disp_all();
					cin.ignore();
					cin.ignore();
					break;
				case 5:
					cout<<"\033[10;30fEnter The Room no.: ";
					cin>>rnum;
					addsubdue(rnum);
					cin.ignore();
					cin.ignore();
					break;
				case 6:
					cout<<"\033[10;30fEnter The Room No.: ";
					cin>>rnum;
					d=checkdue(rnum);
					if(d==0)
					delete_cus(rnum);

					else
					{
						system("clear");
						intro1();
						cout<<"\033[20;45fUncleared Dues of Rs."<<d;
						cout<<"\033[21;45fCannot checkout";
						cout<<"\033[22;45fPlease Clear The Dues Through User Login";
					}
					cin.ignore();
					cin.ignore();
					break;
				case 7:
					a=1;
					break;
				case 8:
					system("clear");
					intro1();
					cout<<"\033[20;60fExiting the software                               ";
		                	cout<<"\033[22;60f                                                   ";
                		        cout<<"\033[23;60f                                                   ";
                     			cout<<"\033[23;60fPlease wait";
                     			cout.flush();
                     			for(int i=0;i<7;++i)
                     			{
                          			cout<<". ";
                          			sleep(1);
                          			cout.flush();
                     			}
                     			system("clear");
                     			exit(0);


				default:
					cout<<"\033[10;30fInvalid Input..";
			}
				if(ch==7)
				{
					break;
				}
			}

			}

		     	break;
          case 2:
                     system("clear");
 			 intro1();
  		     int rnum,choice;
  		     while(1)
		    {
			system("clear");
		        intro1();
     			cout<<"\033[8;65fUser's Personal Database";
     			cout<<"\033[14;64f1.Order Food";
     			cout<<"\033[16;64f2.Clear your Dues.";
     			cout<<"\033[18;64f3.Main Login Page.";
     			cout<<"\033[20;64f4.Exit.";
     			cout<<"\033[25;64fEnter Your Choice: ";
     			cin>>choice;
     			system("clear");
     			intro1();
     			switch(choice)
			{

	 			/* case 1:
		    		usertype();
		    		cin.ignore();
		    		cin.ignore();
		    		break;*/
	  			case 1:
		    			cout<<"\033[15;64fEnter Your Room No.: ";
		    			cin>>rnum;
					system("clear");
					intro1();
		    			userorder(rnum);
		    			cin.ignore();
		    			cin.ignore();
		    			break;
	  			case 2:
		   			cout<<"\033[15;64fEnter Your Room No. : ";
		   			cin>>rnum;
					system("clear");
					intro1();
		    			cleardue(rnum);
		    			cin.ignore();
		    			break;
	  			case 3:
		  			break;
	  			case 4:
			 		system("clear");
                         		intro1();
                         		cout<<"\033[20;60fExiting the software                               ";
                        	 	cout<<"\033[22;60f                                                   ";
                         		cout<<"\033[23;60f                                                   ";
                         		cout<<"\033[23;60fPlease wait";
                         		cout.flush();
                         		for(int i=0;i<7;++i)
                         		{
                             			cout<<". ";
                             			sleep(1);
                             			cout.flush();
                         		}
                         		system("clear");
                         		exit(0);
			 		break;

	  			default:
					cout<<"\033[27;64fInvalid Input";
			}

			if(choice==3)
					break;

			}
                     			break;
          		case 3:

                     		cout<<"\033[30;60fExiting the software                               ";
                     		cout<<"\033[32;60f                                                   ";
                     		cout<<"\033[33;60f                                                   ";
                     		cout<<"\033[33;60fPlease wait";
                     		cout.flush();
                     		for(int i=0;i<7;++i)
                     		{
                          		cout<<". ";
                          		sleep(1);
                          		cout.flush();
                     		}
                     		system("clear");
                     		exit(0);

	  		default:
                    		cout<<"Invalid choice";
      		}
    }while(a==1);

      system("clear");
	cout<<"\033[20;60fBYE BYE...";
      cout.flush();
      sleep(3);
      system("clear");
    cin.ignore();
    cin.ignore();
}




int admin()
{
  char user[20],pass[20],u1[20]="Ayush",u2[20]="Akshay",p1[20]="Ayush05",p2[20]="AK47";
  int k=1,i=2,l=0;
  char ans,ch;
  while(k<4)
  {
    if(k>1)
    {
      cout<<"\033[15;75f                     ";
    cout<<"\033[17;75f                        ";
    cout<<"\033[30;60f                                                           ";
    cout<<"\033[32;60f                                                            ";
    }
    cout<<"\033[10;64f";
    cout<<"Admin Panel";
    cout<<"\033[19;64f         ";
    cout<<"\033[25;63fAccess \033[33mRestricted\033[0m";
    cout<<"\033[1m";
    cout<<"\033[15;64fUsername : ";
    cout<<"\033[17;64fPassword :    ";
    cout<<"\033[15;75f                                ";
    cout<<"\033[15;75f";
    cin>>user;
    cout<<"\033[17;75f                                 ";
    cout<<"\033[17;75f";
    cin>>pass;
    if(((strcmp(user,u1)==0) && (strcmp(pass,p1)==0)) || ((strcmp(user,u2)==0) && (strcmp(pass,p2)==0)))
    {
      cout<<"\033[15;74f \033[32mMatches  ";
      cout<<"\033[17;74f \033[32mMatches  ";
      cout<<"\033[25;70f \033[32mGranted  \033[0m";
      cout<<"\033[1m";
      cout<<"\033[30;60fLogging You In                                          ";
      cout<<"\033[32;60f                                                         ";
      cout<<"\033[33;60fPlease Wait";
      cout.flush();
      for(int i=0;i<6;++i)
      {
             cout<<". ";
             sleep(1);
             cout.flush();
      }
     cout<<"\033[30;60f                      ";
     cout<<"\033[33;60f                       ";
     l=0;
      break;
    }

    else
    {
      cout<<"\033[15;74f \033[31mError    ";
      cout<<"\033[17;74f \033[31mError    ";
      cout<<"\033[25;70f \033[31mDenied   \033[0m";
      cout<<"\033[1m";

      if(i==2)
	{
        cout<<"\033[30;60fYou have "<<i<<" More Attempts left";
        i--;
        }
      else if(i==1)
        {
        cout<<"\033[30;60fYou have "<<i<<" More Attempt left..";
        i--;
        }
      else
      {
        cout<<"\033[32;60f                                          ";
      cout<<"\033[30;60fDo you want to go to Main Login Page? ";
      cin>>ch;
      cout<<"\033[30;60f                                            ";
      if(ch=='y' || ch=='Y')
      {
        l=1;
        break;
      }
      else
      {

                     cout<<"\033[30;60fExiting Software                           ";
                     cout<<"\033[32;60f                                                   ";
                     cout<<"\033[33;60fPlease wait";
                     cout.flush();
                     for(int i=0;i<7;++i)
                     {
                          cout<<". ";
                          sleep(1);
                          cout.flush();
                     }
                     system("clear");
                     exit(0);
     }
    }
    }
    cout<<"\033[32;60fDo you want to Enter Details again? ";
    cin>>ans;
    if(ans=='y' || ans=='Y')
    k++;
    else
    {
      cout<<"\033[32;60f                                          ";
      cout<<"\033[30;60fDo you want to go to Main Login Page? ";
      cin>>ch;
      cout<<"\033[30;60f                                            ";
      if(ch=='y' || ch=='Y')
      { l=1;
        break;
      }
      else
        {            cout<<"\033[30;60fExiting Software                           ";
                     cout<<"\033[32;60f                                                   ";
                     cout<<"\033[33;60fPlease wait";
                     cout.flush();
                     for(int i=0;i<7;++i)
                     {
                          cout<<". ";
                          sleep(1);
                          cout.flush();
                     }
                     system("clear");
                     exit(0);
	}
    }
   }
 return (l);
}


void write_cus()
{
	Hotel h;
	ofstream outFile;
	outFile.open("hotel.dat",ios::binary|ios::app);
	h.getcus();
	outFile.write((char *) &h, sizeof(Hotel));
	system("clear");
	intro1();
	cout<<"\033[20;65fYou Have Successfully Booked The Room";
	cout<<"\033[23;65fYour Tariff For 24hrs is: "<<h.retbase();
}

void disp_spcus(int n)
{
	Hotel h;
	int flag=0;
	ifstream inFile;
	inFile.open("hotel.dat",ios::binary);
	if(!inFile)
	{

		cout<<"File could not be open !! Press any Key...";

		return;

	}



    while(inFile.read((char *) &h, sizeof(Hotel)))

	{
		if(h.retroomno()==n)
		{
			cout<<"\033[12;64fCustomer Details";
			h.dispcus();
			flag=1;
		}
	}

    inFile.close();

	if(flag==0)

		cout<<"\n\nRoom Is Vacant";
}


void disp_all()
{
	Hotel h;
	ifstream inFile;
	inFile.open("hotel.dat",ios::binary);
	if(!inFile)
	{
		cout<<"File Could not Be open !! Press any key ";
		return;
	}

	cout<<"\n\n\n\n\n\n\n\t\t\t\t\t\t\tAll Customer Details";
	cout<<"\n\n\n\t\t\t";
	cout<<setw(10)<<"Roomno."<<" "<<setw(19)<<"Name"<<" "<<setw(16)<<"Room pref"<<" "<<setw(18)<<"A/c/Non-A/c"<<" "<<setw(18)<<"Sing/Double"<<" "<<"\n";
	while(inFile.read((char *) &h,sizeof(Hotel)))
	{
		cout<<"\n\t\t\t";
		h.report();
	}
	inFile.close();
}



void modify_cus(int n)

{
	system("clear");
	intro1();
	int found=0;
	Hotel h;
	fstream File;
	File.open("hotel.dat",ios::binary|ios::in|ios::out);
	if(!File)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}

    while(File.read((char *) &h, sizeof(Hotel)) && found==0)
	{
		if(h.retroomno()==n)
		{
			cout<<"\033[9;56fEnter The New Details of customer.."<<endl;
			h.modcus();
			long pos=(-1)*sizeof(Hotel);
			File.seekp(pos,ios::cur);
			File.write((char *) &h, sizeof(Hotel));
			system("clear");
			intro1();
			cout<<"\033[20;60fRoom Changed Successfully";
			cout<<"\033[22;60fYour Updated Tariff for 24 hrs is: "<<h.retbase();
			found=1;
		}
	}

	File.close();
	if(found==0)
		cout<<"\n\n Record Not Found ";
}


int checkdue(int n)
{
	Hotel h;
	int d;
	ifstream f;
	f.open("hotel.dat",ios::binary);
	while(f.read((char *) &h, sizeof(Hotel)))
	{
		if(h.retroomno()==n)
			d=h.retdue();
	}
	f.close();
	return d;
}
void delete_cus(int n)

{
	Hotel h;
	int found=0,flag=0;
	ifstream inFile;
	ofstream outFile;
	inFile.open("hotel.dat",ios::binary);
	if(!inFile)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}
	outFile.open("Temp.dat",ios::binary);
	inFile.seekg(0,ios::beg);
	while(inFile.read((char *) &h, sizeof(Hotel)))
	{
		if(h.retroomno()!=n)
		{
			outFile.write((char *) &h, sizeof(Hotel));
		}
		else
		{
			flag=1;
		}
	}

	if(flag==1)
	{
			inFile.close();
			outFile.close();
			remove("hotel.dat");
			rename("Temp.dat","hotel.dat");
			system("clear");
			intro1();
			cout<<"\033[25;30fAll Dues Are Clear.Check Out Successfull...";
			found=1;
	}

	if(found==0)
	{
		cout<<"\n\n\n\t\t\tNo record found";
	}

}



void addsubdue(int n)
{
	Hotel h;
	int found=0;
	ifstream Fin;
	Fin.open("hotel.dat",ios::binary);
	while(Fin.read((char *) &h, sizeof(Hotel)))
		{
			if(h.retroomno()==n)
			{
				system("clear");
				intro1();
				cout<<"\033[25;60fBase Fare : ";
				cout<<h.retbase();
				cout<<"\033[27;60fFood Order : ";
				cout<<h.retdue1();
				cout<<"\033[30;60fTotal Due on customer : ";
				cout<<h.retdue();
				found=1;
			}
		}
	Fin.close();
	if(found==0)
		{	system("clear");
			intro1();
			cout<<"\033[25;60fRoom Is Vacant";\
		}
}




void cleardue(int n)
{
	Hotel h;
        int found=0;
        fstream Fin;
        Fin.open("hotel.dat",ios::binary|ios::in|ios::out);
        while(Fin.read((char *) &h, sizeof(Hotel)))
                {
                        if(h.retroomno()==n)
                        {
                                system("clear");
                                intro1();
                                cout<<"\033[15;60fBase Fare : ";
                                cout<<h.retbase();
                                cout<<"\033[17;60fFood Order : ";
                                cout<<h.retdue1();
                                cout<<"\033[20;60fTotal Due : ";
                                cout<<h.retdue();
				cout<<"\033[24;60fPress Enter Key To Pay Your Due";
				cin.ignore();
				cin.ignore();
				h.cldue();
                                found=1;
				long pos=(-1)*sizeof(Hotel);
       				Fin.seekp(pos,ios::cur);
       				Fin.write((char *) &h, sizeof(Hotel));

                        }
                }
        Fin.close();
        if(found==0)
                {       system("clear");
                        intro1();
                        cout<<"\033[25;60fRoom Is Vacant";
                }
	if(found==1)
		{
			system("clear");
                        intro1();
                        cout<<"\033[25;60fDues are Cleared";
		}
}





void intro()
{
      system("clear");
      cout<<"\033[1m";
      cout<<"\033[3;65f";
      cout<<"Welcome to";
      cout.flush();
      sleep(2);
      cout<<"\033[4;60f";
      cout<<"\033[36m AA Group of Hotels\033[0m";
      cout<<"\033[1m";
      cout.flush();
      sleep(2);
      cout<<"\033[45;35f";
      cout<<"^A 7star Hotel with a venture in partnership of Mr.Ayush Oberoi and Mr.Akshay Bawane";
      cout.flush();
      sleep(2);
}
void intro1()
{
      system("clear");
      cout<<"\033[1m";
      cout<<"\033[3;65f";
      cout<<"Welcome to";
      cout<<"\033[4;60f";
      cout<<"\033[36m AA Group of Hotels\033[0m";
      cout<<"\033[1m";
      cout<<"\033[45;35f";
      cout<<"^A 7star Hotel with a venture in partnership of Mr.Ayush Oberoi and Mr.Akshay Bawane";
}


void userorder(int n)
{
	Hotel h;
	fstream File;
	char ans,a1,a2,a3;
  	int choice,c1,c2,c3,found=0,sum=0;
	File.open("hotel.dat",ios::binary|ios::in|ios::out);
	while(File.read((char *) &h,sizeof(Hotel)))
	{
		if(h.retroomno()==n)
		{
		while(1){
				system("clear");
				intro1();
       			cout<<"\033[10;65fYour Menu Card";
       			cout<<"\033[14;64f1.Starters.";
       			cout<<"\033[16;64f2.Main Course.";
       			cout<<"\033[18;64f3.Desert.";
       			cout<<"\033[20;64f4.Back";
       			cout<<"\033[24;64fEnter your choice: ";
       			cin>>choice;
       			system("clear");
			intro1();

       			switch(choice)
       			{
           		case 1:
                  		do{
                   			system("clear");
					intro1();
				cout<<"\033[14;64f1.Paneer  Tikka   -     Rs.150";
                   		cout<<"\033[16;64f2.Malai   Tikka   -     Rs.160";
                   		cout<<"\033[18;64f3.Chicken Tikka   -     Rs.220";
                   		cout<<"\033[20;64f4.Tandoori Chi.   -     Rs.200";
                   		cout<<"\033[22;64f5.H Bhara Kabab   -     Rs.155";
                   		cout<<"\033[24;64f6.Chi. lollipop   -     Rs.170";
                   		cout<<"\033[27;64fEnter your choice: ";
                   		cin>>c1;
                   		if(c1==1)
                     		sum+=150;
                   		if(c1==2)
                     		sum+=160;
                   		if(c1==3)
                     		sum+=220;
                   		if(c1==4)
                    	 	sum+=200;
                   		if(c1==5)
                     		sum+=155;
                   		if(c1==6)
                     		sum+=170;
                  		cout<<"\033[30;64fDo You Want to Enter More Starters??\n";
                  		cin>>a1;
                		}while(a1=='y' || a1=='Y');
                		break;
          case 2:
                 do{
                   		system("clear");
				intro1();
		   cout<<"\033[14;64f1.Paneer Butter Masala       -       Rs.230";
                   cout<<"\033[16;64f2.Paneer Tikka Masala        -       Rs.240";
                   cout<<"\033[18;64f3.Butter Chiken              -       Rs.300";
                   cout<<"\033[20;64f4.Chiken Tikka  Masala       -       Rs.310";
                   cout<<"\033[22;64f5.Chiken Mughlai             -       Rs.320";
                   cout<<"\033[24;64f6.Paneer Kadai               -       Rs.250";
                   cout<<"\033[27;64fEnter your choice :";
                   cin>>c2;
                   if(c2==1)
                   sum+=230;
                   if(c2==2)
                   sum+=240;
                   if(c2==3)
                   sum+=300;
                   if(c2==4)
                   sum+=310;
                   if(c2==5)
                   sum+=320;
                   if(c2==6)
                   sum+=250;
                  cout<<"\033[30;64fDo you Want to Enter More Main Course??";
                  cin>>a2;
                }while(a2=='y' || a2=='Y');
                break;
            case 3:
                   do{
                     	system("clear");
			intro1();
		     cout<<"\033[14;64f1.Cold drinks       -        Rs25";
                     cout<<"\033[16;64f2.Ice Creams        -        Rs50";
                     cout<<"\033[18;64f3.Shakes            -        Rs100";
                     cout<<"\033[20;64f4.Sweets            -        Rs150";
                     cout<<"\033[24;64fEnter your choice";
                     cin>>c3;
                     if(c3==1)
                      sum+=25;
                     if(c3==2)
                      sum+=50;
                     if(c3==3)
                      sum+=100;
                     if(c3==4)
                      sum+=150;
                    cout<<"\033[30;64fDo you want to Enter More Desert??";
                    cin>>a3;
                  }while(a3=='y' || a3=='Y');
                  break;
		case 4:
			break;
		case 5:
			system("clear");
			intro1();
			cout<<"\033[20;64fYour order have been successfully placed";
			cin.ignore();
			cin.ignore();
			break;
           default:
                   cout<<"\033[30;64fInvalid Choice!!";
       }

	if(choice==4 || choice==5)
		break;
	}
	found=1;
	h.adddue(sum);
	h.subdue(h.retdue1());
	long pos=(-1)*sizeof(Hotel);
	File.seekp(pos,ios::cur);
	File.write((char *) &h, sizeof(Hotel));
}
}
File.close();

if(found==0)
{
	system("clear");
	intro1();
	cout<<"\033[25;60fRoom is Vacant";
}
}
