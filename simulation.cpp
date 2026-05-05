#include <bits/stdc++.h>
using namespace std;

int main(){
    int M = 1000000;

    mt19937 gen(0);
    uniform_real_distribution<long double> dist(0.0, 1.0);
    
    long double p, q;
    cin>>p>>q;
    
    long double A[2][2];
    A[0][0] = 1-p;
    A[0][1] = p;
    A[1][0] = q;
    A[1][1] = 1-q;
    
    long double count=0;
    int position=0;
    long double first_T = -1;
    long double last_T = -1;
    long double returns = 0;

    ofstream data_counting("./plot_count.dat");
    data_counting << "# Tempo\tProbabilidade\n";

    ofstream data_kac("./plot_kac.dat");
    data_kac << "# Tempo\tProbabilidade\n";
    
    for(long double i=0; i<M; i++){
        if(position == 0){
            count++;
            
            if(first_T == -1) first_T = i;
            else returns++;

            last_T = i;
        }

        long double Ui = dist(gen);
        cout<<"Posição "<<position<<", probabilidade "<<A[position][1 - position]
            <<": valor sorteado -> "<<Ui<<endl;
        if(Ui <= A[position][1 - position]) position = 1-position;

        data_counting<<i+1<<"\t"<<count/(i+1)<<"\n";
        data_kac<<i+1<<"\t"<<returns/(last_T - first_T)<<"\n";
    }

    data_counting.close();
    data_kac.close();

    return 0;
}