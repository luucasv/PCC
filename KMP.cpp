#include <iostream>
#include <string>
#include <vector>

std::vector<int> getBorder(std::string P){
	int m = P.size();
	std::vector<int> nxt(m+1, -1);
	if(m == 0){
		return nxt;
  }
  int i = 1, j = 0;
  if(m == 1 || P[0] != P[1]){
		nxt[1] = 0;
  }
	while(i+j < m){
		while(i+j < m && P[i+j] == P[j]){
			j++;
			if(i+j == m || P[i+j] != P[j]){
        nxt[i+j] = j;
      }
      else{
        nxt[i+j] = nxt[j];
      }
		}
		i += j - nxt[j];
		j = std::max(0, nxt[j]);
	}
	return nxt;
}

std::vector<int> KMP(std::string T, std::string P){
	int n = T.size(), m = P.size();
	std::vector<int> occ;
	std::vector<int> nxt = getBorder(P);
	int i = 0, j = 0;
	while(i <= n-m){
		while(j < m && T[i+j] == P[j])
			j++;
		if(j == m){
			occ.push_back(i);
		}
		i += std::max(1, (j-nxt[j]));
		j = std::max(0, nxt[j]);
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
	std::string txt, pat;
	std::cin >> txt >> pat;
	std::vector<int> occ = KMP(txt, pat);
	printVector(occ);
}
