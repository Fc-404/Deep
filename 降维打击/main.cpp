#include <easyx.h>
#include <conio.h>
#include <iostream>
#include <stdlib.h>
#include <atlstr.h>
#include "resource.h"//������Դ֮����һ��resource.hͷ�ļ�
#include <Windows.h>
#include <mmsystem.h>

#pragma comment(lib,"winmm.lib")

char* ToChar(int Num, int MaxBit = 8);//����ת�����ַ�����û�õĹ��ܣ�ֻΪ����drawtext()��ʾ��
unsigned long int pow10(int i);//10�Ĵη���
int ReDim(int set_mul);//��ά�����
void To16(long int num);//10����ת16���ƣ�
void foreword();

int windowX, windowY, level = 5;//ͼƬͼ�񴰿ڴ�С��������
char c[256] = {};//ת�����ʮ�����ַ�����
char count16[256] = {};//16�������飻

int main() {
	FILE *testFile;
	LPCTSTR path_end;
	char path[256] = {};
	int width = 0, height = 0;

	//do {
		std::cout << "\n�����뱻���ͼƬ·����\n\n֧�־���·�����·����\n\n�����ļ���ַ�ήάʧ�ܣ�\n" << std::endl;
		std::cin >> path;
		CString str = path;
		path_end = str;
	//} while (_access(path_end, 00) != 0);
	std::cout << "\n\n������ͼƬ��ȣ�0��Ĭ�ϴ�С��\n" << std::endl;
	std::cin >> width;
	std::cout << "\n\n������ͼƬ�߶ȣ�0��Ĭ�ϴ�С��\n" << std::endl;
	std::cin >> height;
	std::cout << "\n\n�����ý�ά�����߼�����\n\n���鲻����10��\n" << std::endl;
	std::cin >> level;
	system("cls");
	Sleep(1000);
	foreword();

	if (width == 0)
		width = NULL;
	if (height == 0)
		height = NULL;

	IMAGE img;
	loadimage(&img, path_end, width, height);
	//loadimage(&img, _T("img.jpg"));

	windowX = img.getwidth();
	windowY = img.getheight();

	initgraph(windowX, windowY);
	putimage(0, 0, &img);

	for(int i = 1; i < level; i++)
		ReDim(i);

	saveimage(_T("�޴�������.jpg"));
	_getch();

	return 0;
}

char* ToChar(int Num, int MaxBit) {
	unsigned long int bit_temp = 0;
	char c_temp[256] = {};
	int count = 0;
	//������ת�����ַ��ͣ�
	for (int i = 1; i <= MaxBit; i++) {
		count = pow10(i);
		bit_temp = (Num % count) / (count / 10);
		if ((Num / (count / 10)) != 0) {
			c_temp[i - 1] = bit_temp + 48;
			bit_temp = 0;
		}
		else {
			c_temp[i - 1] = '\0';
			break;
		}
		c_temp[i] = '\0';
	}
	//���ַ����û���
	int i = 0;
	for (; c_temp[i] != '\0'; i++);
	i--;
	for (int n = 0; i >= 0; i--, n++) {
		c[n] = c_temp[i];
		c[n + 1] = '\0';
	}

	return c;
}

unsigned long int pow10(int i) {
	if (i <= 1)
		return 10;
	return 10 * pow10(i - 1);
}

int ReDim(int set_mul) {
	COLORREF color;
	for (int x = 0; x < windowX; x += set_mul) {
		if (x >= windowX)
			continue;
		for (int y = 0; y < windowY; y += set_mul) {
			if (y >= windowY)
				continue;
			color = getpixel(x + set_mul, y + set_mul);
			setfillcolor(RGBtoGRAY(color));
			solidcircle(x + set_mul - 1, y + set_mul - 1, set_mul - 1);
		}
	}

	return 0;
}

void To16(long int num) {
	char count16_temp[256] = {};
	long int num_temp = num, i = 0;
	do {
		if (num_temp % 16 > 9) {
			switch (num_temp % 16) {
			case 10: count16_temp[i] = 'A'; break;
			case 11: count16_temp[i] = 'B'; break;
			case 12: count16_temp[i] = 'C'; break;
			case 13: count16_temp[i] = 'D'; break;
			case 14: count16_temp[i] = 'E'; break;
			case 15: count16_temp[i] = 'F'; break;
			}
		}
		else
			count16_temp[i] = num_temp % 16 + 48;
		i++;
		count16_temp[i] = '\n';
		num_temp = num_temp / 16;
	} while (num_temp != 0);

	for (int n = 0; n < i; n++)
		count16[n] = count16_temp[i - n - 1];
}

void foreword() {
	char str[256] = "\n\n\n\n���Ǿ���һȺ����\n\n�����߼�����������ָ��\n\n���Ǿ͸������ڴ���\n\n......\n\n������\n\n����Ҳ������\n\n";
	int i = 0;
	PlaySound(LPCSTR(IDR_WAVE1), GetModuleHandle(NULL), SND_RESOURCE | SND_ASYNC);
	while (str[i] != '\0') {
		printf("%c", str[i]);
		Sleep(50);
		i++;
	}
	Sleep(3000);
}