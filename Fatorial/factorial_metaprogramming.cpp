#include <iostream>
//Define um template primario sem parametro especifico

template <uint32_t n>
struct fact {
    const static uint32_t value = n * fact<n - 1>::value;
};

//Templeta especializado para condição n = 0
template <>
struct fact <0> {
    const static uint32_t value = 1;
};

using namespace std;

int main(){
    cout << "Fact<0>= " << fact<0>::value << endl;
    cout << "Fact<10>= " << fact<10>::value << endl;

    //uint32_t m = 5;
    //cout << fact<m>::value << endl;
}