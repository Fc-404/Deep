#include <iostream>
#include <windows.h>
#include <time.h>

#define QIAN "乾"
#define KUN  "坤"
#define ZHEN "震"
#define XUN  "巽"
#define KAN  "坎"
#define LI   "离"
#define GEN  "艮"
#define DUI  "兑"

void typer(char*);
bool isTruth(char*);

using namespace std;
int main() {
	system("color 02");

	char str[1024] = "\n\n\t\t大道之巧 巧在灵心 灵心以为巧 则巧\n\n";
	typer(str);

	char truth[9] = {};
	strcpy_s(str, "\n\n  太极生两仪 两仪生四象 四象生八卦\n\n  卦为\t乾 坤 震 巽 坎 离 艮 兑\n  表为\t0  1  2  3  4  5  6  7\n\n  请置八字像 空格分之\t");
	typer(str);
	do {
		cin >> truth[0] >> truth[1] >> truth[2] >> truth[3] >> truth[4] >> truth[5] >> truth[6] >> truth[7];
		truth[8] = '\0';
	} while (!isTruth(truth));
	strcpy_s(str, "\n\n  置了 八字像为\t");
	typer(str);
	for (int i = 0; i < 8; i++) {
		switch (truth[i]) {
		case '0': cout << " 乾"; break;
		case '1': cout << " 坤"; break;
		case '2': cout << " 震"; break;
		case '3': cout << " 巽"; break;
		case '4': cout << " 坎"; break;
		case '5': cout << " 离"; break;
		case '6': cout << " 艮"; break;
		case '7': cout << " 兑"; break;
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
		cout << "\n  第" << objCount << "象为\t" << obj << '\t';
		for (int i = 0; i < 8; i++) {
			switch (obj[i]) {
			case '0': cout << " 乾"; break;
			case '1': cout << " 坤"; break;
			case '2': cout << " 震"; break;
			case '3': cout << " 巽"; break;
			case '4': cout << " 坎"; break;
			case '5': cout << " 离"; break;
			case '6': cout << " 艮"; break;
			case '7': cout << " 兑"; break;
			}
			//Sleep(60);
		}
		if (strcmp(obj, truth) != 0) {
			cout << "\t不实";
			objCount++;
			continue;
		}
		break;
	}

	cout << "\n\n\t历 " << objCount << " 像\t道像归一\n\n" << endl;
	strcpy_s(str, "\n  前仅八字像 轮如此之久 世间万物 甚远于八字像 乃至吾灵不可记 在世间字像 轮以 此久 灵以为久 久过千万代子嗣 于浩瀚星辰 此久则轻如鸿毛乎 大误 鸿毛也不及 此乃久乎 久至灵思之堤 道包容万物 为万像 灵为万物其一 灵以为与道巧 殊不知 甚久才与道巧 苍穹间 皆定数 \n\t大道之巧 巧在灵心 灵心以为巧 则巧\n\n");
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
			char str[1024] = "\n  八字道不实 请复置\t";
			typer(str);
			return false;
		}
	}
	return true;
}
