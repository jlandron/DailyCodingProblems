#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

bool sumEqualNum(int[], int, int);
bool sumEqualNum2(int[], int, int);
string toString(int[],int);
void test(int[], int);

int main() {
    int arr1[] = {1,2,3,4,5,6,7,8,9};
    int len1 = (sizeof(arr1)/sizeof(arr1[0]));
    int arr2[] = {1,1,1,1,1,1};
    int len2 = (sizeof(arr2)/sizeof(arr2[0]));
    int arr3[] = {1,10,100,1000,10000,100000};
    int len3 = (sizeof(arr3)/sizeof(arr3[0]));
    int arr4[] = {10,15,3,7};
    int len4 = (sizeof(arr4)/sizeof(arr4[0]));
    int arr5[100];
    int len5 = (sizeof(arr4)/sizeof(arr4[0]));
    //test here
    test(arr1, len1);
    test(arr2, len2);
    test(arr3, len3);
    test(arr4, len4);
    test(arr5, len5);
}
bool sumEqualNum(int arr[], int n, int len){
    for(int i = 0; i < len; i++){
        for(int j = (i+1); j < len; j++){
            if(arr[i]+arr[j] == n){
                return true;
            }
        }
    }
    return false;
};
bool sumEqualNum2(int arr[], int n, int len){
    vector<int> v;
    if(len <= 1){return false;}
    v[arr[0]] = 1;
    for(int i = 1; i < len; i++){
        v[arr[i]] = 1;
        int target = n - arr[i];
        if(v[target] == 1){
            return true;
        }
    }
    return false;
};
//This method is so that I can print int[] easily
string toString(int arr[],int len){
    stringstream result;
    result << "[" << arr[0];
    for(int i = 1; i < len; i++){
        result << "," << arr[i];
    }  
    result << "]";
    return result.str();
};
//test harness
void test(int arr[], int len){
    int sums[] = {1,2,3,4,10,11,17,10001,10002};
    cout << "Does The array " << toString(arr, len) << " contain two numbers that sum to : " << endl;
    for(int x = 0 ; x < sizeof(sums)/sizeof(sums[0]); x++){
        cout << sums[x] << "? ";
        if(sumEqualNum2(arr, sums[x], len)){
            cout << "\tTrue" << endl;
        }else{
            cout << "\tFalse" << endl;
        }
    }
    cout << endl;
}