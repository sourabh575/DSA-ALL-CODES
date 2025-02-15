#include<iostream>
#include<queue>
#include<vector>
using namespace std;

class heap{
    public:
    int arr[100];
    int size;

    heap(){
        arr[0]=-1;
        size = 0;
    }

    void insert(int val){
        size=size+1;
        int index=size;
        arr[index]=val;

        while(index>1){
            int parents=index/2;

            if(arr[parents]<arr[index]){
                swap(arr[parents],arr[index]);
                index=parents;
            }
            else{
                return ;
            }

        }
    }
    void print(){
        for(int i=1;i<=size;i++){
            cout<<arr[i]<<" ";
        }cout<<endl;
    }
    void deleteheap(){
        if(size==0){
            cout<<"nothing to delete "<<endl;
            return;
        }
        //step 1 put last elememt into first element
        arr[1]=arr[size];

        //step 2 remove last element
        size--;

        //step 3 took nodes into its right postion
        int i=1;
        while(i<size){
        int leftindex=2*i;
        int rightindex=2*i+1;

        if(leftindex < size && arr[i] < arr[leftindex]){
            swap(arr[i],arr[leftindex]);
            i=leftindex;
        }
        else if(rightindex<size && arr[i]<arr[rightindex]){
            swap(arr[i],arr[rightindex]);
            i=rightindex;
        }
        else{
            return ;
        }
        }

    }

};

//alert-in this code we use long long

int mincost(int arr[],int n){
    //createa min-heap
    priority_queue<int,vector<int>,greater<int>>pq;
    for(int i=0;i<n;i++){
        pq.push(arr[i]);
    }
    int cost=0;

    while(pq.size()>1){
        int a=pq.top();
        pq.pop();

        int b=pq.top();
        pq.pop();

        int sum=a+b;
        cost+=sum;

        pq.push(sum);
    }
    return cost;
}


int main(){
    heap h;
    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(54);
    h.print();

    h.deleteheap();
    h.print();

    int arr[5]={4,3,2,6};
    int n=4;


    cout<<"Minimum cost of ropes is:"<<mincost(arr,n);




}
