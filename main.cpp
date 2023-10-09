#include <iostream>
using namespace std;

//функция поиска максимального элемента в массиве
int maximum(int *arr, int n){

    int maxi = arr[0];

    for (int i = 0; i < n; i++){
        if (arr[i] > maxi){
            maxi = arr[i];
        }
    }
    return maxi;
}

// фнкция поиска суммы элементов в массиве
long int arrsum (int *arr, int n){

    long int sum = 0;

    for (int i = 0; i < n; i++)
        sum += arr[i];

    return sum;
}

long int answ (int *arr, int n){

    int arrtmp[n];

    for (int i = 0; i < n; i++){
        arrtmp[i] = arr[i];
    }

    long int s1 = 0;
    long int s2 = 0;

    cout<<"Process: "<<endl;
    cout<<"Begining: "<<"Masha: "<<s1<<' '<<"Petya: "<<s2<<endl;

    while (arrsum(arrtmp, n) != 0){

        if (s1 <= s2){
            s1 += maximum(arrtmp, n);
        }
        else{
            s2 += maximum(arrtmp, n);
        }

        cout<<"Add: "<<maximum(arrtmp, n)<<' '<<"Masha: "<<s1<<' '<<"Petya: "<<s2<<endl;

        for (int i = 0; i < n; i++){
            if (arrtmp[i] == maximum(arrtmp, n)){
                arrtmp[i] = 0;
                break;
            }
        }
    }

    cout<<endl;

    long int result;

    if (s1 <= s2){
        result = s2 - s1;
    }
    else{
        result = s1 - s2;
    }

    return result;

}

int main () {

    int n;
    cout<<"Enter the numer of cups: ";
    cin>>n;
    cout<<endl;

    int m;
    int arr[n];
    cout<<"Enter the cups' weight: ";
    for (int i = 0; i < n; i++){
        cin>>m;
        arr[i] = m;
    }
    cout<<endl;

    long int result = answ(arr, n);

    cout<<"Minimum portion difference: "<<result;

    return 0;
}
