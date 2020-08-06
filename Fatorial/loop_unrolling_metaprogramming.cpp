#include <iostream>

//declaração do template primário
template <int N, typename T>
class dotp {
public:
    static T result (T* a, T* b) {
        return (*a) * (*b) + dotp<N - 1,T>::result(a + 1, b + 1);
    }
};

//especialização parcial para condição final
template <typename T>
class dotp<1,T> {
public:
    static T result(T* a, T* b){
        return (*a) * (*b);
    }
};

int main(){
    float a[5] = {1,2,3,4,5};
    float b[5] = {6,7,8,9,10};

    std::cout << "dot_product(5,a,b)= " << dotp<5,float>::result(a,b) << std::endl;
    std::cout << "dot_product(5,a,a)= " << dotp<5,float>::result(a,a) << std::endl;
}