#include<iostream>
#include<list>
#include<string>

using namespace std;

template<class T>
void prtlist(const list<T>& list)
{
    for (typename list<T>::const_iterator it = list.begin(); it != list.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;
}

class Main
{
    public:
        Main()
        {
            // list<int> list1 = {1, 2, 3};
            // list<int> list2(3, 3);
            // list<int> list3(list2);
            // list<string> list4 = {"Hello", "World"};
            // list<string> list5 = list4;
            // list<string> list6(3, "Hello World ");
            // list6.assign(2, "Good"); //整个list进行替换
            // prtlist(list1);
            // prtlist(list2);
            // prtlist(list3);
            // prtlist(list4);
            // prtlist(list5);
            // prtlist(list6);

            list<int> list1 = {1, 2, 3};
        }
};

int main()
{
    Main mainn = Main();
}