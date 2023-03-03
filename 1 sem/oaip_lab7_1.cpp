int main()
{
    string str, ch;
    cout << "vvedite stroku: ";
    getline(cin, str);

    vector<string> vector_str;
    stringstream sstr(str);
    while (getline(sstr, ch, ' '))
    {
        vector_str.push_back(ch);
    }
    int len = vector_str.size();
    for (int t = 1; t < len; t++)
    {
        for (int i = 0; i < len - t; i++)
        {
            if (stoi(vector_str[i]) > stoi(vector_str[i + 1]))
            {
                swap(vector_str[i + 1], vector_str[i]);
            }
        }
    }
    for (int a = 0; a < len; a++)
    {
        cout << vector_str[a] << " ";
    }
}