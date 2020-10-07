#include<bits/stdc++.h>
using namespace std;

long long int mod=pow(10,9)+7;

long long int find_total_vol(vector<int> goldsize_arr,int breadth,int height,int no_gold)
{
    long long int total_vol=0;
    for(int counter=0;counter<no_gold;counter++)
    {
        total_vol=(total_vol+goldsize_arr[counter])%mod;

    }
    return (((((total_vol%mod)*breadth)%mod)*height)%mod);

}

long long int find_shaded_vol(vector<int> goldsize_arr,int breadth,int height,int no_gold)
{
    long long int shaded_area=0,top_area=0,res;
    int top_gold_size;
    stack<int> gold_size;
    int counter;
    for(counter=0;counter<no_gold;counter++)
    {
        while(gold_size.empty()==false&&goldsize_arr[counter]<=goldsize_arr[gold_size.top()])
        {
            top_gold_size=gold_size.top();
            gold_size.pop();
            if(gold_size.empty())
            {
                res=counter;
            }
            else
            {
                res= (counter-gold_size.top()-1);
            }
            top_area=goldsize_arr[top_gold_size]*res;
            shaded_area=max(shaded_area%mod,top_area);
        }
        gold_size.push(counter);
    }


   while(gold_size.empty()==false)
   {
       top_gold_size=gold_size.top();
       gold_size.pop();
       if(gold_size.empty())
            {
                res=no_gold;
            }
            else
            {
                res= (no_gold-gold_size.top()-1);
            }
       top_area=goldsize_arr[top_gold_size]*res;
       shaded_area=max(shaded_area%mod,top_area);
   }
    return (((((shaded_area%mod)*breadth)%mod)*height)%mod);
}


int main()
{
    int no_gold,counter,breadth,height;
    cin>>no_gold;
    cin>>breadth>>height;
    vector<int> goldsize_arr;
    for(counter=0;counter<no_gold;counter++)
    {
        int goldsize;
        cin>>goldsize;
        goldsize_arr.push_back(goldsize);
    }
    long long int total_vol,shaded_vol;
    total_vol=find_total_vol(goldsize_arr,breadth,height,no_gold);
    //cout<<total_vol;
    shaded_vol=find_shaded_vol(goldsize_arr,breadth,height,no_gold);
    //cout<<shaded_vol;
    cout<<(total_vol-shaded_vol)%mod;
  return 0;

}
