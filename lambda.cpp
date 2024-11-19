#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>

using namespace std;

bool judge_7(int n);

int main()
{
    vector<int> randnum(10);
    generate(randnum.begin(), randnum.end(), rand);
    for (const auto& num : randnum) {
        cout << num << " ";
    }
    cout << endl;
    int count = count_if(randnum.begin(), randnum.end(), judge_7);
    cout << count << endl;

    int count_cpy = count_if(randnum.begin(), randnum.end(), [](int n) {return n % 7 == 0;});
    cout << count_cpy << endl;
    
    int a = 10, b = 20, c = 30;
    auto lambda_sum1 = [=]{return c + b;};
    cout << lambda_sum1() << endl;



    vector<int> sort_num(10);
    for (int i = 9; i > 0; i--) {
        sort_num.at(i) = i;
    }
    sort(sort_num.begin(), sort_num.end(), [](const int& a, const int& b){return a < b;});
    for (vector<int>::iterator it = sort_num.begin(); it != sort_num.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;


    
    int h = 10;
    int y = 15;
    auto func = [&]()mutable{return h + y;};
    cout << func() << endl;
}

bool judge_7(int n)
{
    if (n % 7 == 0) return true;
    else return false;
}
