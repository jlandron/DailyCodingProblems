#include <iostream>
using namespace std;

int numWays(int);
int betterNumWays(int);

int main() {
    cout << "If you are given a number of steps N, and you can take either 1 or 2 steps at a time, how many ways can you traverse the steps?" << endl;

/*
find some cases and find patters
1 step, [1]   1 ways
2 steps, [1,1]||[2]   2 ways
3 steps, [1,1,1],[1,2],[2,1]  3 ways
4 steps, [1,1,1,1],[2,2],[1,2,1],[1,1,2],[2,1,1]  5 ways
seems to follow fibbonnacci sequence
5 
*/

    cout << "if N = 1, there are " << numWays(1) << " ways" << endl;
    cout << "if N = 2, there are " << numWays(2) << " ways" << endl;
    cout << "if N = 4, there are " << numWays(4) << " ways" << endl;
    cout << "if N = 5, there are " << numWays(5) << " ways" << endl;
    cout << "if N = 10, there are " << numWays(10) << " ways" << endl;
    cout << "if N = 20, there are " << numWays(20) << " ways" << endl;
    cout << "-------------------------------------------------" << endl;
    cout << "if N = 1, there are " << betterNumWays(1) << " ways" << endl;
    cout << "if N = 2, there are " << betterNumWays(2) << " ways" << endl;
    cout << "if N = 4, there are " << betterNumWays(4) << " ways" << endl;
    cout << "if N = 10, there are " << betterNumWays(10) << " ways" << endl;
    cout << "if N = 20, there are " << betterNumWays(20) << " ways" << endl;
    //the second way is less cumbersome for the call stack
}
//recursuve fibbonacci numbers
int numWays(int n){
    int result = 0;
    if(n <= 1){
        return result + 1;
    }else{
        return result + numWays(n-1) + numWays(n-2);
    } 
};
int betterNumWays(int n){
    if(n <= 1){
        return 1;
    }else{
        int nums[] = {1,1,2};
        for(int i = 2; i < n; i++){
            nums[2] = (nums[0] + nums[1]);
            nums[0] = nums[1];
            nums[1] = nums[2];
        }
        return nums[2];
    }
};