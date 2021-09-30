#include "setSimple.hxx"

int main() {
    std::srand(unsigned(std::time(NULL)));
    setSimple<int> A, B, C;

    setSimple<std::string>D,E,F;

    D.insert("ABCD");
    
    E.insert("EFGH");
    
    D.view();
    E.view();

    F = D + E;

    F.view();

    generator(A, 100, 100);
    std::cout << "A:\n";
    A.view();
    generator(B, 100, 100);
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
    std::cout << "(C insert 11111)\n";
    C.insert(11111);
    C.view();
    std::cout << "(C delete 11111)\n";
    C.del(11111);
    C.view();
    std::cout << "(A==B)?\n";
    if(A==B) std::cout << "YES\n";
    else std::cout << "NO\n";


      return 0;
}