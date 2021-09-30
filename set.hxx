#pragma once

#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <ctime>
#include <random>
#include <iomanip>
#include <string>
#include<cmath>

constexpr int M = 2526;
constexpr int n = 10;
constexpr int N_ = 26;

class x {
    int tab[M];
    int n;
    public:
    x() {
        for(int i = 0; i < M; i++) 
            tab[i] = n + i;         
    }

    bool check(int k) {
        for(int i = 0; i < M; i++) 
            if(tab[i] == k) return true;
            
        return false;
    }

    int get(int k) {
   
        if(k>=0 && k<M) return tab[k];
        else return -1;
    }

    int getID(int k) {     
        std::cout<<k<<'\n';
        for(int i = 0; i < N_; i++) 
            if(k == tab[i]) return i;

        return -1;
    }
};

class x2 {
    int tab[M];
    int n;
    public:
    x2() {
        for(int i = 0; i < M; i++)
            tab[i] = n + (i*2); 
    }

    bool check(int k) {
        for(int i = 0; i < M; i++) 
            if(tab[i] == k) return true;
            
        return false;
    }

    int get(int k) {
        if(k>=0 && k<M) return tab[k];
        else return -1;
    }

    int getID(int k) {
        for(int i = 0; i < M; i++) 
            if(k == tab[i])return i;

        return -1;
    }
};

class abc {
    char L[N_] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','y','v','w','x','y','z'};

    public:
    bool check(char k) {
        for(int i = 0; i < N_; i++) 
            if(L[i] == k) return true;
            
        return false;
    }

    int getID(char k) {
        for(int i = 0; i < N_; i++) 
            if(k == L[i])return i;

        return -1;
    }    
    
    char get(int k) {
            if(k>=0 && k<N_) return L[k];
            else return '0';
    }
};

class abc2 {
    // 97 - 122
    char L[N_] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','y','v','w','x','y','z'};
    public:
    bool check(std::string k) {
        if((int)k[0]>=97 && (int)k[0]<=122 && (int)k[1]>=97 && (int)k[1]<=122) return true;
        else return false;
    }

    int getID(std::string k) {
        int result = 0;
        if(check(k)) {
                result = ( (int)k[0] - 97 ) * 100;
                result += ( (int)k[1] - 97);
        return result;
        }else return -1;
    }
    
    std::string get(int k) {
        std::string result;
        result = L[k / 100];
        result += L[k % 100];
        return result;
    }

};

template <class T, class U>
class Set {
    bool set[M]{false};
    U* typ = new U;

    public:
    Set() = default;
    Set(const Set& obj) {
        for(int i = 0; i<M; i++){
            set[i] = obj.set[i];
        }
    }

    Set operator+(const Set &obj) {
        Set result(*this);

        for(int i = 0; i < M; i++) {
            if(obj.set[i]==true && result.set[i]==false) result.set[i]=true;
        
        }
        return result;
    }

    Set operator&&(Set &obj) {
        Set result;

        for(int i = 0; i<M; i++) {
            if(obj.set[i]==true && set[i]==true) result.set[i]=true;
        }
        return result;
    }
    
    Set operator-(Set &obj) {
        Set result(*this);

        for(int i = 0; i<M; i++) {
            if(obj.set[i]==true && set[i]==true) result.set[i]=false;
        }
        return result;
    }
        
    bool operator==(const Set &obj) {
        
        for(int i = 0; i<M; i++) {
            if(obj.set[i]!=set[i]) return false;
        }
        return true;
    }
            
    bool operator!=(const Set &obj) {
        return !(*this==obj);
    }

    void insert(T k) {
        //std::cout<<" k = "<< k <<'\n';
        //std::cout<<" typ->getID(k) = "<< typ->getID(k) <<'\n';
       if(typ->getID(k) != -1) {   
           set[typ->getID(k)] = true;
       }
    }

    bool find(T k) {
        if(typ->check(k) == true)return true;
        return false;    
    }

    void del(T k) {
        if(typ->check(k) == true)set[typ->getID(k)] = false;
        else std::cout<< k <<" not exsist\n";
    }

    void view() {
        for(int i = 0; i<M; i++) {
            if(set[i] == true)
                std::cout<<"["<<i<<"]"<<typ->get(i)<<" , ";
        }
        std::cout<<'\n';
    }


};


void generator(Set<int, x>& obj, const int& n_, const int&& max) {  
    static std::uniform_int_distribution<int> dist1 ( 0, max );
    static std::mt19937 gen ( time ( NULL ) );
    
    for( int i = 0; i < n_; i++ ) {
            obj.insert(dist1(gen));
    }
}

void generator(Set<int, x2>& obj, const int& n_, const int&& max) {  
    static std::uniform_int_distribution<int> dist1 ( 0, max );
    static std::mt19937 gen ( time ( NULL ) );
    
    for( int i = 0; i < n_; i++ ) {
            obj.insert(dist1(gen));
    }
}

void generator(Set<char, abc>& obj, const int& n_) {  
    static std::uniform_int_distribution<int> dist1 ( 97, 122 );
    static std::mt19937 gen ( time ( NULL ) );
    
    for( int i = 0; i < n_; i++ ) {
            obj.insert((char)dist1(gen));
    }
}