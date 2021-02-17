#include <iostream>
#include <string>
#include <queue>
using namespace std;
int wall[101][101],M,N,answer = 987654321;
int dir[4][2] = {{0,1},{1,0},{0,-1},{-1,0}}; 
int dist[101][101];
bool isvisit[101][101];
struct Vertex{
  int cnt;
  pair<int,int> coordinate; 
  bool operator < (const struct Vertex& rhs) const 
  { 
    return cnt > rhs.cnt; 
    }
};
int main() {
  cin >> M >> N;
  for(int i=0;i<N;i++){
    string buf;
    cin >> buf;
    for(int j=0;j<M;j++){
      wall[i][j] = buf[j] - '0';
      dist[i][j] = 987654321;
    }
  }
  priority_queue<Vertex> pq;
  pq.push({0,{0,0}});
  isvisit[0][0] = true;
  dist[0][0] = 0;
  while(!pq.empty()){
    int x = pq.top().coordinate.first;
    int y = pq.top().coordinate.second;
    int cnt = pq.top().cnt;
    //cout << cnt << ", " << x << ", " << y << endl;
    pq.pop();
    if(x==M-1 && y == N-1){
      break;
    }
    for(int i=0;i<4;i++){
      int nx = x + dir[i][0];
      int ny = y + dir[i][1];
      if(nx >= N || nx < 0 || ny >= M || ny < 0) continue;
      int nds = dist[x][y] + wall[nx][ny];
      if(nds < dist[nx][ny]){
        dist[nx][ny] = nds;
        pq.push({nds,{nx,ny}});
      }
    }
  }

  cout << dist[N-1][M-1] << '\n';
}