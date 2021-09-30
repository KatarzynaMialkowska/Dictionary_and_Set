#include "setSimple.hxx"
#include "setLinked.hxx"
#include "setHashed.hxx"
#include "gnuplot.hxx"
#include <chrono>
#include <fstream>
#include <cmath>
#include <cstdio>

template<class T>
setSimple<T> sum_setSimple(setSimple<T> A, setSimple<T> B){return A+B;}
template<class T>
setSimple<T> diff_setSimple(setSimple<T> A, setSimple<T> B){return A-B;}
template<class T>
setSimple<T> comm_setSimple(setSimple<T> A, setSimple<T> B){return A&&B;}
template<class T>
setLinked<T> sum_setLinked(setLinked<T> A, setLinked<T> B){return A+B;}
template<class T>
setLinked<T> diff_setLinked(setLinked<T> A, setLinked<T> B){return A-B;}
template<class T>
setLinked<T> comm_setLinked(setLinked<T> A, setLinked<T> B){return A&&B;}
template<class T, int N>
setHashed<T, N> sum_setHashed(setHashed<T, N> A, setHashed<T, N> B){return A+B;}
template<class T, int N>
setHashed<T, N> diff_setHashed(setHashed<T, N> A, setHashed<T, N> B){return A-B;}
template<class T, int N>
setHashed<T, N> comm_setHashed(setHashed<T, N> A, setHashed<T, N> B){return A&&B;}


void test_100();
void test_1k();
void test_10k();

std::ofstream setSimpleData, setLinkedData, setHashedData;
std::string setSimplePlot("setSimpleData.dat");
std::string setLinkedPlot("setLinkedData.dat");
std::string setHashedPlot("setHashedData.dat");
std::string name_graphs("graphs");
std::string type("pdf");

    setSimple<std::string> As_100, Bs_100, Cs_100; //100 N
    setSimple<std::string> As_1k, Bs_1k, Cs_1k; //1000 N
    setSimple<std::string> As_10k, Bs_10k, Cs_10k; //10000 N
    setLinked<std::string> Al_100, Bl_100, Cl_100; 
    setLinked<std::string> Al_1k, Bl_1k, Cl_1k;
    setLinked<std::string> Al_10k, Bl_10k, Cl_10k;
    setHashed<std::string, 10> Ah_100, Bh_100, Ch_100; 
    setHashed<std::string, 10> Ah_1k, Bh_1k, Ch_1k;
    setHashed<std::string, 10> Ah_10k, Bh_10k, Ch_10k;

int main() {

    /*dane potrzebne do wykresów*/
    setSimpleData.open (setSimplePlot, std::ios::out | std::ios::app); 
    setLinkedData.open (setLinkedPlot, std::ios::out | std::ios::app); 
    setHashedData.open (setHashedPlot, std::ios::out | std::ios::app); 
    std::srand(unsigned(std::time(NULL)));

    int N = 10000;
    std::string x, y;
    for(int i=1; i<=N; i++){
        std::cin >> x;
        std::cin >> y;
        if(i<=100){
            As_100.insert(x); As_1k.insert(x); As_10k.insert(x); 
            Bs_100.insert(y); Bs_1k.insert(y); Bs_10k.insert(y);
            Al_100.insert(x); Al_1k.insert(x);  Al_10k.insert(x);
            Bl_100.insert(y); Bl_1k.insert(y); Bl_10k.insert(y);
            Ah_100.add(x); Ah_1k.add(x);  Ah_10k.add(x);
            Bh_100.add(y); Bh_1k.add(y); Bh_10k.add(y);
        }
        if(i>100 && i<=1000){
            As_1k.insert(x); As_10k.insert(x); 
            Bs_1k.insert(y); Bs_10k.insert(y);
            Al_1k.insert(x); Al_10k.insert(x);
            Bl_1k.insert(y); Bl_10k.insert(y);
            Ah_1k.add(x); Ah_10k.add(x);
            Bh_1k.add(y); Bh_10k.add(y);
        }
        if(i>1000 && i<=10000){
            As_10k.insert(x); 
            Bs_10k.insert(y);
            Al_10k.insert(x);
            Bl_10k.insert(y);
            Ah_10k.add(x);
            Bh_10k.add(y);
        }
    }
    // std::cout << "As:\n";
    // As_10k.view();
    // std::cout << "Bs:\n";
    // Bs_10k.view();
    // std::cout << "Al:\n";
    // Al_10k.view();
    // std::cout << "Bl:\n";
    // Bl_10k.view();

    test_100();
    test_1k();
    test_10k();


   /*Tworzenie wykresu*/
    gnuplot p;
    std::string setS("\'./" + setSimplePlot + "\' u 1:2 w l");
    std::string setL("\'./" + setLinkedPlot + "\' u 1:2 w l");
    std::string setH("\'./" + setHashedPlot + "\' u 1:2 w l");

    p("set terminal " + type);
    p("set output \"" + name_graphs + '.' + type + "\""); 
    p("set xlabel 'data'");
    p("set ylabel 't/s'");
    p("set title 'setSimple vs setLinked vs setHashed'");

        p("set xrange [0:10000]");
        p("set yrange [0:15]");
    p("plot " + setS + " , " + setL + " , " + setH);
 

    setSimpleData.close();
    setLinkedData.close();
    setHashedData.close();

    return 0;
}

void test_100() {
    int N = 100;
    std::cout << "\t-TEST 100 n-\n";

    /*test setSimple*/
    auto Sstart = std::chrono::high_resolution_clock::now();
        Cs_100 = sum_setSimple(As_100, Bs_100);
        Cs_100 = diff_setSimple(As_100, Bs_100);
        Cs_100 = comm_setSimple(As_100, Bs_100);
    auto Send = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> setSimpleElapsed = Send - Sstart;
    std::cerr << "setSimple elapsed time[s] =" << setSimpleElapsed.count() << std::endl;
        setSimpleData << N << '\t' << setSimpleElapsed.count() << '\n';

    /*test setLinked*/
    auto Lstart = std::chrono::high_resolution_clock::now();
        Cl_100 = sum_setLinked(Al_100, Bl_100);
        Cl_100 = diff_setLinked(Al_100, Bl_100);
        Cl_100 = comm_setLinked(Al_100, Bl_100);
    auto Lend = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> setLinkedElapsed = Lend - Lstart;
    std::cerr << "setLinked elapsed time[s] =" << setLinkedElapsed.count() << std::endl;
        setLinkedData << N << '\t' << setLinkedElapsed.count() << '\n';

       /*test setHashed*/
    auto Hstart = std::chrono::high_resolution_clock::now();
        Ch_100 = sum_setHashed(Ah_100, Bh_100);
        Ch_100 = diff_setHashed(Ah_100, Bh_100);
        Ch_100 = comm_setHashed(Ah_100, Bh_100);
    auto Hend = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> setHashedElapsed = Hend - Hstart;
    std::cerr << "setHashed elapsed time[s] =" << setHashedElapsed.count() << std::endl;
        setHashedData << N << '\t' << setHashedElapsed.count() << '\n';
    
}

void test_1k() {
    int N = 1000;
    std::cout << "\t-TEST 1000 n-\n";

    /*test setSimple*/
    auto Sstart = std::chrono::high_resolution_clock::now();
        Cs_1k = sum_setSimple(As_1k, Bs_1k);
        Cs_1k = diff_setSimple(As_1k, Bs_1k);
        Cs_1k = comm_setSimple(As_1k, Bs_1k);
    auto Send = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> setSimpleElapsed = Send - Sstart;
    std::cerr << "setSimple elapsed time[s] =" << setSimpleElapsed.count() << std::endl;
        setSimpleData << N << '\t' << setSimpleElapsed.count() << '\n';

    /*test setLinked*/
    auto Lstart = std::chrono::high_resolution_clock::now();
        Cl_1k = sum_setLinked(Al_1k, Bl_1k);
        Cl_1k = diff_setLinked(Al_1k, Bl_1k);
        Cl_1k= comm_setLinked(Al_1k, Bl_1k);
    auto Lend = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> setLinkedElapsed = Lend - Lstart;
    std::cerr << "setLinked elapsed time[s] =" << setLinkedElapsed.count() << std::endl;
        setLinkedData << N << '\t' << setLinkedElapsed.count() << '\n';


   /*test setHashed*/
    auto Hstart = std::chrono::high_resolution_clock::now();
        Ch_1k = sum_setHashed(Ah_1k, Bh_1k);
       // Ch_1k.viewAll();
        Ch_1k = diff_setHashed(Ah_1k, Bh_1k);
        Ch_1k = comm_setHashed(Ah_1k, Bh_1k);
    auto Hend = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> setHashedElapsed = Hend - Hstart;
    std::cerr << "setHashed elapsed time[s] =" << setHashedElapsed.count() << std::endl;
        setHashedData << N << '\t' << setHashedElapsed.count() << '\n';
    
}
void test_10k() {
    int N = 10000;
    std::cout << "\t-TEST 10000 n-\n";

    /*test setSimple*/
    auto Sstart = std::chrono::high_resolution_clock::now();
        Cs_10k = sum_setSimple(As_10k, Bs_10k);
        Cs_10k = diff_setSimple(As_10k, Bs_10k);
        Cs_10k = comm_setSimple(As_10k, Bs_10k);
    auto Send = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> setSimpleElapsed = Send - Sstart;
    std::cerr << "setSimple elapsed time[s] =" << setSimpleElapsed.count() << std::endl;
        setSimpleData << N << '\t' << setSimpleElapsed.count() << '\n';

    /*test setLinked*/
    auto Lstart = std::chrono::high_resolution_clock::now();
        Cl_10k = sum_setLinked(Al_10k, Bl_10k);
        Cl_10k = diff_setLinked(Al_10k, Bl_10k);
        Cl_10k= comm_setLinked(Al_10k, Bl_10k);
    auto Lend = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> setLinkedElapsed = Lend - Lstart;
    std::cerr << "setLinked elapsed time[s] =" << setLinkedElapsed.count() << std::endl;
        setLinkedData << N << '\t' << setLinkedElapsed.count() << '\n';


   /*test setHashed*/
    auto Hstart = std::chrono::high_resolution_clock::now();
        Ch_10k = sum_setHashed(Ah_10k, Bh_10k);
        Ch_10k = diff_setHashed(Ah_10k, Bh_10k);
        Ch_10k = comm_setHashed(Ah_10k, Bh_10k);
    auto Hend = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> setHashedElapsed = Hend - Hstart;
    std::cerr << "setHashed elapsed time[s] =" << setHashedElapsed.count() << std::endl;
        setHashedData << N << '\t' << setHashedElapsed.count() << '\n';
}

