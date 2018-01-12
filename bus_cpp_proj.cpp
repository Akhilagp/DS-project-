#include<iostream>
#include<string>
#include<list>
#include<iomanip>
#include<fstream>
#include<queue>
#include<list>
using namespace std;
list<string> q;
static int p=0;
class person
{
	string name;
	int age;
	char gender;
	public:
	person()
	{
	}
	virtual 	void get()
	{
		cout<<"\n enter the details of the passenger\n";
		cout<<"\n name	:";
		cin>>name;
		cout<<"\n age	:";
		cin>>age;
		cout<<"\n gender:";
		cin>>gender;
	}
	string  getName()
	{
		return name;
	}
	int getAge()
	{
		return age;
	}
	char getGender()
	{
		return gender;
	}
};
class b:public person
{
	string bus_num;
	string from;
	string to;
	string departure;
	string driver_name;
	int kms;
	float rate;
	public:
	b()
	{
	}
	void print();
	void install();
	void show();
	void avail();
	void book();
	void vline(char ch)
	{
		for (int i=20;i>0;i--)
		{
			cout<<ch;
		}
		cout<<"\n";
	}
}bus[10];
void b::print()
{
	for(int n=0;n<p;n++)
	{
		vline('*');
		cout<<"\nBus no: \t"<<bus[n].bus_num<<"\nDriver: \t"<<bus[n].driver_name
			<<"\tDeparture Time: \t"<<bus[n].departure<<"\nFrom: \t\t"<<bus[n].from<<"\t\tTo: \t\t\t"
			<<bus[n].to<<"\n";
		vline('*');
		string fname,content;
		ifstream f;
		fname=bus[n].bus_num + ".txt";
		f.open(fname.c_str(),ios::in);
		if(!f.is_open())
		{
			cout<<"\n No passengers entry in this bus\n";
			continue;
		}
		else
		{		while(!f.eof())
			{
				getline(f,content);
				cout<<content<<endl;
			}
			f.close();
		}
	}
}
void b:: install()
{
	cout<<"Enter bus no: ";
	cin>>bus[p].bus_num;
	cout<<"\nEnter Driver's name: ";
	cin>>bus[p].driver_name;
	cout<<"\nDeparture: ";
	cin>>bus[p].departure;
	cout<<"\nFrom: \t\t\t";
	cin>>bus[p].from;
	cout<<"\nTo: \t\t\t";
	cin>>bus[p].to;
	cout<<"\n Enter the distance between source and destination:\t\t\t";
	cin>>bus[p].kms;
	cout<<"\n Enter the price of a ticket:\t\t\t";
	cin>>bus[p].rate;
	p++;
}
void b::show()
{
	int n;
	ifstream f;
	string fname,content,number;
top1:
	cout<<"\nEnter bus no: ";
	cin>>number;
	for(n=0;n<=p;n++)
	{
		if(number==bus[n].bus_num)
			break;
	}
	if(n>p)
	{
		cout<<"\nIncorrect bus no: ";
		goto top1;
	}
	else
	{
		vline('*');
		cout<<"\nBus no: \t"<<bus[n].bus_num<<"\nDriver: \t"
			<<bus[n].driver_name<<"\tDeparture time:"<<bus[n].departure
			<<"\nFrom: \t\t"<<bus[n].from<<"\t\tTo: \t\t"<<bus[n].to<<"\n";
		vline('*');
		fname=bus[n].bus_num + ".txt";
		f.open(fname.c_str(),ios::in);
		if(!f.is_open())
		{
			cout<<"\n No passengers entry in this bus\n";

		}
		else
		{		while(!f.eof())
			{
				getline(f,content);
				cout<<content<<endl;
			}
			f.close();
		}
	}

}

void b::avail()
{
	for(int n=0;n<p;n++)
	{
		vline('*');
		cout<<"\nBus no: \t"<<bus[n].bus_num<<"\nDriver: \t"<<bus[n].driver_name
			<<"\tDeparture Time: \t"<<bus[n].departure<<"\nFrom: \t\t"<<bus[n].from<<"\t\tTo: \t\t\t"
			<<bus[n].to<<"\n";
		vline('*');
		vline('_');
	}
}
void b::book()
{
	int cnt;
	int i;
	float getPrice,pr;
	string number;
top:
	cout<<"\n enter bus number:";
	cin>>number;
	for(i=0;i<p;i++)
	{
		if(number==bus[i].bus_num)
			break;
	}
	if(i==p)
	{
		cout<<"\nIncorrect bus number:";
		goto top;
	}
	else
	{
		string fname;
		fname=bus[i].bus_num + ".txt";
		ofstream f;
		f.open(fname.c_str(),ios::app);
		f<<"Name\t"<<setw(20)<<"Age\t"<<setw(20)<<"Gender\t"<<setw(20)<<" Rate per person"<<endl;
		cout<<"\n how many tickets do you need to book?";
		cin>>cnt;
		getPrice=cnt*bus[i].rate;
		int k=0;
		while(k<cnt)
		{
			get();
			q.push_back(getName());
			if(getAge()>6)
			{
				pr=bus[i].rate;
			}
			else
			{
				pr=bus[i].rate/2;
			}
			f<<getName()<<"\t"<<setw(20)<<getAge()<<"\t"<<setw(20)<<getGender()<<"\t"<<setw(20)<<pr<<endl;
			k++;
		}

		f.close();
		cout<<"\n Happy Journey!!\n Your tickets are booked\n";
		list<string>:: iterator itr;
		int i=0;
		for(itr=q.begin();itr!=q.end();itr++)
		{
			cout<<i+1<<"\t"<<*itr<<"\n";
			i++;
		}

		cout<<"\n The total amount to be paid  : "<<getPrice<< " rupees\n";
	}
}

int main()
{
	int ch1,ch2;
	char ch;
	cout<<"\nWelcome to OUR_INDIA Travels!!\n";
	while(1)
	{
		cout<<"\na.Admin\nb.Passenger\nPlease specify:";
		cin>>ch;
		switch(ch)
		{
			case 'a':
				{
					cout<<"\n Hello Admin\n";
					cout<<"\n 1.Install and Instantiate the buses\n 2.Print Passenger's list\n Please specify:";
					cin>>ch1;
					if(ch1==1)
					{
						bus[p].install();
					}
					else if(ch1==2){
						cout<<"\n All buses list with passengers:\n";
						bus[0].print();


					}
					else
						cout<<"\n wrong input\n";
				}
				break;

			case 'b':
				{
					cout<<"\nHello passenger!!A warm welcome\n";
					cout<<"\n 1.Book Tickets\n 2.Available buses\n 3.Passenger's list\n Please specify:";
					cin>>ch2;
					switch(ch2)
					{
						case 1:
							cout<<"\n Check out from the available bus list:";
							bus[0].avail();
							bus[0].book();
							break;
						case 2:
							bus[0].avail();
							break;
						case 3:
							bus[0].show();
							break;
					}
				}
				break;


			default:
				cout<<"\ncheck your input\n";
		}
	}
}


