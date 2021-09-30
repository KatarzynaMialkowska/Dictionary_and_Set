#pragma once

#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <ctime>
#include <random>
#include <iomanip>

template <class T> 
class setSimple {
    std::vector<T> set;

    public:
    setSimple() = default;
    setSimple(const setSimple<T>& obj) {
        for(auto a : obj.set){
            set.push_back(a);
        }
    }

    setSimple operator+(const setSimple<T> &obj) {
        setSimple<T> result(*this);

        for(auto a : obj.set) {
            if(!find(a)) result.insert(a);
        }
        return result;
    }

    setSimple operator&&(setSimple<T> &obj) {
        setSimple<T> result;

        if(set.size() < obj.set.size()) {
            for(auto a : set) {
                if(obj.find(a)) result.insert(a);
            }
        }else{
            for(auto a : obj.set) {
                if(find(a)) result.insert(a);
            }
        }
        return result;
    }
    
    setSimple operator-(setSimple<T> &obj) {
        setSimple<T> result;

        for(auto a : set) {
            if(!obj.find(a)) result.insert(a);
        }
        return result;
    }
        
    bool operator==(const setSimple<T> &obj) {
        if(set.size() != obj.set.size()) return false;
        else{
            for(auto a : obj.set) {
                if(!find(a)) return false;
            }
        }
        return true;
    }
            
    bool operator!=(const setSimple<T> &obj) {
        return !(*this==obj);
    }

    void insert(T x) {
        if (!find(x)) 
            set.push_back(x);
    }

    bool find(T x) {
        for(auto a : set) {
            if(a == x)return true;
        }
        return false;    
    }

    void del(T x) {
        int id{0};
        for(auto a : set) {
            if(a == x){
                set.erase(set.begin()+id);
                break;
            }
            id++;
        }
     
    }

    void view() {
        for(auto a : set) {
            std::cout << a << " ";
        }
        std::cout<<'\n';
    }

    T getElement(int id){return set[id];}

};

template<class T>
void generator(setSimple<T>& obj, const int& n, const int&& max) {  
    static std::uniform_int_distribution<int> dist1 ( 0, max );
    static std::mt19937 gen ( time ( NULL ) );
  
    for( int i = 0; i < n; i++ ) {
        obj.insert(dist1(gen));
    }
}
