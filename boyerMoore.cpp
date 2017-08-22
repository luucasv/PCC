#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

std::vector<int> getBadChar(std::string P, int sigmaSize){
  int m = P.size();
  std::vector<int> ans(sigmaSize, -1);
  for(int i = 0; i < m; i++){
    ans[P[i]] = i;
  }
  return ans;
}

std::vector<int> getBorder(std::string P){
	int m = P.size();
	std::vector<int> nxt(m+1, 0);
  int i = 1, j = 0;
	while(i+j < m){
		while(i+j < m && P[i+j] == P[j]){
			j++;
      nxt[i+j] = j;
    }
		i += std::max(1, j - nxt[j]);
		j = nxt[j];
	}
	return nxt;
}

std::vector<int> getGoodSufix(std::string P){
  std::string rev = P;
  std::reverse(rev.begin(), rev.end());
  int m = P.size();
  int PBorder = getBorder(P)[m];
  std::vector<int> revBorder = getBorder(rev), S(m+1, m - PBorder);
  for(int l =  1; l <= m; l++){
    int j = m - revBorder[l];
    S[j] = std::min(S[j], l - revBorder[l]);
  }
  return S;
}

std::vector<int> boyerMoore(std::string T, std::string P, int sigmaSize){
	int n = T.size(), m = P.size();
  std::vector<int> bad = getBadChar(P, sigmaSize), good = getGoodSufix(P), occ;
	for(int i = 0; i <= n - m; i++){
		int j = m-1;
		while(j > -1 && T[i+j] == P[j]){
      j--;
    }
    if(j < 0){
      occ.push_back(i);
      i += good[0];
    }
    else{
      i += std::max(good[j+1], j - bad[T[i+j]]);
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
	std::vector<int> occ = boyerMoore(txt, pat, 500);
	printVector(occ);
}
