#include <iostream>
#include <windows.h>
#include <time.h>

#define QIAN "Ǭ"
#define KUN  "��"
#define ZHEN "��"
#define XUN  "��"
#define KAN  "��"
#define LI   "��"
#define GEN  "��"
#define DUI  "��"

void typer(char*);
bool isTruth(char*);

using namespace std;
int main() {
	system("color 02");

	char str[1024] = "\n\n\t\t���֮�� �������� ������Ϊ�� ����\n\n";
	typer(str);

	char truth[9] = {};
	strcpy_s(str, "\n\n  ̫�������� ���������� ����������\n\n  ��Ϊ\tǬ �� �� �� �� �� �� ��\n  ��Ϊ\t0  1  2  3  4  5  6  7\n\n  ���ð����� �ո��֮\t");
	typer(str);
	do {
		cin >> truth[0] >> truth[1] >> truth[2] >> truth[3] >> truth[4] >> truth[5] >> truth[6] >> truth[7];
		truth[8] = '\0';
	} while (!isTruth(truth));
	strcpy_s(str, "\n\n  ���� ������Ϊ\t");
	typer(str);
	for (int i = 0; i < 8; i++) {
		switch (truth[i]) {
		case '0': cout << " Ǭ"; break;
		case '1': cout << " ��"; break;
		case '2': cout << " ��"; break;
		case '3': cout << " ��"; break;
		case '4': cout << " ��"; break;
		case '5': cout << " ��"; break;
		case '6': cout << " ��"; break;
		case '7': cout << " ��"; break;
		}
		Sleep(60);
	}
	cout << endl;
	
	char obj[9] = {};
	unsigned long int objCount = 1;
	while (1) {
		for (int i = 0; i < 8; i++)
			obj[i] = rand() % 8 + 48;
		obj[8] = '\0';
		cout << "\n  ��" << objCount << "��Ϊ\t" << obj << '\t';
		for (int i = 0; i < 8; i++) {
			switch (obj[i]) {
			case '0': cout << " Ǭ"; break;
			case '1': cout << " ��"; break;
			case '2': cout << " ��"; break;
			case '3': cout << " ��"; break;
			case '4': cout << " ��"; break;
			case '5': cout << " ��"; break;
			case '6': cout << " ��"; break;
			case '7': cout << " ��"; break;
			}
			//Sleep(60);
		}
		if (strcmp(obj, truth) != 0) {
			cout << "\t��ʵ";
			objCount++;
			continue;
		}
		break;
	}

	cout << "\n\n\t�� " << objCount << " ��\t�����һ\n\n" << endl;
	strcpy_s(str, "\n  ǰ�������� �����֮�� �������� ��Զ�ڰ����� �������鲻�ɼ� ���������� ���� �˾� ����Ϊ�� �ù�ǧ������� �ں���ǳ� �˾��������ë�� ���� ��ëҲ���� ���˾ú� ������˼֮�� ���������� Ϊ���� ��Ϊ������һ ����Ϊ����� �ⲻ֪ ���ò������ ���� �Զ��� \n\t���֮�� �������� ������Ϊ�� ����\n\n");
	typer(str);

	return 0;
}

void typer(char* str) {
	for (int i = 0; str[i] != '\0'; i++) {
		cout << str[i];
		Sleep(60);
	}
}

bool isTruth(char* str) {
	for (int i = 0; i < 8; i++) {
		if (str[i] >= '0' && str[i] <= '7');
		else {
			char str[1024] = "\n  ���ֵ���ʵ �븴��\t";
			typer(str);
			return false;
		}
	}
	return true;
}
