#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

std::vector<std::vector<int>> buildFSM(std::string P, int sigmaSize){
  int m = P.size();
  std::vector<std::vector<int>> A(m+1, std::vector<int>(sigmaSize, 0));
  A[0][P[0]] = 1;
  int brd = 0;
  for(int i = 1; i <= m; i++){
    for(int a = 0; a < sigmaSize; a++){
      brd = A[brd][P[i-1]];
      if(i < m && a == P[i]){
				A[i][a] = i+1;
      }
			else{
				A[i][a] = A[brd][a];
      }
    }
	}
  return A;
}

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
