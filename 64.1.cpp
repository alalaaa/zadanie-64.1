#include <iostream>
#include <fstream>
using namespace std;
const int SIZE = 200;
ifstream in("obrazek.txt");
char tab[21][21];
void zczytaj()
{
  	for (int i=0; i<21; i++)
	{
    		for(int j=0; j<21; j++)
		{
      			if (i==20 && j==20) 
			return;
      			in >> tab[i][j];
    		}
  	}
}
bool rewers() 
{
  	int licznik_jedynek=0, licznik_zer=0;
  	for (int i=0; i<20; i++) 
	{
    		for (int j=0; j<20; j++) 
		{
      			if (tab[i][j] == '0') licznik_zer++;
      			if (tab[i][j] == '1') licznik_jedynek++;
    		}
  	}
  	return licznik_jedynek>licznik_zer;
}

int razem() 
{
  	int counter=0;
  	for (int i=0; i<20; i++) 
	{
    		for (int j=0; j<20; j++) 
		{
      			if (tab[i][j] == '1') counter++;
    		}
  	}
  	return counter;
}

int main() 
{
  	int rewersCounter = 0, max_jedynek = 0;
	for (int n = 0; n < SIZE; n++) 
	{
    		zczytaj();
    		if (rewers()) rewersCounter++;
    		if (razem()>max_jedynek)max_jedynek = razem();
	}
	cout<<"Liczba rewersow: "<<rewersCounter <<endl;
	cout<<"Najwieksza liczba czarnych pikseli: "<<max_jedynek<< endl;
}
