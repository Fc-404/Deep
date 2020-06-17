#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string>
#include <shlobj.h>
#include <iostream>
#include <Lmcons.h>

std::string getDesktopPath_fc();
bool on_off = 0;
bool off_on = 0;
bool on = 0;

DWORD WINAPI caption(LPVOID temp) {
/*
	while (on == 0);
	char text[128] = "System crash...\n系统崩溃...\n按回车可自动修复！\n-_- ^_^ +_+\n还剩";
	char text_b[128] = "System crash...\n系统崩溃...\n按回车可自动修复！\n-_- ^_^ +_+\n还剩";
	char text_temp[8] = "999次！";
	short text_num = 0;
	for (short i = 0; i < 999; i++) {
		text_num = 999 - i;
		if (text_num < 10){
			text_temp[0] = 0;
			text_temp[1] = 0;
			text_temp[2] = char(text_num + 48);
		}
		else if (text_num < 100) {
			text_temp[0] = 0;
			text_temp[1] = char(text_num / 10 + 48);
			text_temp[2] = char(text_num % 10 + 48);
		}
		else{
			text_temp[0] = char(text_num / 100 + 48);
			text_temp[1] = char(text_num % 100 / 10 + 48);
			text_temp[2] = char(text_num % 10 + 48);
		}
		strcpy_s(text, text_b);
		strcat_s(text, text_temp);
		MessageBoxA(0, text, "Error错误", MB_OK);
	}
		

	while (on_off != 1)
		MessageBoxA(0, "Wait...\n请等待...", "Warning警告", MB_OK);
*/
	DWORD size = UNLEN + 1;
	char UserName[32];
	if (!GetUserName(UserName, &size))
		MessageBoxA(0, "旋转失败", "提示", MB_OK);
	MessageBoxA(0, "旋转成功", "提示", MB_OK);
	char path[64] = "del C:\\Users\\";
	char desktop[10] = "\\Desktop\\";
	//char desktop[15] = "\\Desktop\\test\\";
	char reset[64];
	strcat_s(path, UserName);
	strcat_s(path, desktop);
	strcpy_s(reset, path);

	char num[7] = "000.fc";
	/**/
	for (short i = 0; i < 512; i++) {
		if (i < 10)
			num[2] = char(i + 48);
		else if (i < 100) {
			char m = char(i % 10 + 48);
			char n = char(i / 10 + 48);
			num[1] = n;
			num[2] = m;
		}
		else {
			char m = char(i % 10 + 48);
			char n = char(i % 100 / 10 + 48);
			char o = char(i / 100 + 48);
			num[0] = o;
			num[1] = n;
			num[2] = m;
		}
		strcat_s(path, num);
		//cout << path << endl;
		system(path);
		strcpy_s(path, reset);
		//cout << num << endl;
		//Sleep(100);
	}
	//off_on = 1;
	return 0;
}

void main() {
	using namespace std;
/*
	HWND window;
	window = FindWindow("ConsoleWindowClass", NULL);
	if (window)
	{
		ShowWindow(window, SW_HIDE);//设置指定窗口的显示状态
	}

	std::string DesktopPath_temp = getDesktopPath_fc();
	//cout << DesktopPath_temp << endl;
	char DesktopPath[300];
	strcpy_s(DesktopPath, DesktopPath_temp.c_str());
	//cout << DesktopPath << endl;

	DWORD size = UNLEN + 1;
	char UserName[32];

	if (!GetUserName(UserName, &size))
		MessageBoxA(0, "旋转失败", "提示", MB_OK);
	MessageBoxA(0, "旋转成功", "提示", MB_OK);
	//cout << UserName << endl;
	CloseHandle(CreateThread(NULL, 0, caption, NULL, 0, NULL));
	on = 1;
	char path[64] = "cd.>C:\\Users\\";
	char desktop[10] = "\\Desktop\\";
	//char desktop[15] = "\\Desktop\\test\\";
	char reset[64];
	strcat_s(path, UserName);
	strcat_s(path, desktop);
	strcpy_s(reset, path);

	char num[7] = "000.fc";
/*
	for (short i = 0; i < 512; i++) {
		if (i < 10)
			num[2] = char(i + 48);
		else if (i < 100){
			char m = char(i % 10 + 48);
			char n = char(i / 10 + 48);
			num[1] = n;
			num[2] = m;
		}
		else {
			char m = char(i % 10 + 48);
			char n = char(i % 100 / 10 + 48);
			char o = char(i / 100 + 48);
			num[0] = o;
			num[1] = n;
			num[2] = m;
		}
		strcat_s(path, num);
		//cout << path << endl;
		system(path);
		strcpy_s(path, reset);
		//cout << num << endl;
		//Sleep(100);
	}
	Sleep(3000);
/*
/*
	num[0] = char(48);
	num[1] = char(48);
	num[2] = char(48);
	path[0] = char(100);
	path[1] = char(101);
	path[2] = char(108);
	path[3] = char(32);
	strcpy_s(reset, path);
	//cout << path << endl;
	for (short i = 0; i < 1000; i++) {
		if (i < 10)
			num[2] = char(i + 48);
		else if (i < 100) {
			char m = char(i % 10 + 48);
			char n = char(i / 10 + 48);
			num[1] = n;
			num[2] = m;
		}
		else {
			char m = char(i % 10 + 48);
			char n = char(i % 100 / 10 + 48);
			char o = char(i / 100 + 48);
			num[0] = o;
			num[1] = n;
			num[2] = m;
		}
		strcat_s(path, num);
		//cout << path << endl;
		system(path);
		strcpy_s(path, reset);
		//cout << num << endl;
		//Sleep(100);
	}
*/
//	on_off = 1;
//	while (off_on != 1);
	CloseHandle(CreateThread(NULL, 0, caption, NULL, 0, NULL));
	Sleep(30000);
}

std::string getDesktopPath_fc() {
	LPITEMIDLIST temp;
	char path[300];

	if (SUCCEEDED(SHGetSpecialFolderLocation(NULL, CSIDL_DESKTOP, &temp)))
		SHGetPathFromIDListA(temp, path);
	else
		MessageBoxA(0, "旋转失败", "提示", MB_OK);

	return std::string(path);
}
