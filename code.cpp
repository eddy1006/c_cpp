#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;
    map<int, vector<int>> ycord;
    vector<int> xcord;
    for (int i = 1; i <= (2 * n); i++)
    {
        int x, y;
        cin >> x >> y;
        vector<int> vec;
        vec = ycord[x];
        vec.push_back(y);
        ycord[x] = vec;
        xcord.push_back(x);
    }
    vector<int>::iterator it;
    int maxlen = 0, size = 0;
    int x1, y1, y2;
    for (it = xcord.begin(); it != xcord.end(); it++)
    {
        vector<int> yvalue;
        yvalue = ycord[(*it)];
        vector<int>::iterator it2;
        sort(yvalue.begin(), yvalue.end());
        if (maxlen == 0)
        {
            maxlen = yvalue[yvalue.size() - 1] - yvalue[0];
            size = yvalue.size();
            x1 = (*it);
            y1 = yvalue[yvalue.size() - 1];
            y2 = yvalue[0];
        }
        else if ((yvalue[yvalue.size() - 1] - yvalue[0]) > maxlen)
        {
            maxlen = yvalue[yvalue.size() - 1] - yvalue[0];
            size = yvalue.size();
            x1 = (*it);
            y1 = yvalue[yvalue.size() - 1];
            y2 = yvalue[0];
        }
        else if ((yvalue[yvalue.size() - 1] - yvalue[0]) == maxlen)
        {
            if (yvalue.size() < size)
            {
                size = yvalue.size();
                x1 = (*it);
                y1 = yvalue[yvalue.size() - 1];
                y2 = yvalue[0];
            }
        }
    }
    cout<<x1<<y2<<" "<<x1<<y1;
}