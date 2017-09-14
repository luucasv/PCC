#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int edit_distance(const std::string &x, const std::string &y) {
  int n = x.size(), m = y.size();
  std::vector<std::vector<int>> memo(2, std::vector<int>(m+1));
  for (int j = 0; j <= m; j++) {
    memo[0][j] = j;
  }
  for (int i = 1; i <= n; i++) {
    memo[i%2][0] = i;
    for (int j = 1; j <= m; j++) {
      int d = x[i-1] == y[j-1] ? 0 : 1;
      memo[i%2][j] = d + memo[1 - i%2][j-1];
      memo[i%2][j] = std::min(memo[i%2][j], 1 + memo[i%2][j-1]);
      memo[i%2][j] = std::min(memo[i%2][j], 1 + memo[1 - i%2][j]);
    }
  }
  return memo[n%2][m];
}

int main(){
  std::string x, y;
  std::cin >> x >> y;
  std::cout << edit_distance(x, y) << std::endl;
}
