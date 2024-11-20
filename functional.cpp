#include<iostream>
#include<functional>

using namespace std;

void func1();

class Test
{
    public:
        Test() = default;
        void func2();
};

auto func3 = [](const string& str) -> void
{
    cout << "lambda function" << endl;
};

int main(int argc, char **argv)
{
    // Test test_;

    function<void()> save1 = func1;
    function<void(const string&)> save3 = func3;
    // function<void()> save2 = bind(&Test::func2, &test_);
    function<void()> save2 = bind([](Test& t) {t.func2();}, Test());
    /* bind()的第一个参数为可调用对象，后续参数为该可调用对象的参数。
    其后续参数的语法比较特别，C++11后新增一个命名空间域placeholders，
    其内部会存储很多变量，这些变量用于函数的传参，变量的名字为_x，
    表示第x个参数。例如_1可调用对象的第一个参数，_2为第二个参数。 */


    save1();
    save2();
    save3("114514");
}

void func1()
{
    cout << "basic function" << endl;
}

void Test::func2()
{
    cout << "the class function" << endl;
}