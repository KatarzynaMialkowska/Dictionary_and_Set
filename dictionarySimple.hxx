#pragma once

#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <ctime>
#include <random>
#include <iomanip>
#include <string>

constexpr int N = 100;


class DictonarySimple {
    std::string set[N]{""};
    int size = 0;

    public:
    DictonarySimple() = default;
    DictonarySimple(const DictonarySimple& obj): set(obj.set), size(obj.size)  {
        for(int i = 0; i<N; i++){
            set[i] = obj.set[i];
        }
    }

    DictonarySimple operator+(const DictonarySimple &obj) {
        DictonarySimple result(*this);

        for(int i = 0; i<N; i++) {
            if(obj.set[i] != set[i]) {
                result.set[result.size] = obj.set[i]; 
                result.size++;
            }  
        }
        return result;
    }

    DictonarySimple operator&&(DictonarySimple &obj) {
        DictonarySimple result;

        for(int i = 0; i<N; i++) {
            if(obj.set[i]==set[i]) result.set[i] == obj.set[i];
        }
        return result;
    }
    
    DictonarySimple operator-(DictonarySimple &obj) {
        DictonarySimple result(*this);

        for(int i = 0; i<N; i++) {
            if(obj.set[i]==set[i]) result.set[i]=="";
        }
        return result;
    }
        
    bool operator==(const DictonarySimple &obj) {
        
        for(int i = 0; i<N; i++) {
            if(obj.set[i]!=set[i]) return false;
        }
        return true;
    }
            
    bool operator!=(const DictonarySimple &obj) {
        return !(*this==obj);
    }

    void insert(std::string x) {
        if(size>=0 && size<N)set[size] = x;
        else std::cout<<"size error\n";
    
        if(size < N)size++;
    }

    bool find(std::string x) {
        for(int i = 0; i < size; i++)
            if(set[i] == x) return true;

        return false;    
    }

    void del(std::string x) {
        for(int i = 0; i < size; i++)
            if(set[i] == x) set[i] = "";

        if(size>0) size--;
    }

    void view() {
        for(int i = 0; i < size; i++) {
                std::cout<<set[i]<<" ";
        }
        std::cout<<'\n';
    }

    int Size() {
        return size;
    }

    std::string getElement(int id) {
        if(id>=0 && id<N) return set[id];
        else "not exist\n";
    }

};

void generator(DictonarySimple& obj, const int& n) {  
    static std::uniform_int_distribution<int> dist1 ( 65, 90 );
    static std::mt19937 gen ( time ( NULL ) );
    std::string word;
    for( int i = 0; i < n; i++ ) {
        word+=(char)dist1(gen);
        word+=(char)dist1(gen);
        word+=(char)dist1(gen);
        obj.insert(word);
        word = "";
    }
}
