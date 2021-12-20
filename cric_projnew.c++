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
    string name="";
    Batsman()
    {
        run =0;
        balls =0;
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
    string name = "";
    Bowler()
    {
        overs = 0.0;
        wickets = 0;
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
void createbatsman(Batsman* obj,int variable,string st)
{
    obj[variable].name = st;
}
void createbowler(Bowler* obj,int variable,string st)
{
    obj[variable].name = st;
}
void scorecard(Batsman* t1,Bowler* t2, int total)
{
    int size,k;
    k=0;size =0;
    while (t1[k].name!="")
    {
        size++;
        k++;
    }
    cout << "END OF THE INNINGS " << endl;
    cout << "Batting team scorecard :" << endl;
    for (int i = 0; i <=size; i++)
    {
        t1[i].displayrun();
    }
    cout << "Total score at the end of the innings -->" << total << "/" << size - 2 << endl;
    cout << "Bowling team scorecard :" << endl;
    int j=0;
    while(t2[j].name!="")
    {
        t2[j].displayWickets();
        j++;
    }
}
int main(void)
{
    Batsman* team1 = new Batsman[11];
    Bowler* team2 = new Bowler[11];
    int total_score = 0;
    int j = 1;
    Bowler* bow;
    Batsman* onstrike;
    Batsman* offstrike;
    int update = 0;
    int update2 =0;
    for (int i = 1; i <= 18; i++)
    {
        if (i == 1)
        {
            string s;
            string s2;
            cout << "Opener no 1" << endl;
            getline(cin, s);
            createbatsman(team1,update,s);
            onstrike = &team1[update];
            update++;
            cout << "Opener no 2" << endl;
            getline(cin, s2);
            createbatsman(team1,update,s2);
            offstrike = &team1[update];
            update++;
            string st;
            cout << "New Bowler" << endl;
            cin >> st;
            createbowler(team2,update2,st);
            bow = &team2[update2];
            update2++;
        }
        if (i % 6 == 1 && i != 1)
        {
            string st;
            cout << "New Bowler:" << endl;
            cin >> st;
            for (int x = 0; x < 11; x++)
            {
                if (team2[x].name == st)
                    bow = &team2[x];
            }
            if (bow == NULL)
            {
                createbowler(team2,update2,st);
                bow = &team2[update2];
                update2++;
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
            cout << "Enter new Batsman Name:" << endl;
            cin >> st2;
            createbatsman(team1,update,st2);
            onstrike = &team1[update];
            update++;
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