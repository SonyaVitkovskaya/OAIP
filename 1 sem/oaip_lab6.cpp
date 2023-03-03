#include <iostream>
using namespace std;

int main()
{
    int i, a, j;
    cout << "razmer: ";
    //создание
    //-----------------------------------------------------------------------------------
    cin >> i >> j;
    int** dinmas = new int* [i];
    for (int a = 0; a < i; a++)
    {
        dinmas[a] = new int[j];
    }
    //заполнение
    //-----------------------------------------------------------------------------------
    srand(time(NULL));
    for (int a = 0; a < i; a++)
        for (int a = 0; a < i; a++)
        {
            for (int b = 0; b < j; b++)
            {
                dinmas[a][b] = rand() % 20;
            }
        }
    // вывод
    //-----------------------------------------------------------------------------------
    for (int a = 0; a < i; a++)
    {
        for (int b = 0; b < j; b++)
        {
            cout << dinmas[a][b] << " ";
        }
        cout << endl;
    }
    //макс для строк
    //-----------------------------------------------------------------------------------
    int* s = new int[i];
    for (int a = 0; a < i; a++)
    {
        s[a] = dinmas[a][0];
        for (int b = 1; b < j; b++)
        {
            if (dinmas[a][b] > s[a])
            {
                s[a] = dinmas[a][b];

            }
        }
        cout << "Max elemen " << a << " stroki= " << s[a] << endl;
    }
    //пузырёк
    //-----------------------------------------------------------------------------------

    for (int t = 1; t < i; t++)
    {
        for (int a = 0; a < i - t; a++)
        {
            int* temp;
            int temp_s;
            if (s[a] > s[a + 1])
            {
                temp = dinmas[a + 1];
                temp_s = s[a + 1];
                dinmas[a + 1] = dinmas[a];
                s[a + 1] = s[a];
                dinmas[a] = temp;
                s[a] = temp_s;
            }

        }
    }
    //вывод новой 
    //-----------------------------------------------------------------------------------
    for (int a = 0; a < i; a++)
    {
        for (int b = 0; b < j; b++)
        {
            cout << dinmas[a][b] << " ";
        }
        cout << endl;
    }
    //освобождение памяти
    //-----------------------------------------------------------------------------------
    for (int a = 0; a < i; a++)
    {
        delete[] dinmas[a];
    }
    delete[] dinmas;
}