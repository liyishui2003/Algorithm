#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

struct Point {
	int x, y;
};

int main() {
	Point p[5];
	for (int i = 0; i < 5; ++i) {
		cin >> p[i].x >> p[i].y;
	}
	
	// 找到边界
	int lef = 1005, rig = -1005, up = -1005, bot = 1005;
	for (int i = 0; i < 5; ++i) {
		lef = min(lef, p[i].x);
		rig = max(rig, p[i].x);
		up = max(up, p[i].y);
		bot = min(bot, p[i].y);
	}
	
	// 初始化变量
	int seclef = 1005, secrig = -1005, secup = -1005, secbot = 1005;
	int tot = 0;
	
	// 计算次边界的最小距离
	int lef_f=0,rig_f=0,up_f=0,bot_f=0;
	for (int i = 0; i < 5; ++i) {
		if (p[i].x == lef&&lef_f==0) {
			for (int j = 0; j < 5; ++j) {
				if (j != i) seclef = min(seclef, p[j].x);
			}
			tot += abs(lef - seclef);
			lef_f=1;
		}
		
		if (p[i].x == rig&&rig_f==0) {
			for (int j = 0; j < 5; ++j) {
				if (j != i) secrig = max(secrig, p[j].x);
			}
			tot += abs(rig - secrig);
			rig_f=1;
		}
		
		if (p[i].y == up&&up_f==0) {
			for (int j = 0; j < 5; ++j) {
				if (j != i) secup = max(secup, p[j].y);
			}
			tot += abs(up - secup);
			up_f=1;
		}
		
		if (p[i].y == bot&&bot_f==0) {
			for (int j = 0; j < 5; ++j) {
				if (j != i) secbot = min(secbot, p[j].y);
			}
			tot += abs(bot - secbot);
			bot_f=1;
		}
	}
	
	// 加入次边界的长宽周长
	// may be not triangle ,instead a line
	if(secrig==seclef){
		tot+=abs(secup - secbot);
	}
	else if(secup==secbot){
		tot+=abs(secrig - seclef);
	}
	else {
		tot += 2 * (abs(secrig - seclef) + abs(secup - secbot));	
	}
	
	// 检查内点
	for (int i = 0; i < 5; ++i) {
		if (p[i].x == lef || p[i].x == rig || p[i].y == up || p[i].y == bot) continue;
		if (p[i].x == seclef || p[i].x == secrig || p[i].y == secup || p[i].y == secbot) continue;
		
		tot += min(abs(secrig - seclef), abs(secup - secbot));
	}
	
	cout << tot << endl;
	return 0;
}
