#include "LinkedList.hxx"
#include <iostream>
#include <string>


template <class T, int N>
class setHashed {
    
    LinkedList<std::string> array[N];

    
    // hash function
    int hash(std::string item) {
        size_t value = 0;
        for (int i = 0; i < item.length(); i++)
            value = 31 * value + item[i] - 65;
        return value % 10;
    }
    
public:
    setHashed() = default;
    setHashed(const setHashed<T, N>& obj) : array(obj.array){
        for(int i = 0; i < N; i++)array[i] = obj.array[i];
    }

    setHashed operator+(setHashed<T,N> &obj) {
        setHashed<T, N> result(*this);
        for(int i = 0; i < N; i++)
            for(auto a : obj.array[i]) 
                if(!find_(a, i)) result.add(a);
        
        return result;
    }

    setHashed operator&&(setHashed<T, N> &obj) {
        setHashed<T, N> result;

        for(int i = 0; i < N; i++) 
            for(auto a : obj.array[i])
                   if(find_(a, i)) result.add(a);
 
        return result;
    }
    
    setHashed operator-(setHashed<T, N> &obj) {
        setHashed<T, N> result;

        for(int i = 0; i < N; i++) 
            for(auto a : array[i])
                   if(!obj.find_(a, i)) result.add(a);
 
        return result;
    }
        
    bool operator==(setHashed<T, N> &obj) {

        for(int i = 0; i < N; i++) {
            if(array[i].size() != obj.array[i].size()) return false;
            else{
                for(auto a : obj.array[i]) {
                    if(!find_(a, i)) return false;
                }
            }  
        }
 
        return true;
    }
            
    bool operator!=(const setHashed<T, N> &obj) {
        return !(*this==obj);
    }

    bool find_(T x, int id) {
        for(auto a : array[id]) {
            if(a == x)return true;
        }
        return false;    
    }
    
    void add(T x) {
        size_t id = hash(x);
        array[id].insert(x);
    }

    void del(T x) {
        size_t id = hash(x);
        array[id].remove(x);
    }

    void viewAll() {
        for(int i = 0; i < N; i++) {
            std::cout<<i<<"] ";
            for(auto a : array[i]) {
                std::cout << a << " ";
            }   
            std::cout<<'\n';
        }
            
     
    }
};
