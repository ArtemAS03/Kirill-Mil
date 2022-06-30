#include<iostream>
#include<string>
#include<fstream>
using namespace std;

ifstream F1_out("2.txt");
ifstream F_out2("3.txt");
ofstream F_out("4.txt", ios::app);

class users
{
public:
	string name;
	string password;
	string prava;
	void vvod(ifstream file) 
	{
		file >> name;
		file >> password;
		file >> prava;
	}
};
string path = "1.txt";
bool flag = true;
void add_new_users()
{
	string line;
	users user;
	ifstream input;
	input.open(path, ifstream::in);
	if (!input.is_open()) 
	{
		cout << "File didn`t open" << endl;
	}
	else {
		string n;
		string p;
		string d;
		cout << "Введите имя пользователя, которого хотите добавить" << endl;
		getline(cin, n);
		getline(cin, n);
		cout << "Введите пароль для нового пользователя" << endl;
		getline(cin, p);
		cout << "Введите словом права доступа для нового пользователя.\n1. Read \n2. Full \n3. Adm " << endl;
		getline(cin, d);
		do {
			input >> user.name;
			if (n == user.name) 
			{
				cout << "Такой пользователь уже существует. Придумайте другое имя." << endl;
				flag = false;
			}
			input >> user.password;
			input >> user.prava;
		}
		while (getline(input, line) && flag);
		input.close();
		ofstream output;
		output.open(path, ofstream::app);
		if (flag) {
			output << n << endl;
			output << p << endl;
			output << d << endl;
			output << "\n";
			cout << "Пользователь успешно добавлен!" << endl;
		}
		output.close();
	}
}
void add_new_info_in_file() 
{
	if ((!F1_out.is_open()) || (!F_out2.is_open()))
	{
		cout << "Файл не удалось открыть!" << endl;
		exit(0);
	}
	else 
	{
		int chastnoe;
		string sub, k, l;
		int mas[50];
		int i = 0;
		int tmp = 0;
		int w;
		ifstream F_in1("2.txt");
		if (!F_in1)
			cout << "Ошибка при открытии файла" << endl;
		getline(F_in1, k);
		string::size_type v = 0, pos = 0;
		v = k.find(" ", pos);
		while (v < k.length())
		{
			sub = k.substr(pos, v - pos);
			w = stoi(sub);
			mas[i] = w;
			i++;
			pos = v + 1;
			v++;
			v = k.find(" ", pos);
			tmp++;
		}
		v = k.rfind(" ");
		sub = k.substr(pos, k.length());
		w = stoi(sub);
		mas[i] = w;

		int mas1[50];
		i = 0;
		int tmp1 = 0;
		int z = 0;
		int q;
		ifstream F_in2("3.txt");
		if (!F_in2)
			cout << "Ошибка при открытии файла" << endl;
		getline(F_in2, l);
		v = 0, pos = 0;
		v = l.find(" ", pos);
		while (v < l.length())
		{
			sub = l.substr(pos, v - pos);
			q = stoi(sub);
			mas1[i] = q;
			i++;
			pos = v + 1;
			v++;
			v = l.find(" ", pos);
			tmp1++;
		}
		v = l.rfind(" ");
		sub = l.substr(v + 1);
		q = stoi(sub);
		mas1[i] = q;
		if (tmp != tmp1)
		{
			cout << "Ошибка! Добавьте в файле с меньшим значением еще данных!" << endl;
			if (tmp < tmp1)
				cout << "Недостающее количество в файле 3: " << abs(tmp - tmp1) << endl;
			if (tmp1 < tmp)
				cout << "Недостающее количество в файле 4: " << abs(tmp - tmp1) << endl;
			system("pause");
			exit(0);
		}
		else
		{
			F_out << "||";
			F_out << " ";
			while (z < tmp+1)
			{
				if (mas[z] > mas1[z])
				{
					if (mas[z] % mas1[z] == 0)
					{
						chastnoe = mas[z] / mas1[z];
						F_out << chastnoe << " ";
						z++;
					}
					else
					{
						z++;
					}
				}
				if (mas1[z] > mas[z])
				{
					if (mas1[z] % mas[z] == 0)
					{
						chastnoe = mas1[z] / mas[z];
						F_out << chastnoe << " ";
						z++;
					}

					else
					{
						z++;
					}
				}
				if (mas[z] == mas1[tmp1])
				{
					if (mas1[tmp1] % mas[z] == 0)
					{
						chastnoe = mas1[tmp1] / mas[z];
						F_out << chastnoe << " ";
						z++;
					}
					
				}
				
			}
		}
		F_out << "||";
		F_out << endl;
		F1_out.close();
		F_out2.close();
		F_out.close();
		ifstream F_out("4.txt");
		if (!F_out.is_open())
			cout << "Файл не удалось открыть!" << endl;
		else 
		{
			while (!F_out.eof())
			{
				string chek;
				chek = "\n";
				F_out >> chek;
				cout << chek << " ";
			}
			cout << "\n" << endl;
		}
		F_out.close();
		flag == true;
	}
}
void check_info_in_file()
{
	ifstream F_in1("2.txt");
	string g;
	ifstream F_in2("3.txt");
	string f;
	if (F_in1.is_open())
	{
		F_in1.is_open();
		getline(F_in1, g);
		cout << "Строка в первом файле: " << g << endl;
	}
	
	if (F_in2.is_open())
	{
		getline(F_in2, f);
		cout << "Строка во втором файле: " << f << endl;
	}
	else
		cout << "Ошибка при открытии файла!" << endl;
}
void menu(string dostup)
{
	int temp;
	if (dostup == "Read") 
	{
		cout << "Выберите действие" << endl;
		cout << "1. Просмотреть информацию в файле \n0. Выйти" << endl;
		cin >> temp;
		if (temp == 0) 
		{
			cout << endl << "Вы вышли из системы." << endl;
			system("pause");
			exit(0);
		}
		else if (temp == 1) 
		{
			check_info_in_file();
		}
		else 
			cout << "Команды под таким номером не существует" << endl;
	}
	if (dostup == "Full") 
	{
		cout << " 1. Просмотреть информацию в файле \n 2. Добавить информацию в файл \n 3. Выйти" << endl;
		cin >> temp;
		if (temp == 1) 
		{
			check_info_in_file(); 
		}
		else if (temp == 2) 
		{
			add_new_info_in_file(); 
		}
		else if (temp == 3) 
		{
			cout << endl << "Вы вышли из системы." << endl;
			system("pause");
			exit(0);
		}
		else
		{
			cout << "Команды под таким номером не существует" << endl;
			exit(0);
		}
			
	}
	if (dostup == "Adm") 
	{
		cout << "1. Добавить пользователя\n2. Выйти" << endl;
		cin >> temp;
		if (temp == 1) 
		{
			add_new_users();
		}
		else if (temp == 2) 
		{
			cout << endl << "Вы вышли из системы." << endl;
			exit(0);
		}
		else 
			cout << "Команды под таким номером не существует" << endl;
	}
}
int main() 
{
	system("chcp 1251");
	ifstream input;
	input.open(path);
	bool flag = true;
	string line;
	string input_name;
	string name, par;
	users user;
	cout << "Введите имя пользователя" << endl;
	cin >> name;
	if (input.is_open()) 
	{
		do 
		{
			input >> user.name;
			input >> user.password;
			input >> user.prava;
			if (name == user.name) {
				cout << "Введите пароль" << endl;
				cin >> par;
				if (par == user.password)
				{
					menu(user.prava);
				}
				else 
				{
					cout << "Пароль неверный! В доступе отказано." << endl;
				}
				flag = false;
			}
		} 
		while (getline(input, line) && flag);
		if (flag) 
		{
			cout << "Такого пользователя не существует!" << endl;
		}
	}
	else 
	{
		cout << "Файл не удалось открыть!" << endl;
		exit(0);
	}
	system("pause");
	return 0;
}