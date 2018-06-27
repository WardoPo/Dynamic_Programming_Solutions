//UVA 11450
//Solved in 1.500 ms
//@Author: The Pacifist

#include <iostream>
#include <stdio.h>
#include <cstring>
#include <algorithm>

int LookBack[200][20],Garments[20][20],GarmentOptions[20];

int C,M,N;

int doShopping(int budget,int currentGarment){

    if (budget<0){
        return -10;
    }

    if (currentGarment==C){
        return M-budget;
    }

    if (LookBack[budget][currentGarment] != -1){
        return LookBack[budget][currentGarment];
    }

    int bestBuy = -10;

    for(int m=0;m<GarmentOptions[currentGarment];m++){
        bestBuy= std::max(bestBuy, doShopping(budget-Garments[currentGarment][m],currentGarment+1));
    }

    LookBack[budget][currentGarment]=bestBuy;

    return LookBack[budget][currentGarment];
}

int main(){

    scanf("%d",&N);

    while(N--){
        scanf("%i %i",&M,&C);
        for(int m=0;m<C;m++){
            scanf("%i",&GarmentOptions[m]);
            for(int o=0;o<GarmentOptions[m];o++){
                scanf("%i",&Garments[m][o]);
            }
        }

        memset(LookBack,-1,200*20*4);
        int bestBuy=doShopping(M,0);

        if(bestBuy>0){
            std::cout<<bestBuy<<std::endl;
        }
        else{
            std::cout<<"no solution\n";
        }

    }

    return 0;

}
