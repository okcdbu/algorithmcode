#include <iostream>
#include <algorithm>
using namespace std;
int p[1001],dp[1001],n;
#define INF 987654321
void init(){
  cin >> n;
  for(int i=1;i<=n;i++){
    cin >> p[i];
    dp[i] = INF;
  }
}
int find(){
  for(int i=1;i<=n;i++){
    for(int j=1;j<=i;j++){
      dp[i] = min(dp[i],dp[i-j] + p[j]);
    }
  }
  return dp[n];
}
void debug(){
  for(int i=1;i<=n;i++){
    cout << dp[i];
  }
}
void answer(){
  
  cout << find() << '\n';
  //debug();
}
int main() {
  init();
  answer();
}