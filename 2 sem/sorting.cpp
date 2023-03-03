#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

struct Ceh 
{
    string name;
    int number, amount;
};

void create(Ceh& ceh, int ceh_number)
{
    cout << "Название продукции: ";                   
    cin >> ceh.name;
    cout << "Количество: ";
    cin >> ceh.amount;
    cout << "Номер цеха: ";
    cin >> ceh.number;
}

void show_info(Ceh& ceh)
{
    cout << "Название продукции: " << ceh.name << endl;
    cout << "Количество: " << ceh.amount << endl;
    cout << "Номер цеха: " << ceh.number << endl<<endl;
}

void sort(vector<Ceh>& array, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int max = i;
        for (int j = i + 1; j < n; j++) if (array[max].amount < array[j].amount) max = j;
        if (max == i) continue;
        Ceh temp = array[i];
        array[i] = array[max];
        array[max] = temp;
    }
}

void QuickSort(vector<Ceh>& array, int begin, int end)
{
    int left = begin, right = end, middle = array[(left + right) / 2].amount;
    do
    {
        while (array[left].amount > middle) left++;
        while (array[right].amount < middle) right--;
        if (left <= right)
        {
            Ceh temp = array[left];
            array[left] = array[right];
            array[right] = temp;
            left++;
            right--;
        }
    } while (left <= right);
    if (begin < right) QuickSort(array, begin, right);
    if (left < end) QuickSort(array, left, end);
}

int LinearSearch(vector<Ceh>& array, int n)
{
    int result = -1;
    for (int i = 0; i < n; i++)
    {
        if (array[i].amount == n) 
        result = i;
        show_info(array[i]);
    }
    return result;
}

int BinarySearch(vector<Ceh>& array, int left, int right, int n)
{
    if (left > right) return -1;
    int middle = (left + right) / 2;
    if (array[middle].amount < n) return BinarySearch(array, left, middle - 1, n);
    if (array[middle].amount > n) return BinarySearch(array, middle + 1, right, n);
    return middle;
}

int main()
{   
    system("chcp 1251");
    system("cls");

    Ceh ceh;
    vector<Ceh> ceha;

    cout << "1-Создание;\n2-Просмотр;\n";
    int action;
    cin >> action;

    if (action == 1)
    {
        cout << "Количество записей: ";
        int col_vo;
        cin >> col_vo;

        for (int i = 0; i < col_vo; i++)
        {
            create(ceh, i);
            ceha.push_back(ceh);
        }
    }
    else
    {
        ifstream fin;
        fin.open("ceha.txt");
        while (!fin.eof())
        {
            fin >> ceh.name >> ceh.amount >> ceh.number;
            ceha.push_back(ceh);
            cout << endl;
        }
        fin.close();

        for (int i = 0; i < ceha.size(); i++)
            show_info(ceha[i]);
    }

    while (true)
    {
        cout << "1-Редактировать\n2-Продолжить" << endl;
        int sec_action;
        cin >> sec_action;

        if (sec_action == 1)
        {
            cout << "Номер студента" << endl;
            int c_number;
            cin >> c_number;
            
            if (c_number == ceha.size() + 1)
            {
                create(ceh, ceha.size());
                ceha.push_back(ceh);
            }
            else
            {
                create(ceha[c_number - 1], c_number - 1);
            }
        }
        else break;
    }

    ofstream fout;
    fout.open("ceha.txt");
    for (int i = 0; i < ceha.size(); i++)
    {
        fout << ceha[i].name << " " << ceha[i].amount << " " << ceha[i].number;
        if (i < (ceha.size() - 1)) fout << endl;
    }

    fout.close();

    while (true)
    {   
        vector<Ceh> vec1;
        copy(ceha.begin(), ceha.end(), back_inserter(vec1));
        cout << "Выберите операцию:" << endl << "1 - QuickSort" << endl << "2 - Сортировка прямым выбором" << endl << "3 - Линейный поиск" << endl << "4 - Двоичный поиск" << endl<<"5 - Задание"<<endl;
        int th_action;
        cin >> th_action;
         switch (th_action)
          {
          case 1:
             QuickSort(ceha, 0, ceha.size() - 1);
              for (int i = 0; i < ceha.size(); i++)  show_info(ceha[i]);
              break;
          case 2:
              sort(ceha, ceha.size());
              for (int i = 0; i < ceha.size(); i++)  show_info(ceha[i]);
              break;
          case 3:
              cout << "Нужное количество: " << endl;
              int n, res;
              cin >> n;
              res = LinearSearch(ceha, n);
              if (res == -1) cout << "Элемент не найден" << endl<<endl;
              break;
          case 4:
              cout << "Поиск производится в отсортированном массиве: ";
              QuickSort(vec1, 0, vec1.size() - 1);
              for (int i = 0; i < ceha.size(); i++)  show_info(vec1[i]);
              cout << "Нужное количество: " << endl;
              int k, res2;
              cin >> k;
              res2 = BinarySearch(ceha, 0,vec1.size(), k);
              if (res2 == -1) cout << "Элемент не найден" << endl << endl;
              break;
              
          case 5:
              QuickSort(ceha, 0, ceha.size() - 1);
              cout << "Номер, интересующего Вас цеха: ";
              int ceh_number;
              cin >> ceh_number;
              for (int i = 0; i < ceha.size(); i++) if (ceh_number == ceha[i].number) show_info(ceha[i]);
              break;
         }
         cout << "1 - Выполнить еще одну операцию;\n 2-Завершить выполнение программы" << endl;
         int f_action;
         cin >> f_action;
         if (f_action == 2) break;
    }   
}