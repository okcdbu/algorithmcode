#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;
int dp[1001][1001][2],wall[1001][1001];
int dir[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
typedef struct Vertex{
  int x,y,wall,cnt;
}Vertex;
int main() {
  int N,M;
  cin >> N >> M;
  for(int i=0;i<N;i++){
    string buf;
    cin >> buf;
    for(int j=0;j<M;j++){
      wall[i][j] = buf[j] - '0';
    }
  }
  queue <Vertex> q;
  q.push({0,0,0,1});
  dp[0][0][0] = 1;
  while(!q.empty()){
    int x = q.front().x;
    int y = q.front().y;
    int wallcnt = q.front().wall;
    int cnt = q.front().cnt;
    q.pop();
    //cout << "x : " << x << "y : " << y << "wall : " << wallcnt << "cnt : " << cnt << '\n'; 
    if(x==N-1 && y==M-1){
      cout << cnt << '\n';
      exit(0);
    }
    for(int i=0;i<4;i++){
      int nx = x + dir[i][0];
      int ny = y + dir[i][1];
      if(nx >= N || nx < 0 || ny >= M || ny < 0) continue;
      if(wall[nx][ny] == 1 && wallcnt == 0){
        dp[nx][ny][wallcnt + 1] = 1;
        q.push({nx,ny,wallcnt + 1,cnt + 1});
      }
      else if(wall[nx][ny] == 0 && dp[nx][ny][wallcnt] == 0){
        dp[nx][ny][wallcnt] = 1;
        q.push({nx,ny,wallcnt,cnt + 1});
      }
    }
  }
  cout << -1 <<'\n';
}