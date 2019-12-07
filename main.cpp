#include <iostream>
#include "heap.hpp"
#include "Subject.hpp"
int main() {
//
//
//    cout << h;
//    h.push(9);
//    cout << h;
//    h.pop();
//    cout << h;
//

    std::vector<int> g ({12, 11, 13, 5, 6, 7 });
    heap<int, vector<int>> h(g);
    Subject<int, vector<int>> sub{h};
    Observer<int, vector<int>> ob1{};
    Observer<int, vector<int>> ob2{};

    sub.attach(&ob1);
    sub.attach(&ob2);
    sub.push(1);

    sub.detach(&ob1);
    sub.pop();

    std::vector<double> g2 ({12.2, 11.1, 13.6, 5.7, 6.4, 7.3 });
    heap<double, vector<double>> h2(g2);
    Subject<double, vector<double>> sub2{h2};
    Observer<double, vector<double>> ob3{};
    Observer<double, vector<double>> ob4{};

    sub2.attach(&ob3);
    sub2.attach(&ob4);
    sub2.push(1.4);

    sub2.detach(&ob3);
    cout << endl;
    sub2.pop();

    return 0;
}