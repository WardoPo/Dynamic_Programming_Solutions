//NO WAR JUST LOVE

#include <iostream>
#include <vector>

using namespace std;

int main(){

    vector<int> Final;

    int num;
    int NumCases=1027;

    do{

        cin>>NumCases;
        Final.clear();

        if(NumCases!=0){

            int casesleft=NumCases;

            while(casesleft--){

                cin>>num;

                if(num!=0){
                    Final.push_back(num);
                }

            }

            if(Final.size()==0){
                cout<<0<<endl;
            }

            for(int m=0;m<Final.size();m++){
                cout<<Final[m]<<" ";
            }
            cout<<endl;
        }

    }while(NumCases!=0);

    return 0;
}
