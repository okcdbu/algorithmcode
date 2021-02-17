#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
int N,K,answer = 987654321;
bool isvisit[100001] = {false,};
int main() {
  cin >> N >> K;
  priority_queue<pair<int,int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
  q.push({0,N});
  isvisit[N] = true;
  while(!q.empty()){
    int first = q.top().first;//second
    int second = q.top().second;//position
    q.pop();
    if(second == K){
      answer = first;
      break;
    }
    if((second * 2 <= 100000) && !isvisit[second * 2]){
      q.push({first , second * 2});
      isvisit[second * 2] = true;
    }
    if((second + 1 <= 100000)&& !isvisit[second + 1]){
      q.push({first + 1,second + 1});
      isvisit[second + 1] = true;
    }
    if((second - 1 >= 0) && !isvisit[second - 1]){
      q.push({first + 1,second - 1});
      isvisit[second - 1] = true;
    }
  }
  cout << answer << '\n';
}