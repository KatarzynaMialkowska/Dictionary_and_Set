#include "setHashed.hxx"

int main() {

    setHashed<std::string, 10> A, B, C;

    std::cout << "\tA:\n";
    A.add("ALA");
    A.add("MA");
    A.add("KOTA");
    A.add("I");
    A.add("SIE");
    A.add("CIESZY");
    A.viewAll();
    
    std::cout << "\tB:\n";
    B.add("ALA");
    B.add("MA");
    B.add("KOTA");
    B.add("I");
    B.add("PSA");
    B.viewAll();

    std::cout << "\tC = A + B:\n";
    C = A + B;
    C.viewAll();

    std::cout << "\tC = A - B:\n";
    C = A - B;
    C.viewAll();

    std::cout << "\tC = A && B\n";
    C = A && B;
    C.viewAll();

    std::cout << "\tC del KOTA:\n";
    C.del("KOTA");
    C.viewAll();


    std::cout << "\t(A==B)?\n";
    if(A==B) std::cout << "YES\n";
    else std::cout << "NO\n";

    return 0;
}
