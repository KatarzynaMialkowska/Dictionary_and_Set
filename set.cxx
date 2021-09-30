#include "set.hxx"

int main() {
    std::srand(unsigned(std::time(NULL)));
    Set<int , x> A1, B1, C1;
    Set<char , abc> A, B, C;
    Set<std::string, abc2> D, E, F;
    D.insert("aa");
    D.insert("bb");
    D.insert("fg");
    D.insert("zb");
    E.insert("cz");
    E.insert("dd");
    E.insert("ab");
    E.insert("ba");
    D.insert("zz");
    E.insert("ba");
    D.insert("zz");
    F = D + E;
std::cout<<"------D-------\n";
    D.view();
std::cout<<"------E-------\n";
    E.view();
std::cout<<"------F=E+D-------\n";
    F.view();

//     A.insert('a');
//     A.insert('b');
//     A.insert('c');
//     A.insert('e');
//     A.del('a');
//     A.view();

//     B.insert('a');
//     B.insert('r');
//     B.insert('g');
//     B.insert('c');

//     B.view();
//     C = B - A;

//     C.view();
//     generator(A, 10);
//     A.view();
// std::cout<<"-------------\n";
//     D.view();
//     E.view();
//     F = D + E;
//     F.view();
    
//     std::cout << "(A==B)?\n";
//     if(A==B) std::cout << "YES\n";
//     else std::cout << "NO\n";


      return 0;
}