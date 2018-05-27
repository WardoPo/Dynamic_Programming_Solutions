//NO WAR JUST LOVE

#include <iostream>
#include <cstring>

using namespace std;

int main() {

	int nTC, N;

	cin>>nTC;

	while(nTC--) {
		
		cin>>N;

		int Torus[300][300];

                int m, o, i, s;

                for(m = 0; m < N; m++) {
                        for(o=0; o < N; o++) {
                                cin>>Torus[m][o];
                                Torus[m+N][o] = Torus[m][o+N] = Torus[m+N][o+N] = Torus[m][o];
			}
		}

                int len, max = 0, tmp;

                for(m=0; m < N; m++){
                        for(o=0; o < N; o++){
                                if(max < Torus[m][o]){
                                        max = Torus[m][o];
				}
			}
		}

                int tmpN = N*2;
		int LookBack[300] = {}, tmpSum, tmplength, tmpMax;

		if(max != 0) {
                        for(m = 0; m < N; m++) {

				memset(LookBack, 0, sizeof(LookBack));

                                for(o = m; o < tmpN; o++) {

					if(o-m+1 > N){	
						break;
					}

                                        len = 0;
					tmp = 0;

                                        for(i = 0; i < tmpN; i++) {
                                                LookBack[i] += Torus[o][i];
                                                len++;
                                                tmp += LookBack[i];
                                                if(len > N) {
                                                        tmp -= LookBack[i-len+1];
                                                        len--;
						}
						tmpSum = 0;
                                                tmplength = len;
						tmpMax = tmp;

                                                for(s = i-len+1; s <= i; s++) {
							tmpSum += LookBack[s];
                                                        if(tmp-tmpSum >= tmpMax){
								tmplength = i-s;
                                                                tmpMax = tmp-tmpSum;
                                                        }
						}
						tmp = tmpMax;
                                                len = tmplength;
                                                if(len > 0) {
							if(tmp > max){
								max = tmp;
							}
                                                        if(i-len+1 >= N){
								break;
							}
						}
					}
                                        for(i++; i < tmpN; i++)	{
                                                LookBack[i] += Torus[o][i];
					}
				} 
			}
		}
		cout<<max<<endl;
	}
    return 0;
}
