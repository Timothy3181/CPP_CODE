#include<iostream>
#include<map>
#include<string>

using namespace std;

typedef struct Student
{
    string name;
    int score;
}Student;

map<int, Student> m;

int main()
{
    int n = 0;
    cin >> n;
    for (auto i = 0; i < n; i++) {
        Student *stu = new Student;
        cin >> stu->name >> stu->score;
        m.insert(pair<int, Student>(i + 1, *stu));
        delete stu;
    }
    cout << "-----------------------------------------------" << endl;
    for (map<int, Student>::iterator it = m.begin(); it != m.end(); ++it) {
        cout << it->first << "  " << it->second.name << "  " << it->second.score << endl;
    }
    int f_id;
    cin >> f_id;
    map<int, Student>::iterator it1;
    it1 = m.find(f_id);
    if (it1 != m.end()) {
        cout << "found  the info is: " << "id: " << it1->first << "  name: " << it1->second.name << "  score: " << it1->second.score << endl;
    }
    else cout << "not found" << endl;
    if (!m.empty()) {
        cout << "can delete map,0 to exit" << endl;
        int judge = -1;
        while (judge != 0)
        {
            int d_id = -1;
            cin >> d_id;
            map<int, Student>::iterator it2 = m.find(d_id);
            if (it2 != m.end()) {
                m.erase(it2);
                cin >> judge;
            }
            else {
                cout << "not found" << endl;
                cin >> judge;
                continue;
            }
        }
    }
}