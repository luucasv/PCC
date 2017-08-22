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
	std::vector<int> occ = bruteForce(txt, pat);
	printVector(occ);
}
