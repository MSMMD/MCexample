#include <bits/stdc++.h>
using namespace std;

int main(){
    int M = 10000;

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

    ofstream data("./plot_count.dat");
    data << "# Tempo\tProbabilidade\n";

    
    for(long double i=0; i<M; i++){
        if(position == 0) count++;

        long double Ui = dist(gen);
        cout<<"Posição "<<position<<", probabilidade "<<A[position][1 - position]
            <<": valor sorteado -> "<<Ui<<endl;
        if(Ui <= A[position][1 - position]) position = 1-position;

        data<<i+1<<"\t"<<count/(i+1)<<"\n";
    }

    data.close();

    return 0;
}