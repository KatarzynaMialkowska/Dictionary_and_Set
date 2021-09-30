#include "dictionarySimple.hxx"

int main() {
    std::srand(unsigned(std::time(NULL)));
    DictonarySimple A, B, C;

    generator(A, 10);
    std::cout << "A:\n";
    A.view();
    generator(B, 10);
    std::cout << "B:\n";
    B.view();

    std::cout << "||OPERATIONS||\n";
    
    std::cout << "(C = A + B)\n";
    C = A + B;
    C.view();

    std::cout << "(C = A - B)\n";
    C = A - B;
    C.view();

    std::cout << "(C insert ABC)\n";
    C.insert("ABC");
    C.view();

    std::cout << "(C delete ABC)\n";
    C.del("ABC");
    C.view();
    
    std::cout << "(C = A && B)\n";
    C = A && B;
    C.view();
    
    std::cout << "(A==B)?\n";    
    if(A==B) std::cout << "YES\n";
    else std::cout << "NO\n";


      return 0;
}