//
// Created by Alec on 2019-12-06.
//

#ifndef LAB10_HEAP_HPP
#define LAB10_HEAP_HPP

#include <vector>
#include <algorithm>
#include <ostream>

using namespace std;

template <typename T, typename STL>
class heap{
private:
    vector<T> data;

public:
    heap(STL & sequence){
        copy(sequence.begin(), sequence.end(), inserter(data, data.end()));
        heapify();
    }
    void heapify(){
        for (int i = size()/2-1; i >= 0; i--) {
            int largest = i;
            int l = 2 * i + 1;
            int r = 2 * i+ 2;

            if (l < size() && data.at(l) > data.at(largest))
                largest = l;

            if (r < size() && data.at(r) > data.at(largest))
                largest = r;

            if (largest != i) {
                swap(data.at(i), data.at(largest));
                heapify();
            }
        }
    }
    void push(T element){
        data.push_back(element);
        heapify();
    }
    void pop(){
        pop_heap(data.begin(),data.end());
        data.pop_back();
        heapify();
    }
    int size(){
        return data.size();
    }
    bool is_empty(){
        if(data.empty()){
            return true;
        }
        else{
            return false;
        }
    }
    void clear(){
        data.clear();
    }
    friend ostream &operator<<( ostream &output, const heap &h ){
        for (auto i = h.data.begin(); i != h.data.end(); ++i)
            output << *i << ' ';
        output << endl;
    }

//    void print(){
//        for (auto i = data.begin(); i != data.end(); ++i)
//            cout << *i << ' ';
//        cout << endl;
//    }
//    heap( heap const &h) = delete;
//    void operator= (const heap &h) = delete;
//    static heap& get_instance(STL sequence ){
//        static heap instance(sequence);
//        return instance;
//    }

};
#endif //LAB10_HEAP_HPP
