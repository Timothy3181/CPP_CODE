#include<iostream>
#include<memory>
#include<vector>

using namespace std;

class BA;
class AB
{
    public:
        AB() {cout << "AB()" << endl;}
        ~AB() {cout << "~AB()" << endl;}
        void set_ptr(shared_ptr<BA>& p_ba)
        {
            m_ptr_ba = p_ba;
        }
    private:
        shared_ptr<BA> m_ptr_ba;
};

class BA
{
    public:
        BA() {cout << "BA()" << endl;}
        ~BA() {cout << "~BA()" << endl;}
        void set_ptr(shared_ptr<AB> p_ab)
        {
            m_ptr_ab = p_ab;
        }
    private:
        weak_ptr<AB> m_ptr_ab;
};

int main()
{
    shared_ptr<AB> pab(new AB());
    shared_ptr<BA> pba(new BA());
    pab->set_ptr(pba);
    pba->set_ptr(pab);
    cout << "pab: " << pab.use_count() << "  " << "pba: " << pba.use_count() << endl;

    pab = NULL;
    pba = NULL;
}