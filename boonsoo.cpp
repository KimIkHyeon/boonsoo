#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;//정수
vector< vector<int> > bs;

void InputData(){ 
	cin >> N; 
}

void makeVector(vector< vector<int> >& bs)
{	
	for (int i = 1; i < N+1; i++) {
		bs[i].assign(i+1, -2);
	}
}

void checkboon(vector< vector<int> >& bs) 
{
	for (int i = 1; i < N+1; i++) {
		for (int j = 0; j < i+1; j++) {
			if (bs[i][j] == -1) continue;
			int t = 2;
			while (i * t <= N) {
				bs[i*t][j*t] = -1;
				t++;
			}
			bs[i][j] = 1000000*j/i;
		}
	}
}

void makevp(vector< pair<int, int> >& tmp, const vector< vector<int> >& bs)
{
	for (int i = 1; i < N+1; i++) {
		for (int j = 0; j < i+1; j++) {
			if (bs[i][j] == -1) continue;
			tmp.push_back(make_pair(i,j));
		}
	}
}

void finish(const vector< pair<int, int> >& tmp)
{
	for (int i = 0; i < tmp.size(); i++) {
		cout << tmp[i].second << "/" << tmp[i].first << endl;
	}
}

bool comp(const pair<int,int>& a, const pair<int, int>& b)
{
	return bs[a.first][a.second] < bs[b.first][b.second];
}

int main() {
	InputData();//입력
	
	//여기서부터 작성
	bs.assign(N+1, vector<int>(0));
	makeVector(bs);
	checkboon(bs);
	
	vector< pair<int, int> > tmp;
	makevp(tmp, bs);
	sort(tmp.begin(), tmp.end(), comp);
	

	finish(tmp);
	
	return 0;
}
