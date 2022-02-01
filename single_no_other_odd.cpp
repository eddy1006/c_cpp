//Question :-  All the numbers are repeating thrice or odd no of times in the array except one number . Find that number.

/*Approach : -Since every no is repeating odd no of times(thrice in this case) we can store their set bits(1) in an array and since they are appearing
 for a cerrtain number of time all their set bits will also be appearing that many times and hence modulo that number should give us zero
 but since here one number is just appearing once some set bits number will not give modulo zero*/

#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int arr[] = { 3, 4, 4,4,2,2,2,6,6,6,7,7,7};
    
    return 0;
}