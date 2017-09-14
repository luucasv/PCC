#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


class MyBitSet {
public:
  MyBitSet() {}
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
    int bucket = pos / SIZE, id = pos % SIZE;
    return (bits[bucket] >> id)&1;
  }

  void reset(int pos) {
    int bucket = pos / SIZE, id = pos % SIZE;
    bits[bucket] &= ~(UM << id);
  }
  
  void reset(int pos) {
    int bucket = pos / SIZE, id = pos % SIZE;
    bits[bucket] |= (UM << id);
  }

  MyBitSet operator<<=(int shift) {
    for (int i = length - 1; i > -1; --i) {
      __uint128_t val = bits[i];
      int pos = (i + 1) * SIZE - 1 + shift;
      bits[i] = 0;
      set_mask(pos, val);
    }
    return *this;
  }

  MyBitSet operator<<(int shift) {
    MyBitSet ans(SIZE * ceil, false);
    for (int i = length - 1; i > -1; --i) {
      __uint128_t val = bits[i];
      int pos = (i + 1) * SIZE - 1 + shift;
      ans.set_mask(pos, val);
    }
    return ans;
  }

  __uint128_t& get_bucket(int buck) {
    return bits[buck];
  }

  MyBitSet operator|(const MyBitSet &bit_array) {
    MyBitSet ans = bit_array;
    for (int i = 0; i < length; i++) {
      ans.get_bucket(i) |= bits[i];
    }
    return ans;
  }
private:
  const int SIZE = sizeof(__uint128_t) * 8;
  const __uint128_t UM = 1;
  int length;
  std::vector<__uint128_t> bits;

  void set_mask(int pos, __uint128_t mask) {
    int bucket = pos / SIZE, id = pos % SIZE;
    if (bucket < length) {
      bits[bucket] |= (mask >> (SIZE - 1 - id));
    }
    if (bucket - 1 >= 0 && id + 1 < SIZE) {
      bits[bucket - 1] |= (mask << (id + 1))
    }
  }
};

std::vector<MyBitSet> char_mask(std::string P, int sigmaSize) {
  std::vector<MyBitSet> ans(sigmaSize, MyBitSet(P.size()));
  MyBitSet stamp(P.size());
  stamp.reset(0);
  for (int i = 0; i < P.size(); i++) {
    ans[P[i]] &= stamp;
    stamp <<= 1;
    stamp.reset(0);
  }
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

}
