#include <iostream>
#include <cmath>


int main() {
    unsigned int a,b,c;

    for (c=999; c>1; c--) {
        for (a=1; a<334; a++) {
            b = 1000 - (a+c);
            if (pow(a,2) + pow(b,2) == pow(c,2)) {
                std::cout << "a: " << a << " b: " << b << " c: " << c << std::endl;
                std::cout << a*b*c << std::endl;
            }
        }
    }
}