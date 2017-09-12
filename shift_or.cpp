#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


class MyBitSet {
public:
  MyBitSet(){}
  MyBitSet(int length, bool start = true) {
    int ceil = (length + SIZE - 1) / SIZE;
    this->length = ceil;
    if (start) {
      this->bits.assign(ceil, ((UM << (SIZE - 1)) - 1) | (UM << (SIZE - 1)));
    } else {
      this->bits.assign(ceil, (__uint128_t) 0);
    }
  }

  int operator[](int pos) {
    int id = pos / SIZE, in = pos % SIZE;
    return (bits[id] >> in)&1;
  }
  
  MyBitSet operator<<(int shift) {
    MyBitSet ans(SIZE * ceil, false);
    for (int i = length - 1; i > -1; --i) {

    }
  }
private:
  const int SIZE = sizeof(__uint128_t) * 8;
  const __uint128_t UM = 1;
  int length;
  std::vector<__uint128_t> bits;

  void set_mask(int pos, __uint128_t mask) {
    int id = pos / SIZE, in = pos % SIZE;
    bits[id] |= (mask >> (SIZE - 1 - in));
    if (id - 1 >= 0 &&) {
      bits[id - 1] |= (mask << in)
    }
  }

};

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

}
