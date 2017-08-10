#include <iostream>
#include <string>
#include <vector>

std::vector<int> bruteForce(std::string T, std::string P){
	int n = T.size(), m = P.size();
	std::vector<int> occ;
	for(int i = 0; i <= n - m; i++){
		int j;
		for(j = 0; j < m && T[i+j] == P[j]; j++);
		if(j == m){
			occ.push_back(i);
		}
	}
	return occ;
}

int main(){
	std::string txt = "abracadabra", pat = "abra";
	std::vector<int> occ = bruteForce(txt, pat);
	for(int oc : occ){
		std::cout << oc << ' ';
	}
	std::cout << '\n';
}