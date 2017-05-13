#include <iostream>
using namespace std;

// 1 = white  2 = black
struct piece{
	int map[4][4];
	int who;
	int step;
	long hash;
};

const int N=30000;
piece queue[N];
int head,tail;
bool h[2][44000000];

int check(piece now){
	for (int i=0;i<4;i++){
		if (now.map[i][0]==now.map[i][1] && now.map[i][1]==now.map[i][2] && now.map[i][2]==now.map[i][3])
			return 1;
		if (now.map[0][i]==now.map[1][i] && now.map[1][i]==now.map[2][i] && now.map[2][i]==now.map[3][i])
			return 1;
	}
	if (now.map[1][1]==now.map[2][2] && now.map[2][2]==now.map[3][3] && now.map[1][1]==now.map[0][0])
		return 1;
	if (now.map[0][3]==now.map[1][2] && now.map[1][2]==now.map[2][1] && now.map[2][1]==now.map[3][0])
		return 1;
	return 0;
}

long gethash(piece now){
	long t=0;
	for (int i=0;i<4;i++)
		for (int j=0;j<4;j++)
			t = t*3 + now.map[i][j];
	return t;
}

int move(piece now){
	piece tmp;
	for (int i=0;i<4;i++)
		for (int j=0;j<4;j++){
			if (now.map[i][j] == now.who){
				if ((j+1<4) && (now.map[i][j+1]==0)){
					tmp=now;
					tmp.map[i][j]=0;
					tmp.map[i][j+1]=tmp.who;
					tmp.hash=gethash(tmp);
					if (h[tmp.who-1][tmp.hash]==0){
						tmp.who = 3-tmp.who;
						tmp.step++;
						h[tmp.who-1][tmp.hash]=1;
						head++;
						queue[head]=tmp;
					}
				}
				if ((i+1<4) && (now.map[i+1][j]==0)){
					tmp=now;
					tmp.map[i][j]=0;
					tmp.map[i+1][j]=tmp.who;
					tmp.hash=gethash(tmp);
					if (h[tmp.who-1][tmp.hash]==0){
						tmp.who = 3-tmp.who;
						tmp.step++;
						h[tmp.who-1][tmp.hash]=1;
						head++;
						queue[head]=tmp;
					}
				}
				if ((j-1>=0) && (now.map[i][j-1]==0)){
					tmp=now;
					tmp.map[i][j]=0;
					tmp.map[i][j-1]=tmp.who;
					tmp.hash=gethash(tmp);
					if (h[tmp.who-1][tmp.hash]==0){
						tmp.who = 3-tmp.who;
						tmp.step++;
						h[tmp.who-1][tmp.hash]=1;
						head++;
						queue[head]=tmp;
					}
				}
				if ((i-1>=0) && (now.map[i-1][j]==0)){
					tmp=now;
					tmp.map[i][j]=0;
					tmp.map[i-1][j]=tmp.who;
					tmp.hash=gethash(tmp);
					if (h[tmp.who-1][tmp.hash]==0){
						tmp.who = 3-tmp.who;
						tmp.step++;
						h[tmp.who-1][tmp.hash]=1;
						head++;
						queue[head]=tmp;
					}
				}
			}	
		}
	return 0;
}

int main(){
	char ch;
	piece now;
	
	for (int i=0;i<4;i++){
		for (int j=0;j<4;j++){
			cin >> ch;
			if (ch == 'W') now.map[i][j] = 1;
			else if (ch == 'B') now.map[i][j] = 2;
			else now.map[i][j] = 0;
		}
	}
	now.hash = gethash(now);
	now.step = 0;
	
	head=-1;tail=-1;
	now.who=1;
	h[now.who-1][now.hash]=1;
	head++;
	queue[head]=now;
	
	now.who=2;
	h[now.who-1][now.hash]=1;
	head++;
	queue[head]=now;
	while (tail < head){
		tail++;
		now = queue[tail];
		if (check(now)){
			break;
		}
		else {
			move(now);
		}
	}
	cout << now.step << endl;
	return 0;	
}
