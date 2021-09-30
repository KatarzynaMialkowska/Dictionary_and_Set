#pragma once

#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <ctime>
#include <random>
#include <iomanip>
constexpr int N = 100;


class setSimple {
   bool set[N]{false};

    public:
    setSimple() = default;
    setSimple(const setSimple& obj) {
        for(int i = 0; i<N; i++){
            set[i] = obj.set[i];
        }
    }

    setSimple operator+(const setSimple &obj) {
        setSimple result(*this);

        for(int i = 0; i < N; i++) {
            if(obj.set[i]==true && result.set[i]==false) result.set[i]=true;
        
        }
        return result;
    }

    setSimple operator&&(setSimple &obj) {
        setSimple result;

        for(int i = 0; i<N; i++) {
            if(obj.set[i]==true && set[i]==true) result.set[i]=true;
        }
        return result;
    }
    
    setSimple operator-(setSimple &obj) {
        setSimple result(*this);

        for(int i = 0; i<N; i++) {
            if(obj.set[i]==true && set[i]==true) result.set[i]=false;
        }
        return result;
    }
        
    bool operator==(const setSimple &obj) {
        
        for(int i = 0; i<N; i++) {
            if(obj.set[i]!=set[i]) return false;
        }
        return true;
    }
            
    bool operator!=(const setSimple &obj) {
        return !(*this==obj);
    }

    void insert(int x) {
        if(x>=0 && x<N)set[x] = true;
        else std::cout<<"wrong arg\n";
    }

    bool find(int x) {
        if(set[x] == true)return true;
        return false;    
    }

    void del(int x) {
        if(x>=0 && x<N)set[x] = false;
            else std::cout<<"not exsist\n";
    }

    void view() {
        for(int i = 0; i<N; i++) {
            if(set[i]==true)
                std::cout<<i<<" ";
        }
        std::cout<<'\n';
    }

    int getElement(int id) {
        if(id>=0 && id<N) return set[id];
        else -1;
    }

};

void generator(setSimple& obj, const int& n, const int&& max) {  
    static std::uniform_int_distribution<int> dist1 ( 0, max );
    static std::mt19937 gen ( time ( NULL ) );
  
    for( int i = 0; i < n; i++ ) {
        obj.insert(dist1(gen));
    }
}
