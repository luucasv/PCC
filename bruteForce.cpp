#include <iostream>
#include <string>
#include <list>

std::list<int> bruteForce(std::string T, std::string P){
	int n = T.size(), m = P.size();
	std::list<int> occ;
	for(int i = 0; i <= n - m; i++){
		int j;
		for(j = 0; j < m && T[i+j] == P[j]; j++);
		if(j == m){
			occ.push_back(i);
		}
	}
	return occ;
}

void printList(std::list<int> v){
	if(v.empty()){
		std::cout << "[]\n";
		return;
	}
	std::cout << "[" << *v.begin();
	v.pop_front();
	for(int a : v){
		std::cout << " , " << a;
	}
	std::cout << "]\n";
}

int main(){
	std::string txt = "abracadabra", pat = "abra";
	std::list<int> occ = bruteForce(txt, pat);
	printList(occ);
}