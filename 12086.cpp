#include <iostream>
#include <cstdio>

int Fenwick[200001], RealVector[200001];

int query(int index) {
    int sum;
    sum = 0;
    while(index) {
        sum += Fenwick[index];
        index -= index&(-index);
    }
    return sum;
}

void set(int index, int size, int value) {
    while(index <= size) {
        Fenwick[index] += value;
        index += index&(-index);
    }
}

int main() {
    int N, x, y;
    int cases = 0;
    char Action, cmd[50];
    
    while(std::cin>>N && N!=0) {
        
        for(int m = 1; m <= N; m++) {
            std::cin>>RealVector[m];
            Fenwick[m] = 0;
        }
        
        for(int m= 1; m <= N; m++){
            set(m, N, RealVector[m]);
        }

        if(cases){
            std::cout<<std::endl;
            }
        std::cout<<"Case "<<++cases<<std::endl;
        while(std::cin>>cmd) {
            
            if(cmd[0] == 'E'){
                break;
	}
                
            sscanf(cmd, "%c %i %i", Action, &x, &y);
            
            if(Action == 'M'){
                std::cout<<std::endl<<query(y) - query(x-1);
            }
            else {
                set(x, N, y-RealVector[x]);
                RealVector[x] = y;
            }
        }
    }

    return 0;
}