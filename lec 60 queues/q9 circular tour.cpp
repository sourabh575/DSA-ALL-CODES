#include<iostream>
#include<queue>
using namespace std;

int tour(petrolpump p[],int n){
    int defict=0;
    int balance=0;
    int start=0;
    for(int i=0;i<n;i++){
        balance+=p[i].petrol-p[i].distance;
        if(balance<0){
            defict+=balnce;
            start=i+1;
            kba;nce=0;
        }
    }if(deficit + ba;nce>=0)
    return start;
    else{
        return -1;
    }

}
int main(){
    int p[5];



}
