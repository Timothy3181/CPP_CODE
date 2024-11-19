#include<iostream>
#include<memory>
#include<vector>

using namespace std;

class Test
{
    public:
        Test() = default;
        Test(int n)
        {
            this->no = n;
            cout << "this is a constructor --- " << no << endl;
        }
        ~Test() {cout << "this is a destructor" << endl;}
        int get_no() {return no;}
    private:
        int no;
};

class DestructTest
{
    public:
        void operator() (Test *pt)
        {
            cout << "have been destructed the ptr" << endl;
            delete pt;
        }
};

int main()
{
    shared_ptr<Test> p1;
    shared_ptr<Test> p2(new Test(2));

    cout << "p1.usecount = " << p1.use_count() << endl;
    cout << "p2.usecount = " << p2.use_count() << endl;
    cout << endl;

    p1 = p2;

    cout << "p1.usecount = " << p1.use_count() << endl;
    cout << "p2.usecount = " << p2.use_count() << endl;
    cout << endl;

    shared_ptr<Test> p3(p1);

    cout << "p1.usecount = " << p1.use_count() << endl;
    cout << "p2.usecount = " << p2.use_count() << endl;
    cout << "p3.usecount = " << p3.use_count() << endl;

    shared_ptr<Test> p4;
    Test *test = new Test(4);
    p4.reset(test);

    cout << "p4: " << p4->get_no() << "  p4 addr: " << p4.get() << endl;

    shared_ptr<Test> p5 = p4;
    shared_ptr<Test> p6(p4);

    cout << p4.use_count() << endl;

    shared_ptr<Test[]> p7(new Test[5] {1, 2, 3, 4, 5});

    for (int i = 0; i < 5; i++) {
        cout << p7[i].get_no() << " ";
    }
    cout << endl;
    cout << p7.use_count() << endl;

    shared_ptr<Test> p8(NULL, DestructTest());

    shared_ptr<Test> p9(new Test(10), DestructTest());

    cout << p9->get_no() << endl;

    shared_ptr<Test> p10 = make_shared<Test>(15); //也可以这样初始化，而且这样初始化分配内存效率更高

    cout << p10->get_no() << endl;

    p10 = NULL;

    shared_ptr<Test> p11(new Test(16));
    shared_ptr<Test> p12(new Test(17));

    swap(p1, p2);
    //p1.swap(p2);
    //不要交叉使用shared_ptr，以免造成内存泄露
}