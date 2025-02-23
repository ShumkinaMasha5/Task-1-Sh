#include <bits/stdc++.h>

using namespace std;

template<class T>
void swap(int i, int j, T* A){ 
    T c = A[i];
    A[i] = A[j];
    A[j] = c;
}

template<class T>
void arr(int i, int j, T* A){ //переворот части массива между нашими точками
    for(int k = i; k < (i+j + 1)/2; k++){
        swap(k, j + i - k, A);
    }
}

double distance(int i, int j, double* X, double*Y){ //функция для расстония между точками
    return sqrt((X[i] - X[j])*(X[i] - X[j]) + (Y[i] - Y[j])*(Y[i] - Y[j]));
}


void two_opt(double* X, double* Y, int* N, int n){
    bool flag = true;
    double max = 0.0;
    int ind_1;
    int ind_2;
    while(flag){
        flag = false;
        max = 0.0;
        for(int i = 0; i < n; i++){
            for(int j = i + 2; j < n - 1; j++){
                double D = distance(i, i + 1, X, Y) + distance(j, j + 1, X, Y) - distance(i, j, X, Y) - distance(i + 1, j + 1, X, Y);
                if(D > max){
                    max = D;
                    ind_1 = i;
                    ind_2 = j;
                    flag = true;
                }

            }
        }
        if(flag){
            arr<double>(ind_1 + 1, ind_2, X);
            arr<double>(ind_1 + 1, ind_2, Y);
            arr<int>(ind_1 + 1, ind_2, N);
        }

    }
}

int main(){
    string s;
    cin >> s;
    ifstream in;
    in.open(s); 
    int n;
    in >> n;
    double X[n], Y[n];
    int N[n];
    for (int i = 0; i < n; i++) {
        in >> X[i] >> Y[i];
        N[i] = i;
    }
    two_opt(X, Y, N, n);
    double L = 0.0;
    for(int i = 0; i < n; i++){
        L = L + distance(i, i + 1, X, Y);
    }
    cout << L << ' ' << 0 << endl;
    for(int i = 0; i < n; i++){
        cout << N[i] << ' ';
    }
    return 0;
}
