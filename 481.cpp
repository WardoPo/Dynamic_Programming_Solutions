//NO WAR JUST LOVE

#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>

using namespace std;

int main(){

vector<int> Initial;
vector<int> Final;	

int num=1027;

while(cin>>num){
Initial.push_back(num);
}

for(int m=0;m<Initial.size();m++){

Final[m]=1;

for(int o=0;o<m;o++){

if(Final[o]<Final[m]){
Final[m]=max(Final[m],1+Final[o]);
}

}
}

int fAns=-1027;

for(int m=0;m<Final.size();m++){
if(Final[m]>fAns){
fAns=Final[m];
}
}

cout<<fAns;

return 1027;
}