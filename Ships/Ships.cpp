// Ships.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "windows.h"
#include <string>
#include <vector>
#include <deque>
#include <fstream>
using namespace std;
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int N;
	int count = 1;
	string information;
	bool is_empty;
	deque <string> raid;
	vector <string> ports;
	ifstream fin;
	ofstream fout;
	fin.open("SHIPS.IN");
	fout.open("SHIPS.OUT");
	if (!fin.is_open())
	{
		cout << "Ошибка! Файл не открылся!" << endl;
		return 0;
	}
	if (fin.peek() == EOF)
	{
		cout << "Ошибка! Файл пустой!" << endl;
		return 0;
	}
	fin >> N;
	for (int i = 0; i < N; i++)
		ports.push_back("");
	fin.ignore(1, '\n');
	while (getline(fin, information))
	{
		char op = information[0];
		switch (op)
		{

		case '1':
			is_empty = false;
			information.erase(0, 2);
			for (int i = 0; i < N; i++)
			{
				if (ports[i] == "")
				{
					ports[i] = information;
					is_empty = true;
					fout << "Корабль " << information << " теперь находиться у " << i + 1 << "-го причала" << endl;
					break;
				}
			}
			if (is_empty == false)
			{
				raid.push_back(information);
				fout << "Свободных причалов нет!" << endl;
				fout << "Корабль " << information << " отправился на рейд" << endl;
			}
			fout << "----------------------------------------" << endl;
			break;

		case '2':
			information.erase(0, 2);
			fout << "Причал номер " << information << " освободился" << endl;
			if (raid.size() > 0)
			{

				ports[stoi(information) - 1] = raid[0];
				fout << "Корабль " << raid[0] << " теперь у причала номер " << stoi(information) << endl;
				raid.pop_front();
			}
			else
				ports[stoi(information) - 1] = "";
			fout << "----------------------------------------" << endl;
			break;

		case '3':
			fout << "СТАТУС РЕЙДА:" << endl;
			if (raid.size() > 0)
			{
				fout << "Корабли на рейде:" << endl;
				for (auto ship_on_raid : raid) {
					fout <<count << ". " << ship_on_raid << endl;
					count++;
				}
				count = 1;
			}
			else
			{
				fout << "На рейде нет кораблей" << endl;
			}
			fout << "----------------------------------------" << endl;
			break;

		case '4':
			fout << "СОСТОЯНИЕ ПОРТА:" << endl;
			for (int i = 0; i < ports.size(); i++)
			{
				if (ports[i] == "")
					fout << i + 1 << "-й причал свободен" << endl;
				else
					fout << i + 1 << "-й причал занят кораблем " << ports[i] << endl;
			}
			fout << "----------------------------------------" << endl;
			break;
		}
	}
	fin.close();
	fout.close();
	system("SHIPS.OUT");
	return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
