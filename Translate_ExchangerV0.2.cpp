#include <iostream>
#include <fstream>
using namespace std;
int startsubs;
int fileLineSize[500];
int checker_Size(int b)
{
fstream sub_aegi;
	sub_aegi.open ("anime_before.ass", ios::in);
	int i=0;
	int s;
	while(!sub_aegi.eof())
	{
		string linia;
		getline(sub_aegi, linia);
		if(i>=b)
		{
			for(int k=1;k<=linia.length();k++)
			{
				
				if(linia[k]==linia[k+1] && linia[k]==',' || linia[k]==' ')
				{
					s=k+2;
					fileLineSize[i]=s;
				}
				
			}
		}
		i++;
	};
	sub_aegi.close();
}
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
  checker_Size(startsubs);
  while(!sub_aegi.eof())
	{
		if(i<startsubs)
		{
		string line;
		getline(sub_aegi, line);
		sub_time << line << '\n';
		}
		else if(i>=startsubs){
		string line;
		getline(sub_aegi, line);
		time=line.substr(0,fileLineSize[i]);
		subs=line.substr(fileLineSize[i],line.length());
		sub_raw << subs << '\n';
		sub_time<<time<<'\n';
		}
		else if(i>=500)
		{
			return;
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
  while(!sub_time.eof())
	{
		if(i>=0&&i<startsubs)
		{
		string line;
		getline(sub_time, line);
		sub_aegi << line << '\n';
		}
		else if(i>=startsubs){
		string line;
		string time;
		getline(sub_raw, line);
		getline(sub_time, time);
		sub_aegi<<time+line<< '\n';
		}
		else if(i>=500)
		{
			return;
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
	cout<<"Translate Exchanger V.02"<<endl;	
	cout<<"1 Export"<<endl;
	cout<<"2.Import"<<endl;
	cout<<"3.Instrukcja"<<endl;
	cout<<"0.Wyjscie"<<endl;
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
	else if(option==3
	{
		cout<<"Instrukcja"<<endl;
		cout<<"Uwaga!!! Jesli masz wlaczone rozszezenia to anime_before i after  bedzie mialo .ass a pliki raw_sub, raw_time i translated bedzie mialo .txt"<<endl;
		cout<<"Nazwij plik z tlumaczeniem anime_before"<<endl;
		cout<<"Po uruchomieniu exportu, utworzy 2 pliki raw_sub i raw_time"<<endl;
		cout<<"Nastepnie utworz plik translated i do niego przetlumaczone z raw_sub wpisz"<<endl;
		cout<<"Po uruchomieniu importu utworzy sie plik anime_after"<<endl;
	}
	else
	{
		cout<<"Zla wartosc. 1 export. 2. import 0.exit"<<endl;
	}
	}while(option!=0);
	return 0;
}
