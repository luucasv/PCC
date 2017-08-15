#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

std::string gen(int x){
    if(x == 0){
        return "a";
    }
    std::string bf = gen(x-1);
    return bf + char('a' + x) + bf;
}

int main(){
    srand(time(NULL));
    int x;
    std::cin >> x;
    std::string st = gen(x);
    std::cin >> x;
    int n = st.size(), i = rand()%(n-x);
    std::cout << st << std::endl;
    std::cout << st.substr(i, i+x) << std::endl;
}

