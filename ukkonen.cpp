#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


class HashTree {
public:
  HashTree() {
    root = new Node;
    next_id = 0;
  }

  ~HashTree() {
    delete root;
  }

  int get_id (const std::vector<int> &v) {
    Node *cur = root;
    for (int i = 1; i < v.size(); i++) {
      int delta = v[i] - v[i-1] + 1;
      if (cur[delta] == NULL) {
        cur[delta] = new Node();
      }
      cur = cur[delta];
    }
    if (cur.id() == -1) {
      cur.id() = next_id++;
    }
    return cur.id();
  }
private:
  class Node {
  public:
    Node() {
      children[0] = children[1] = children[2] = NULL;
      id = -1;
    }

    ~Node() {
      for (int i = 0; i < 3; i++) {
        if (children[i] != NULL)
          delete children[i];
      }
    }

    Node* operator[](int i) {
      return children[i];
    }

    int& id() {
      return id;
    }
  private:
    Node *children[3];
    int id;
  };
  int next_id;
  Node *root;
}

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

std::vector<int> seller(const std::string &T, const std::string &P, int max_error) {
  int n = T.size(), m = P.size();
  std::vector<std::vector<int>> memo(2, std::vector<int>(m+1, 0));
  for (int j = 0; j <= m; j++) {
    memo[0][j] = j;
  }
  std::vector<int> occ;
  for (int i = 1; i <= n; i++) {
    memo[i%2][0] = 0;
    for (int j = 1; j <= m; j++) {
      int d = T[i-1] == P[j-1] ? 0 : 1;
      memo[i%2][j] = d + memo[1 - i%2][j-1];
      memo[i%2][j] = std::min(memo[i%2][j], 1 + memo[i%2][j-1]);
      memo[i%2][j] = std::min(memo[i%2][j], 1 + memo[1 - i%2][j]);
    }
    if (memo[i%2][m] <= max_error) {
      occ.push_back(i - 1);
    }
  }
  return occ;
}

void print_vetor(std::vector<int> v) {
  std::cout << "[";
  for (int i = 0; i < v.size(); i++) {
    if (i > 0) {
      std::cout << ", ";
    }
    std::cout << v[i];
  }
  std::cout << "]\n";
}

int main(){
  std::string T, P;
  int err;
  std::cin >> T >> P >> err;
  std::vector<int> occ = seller(T, P, err);
  print_vetor(occ);
}
