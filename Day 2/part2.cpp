#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
bool chk(vector<int> &v)
{
    if (v.size() == 1)
        return true;
    for (int i = 0; i < v.size() - 1; i++)
    {
        if (abs(v[i + 1] - v[i]) == 0 || abs(v[i + 1] - v[i]) > 3)
            return false;
    }
    bool b = v[0] > v[1] ? 1 : 0;
    for (int i = 1; i < v.size() - 1; i++)
    {
        if (b)
        {

            if (v[i + 1] > v[i])
                return false;
        }
        else
        {
            if (v[i + 1] < v[i])
                return false;
        }
    }
    return true;
}
int main()
{
    fstream file("input.txt", ios::in);
    string line;
    int ans = 0;
    while (getline(file, line))
    {
        vector<int> v;
        string word;
        stringstream obj(line);
        while (getline(obj, word, ' '))
        {
            v.push_back(stoi(word));
            cout << word << " ";
        }
        cout << endl;
        for(int i =0;i<v.size();i++)
        {
            vector<int>t;
            for(int j =0;j<v.size();j++)
            {
                if(i!=j)
                {
                    t.push_back(v[j]);
                }
            }
            if(chk(t))
            {
                ans++;
                break;
            }
        }
    }
    cout << ans << endl;
}