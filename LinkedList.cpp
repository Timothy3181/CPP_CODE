#include<iostream>
#include<cstdlib>
#include<string>

using namespace std;

typedef struct Student
{
    string name;
    int id;
}Student;


typedef struct listpoint
{
    Student *info;
    listpoint *next;
    listpoint *last;
}listpoint;


listpoint *list(int n)
{
    listpoint *head, *mid, *end;
    head = new listpoint;
    head->info = new Student;
    end = head;
    for (int i = 0; i < n; i++)
    {
        mid = new listpoint;
        mid->info = new Student;
        cout << "enter the number" << endl;
        cin >> mid->info->id;
        cout << "enter the name" << endl;
        cin >> mid->info->name;
        end->next = mid;
        mid->last = end;
        end = mid;
    }
    end->next = NULL;
    head->last = NULL;
    return head;
}

listpoint *loop_list(int n)
{
    listpoint *head, *mid, *end;
    head = new listpoint;
    head->info = new Student;
    end = head;
    for (int i = 0; i < n; i++) {
        mid = new listpoint;
        mid->info = new Student;
        cout << "enter the number" << endl;
        cin >> mid->info->id;
        cout << "enter the name" << endl;
        cin >> mid->info->name;
        end->next = mid;
        mid->last = end;
        end = mid;
    }
    end->next = head;
    head->last = end;
    return head;
}

void change_list(listpoint *list, int n, Student *student)
{
    if (list == NULL || student == NULL) return;
    listpoint *p = list;
    for (int i = 0; i < n; i++) {
        p = p->next;
    }
    if (p != NULL) p->info = student;
}

void delete_list(listpoint *list, int n)
{
    if (list == NULL) return;
    listpoint *p = list;
    for (int i = 0; i < n; i++) {
        p = p->next;
    }
    if (p != NULL) {
        p->last->next = p->next;
        p->next->last = p->last;
        delete p;
    }
}

void insert_point(listpoint *list, int n, Student *student)
{
    if (list == NULL) return;
    listpoint *p = list;
    for (int i = 0; i < n; i++) {
        p = p->next;
    }
    if (p != NULL) {
        listpoint *insertpoint = new listpoint;
        insertpoint->info = student;
        insertpoint->next = p->next;
        p->next->last = insertpoint;
        p->next = insertpoint;
        insertpoint->last = p;
    }
}

listpoint *search_point(listpoint *list, int n)
{
    listpoint *p = list;
    for (int i = 0; i < n; i++) {
        p = p->next;
    }
    return p;
}

void output_single_point(listpoint *list)
{
    cout << "the id is : " << list->info->id << endl;
    cout << "the name is : " << list->info->name << endl;
    cout << "-------------------------" << endl;
}

void output_list(listpoint *list)
{
    if (list == NULL) return;
    listpoint *p = list;
    cout << endl << endl << endl;
    while ((p = p->next) != NULL)
    {
        output_single_point(p);
    }
}

void output_range(listpoint *list, int m, int n)
{
    if (list == NULL) return;
    int diff = m - n;
    listpoint *p = list;
    cout << endl << endl << endl;
    for (int i = 0; i < m; i++) {
        p = p->next;
    }
    for (int i = 0; i < diff; i++) {
        output_single_point(p);
        p = p->next;
    }
}

int main()
{
    listpoint *head;
    head = list(3);
    output_list(head);
    system("pause");
    return 0;
}
