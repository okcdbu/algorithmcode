#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;

int isvisit[1001][1001];
queue<pair<int,int>> q;
int main() {
  int N;
  cin >> N;
  isvisit[1][0] = 0;
  q.push({1,0});
  while(!q.empty()){
    int screen = q.front().first;
    int clipboard = q.front().second;
    q.pop();
    if(!isvisit[screen][screen]){
      isvisit[screen][screen] = isvisit[screen][clipboard] + 1;
      q.push({screen,screen});
    }
    if((screen + clipboard <= N) && !isvisit[screen + clipboard][clipboard]){
      isvisit[screen + clipboard][clipboard] = isvisit[screen][clipboard] + 1;
      q.push({screen + clipboard,clipboard});
    }
    if(!isvisit[screen - 1][clipboard] && screen >= 1){
      isvisit[screen - 1][clipboard] = isvisit[screen][clipboard] + 1;
      q.push({screen - 1,clipboard});
    }
  }
  int answer = 98765432;
  for(int i=0;i<=N;i++){
    if(!isvisit[N][i])continue;
    answer = min(answer,isvisit[N][i]);
  }
  cout << answer << '\n';
}