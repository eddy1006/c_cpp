#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Batsman
{
private:
    int run;
    int balls;

public:
    string name;
    Batsman(string s, int r, int b)
    {
        run = r;
        balls = b;
        name = s;
    }
    void runsByBatsman(int x)
    {
        balls++;
        if (x == -1)
        {
            displayrun();
        }
        else
        {
            run = run + x;
        }
    }
    void displayrun()
    {
        cout << name << " " << run << "(" << balls << ")" << endl;
    }
};

class Bowler
{
private:
    float overs;
    int wickets;
    int runs = 0;
    int balls = 0;

public:
    string name;
    Bowler(string s, int o, int w)
    {
        name = s;
        overs = o;
        wickets = w;
    }
    void displayWickets()
    {
        cout << name << "  Runs Given->" << runs << " Wickets taken->" << wickets << " " << overs << "overs" << endl;
    }
    void wicket()
    {
        wickets++;
        displayWickets();
    }
    void runsgiven(int r)
    {
        runs = runs + r;
        balls++;
        if (balls % 6 == 0)
            overs = overs + 0.5;
        else
            overs = overs + 0.1;
    }
};
Batsman createbatsman(string st)
{
    Batsman obj(st, 0, 0);
    Batsman &bt = obj;
    return bt;
}
Bowler createbowler(string st)
{
    Bowler obj(st, 0, 0);
    Bowler &bw = obj;
    return bw;
}
void scorecard(vector<Batsman> &v1, vector<Bowler> &v2, int total)
{
    cout << "END OF THE INNINGS " << endl;
    cout << "Batting team scorecard :" << endl;
    for (int i = 0; i < v1.size(); i++)
    {
        v1[i].displayrun();
    }
    cout << "Total score at the end of the innings -->" << total << "/" << v1.size() - 2 << endl;
    cout << "Bowling team scorecard :" << endl;
    for (int j = 0; j < v2.size(); j++)
    {
        v2[j].displayWickets();
    }
}
int main(void)
{
    vector<Batsman> team1;
    vector<Bowler> team2;
    int total_score = 0;
    int j = 1;
    Bowler *bow;
    Batsman *onstrike;
    Batsman *offstrike;
    for (int i = 1; i <= 18; i++)
    {
        if (i == 1)
        {
            string s;
            string s2;
            cout << "Opener no 1" << endl;
            getline(cin, s);
            Batsman opener1 = createbatsman(s);
            team1.push_back(opener1);
            cout << "Opener no 2" << endl;
            getline(cin, s2);
            Batsman opener2 = createbatsman(s2);
            team1.push_back(opener2);
            string st;
            cout << "New Bowler" << endl;
            cin >> st;
            Bowler bowler1 = createbowler(st);
            team2.push_back(bowler1);
            bow = &team2[team2.size() - 1];
            onstrike = &team1[team1.size() - 2];
            offstrike = &team1[team1.size() - 1];
        }
        if (i % 6 == 1 && i != 1)
        {
            string st;
            cout << "New Bowler:" << endl;
            cin >> st;
            for (int x = 0; x < team2.size(); x++)
            {
                if (team2[x].name == st)
                    bow = &team2[x];
            }
            if (bow == NULL)
            {
                Bowler b = createbowler(st);
                team2.push_back(b);
                bow = &team2[team2.size() - 1];
            }
        }
        cout << "Over Number :" << j << endl;
        cout << "Batsman on Strike:" << onstrike->name << endl;
        cout << "Bowler Bowling:" << bow->name << endl;
        cout << "THROW BALL!" << endl;
        int temp;
        cin >> temp;
        if (temp != -1)
        {
            onstrike->runsByBatsman(temp);
            bow->runsgiven(temp);
            total_score = total_score + temp;
        }
        else
        {
            string st2;
            onstrike->runsByBatsman(temp);
            bow->runsgiven(0);
            bow->wicket();
            Batsman& somethin = *offstrike;
            cout << "Enter new Batsman Name:" << endl;
            cin >> st2;
            Batsman temp = createbatsman(st2);
            team1.push_back(temp);
            onstrike = &team1[team1.size() - 1];
            offstrike = &somethin;
        }
        if (temp != -1 && temp % 2 != 0)
        {
            Batsman *temporary;
            temporary = onstrike;
            onstrike = offstrike;
            offstrike = temporary;
        }
        if (i % 6 == 0)
        {
            Batsman *temporary;
            temporary = onstrike;
            onstrike = offstrike;
            offstrike = temporary;
            j++;
            bow = NULL;
        }
    }
    scorecard(team1, team2, total_score);
    return 0;
}