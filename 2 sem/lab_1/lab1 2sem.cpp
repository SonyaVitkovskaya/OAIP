#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <math.h>

using namespace std;

struct Student
{ 
    string name;
    int year, group_number,phys, math, inf, chem;
    float srednij_ball;
};


int check(int variant, int min, int max)
{
    if (variant >= min && variant <= max)return variant;
    else
    {
        cout << "Введите корректное значение ";
        cin >> variant;
        return check(variant, min, max);
    }
}
void create(Student& student, int student_number)
{
    int y,g,p,m,i,c;
    cout << "Студент номер " << student_number + 1 << endl;
    cout << "Имя: ";                    cin >> student.name;
    cout <<"Год рождения: ";            
    cin >> y;
    student.year = check(y, 1980, 2005);
    cout << "Группа: ";                 
    cin >> g;
    student.group_number= check(g, 1, 10);
    cout <<  "Физика: ";                 
    cin >> p;
    student.phys= check(p, 1, 10);
    cout << "Математика: ";              
    cin >> m;
    student.math= check(m, 1, 10);
    cout << "Информатика: ";             
    cin >> i;
    student.inf= check(i, 1, 10);
    cout << "Химия: ";                  
    cin >> c;
    student.chem= check(c, 1, 10);
    student.srednij_ball = (student.phys + student.math + student.inf + student.chem) / 4.0;
    cout <<"Средний балл: "<<student.srednij_ball<< endl;
}
void show_info(Student& student, int student_number) 
{   
    cout << "Студент номер " << student_number + 1 << endl;
    cout << "Имя: " << student.name << endl;
    cout << "Год рождения: " << student.year << endl;
    cout << "Группа: " << student.group_number << endl;
    cout << "Физика: " << student.phys << endl;
    cout << "Математика: " << student.math << endl;
    cout << "Информатика: " << student.inf << endl;
    cout << "Химия: " << student.chem << endl;
    cout << "Средний балл: " << student.srednij_ball << endl<<endl;
}

int main()
{
    system("chcp 1251");
    system("cls");
    Student student;
    vector<Student> students;

    cout << "1-Создание;\n2-Просмотр;\n";
    int a, action;
    cin >> a;
    action = check(a, 1, 2);

    if (action == 1)
    {       
        cout << "Количество студентов: ";
        int amount;
        cin >> amount;
         
        for (int i = 0; i < amount; i++)
        {
           create(student, i);
           students.push_back(student);
        }
    }
    else
    {     
        ifstream fin("Students.txt");  
        
          while (fin.read((char*)&student, sizeof(Student)))
            {
                 students.push_back(student);
                 cout << endl;
        
            }
        
       
        for (int i = 0; i < students.size(); i++)
        show_info(students[i], i);
       
    }

    while (true)
    {
        cout << "1-Редактировать\n2-Продолжить" << endl;
        int sec_action,s;
        cin >> s;
        sec_action=check(s, 1, 2);
        if (sec_action == 1)
        {
           cout << "Номер студента" << endl;
           int number,n;
           cin >> n;
           number=check(n, 1, students.size() + 1);
           if (number = students.size() + 1)
           {
              create(student, students.size());
              students.push_back(student);
           }
           else
           {   
              create(students[number - 1], number - 1);
           }
        }
        else break;
    }

    ofstream fout("Students.txt");
    for (int i = 0; i < students.size(); i++)
    {
       fout.write((char*)&students[i], sizeof(Student));
    }

        int sum = 0;
        for (int i = 0; i < students.size(); i++) 
             sum = students[i].phys + students[i].math + students[i].inf + students[i].chem;
        float obshij_srednij = sum / (students.size() * 4.0);
        cout << "Номер группы" << endl;
        int group_number;
        cin >> group_number;
        check(group_number, 1, 10);
        cout << "Студенты с баллом, выше среднего"<<endl;
        for (int i = 0; i < students.size(); i++)
        {
        if (group_number == students[i].group_number && students[i].srednij_ball > obshij_srednij)
               cout << students[i].name<<endl;
        }
}
