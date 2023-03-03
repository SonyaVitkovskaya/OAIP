#include <iostream>
#include <vector>
using namespace std;

int main()
{

    cout << "stroka:" << endl;
    char string[100];
    int n = 1;
    vector<char> vector_str;
    //cin.getline(string, 100);
    for (int j = 0; j < n; j++)
    {
        string[j] = getchar();
        if (string[j] != '\n')
        {
            n++;
            if (string[j] != ' ')
                vector_str.push_back(string[j]);
        }
    }
    int i = vector_str.size();
    for (int t = 1; t < i; t++)
    {
        for (int k = 0; k < i - t; k++)
        {
            if ((int)(vector_str[k]) > (int)(vector_str[k + 1]))
            {
                swap(vector_str[k + 1], vector_str[k]);
            }
        }
    }

    for (int a = 0; a < i; a++)
    {
        cout << vector_str[a] << " ";
    }

}