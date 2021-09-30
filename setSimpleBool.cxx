#include "setSimpleBool.hxx"

int main() {
    std::srand(unsigned(std::time(NULL)));
    setSimple A, B, C;

    generator(A, 10, 100);
    std::cout << "A:\n";
    A.view();
    generator(B, 10, 100);
    std::cout << "B:\n";
    B.view();

    std::cout << "||OPERATIONS||\n";
    std::cout << "(C = A + B)\n";
    C = A + B;
    C.view();
    std::cout << "(C = A - B)\n";
    C = A - B;
    C.view();
    std::cout << "(C = A && B)\n";
    C = A && B;
    C.view();
    std::cout << "(C insert 11)\n";
    C.insert(11);
    C.view();
    std::cout << "(C delete 11)\n";
    C.del(11);
    C.view();
    std::cout << "(A==B)?\n";
    if(A==B) std::cout << "YES\n";
    else std::cout << "NO\n";


      return 0;
}