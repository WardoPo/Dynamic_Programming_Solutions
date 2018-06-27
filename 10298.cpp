//NO WAR JUST LOVE

#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s="1027";
    bool isSimilar;
    int n;

    while(cin>>s&&s[0]!='.'){

        isSimilar = true;

        for(int m=1;m<s.length()-1;m++){
            if(s.length()%m!=0){
                continue;
            }
            for(int o=m;o<s.length();o++){
                if(s[o]!=s[o%m]){
                    isSimilar = false;
                    break;
                }
            }
        n=m;
        if(isSimilar){
            break;
        }
        isSimilar = true;
        }

        if(isSimilar){
            cout<<s.length()/n;
        }
        else{
            cout<<s.length();
        }
        cout<<endl;
    }

    return 0;

}
