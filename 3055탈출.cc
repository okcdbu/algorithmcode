#include <iostream>
#include <algorithm>
#include <queue>
#include <string>
using namespace std;
char map[51][51];
int dp[51][51],startp,endp;
queue<pair<int,int>> stream,mole;
int dir[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};
int main() {
  int R,C;
  cin >> R >> C;
  for(int i=0;i<R;i++){
    string buf;
    cin >> buf;
    for(int j=0;j<C;j++){
      map[i][j] = buf[j];
      if(buf[j] == 'S')
        startp= i * C + j;
      else if(buf[j] == 'D'){
        endp = i * C + j;
      }
      else if(buf[j] == '*'){
        stream.push({i,j});
      }
    }
  }
  mole.push({startp / C,startp % C});
  dp[startp / C][startp % C] = 1;
  while(!mole.empty()){
    int streamlength = stream.size();
    for(int i=0;i<streamlength;i++){
      int x = stream.front().first;
      int y = stream.front().second;
      stream.pop();
      for(int k=0;k<4;k++){
        int nextX= x + dir[k][0];
        int nextY = y + dir[k][1];
        if(nextX >= 0 && nextX < R && nextY >= 0 && nextY < C){
          if(map[nextX][nextY] == '.'){
            map[nextX][nextY] = '*';
            stream.push({nextX,nextY});
          }
        }
      }
    }
    int molesize = mole.size();
    for(int i=0;i<molesize;i++){
      int x = mole.front().first;
      int y = mole.front().second;
      mole.pop();
      if(x == endp / C && y == endp % C){
        cout << dp[x][y] - 1 << '\n';
        exit(0);
      }
      for(int k=0;k<4;k++){
        int nextX = x + dir[k][0];
        int nextY = y + dir[k][1];
        if(nextX >= 0 && nextX < R && nextY >= 0 && nextY < C){
          if(map[nextX][nextY] != '*'&&map[nextX][nextY] != 'X'&&dp[nextX][nextY] == 0){
            dp[nextX][nextY] = dp[x][y] + 1;
            mole.push({nextX,nextY});
          }
        }
      }
    }
  }
  cout << "KAKTUS" << '\n';

}