#include<iostream>
#include<vector>
using namespace std;
int r,k;

int findmax(int R[r+1]){
int maxi=R[1];
for(int i=2;i<=r;i++){
        if(maxi<R[i]){
                maxi=R[i];
        }

}
return maxi;
}



void total_ways(int R[r+1],int W[k+1]){

int sum=0;
W[2]=1;
W[3]=2;
for(int i=4;i<=k;i++){
        W[i]=W[i-1]+W[i-2];
}

for(int i=1;i<=r;i++){
        sum+=W[R[i]];
}
cout<<"the total ways are "<<sum<<endl;

}




void list(int R[r+1]){
    vector<vector<int> > A;
vector<vector<int> > B;
vector<vector<int> > C;

vector<int> temp;
temp.push_back(1);
temp.push_back(2);
A.push_back(temp);
temp.clear();


temp.push_back(1);
temp.push_back(2);
temp.push_back(3);
B.push_back(temp);
temp.clear();

temp.push_back(1);
temp.push_back(3);
B.push_back(temp);
temp.clear();
int s=1;
for(int i=4;i<=k;i++){
        C.clear();
        for(int j=0;j<A.size();j++){
                vector<int> m = A.at(j);
                m.push_back(i);
                C.push_back(m);
        }
             for(int j=0;j<B.size();j++){
                vector<int> n = B.at(j);
                n.push_back(i);
                C.push_back(n);
        }

                        if(i==R[s]){
                           cout<<"for root "<< s<<endl;
                               for(int i=0;i<C.size();i++){
                        vector<int>  in=C.at(i);
                        for(int j=0;j<in.size();j++){

                                cout<<in.at(j)<<" ";
                        }
                        cout<<endl;


                        }s++;


                        }


A=B;
B=C;

}
    
}




int main(){

cout<<"enter # routes"<<endl;
cin>>r;
int R[r+1];
cout<<"enter # levels in each route ascending order(min # 4) "<<endl;
for(int i=1;i<=r;i++){
        cin>>R[i];
}
k=findmax(R);
int W[k+1];
total_ways(R,W);

cout<<"the list of ways are "<<endl;


list(R);



return 0;
}

