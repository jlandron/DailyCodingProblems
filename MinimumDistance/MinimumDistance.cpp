#include <iostream>
#include <vector>
#include <unordered_map>
#include <limits.h>

using namespace std;

// Complete the minimumDistances function below.
int minimumDistances(vector<int> a) {
    int min = INT_MAX;
    unordered_map<int, int> numAndLocation;
    numAndLocation.emplace(a[0], 0);
    for(int i = 1; i < a.size(); i++){
      unordered_map<int, int>::iterator it = numAndLocation.find(a[i]);
      if (it != numAndLocation.end() && (it->first == a[i]) && ((i - it->second) < min)) {
           min = (i - it->second);
        } else {
           numAndLocation.emplace(a[i], i);
        }
    }
    if(min == INT_MAX){
        return -1;
    }
    return min;
}

int main(){

    //two similer numbers 14 spaces apart
    vector<int> myNums1 = {454, 9087, 2397, 2541, 1459, 483, 3944, 
    2437, 6544, 982, 8902, 576, 9336, 9672, 7742, 433, 5982, 8461, 4640, 
    9236, 9248 ,8333 ,9742 ,6718 ,6213 ,4368, 4553, 7815, 4666, 433, 
    4071 ,3173, 7239, 3159, 1923, 9780, 4618 ,2406 ,76, 3407, 5302, 1058};
    cout << minimumDistances(myNums1) << endl;
    //two similer numbers 1 space apart
    vector<int> myNums2 = {454, 9087, 2397, 2541, 1459, 483, 3944, 
    2437, 6544, 982, 8902, 576, 9336, 9672, 7742, 433, 5982, 8461, 4640, 
    9236, 9248 ,8333 ,9742 ,6718 ,6213, 6213, 4368, 4553, 7815, 4666, 433, 
    4071 ,3173, 7239, 3159, 1923, 9780, 4618 ,2406 ,76, 3407, 5302, 1058};
    cout << minimumDistances(myNums2) << endl;
    //no similer numbers
    vector<int> myNums3 = {454, 9087, 2397, 2541, 1459, 483, 3944, 
    2437, 6544, 982, 8902, 576, 9336, 9672, 7742, 5982, 8461, 4640, 
    9236, 9248 ,8333 ,9742 ,6718 ,6213 ,4368, 4553, 7815, 4666, 433, 
    4071 ,3173, 7239, 3159, 1923, 9780, 4618 ,2406 ,76, 3407, 5302, 1058};
    cout << minimumDistances(myNums3) << endl;
    //check edge cases with two similer numbers next to each other at both the begining and end
    vector<int> myNums4 = {454, 454, 9087, 2397, 2541, 1459, 483, 3944, 
    2437, 6544, 982, 8902, 576, 9336, 9672, 7742, 5982, 8461, 4640, 
    9236, 9248 ,8333 ,9742 ,6718 ,6213 ,4368, 4553, 7815, 4666, 433, 
    4071 ,3173, 7239, 3159, 1923, 9780, 4618 ,2406 ,76, 3407, 5302, 1058};
    cout << minimumDistances(myNums4) << endl;
    vector<int> myNums5 = {454, 9087, 2397, 2541, 1459, 483, 3944, 
    2437, 6544, 982, 8902, 576, 9336, 9672, 7742, 5982, 8461, 4640, 
    9236, 9248 ,8333 ,9742 ,6718 ,6213 ,4368, 4553, 7815, 4666, 433, 
    4071 ,3173, 7239, 3159, 1923, 9780, 4618 ,2406 ,76, 3407, 5302, 1058, 1058};
    cout << minimumDistances(myNums5) << endl;
}