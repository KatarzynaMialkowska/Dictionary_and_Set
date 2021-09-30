#pragma once

#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <ctime>
#include <random>
#include <iomanip>
#include "LinkedList.hxx"

template <class T> 
class setLinked {
    LinkedList<T>set;

    public:
    setLinked() = default;
    setLinked(const setLinked<T>& obj) : set(obj.set){}

    setLinked operator+(setLinked<T> &obj) {
        setLinked<T> result(*this);
        for(auto a : obj.set) {
            if(a<=set.last() && !find_(a)) result.insert(a);
            else result.insert(a);
        }
        return result;
    }

    setLinked operator&&(setLinked<T> &obj) {
        setLinked<T> result;

        if(set.size() < obj.set.size()) {
            for(auto a : set) {
                if(obj.find_(a)) result.insert(a);
                if(a>=obj.set.last()) break;
            }
        }else{
            for(auto a : obj.set) {
                if(find_(a)) result.insert(a);
                if(a>=set.last()) break;
            }
        }
        return result;
    }
    
    setLinked operator-(setLinked<T> &obj) {
        setLinked<T> result;

        for(auto a : set) {
            if(!obj.find_(a)) result.insert(a);
            if(a > obj.set.last())break;
        }
        return result;
    }
        
    bool operator==(setLinked<T> &obj) {
        if(set.size() != obj.set.size()) return false;
        else{
            for(auto a : obj.set) {
                if(!find_(a)) return false;
            }
        }
        return true;
    }
            
    bool operator!=(const setLinked<T> &obj) {
        return !(*this==obj);
    }

    void insert(T x) {
        if(!find_(x)) 
            set.sort_insert(x);
    }


    bool find_(T x) {
        for(auto a : set) {
            if(a == x)return true;
            if(a >= x)break;
        }
        return false;    
    }

    void del(T x) {
        int id{0};
        for(auto a : set) {
            if(a == x){
                set.erase(set.find(x));
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

};

template<class T>
void generator(setLinked<T>& obj, const int& n, const int&& max) {  
    static std::uniform_int_distribution<int> dist1 ( 0, max );
    static std::mt19937 gen ( time ( NULL ) );
  
    for( int i = 0; i < n; i++ ) {
        obj.insert(dist1(gen));
    }
}
