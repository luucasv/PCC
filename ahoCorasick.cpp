#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>

class Trie{
public:
  struct node{
    std::unordered_map<char, node*> edges;
    std::unordered_set<int> theta;
  };

  Trie(std::vector<std::string> pi){
    root = new node;
    for(std::string s : pi){
      insert(s);
    }
  }

  void insert(const std::string& s){
    node *cur = root;
    for(char ch : s){
      if(!cur->edges.count(ch)){
        cur->edges[ch] = new node;
      }
      cur = cur->edges[ch];
    }
  }

private:
  node *root;
};


std::vector<int> ahoCorasick(std::string T, std::string P, int sigmaSize){
	int n = T.size(), m = P.size();
  std::vector<std::vector<int>> A = buildFSM(P, sigmaSize);
  std::vector<int> occ;
  int state = 0;
  for(int i = 0; i < n; i++){
    state = A[state][T[i]];
    if(state == m){
      occ.push_back(i - m + 1);
    }
  }
  return occ;
}

void printVector(std::vector<int> v){
	std::cout << "[";
	for(int i = 0; i < v.size(); i++){
		if(i > 0){
			std::cout << ", ";
		}
		std::cout << v[i];
	}
	std::cout << "]\n";
}

int main(){
	std::string txt = "abracadabra", pat = "abra";
	std::vector<int> occ = ahoCorasick(txt, pat, 500);
	printVector(occ);
}
