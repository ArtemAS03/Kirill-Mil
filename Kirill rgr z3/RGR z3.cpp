#include <fstream>
#include <string>
#include <iostream>

using namespace std;

int n;

struct igrushki
{
	string nazv;
	int price;
	string izg;
	int kol;
	int vozr;
};

igrushki igr[100];

void one()
{
	ifstream list("test.txt");
	n = 0;
	while (!list.eof())
	{
		list >> igr[n].nazv >> igr[n].price >> igr[n].izg >> igr[n].kol >> igr[n].vozr;
		n++;
	}
	list.close();
}

void two()
{
	int years;
	cout << "¬ведите сколько лет ребенку - ";
	cin >> years;
	for (int i = 0; i < n; i++)
	{
		if (years >= igr[i].vozr)
		{
			cout << endl << igr[i].nazv << endl << igr[i].price << endl << igr[i].izg << endl << igr[i].kol << endl << igr[i].vozr << endl;
		}
	}
}

int main()
{
	setlocale(LC_ALL, "rus");
	ifstream list("test.txt");
	one();
	two();
	system("pause");
	return 0;
}