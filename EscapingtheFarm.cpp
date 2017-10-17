//  Copyright © 2017 Dougy Ouyang. All rights reserved.

#include <iostream>

using namespace std;
int cow[25], ccow[25], lar=0;

int check(int total)
{
    int di[9];
    int i;
    for(i=0;i<9;i++)
        di[i]=0;
    for(i=0;i<total;i++){
        if(ccow[i]){
            int num=cow[i], j=0;
            while(num){
                di[j]+=num%10, num/=10, j++;
            }
        }
    }
    for(i=0;i<9;i++)
        if(di[i]>9)
            return 0;
    return 1;
}

void rec(int total, int level, int sum)
{
    if(total==level){
        if(check(level)){
            lar=max(lar, sum);
        }
        return;
    }
    ccow[level]=1;
    rec(total, level+1, sum+1);
    ccow[level]=0;
    rec(total, level+1, sum);
}

int main()
{
    int n;
    int i;
    
    cin >> n;
    for(i=0;i<n;i++){
        cin >> cow[i];
    }
    
    rec(n, 0, 0);
    
    cout << lar << endl;
    
    return 0;
}
