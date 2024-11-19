#include<iostream>
#include<memory>
#include<vector>

using namespace std;

int main()
{
    unique_ptr<string> p1(new string("Hello World"));
    unique_ptr<string> p2(new string("konijiwa"));

    cout << "p1: " << *p1 << "\n" << "the address of the ptr1 is " << p1.get() <<endl;
    cout << "p2: " << *p2 << "\n" << "the address of the ptr2 is " << p2.get() <<endl;

    // unique_ptr<string> p3 = p1;  不允许左值赋值
    // unique_ptr<string> p4(p1);  不允许构造函数赋值

    p1 = move(p2);  //move把左值转为右值

    // reset方法：重置智能指针托管的内存地址，如果地址不一致，原来的会被析构掉
    p2.reset(new string("Hello World"));  /*通过reset在保留其为智能指针的情况下重置p2为p1原来的值
                                            释放掉智能指针托管的指针内存，并将参数指针取代之*/

    cout << "p1: " << *p1 << "\n" << "the address of the ptr1 is " << p1.get() <<endl;
    cout << "p2: " << *p2 << "\n" << "the address of the ptr2 is " << p2.get() <<endl;


//----------------------------------------------------------------------------------------------------------------



    unique_ptr<int> p3(new int(3));
    unique_ptr<int> p4(new int(4));

    vector<unique_ptr<int>> vec;

    vec.push_back(move(p3));
    vec.push_back(move(p4));

    cout << "p3: " << *vec.at(0) << endl;
    cout << "p4: " << *vec.at(1) << endl;

    p3.reset(new int(3));

    cout << p3.get() << " " << *p3 << endl;

    vec.at(1).reset(new int(5));

    cout << *vec.at(1) << endl;

    vec.at(0) = move(vec.at(1));
    vec.at(1).reset(new int(5));

    cout << "vec0: " << *vec.at(0) << "   vec0 addr: " << vec.at(0).get() << endl;
    cout << "vec1: " << *vec.at(1) << "   vec1 addr: " << vec.at(1).get() << endl;


//----------------------------------------------------------------------------------------------------------------



}