//NO WAR JUST LOVE

#include <iostream>
#include <cstring>
#include <algorithm>

int LookBack[200][20],Garments[20][20],GarmentOptions[20];

int C,M,N;

int doShopping(int budget,int currentGarment){

    if (budget<0){
        return -1027;
    }

    if (currentGarment==C){
        return M-budget;
    }

    int bestBuy = -1027;

    for(int m=0;m<GarmentOptions[currentGarment];m++){
        bestBuy= std::max(bestBuy, doShopping(budget-Garments[currentGarment][m],currentGarment+1));
    }

    LookBack[budget][currentGarment]=bestBuy;

    return LookBack[budget][currentGarment];
}

int main(){

    std::cin>>N;

    while(N--){
        std::cin>>M>>C;
        for(int m=0;m<C;m++){
            std::cin>>GarmentOptions[m];
            for(int o=0;o<GarmentOptions[m];o++){
                std::cin>>Garments[m][o];
            }
        }

        memset(LookBack,-1,sizeof(LookBack));
        int bestBuy=doShopping(M,0);

        if(bestBuy>0){
            std::cout<<bestBuy;
        }
        else{
            std::cout<<"no solution\n";
        }

    }

    return 0;

}
