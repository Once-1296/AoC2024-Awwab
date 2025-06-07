#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <string>
using namespace std;
pair<int, int> dirs[4] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
bool chk(int sx, int sy, vector<vector<char>> &maze)
{
    map<pair<int, int>, set<int>> stp = {{{sx, sy}, {0}}};
    int dptr = 0;
    int n = maze[0].size(), m = maze.size();
    int i =0;
    while (i<100000)
    {
        i++;
        int dx = sx + dirs[dptr].second, dy = sy + dirs[dptr].first;
        if (dx < 0 || dx >= n || dy < 0 || dy >= m)
            break;
        if (maze[dy][dx] == '#')
        {
            dptr = (dptr + 1) % 4;
        }
        else
        {
            if (!stp.count({dx, dy}))
            {
                stp[{dx, dy}].insert(dptr);
            }
            else
            {
                if (stp[{dx, dy}].count(dptr))
                    return true;
                stp[{dx, dy}].insert(dptr);
            }
            sy = dy, sx = dx;
        }
    }
    return false;
}
int main()
{
    fstream file("input.txt", ios::in);
    string line;
    vector<vector<char>> maze;
    while (getline(file, line))
    {
        vector<char> t(line.begin(), line.end());
        maze.push_back(t);
    }
    int n = maze[0].size(), m = maze.size();
    int sx, sy;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (maze[i][j] == '^')
            {
                sx = j;
                sy = i;
                break;
            }
        }
    }
    long long ans = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (maze[i][j] != '^' && maze[i][j] != '#')
            {
                maze[i][j] = '#';
                if (chk(sx, sy, maze))
                    ans++;
                maze[i][j]='.';
            }

        }
    }
    cout << ans << endl;
}