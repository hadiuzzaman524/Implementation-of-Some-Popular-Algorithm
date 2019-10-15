#include <iostream>
#include <unordered_map>
#include <string>


using namespace std;
bool subsetsum(int ar[],int n,int sum)
{
    unordered_map<string,bool>mp;

    if(sum==0)
        return true;
    if(n<0||sum<0)
        return false;

    string key=to_string(n)+"|"+to_string(sum);

    if(mp.find(key)==mp.end())
    {
        bool include=subsetsum(ar,n-1,sum-ar[n]);

        bool exclude=subsetsum(ar,n-1,sum);

        mp[key]=include||exclude;
    }
    return mp[key];

}

int main()
{
    int arr[] = { 7, 3, 2, 5, 8 };
    int sum = 18;


    int n = sizeof(arr) / sizeof(arr[0]);

    if (subsetsum(arr, n, sum))
        cout << "Yes";
    else
        cout << "No";
    return 0;
}
