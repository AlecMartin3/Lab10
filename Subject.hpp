//
// Created by Alec on 2019-12-06.
//

#ifndef LAB10_SUBJECT_HPP
#define LAB10_SUBJECT_HPP
#include <vector>
#include "Observer.hpp"
#include "State.hpp"
#include "heap.hpp"
template <typename T, typename STL>
class Subject {
public:
    std::vector<T> g;
    vector<Observer<T, STL>*>observers;
    heap<T, STL> h;

    Subject(heap<T,STL> hp) : h{hp} {
//        h(g);
    }
    void attach(Observer<T, STL> *o) {
        o->RegisterSubject(this);
        observers.push_back(o);
    }
    void detach(Observer<T, STL> *o){
        int deleteIndex = -1;
        for (int i=0; i<observers.size(); i++) {
            if(observers[i] == o)
            {
                deleteIndex = i;
                break;
            }
        }
        o->subject = nullptr;
        observers.erase(observers.begin()+deleteIndex);
    }
    void notify()
    {
        for(Observer<T, STL> *o : observers)
        {
            o->Update();
        }
    }
    void push(T object){
        h.push(object);
        cout << "pushed " << object << endl;
        notify();
    }
    void pop(){
        h.pop();
        cout << "popped" << endl;
        notify();
    }
    heap<T, STL>& getHeap(){
        return h;
    }
};


#endif //LAB10_SUBJECT_HPP
