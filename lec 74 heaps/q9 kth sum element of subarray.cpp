#include<iostream>
#include<queue>
#include<vector>
using namespace std;


int getkthlargest(vector<int>& arr,int k){
    priority_queue<int,vector<int>,greater<int>>mini;

    int n=arr.size();
    for(int i=0;i<n;i++){
        int sum=0;
        for(int j=i;j<n;j++){
            sum+=arr[j];
            if(mini.size()<k){
                mini.push(sum);
            }
            else{
                if(sum>mini.top()){
                    mini.pop();
                    mini.push(sum);
                }
            }
        }
    }
    return mini.top();

}




int main(){
   vector<int>arr={1,2,3,4,5};
    int k=2;

    cout<<"The "<<k<<" th largest element is:"<<getkthlargest(arr,k);


}/*Input: arr = {1, 2, 3, 4, 5}, k = 2
Subarrays and their sums:

{1} → 1
{1, 2} → 3
{1, 2, 3} → 6
{1, 2, 3, 4} → 10
{1, 2, 3, 4, 5} → 15
{2} → 2
{2, 3} → 5
{2, 3, 4} → 9
{2, 3, 4, 5} → 14
{3} → 3
{3, 4} → 7
{3, 4, 5} → 12
{4} → 4
{4, 5} → 9
{5} → 5
Unique sorted subarray sums:

{1, 2, 3, 4, 5, 6, 7, 9, 10, 12, 14, 15}
The 2nd largest sum is 14
*/

