#include<iostream>
#include<string.h>
#include<fstream>
#include<conio.h>
#include<stdlib.h>
#include<dos.h>

using namespace std;
static int p=0;
class atrans
{
	char busn[5],driver[10],arrival[5],depart[5],from[10],to[10],
	seat[8][4][10];
	public:
	void install();
	void allotment();
	void empty();
	void show();
	void available();
	void position(int i);
}bus[5];
void vline(char ch)
{
	for (int i=80;i>0;i--)
	{
	    cout<<ch;
	}
}
void atrans::install()
{
	cout<<"\n Enter bus no: ";
	cin>>bus[p].busn;
	cout<<"\n Enter Driver's name: ";
	cin>>bus[p].driver;
	cout<<"\n Departure time: ";
	cin>>bus[p].depart;
	cout<<"\n Arrival time: ";
	cin>>bus[p].arrival;
	cout<<"\n From: \t\t\t";
	cin>>bus[p].from;
	cout<<"\n To: \t\t\t";
	cin>>bus[p].to;
	bus[p].empty();
	p++;
}
void atrans::allotment()
{
	int seat;
	char number[5];
	top:
	int flag;
	cout<<" Bus no: ";
	cin>>number;
	int n;
	for(n=0;n<=p;n++)
	{
		if(strcmp(bus[n].busn,number)==0)
		break;
	}
	while(n<=p)
	{
		fstream f("sac.dat",ios::in|ios::out);
		cout<<"\n Seat number: ";
		cin>>seat;
		if (seat>32)
		{
			cout<<"\n There are only 32 seats available in this bus.";
		}
		else
		{
			if (strcmp(bus[n].seat[seat/4][(seat%4)-1],"Empty")==0)
			{
				cout<<" Enter passanger's name: ";
				cin>>bus[n].seat[seat/4][(seat%4)-1];
				f<<seat<<endl;
				cout<<" Thank you for reservation in our bus.\n";
				break;
			}
			else
			cout<<" The seat no. is already reserved.\n";
		}
	}
	if (n>p)
	{
		cout<<"\n 1 For Reenter\n 2 For Exit\n";
		cin>>flag;
		if(flag==1)
		{
			cout<<" Enter correct bus no.\n";
			goto top;
		}
		else
		{
		}
	}
}
void atrans::empty()
{
	for(int i=0;i<8;i++)
	{
		for(int j=0;j<4;j++)
		{
			strcpy(bus[p].seat[i][j],"Empty");
		}
	}
}
void atrans::show()
{
	int n;
	char number[5];
	cout<<" Enter bus no: ";
	cin>>number;
	for(n=0;n<=p;n++)
	{
		if(strcmp(bus[n].busn,number)==0)
		break;
	}
	while (n<=p)
	{
		vline('*');
		cout<<"\n Bus no: \t"<<bus[n].busn
		<<"\n Driver: \t"<<bus[n].driver<<"\t Departure time:\t"
		<<bus[n].depart<<" Arrival time:\t"<<bus[n].arrival
		<<"\n From:\t "<<bus[n].from<<"\t\t To: \t\t\t"<<
		bus[n].to<<"\n";
		vline('*');
		bus[0].position(n);
		int a=1;
		for (int i=0;i<8;i++)
		{
			for(int j=0;j<4;j++)
			{
				a++;
				if(strcmp(bus[n].seat[i][j],"Empty")!=0)
				cout<<" The seat no "<<a-1<<" is reserved for "<<bus[n].seat[i][j]<<", ";
			}
		}
		break;
	}
	if(n>p)
		cout<<" Please enter correct bus no."<<endl;
}
void atrans::position(int l)
{
	int s=0,p=0;
	for(int i=0;i<8;i++)
	{
		cout<<"\n";
		for(int j=0;j<4;j++)
		{
			s++;
			if(strcmp(bus[l].seat[i][j],"Empty")==0)
			{
				cout.width(5);
				cout.fill(' ');
				cout<<s<<".";
				cout.width(10);
				cout.fill(' ');
				cout<<bus[l].seat[i][j];
				p++;
			}
			else
			{
				cout.width(5);
				cout.fill(' ');
				cout<<s<<".";
				cout.width(10);
				cout.fill(' ');
				cout<<bus[l].seat[i][j];
			}
		}
	}
	cout<<"\n\n There are "<<p<<" seats empty in Bus No: "<<bus[l].busn;
}
void atrans::available()
{
	for(int n=0;n<p;n++)
	{
		vline('*');
		cout<<"\nBus no: \t"<<bus[n].busn
		<<"\t\tDriver: \t"<<bus[n].driver
		<<"\nFrom: \t"<<bus[n].from
		<<"\t\t\tTo: \t"<<bus[n].to
		<<"\nDeparture Time: \t"<<bus[n].depart
		<<"\tArrival time: \t "<<bus[n].arrival<<"\n";
		vline('*');
		vline('_');
	}
}
void welcome_scrn()
{
int	delay(200);
	while(!kbhit())
	{
		char i;
		if(i>=15)
		{
			i=0;
		}
	}
}
int main()
{
int	clrscr();
	int w;
	welcome_scrn();
	while(1)
	{
		x:
		cout<<" ******************************************************************************"<<endl;
		cout<<" ******* ******* ******* ******* ******* ******* ******* ******* *******"<<endl;
		cout<<"		       * Bus Transportation and Scheduling *"<<endl;


		cout<<" ******* ******* ******* ******* ******* ******* ******* ******* *******"<<endl;
		cout<<" ******************************************************************************"<<endl;
		cout<<" 1. Install a new bus\n 2. Reservation\n 3. Show all seats available in the bus\n 4. Buses Available.\n 6. Exit";
		cout<<"\n Enter your choice:-> ";
		cin>>w;
		switch(w)
		{
			case 1:
			bus[p].install();
			break;
			case 2:
			bus[p].allotment();
			break;
			case 3:
			bus[0].show();
			break;
			case 4:
			bus[0].available();
			break;
			case 6:
			exit(0);
			break;
		}
	}
}
