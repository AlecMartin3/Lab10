//
// Created by Alec on 2019-12-06.
//

#ifndef LAB10_OBSERVER_HPP
#define LAB10_OBSERVER_HPP


template <typename T, typename STL>
class Subject;

using namespace std;
template <typename T, typename STL>
class Observer {
public:
    Subject<T, STL> *subject;
    static int nextID;
    int id;
    Observer(){
        id = ++nextID;
    }
    void RegisterSubject(Subject<T, STL> *sub) {subject = sub;}
    void Update(){
        if(subject == nullptr)
            return;
        heap<T, STL> hp = subject->getHeap();

        cout << "Observer " << id << " for: " << hp << endl;
    }

};
template<class T, class STL>
int Observer<T, STL>::nextID = 0;



#endif //LAB10_OBSERVER_HPP
