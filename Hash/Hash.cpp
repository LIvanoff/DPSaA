#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;
template <class Key, class Adress> class hashtab
{	
public:
	int SIZE;
	hashtab();
	string **tab;
	hashtab(int x, string y);
	void SetSize(int SIZE) 
	{
		this->SIZE = SIZE;
	}
	void add(string x, string &y);
	void remove(){}
	void search(int it){}
	void output(){}
	int end(){}
};
template<class Key, class Adress>
hashtab<Key, Adress>::hashtab()
{

}
template< class Key,class Adress> 
hashtab<Key, Adress>::hashtab(int x,string y)
{
	this->SIZE = x;
	this->tab = new string*[SIZE];
	for (int i = 0; i < SIZE; i++)
	{
		tab[i] = new string[2];
	}
	/*for(int i = 0; i < SIZE; i++)
	{
		for(int j =0 ; j <2 ;j++)
		{
			tab[i][j] = "2";
		}
	}*/
	output();
	cout << y;
}
int hashtab<int, string>::end()
{
	for (int i = 0; i < SIZE; i++) 
	{
		delete[] tab[i];
	}
	delete[] tab;
	return 0;
}
void hashtab<int, string>::output()
{
	for (int i = 0; i < SIZE; i++)
	{
		for(int j =0; j<2;j++)
		{
			if(j==0)
			{
				cout <<i<<". "<<this->tab[i][j] << " ";
			}
			else if(j==1)
			{
				cout << this->tab[i][j] << " ";
			}
		}
		cout << endl;
	}
}
void hashtab<int, string>::add(string key,string &adress)
{
	int x = stoull(key)%this->SIZE;
	int y = stoull(key)% this->SIZE;
	for (int i = x ;i<SIZE;i++)
	{	
		for (int j = 1; j < 2; j++)
		{
			if (tab[i][j]=="")
			{
				tab[i][j - 1] = key;
				cout << "(" << key << ")";
				tab[i][j] = adress;
				cout << "(" << adress << ")";
				return;
			}
		}
		x = (x + y) %SIZE;
		cout << "x = (x + y) %SIZE = " << x;
		//table.resize()
	}
}
/*
template <typename HashType1, typename HashType2> void hashtab<HashType1, HashType2>::output()
{

}
void hashtab<int, string>::search(int it, string v)
{

}
void hashtab<int, string>::remove(int it,string p)
{

}
*/
int main()
{
	int SIZE;
	setlocale(LC_ALL, "Russian");
	cout << " Хэш-таблица телефонного справочника" << endl;
	cout << " Команды:\n start - начать работу\n add - добавлнение\n remove - удаление\n search - поиск\n output - вывод таблицы\n end - завершить работу\n ";
	string start;
	do
	{
		cin >> start;
		if(start!="start")
		{
			cout << "Напишите start..\n ";
		}
	} while (start!="start");
	cout << " Начнём! Напишите размер Хэш-таблицы\n ";
	cin>>SIZE;
	hashtab<int, string> table(SIZE," Хэш-таблица создана..\n");
	int Q=4;
	string hash;
	vector<bool> qeueu;
	string command, vacuum = " ";
	for (int i = 0; ; i++)
	{
		cin >> command;
		cout << "\r";
		if (command == "end")
		{
			table.end();
			break;
		}
		else
		{
			string adress;
			if (command == "add")
			{
				cout << " Введите хэш";
				cin >> hash;
				cout << "Введите адрес";
				cin >> adress;
				table.add(hash,adress);
			}
			else if (command == "remove")
			{
				cin >> hash;
			}
			else if (command == "output")
			{
				table.output();
			}
			else if (command == "search")
			{
				int it;
				cin >> it;
				table.search(it);
			}
		}
	}
	return 0;
}