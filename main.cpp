/**
*
* @Name : EducationGame/main.cpp
* @Version : 1.0
* @Programmer : Max
* @Date : 2019-06-25
* @Released under : https://github.com/BaseMax/EducationGame/blob/master/LICENSE
* @Repository : https://github.com/BaseMax/EducationGame
*
**/
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <string>
using namespace std;

int age = 1;
int beginAge = 7;
bool education = false;
int level = 0;
int gendere = 0;
int country = 0;
int name = 0;
int died = 0;

void init() {
	srand(time(0));
	name = rand() % 7;
	country = rand() % 4;
	gendere = rand() % 2;
	died = rand() % 100;
}

string getGendere() {
	return (gendere == 1) ? "Boy" : "Girl";
}

string getName() {
	switch (country) {
		case 0:
			return "Erfan";
		case 1:
			return "Ali";
		case 2:
			return "Reza";
		case 3:
			return "Hamid";
		case 4:
			return "Heydar";
		case 5:
			return "Saeid";
		case 6:
			return "Mohsen";
	}
	return "";
}

string getCountry() {
	switch (country) {
		case 0:
			return "Iran";
		case 1:
			return "USA";
		case 2:
			return "Canada";
		case 3:
			return "Sweden";
	}
	return "";
}

string getEducation() {
	switch (level) {
		case 0:
			return "None";
		case 1:
			return "E1";
		case 2:
			return "E2";
		case 3:
			return "E3";
		case 4:
			return "E4";
		case 5:
			return "E5";
		case 6:
			return "E6";
		case 7://1
			return "M1";
		case 8://2
			return "M2";
		case 9://3
			return "M3";
		case 10://1
			return "H1";
		case 11://2
			return "H2";
		case 12://3
			return "H3";
		case 13:
			return "U";
		default:
			return "Life";
	}
	return "";
}

void status() {
	cout << "Name: " << getName() << endl;
	cout << "Country: " << getCountry() << endl;
	cout << "Gendere: " << getGendere() << endl;
	cout << "Age: " << age << endl;
	cout << "Education: " << getEducation() << endl;
}

void help() {
	cout << " Help................................." << endl;
	cout << "0. Next Year" << endl;
	cout << "1. Goto education" << endl;
	cout << "2. Leave education" << endl;
}

int main(int argc, char const *argv[]) {
	init();
	bool alive = true;
	while (alive) {
		int action;
#ifdef _WIN32
		system("cls");
#elif __linux__
		// cout << "\033[2J";
		system("clear");
#endif
		status();
		help();
		cout << "Enter your action : ";
		cin >> action;
		switch (action) {
			case 0: {
				age++;
				if (age > died) {
					alive = false;
				}
				if (education == true) {
					level++;
					if(level > 13) {
						education=false;
					}
				}
			}
			break;
			case 1: {
				if (education == true) {
					cout << "Error!" << endl;
				}
				else {
					if (age >= beginAge) {
						education = true;
						if(level == 0)
							level=1;
					}
					else {
						cout << "Error Age!" << endl;
					}
				}
			}
			break;
			case 2: {
				if (education == true) {
					education = false;
				}
				else {
					cout << "Error!" << endl;
				}
			}
			break;
		}
		//#ifdef _WIN32
		system("pause");
		//#endif
	}
	return 0;
}
