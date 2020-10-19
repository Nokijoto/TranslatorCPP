#include <iostream>
#include <fstream>
using namespace std;
int startsubs;
void export_sub(int startsubs)
{
	fstream sub_aegi;
	fstream sub_raw;
	fstream sub_time;
  sub_aegi.open ("anime_before.ass", ios::in);
  sub_raw.open( "raw_sub.txt", ios::out);
  sub_time.open( "raw_time.txt", ios::out);
  int i=0;
  string time;
  string subs;
  while(!sub_aegi.eof())
	{
		if(i>=0&&i<=startsubs)
		{
		string line;
		getline(sub_aegi, line);
		sub_time << line << '\n';
		}
		else if(i>=startsubs+1){
		string line;
		getline(sub_aegi, line);
		time=line.substr(0,50);
		subs=line.substr(50,line.length());
		sub_raw << subs << '\n';
		sub_time<<time<<'\n';
		}
		i++;
	}	
  sub_aegi.close();
  sub_raw.close();
  sub_time.close();
}
void import_sub(int startsubs)
{
	fstream sub_aegi;
	fstream sub_raw;
	fstream sub_time;
  sub_aegi.open ("subs_after.ass", ios::out);
  sub_raw.open( "translated.txt", ios::in);
  sub_time.open( "raw_time.txt", ios::in);
  int i=0;
  string time;
  string subs;
  while(!sub_aegi.eof())
	{
		if(i>=0&&i<=startsubs)
		{
		string line;
		getline(sub_time, line);
		sub_aegi << line << '\n';
		}
		else if(i>=startsubs+1){
		string line;
		string time;
		getline(sub_raw, line);
		getline(sub_time, time);
		sub_aegi<<time+line<< '\n';
		}
		i++;
	}	
  sub_aegi.close();
  sub_raw.close();
  sub_time.close();
}
int main()
{
	int option;
	do{
	cout<<"1 export. 2. import 0.wyjscie"<<endl;
	cin>>option;
	if(option==1)
	{
		cout<<"Podaj start napisow"<<endl;
		cin>>startsubs;
		cout<<"Rozpoczeto export"<<endl;
		export_sub(startsubs);
		cout<<"Zakonczono export"<<endl;
	}
	else if(option==2)
	{
		cout<<"Podaj start napisow"<<endl;
		cin>>startsubs;
		cout<<"Rozpoczeto import"<<endl;
		import_sub(startsubs);
		cout<<"Zakonczono import"<<endl;
	}
	else
	{
		cout<<"Zla wartoœc. 1 export. 2. import 0.exit"<<endl;
	}
	}while(option!=0);
	return 0;
}
