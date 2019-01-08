#include <iostream>
#include <sstream>

using namespace std;

int * arrayProduct(int[], int);
int * arrayProduct2(int[], int);
string toString(int[],int);

int main() {
    int arr1[] = {1,2,3,4,5};
    int len1 = sizeof(arr1)/4;
    
    cout << "The original array is : " << toString(arr1, len1) << endl;
    cout << "The Retruned array is : " << toString(arrayProduct(arr1, len1), len1) << endl;
    cout << "The Retruned array is : " << toString(arrayProduct2(arr1, len1), len1) << endl;

}
//Brute force method, O(n^2)
int * arrayProduct(int arr[], int len){
    int * newArr = new int[len];
    for(int i = 0; i < len; i++){
        newArr[i] = 1;
        for(int j = 0; j < len; j++){
            if(i != j){
                newArr[i] *= arr[j];
            }
        }
    }
    return newArr;
};
//more elegent solution O(n)
int * arrayProduct2(int arr[], int len){
    int * prod = new int[len];
    int left[len];
    int right[len];

    left[0] = 1;
    right[len - 1] = 1;

    for(int i = 1;i < len; i++){
        left[i] = arr[i - 1] * left[i - 1];
    }
    for(int i = (len - 2); i >= 0; i--){
        right[i] = arr[i + 1] * right[i + 1];
    }
    for(int i = 0;i < len; i++){
        prod[i] = left[i] * right[i];
    }
    return prod;   
};
string toString(int arr[],int len){
    stringstream result;
    result << "[" << arr[0];
    for(int i = 1; i < len; i++){
        result << "," << arr[i];
    }  
    result << "]";
    return result.str();
};
