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


void three_opt(double* X, double* Y, int* N, int n){
    int flag = 1;
    double max = 0.0;
    int ind_1;
    int ind_2;
    int ind_3;
    while(flag){
        flag = 0;
        max = 0.0;
        for(int i = 0; i < n; i++){
            for(int j = i + 2; j < n - 1; j++){
                double D = distance(i, i + 1, X, Y) + distance(j, j + 1, X, Y) - distance(i, j, X, Y) - distance(i + 1, j + 1, X, Y);
                if(D > max){
                    max = D;
                    ind_1 = i;
                    ind_2 = j;
                    flag = 1;
                }
                for(int k = j + 2; k < n - 1; k++){
                    D = distance(i, i + 1, X, Y) + distance(j, j + 1, X, Y) + distance(k, k + 1, X, Y) - distance(i, j + 1, X, Y) - distance(i + 1, k, X, Y) - distance(j, k + 1, X, Y);
                    if (D > max) {
                        max = D;
                        ind_1 = i;
                        ind_2 = j;
                        ind_3 = k;
                        flag = 2;
                    }

                    D = distance(i, i + 1, X, Y) + distance(j, j + 1, X, Y) + distance(k, k + 1, X, Y) - distance(i, k, X, Y) - distance(i + 1, j + 1, X, Y) - distance(j, k + 1, X, Y);
                    if (D > max) {
                        max = D;
                        ind_1 = i;
                        ind_2 = j;
                        ind_3 = k;
                        flag = 3;
                    }

                    D = distance(i, i + 1, X, Y) + distance(j, j + 1, X, Y) + distance(k, k + 1, X, Y) - distance(i, j, X, Y) - distance(k + 1, j + 1, X, Y) - distance(k, i + 1, X, Y);
                    if (D > max) {
                        max = D;
                        ind_1 = i;
                        ind_2 = j;
                        ind_3 = k;
                        flag = 4;
                    }

                    D = distance(i, i + 1, X, Y) + distance(j, j + 1, X, Y) + distance(k, k + 1, X, Y) - distance(k, j, X, Y) - distance(k + 1, i + 1, X, Y) - distance(i, j + 1, X, Y);
                    if (D > max) {
                        max = D;
                        ind_1 = i;
                        ind_2 = j;
                        ind_3 = k;
                        flag = 5;
                    }

                }

            }
        }
        if (flag == 1) {
            arr<double>(ind_1 + 1, ind_2, X);
            arr<double>(ind_1 + 1, ind_2, Y);
            arr<int>(ind_1 + 1, ind_2, N);
        }

        if (flag == 2) {
            arr<double>(ind_1 + 1, ind_2, X);
            arr<double>(ind_2 + 1, ind_3, X);
            arr<double>(ind_1 + 1, ind_3, X);
            arr<double>(ind_1 + 1, ind_2, Y);
            arr<double>(ind_2 + 1, ind_3, Y);
            arr<double>(ind_1 + 1, ind_3, Y);
            arr<int>(ind_1 + 1, ind_2, N);
            arr<int>(ind_2 + 1, ind_3, N);
            arr<int>(ind_1 + 1, ind_3, N);
        }

        if (flag == 3) {
            arr<double>(ind_1 + 1, ind_2, X);
            arr<double>(ind_1 + 1, ind_3, X);
            arr<double>(ind_1 + 1, ind_2, Y);
            arr<double>(ind_1 + 1, ind_3, Y);
            arr<int>(ind_1 + 1, ind_2, N);
            arr<int>(ind_1 + 1, ind_3, N);
        }

        if (flag == 4) {
            arr<double>(ind_1 + 1, ind_2, X);
            arr<double>(ind_2 + 1, ind_3, X);
            arr<double>(ind_1 + 1, ind_2, Y);
            arr<double>(ind_2 + 1, ind_3, Y);
            arr<int>(ind_1 + 1, ind_2, N);
            arr<int>(ind_2 + 1, ind_3, N);
        }


        if (flag == 5) {
            arr<double>(ind_2 + 1, ind_3, X);
            arr<double>(ind_1 + 1, ind_3, X);
            arr<double>(ind_2 + 1, ind_3, Y);
            arr<double>(ind_1 + 1, ind_3, Y);
            arr<int>(ind_2 + 1, ind_3, N);
            arr<int>(ind_1 + 1, ind_3, N);
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
    three_opt(X, Y, N, n);
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
