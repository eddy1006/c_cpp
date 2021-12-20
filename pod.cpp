#include<iostream>
#include<vector>
using namespace std;
void operation_one(vector<char> &v,vector<char> &v1)
{
    v1 = v;
}
void operation_two(vector<char> &v)
{
    vector<char>::iterator it = v.begin();
    v.insert(it+1,'r');
}
void operation_three(vector<char> &v)
{
    vector<char>::iterator it = v.begin();
    v.insert(it+2,{'r','r','r','r'});
}
void operation_four(vector<char> &v)
{
    vector<char>::iterator it = v.begin();
    v.erase(it+3);
}
void operation_five(vector<char> &v)
{
    vector<char>::iterator it = v.begin();
    v.erase(it+4,it+5);
}
void operation_six(vector<char> &v)
{
    v.erase(v.begin(),v.end());
}
int main()
{
    int n;
    vector<char> initial_colors;
    int n1;
    cin>>n;
    for(int i=0;i<n;i++){char ch; cin>>ch; initial_colors.push_back(ch); }
    cin>>n1;
    vector<char> player1;
    vector<char> player2;
    player1.assign(initial_colors.begin(),initial_colors.begin()+initial_colors.size());
    player2.assign(initial_colors.begin(),initial_colors.begin()+initial_colors.size());
    int p1[n1];
    int p2[n1];
    for(int i=0;i<n1;i++){cin>>p1[i]; }
    for(int i=0;i<n1;i++){cin>>p2[i]; }
    for(int j=0;j<n1;j++)
    {
        switch(p1[j])
        {
            case 1:
            operation_one(initial_colors,player1);
            break;
            case 2:
            operation_two(player1);
            break;
            case 3:
            operation_three(player1);
            break;
            case 4:
            operation_four(player1);
            break;
            case 5:
            operation_five(player1);
            break;
            case 6:
            operation_six(player1);
            break;
            default:
            break;
        }
          switch(p2[j])
        {
            case 1:
            operation_one(initial_colors,player2);
            break;
            case 2:
            operation_two(player2);
            break;
            case 3:
            operation_three(player2);
            break;
            case 4:
            operation_four(player2);
            break;
            case 5:
            operation_five(player2);
            break;
            case 6:
            operation_six(player2);
            break;
            default:
            break;
        }
    }
    for(int k=0;k<player1.size();k++){cout<<player1[k]<<" ";}
    cout<<"\n";
    for(int l=0;l<player2.size();l++){cout<<player2[l]<<" ";}
    return 0;
}