#include<iostream>
#include<string>
#include<vector>

using namespace std;

template<typename T>
void exc(T& t1, T& t2)
{
    T temp = t1;
    t1 = t2;
    t2 = temp;
}

template<typename M>
double add(const M& m1, const M& m2)
{
    return m1 + m2;
}

int add(const int m1, const int m2)
{
    return m1 + m2;
}   
//当有同名函数时，优先选择非模板函数，若非模板函数不能正确执行，才选择模板函数

template<class T1, class T2>
class Student
{
    public:
	Student() = default;
	Student(const T1& id, const string& name, const string& gender, const T2& age) : 
      	s_id(id), s_name(name), s_gender(gender), s_age(age) {}
	void print_info()
	{
	    cout << s_id << " " << s_name << " " << s_gender << " " << s_age << endl;
	}
    private:
	T1 s_id;
	string s_name;
	string s_gender;
        T2 s_age;
};

int main()
{
    int a = 10;
    int b = 20;
    double c = 0.5;
    double d = 1.5;
    exc(a, b);
    exc(c, d);
    cout << a << " " << b << endl;
    cout << c << " " << d << endl;

    int r = 10;
    double w = 0.4;
    double sum = add<double>(r, w);
    cout << sum << endl;

    cout << "enter the summary of the student" << endl;
    int num = 0;
    cin >> num;
    vector<Student<int, int>> students;
    for (int i = 0; i < num; i++) {
        int id = -1, age = -1;
	    string name = "", gender = "";
	while (id == -1 && age == -1 && name == "" && gender == "") {
	    cout << "enter id, name, gender and age one by one" << endl;
	    cin >> id >> name >> gender >> age;
	}
	Student<int, int> stu = Student(id, name, gender, age);
	students.emplace_back(stu);
    }
    cout << endl;
    cout << endl;
    cout << endl;
    cout << "-------------------------------------------------------" << endl;
    for (vector<Student<int, int>>::iterator it = students.begin(); it != students.end(); ++it) {
        it->print_info();
	cout << "-------------------------------------------------------" << endl;
    }
}
