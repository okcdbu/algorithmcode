#include <iostream>
#include <algorithm>
using namespace std;
long long dp[4][1000001];
void solution(){
  int n;
  cin >> n;
  dp[1][1] = dp[2][2] = dp[3][3] = dp[1][3] = dp[2][3] = 1;
  for(int i=4;i<=n;i++){
    dp[1][i] = (dp[2][i-1] + dp[3][i-1] )% 1000000009;
    dp[2][i] = (dp[1][i-2] + dp[3][i-2])% 1000000009;
    dp[3][i] = (dp[1][i-3] + dp[2][i-3])% 1000000009;
  }
  cout << (dp[1][n] + dp[2][n] + dp[3][n])% 1000000009 << '\n';
}
void TC(){
  int T;
  cin >> T;
  while(T--){
    solution();
  }
}
int main() {
  TC();
}