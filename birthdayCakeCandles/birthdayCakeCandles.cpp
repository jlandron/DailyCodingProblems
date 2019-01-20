#include <unordered_map>
#include <vector>

using namespace std;

int birthdayCakeCandles(vector<int> ar) {

    //create a hashmap to better solve this problem
    unordered_map<int, int> counts;

    for(int i = 0; i < ar.size(); i++){
        //check if ar[i] "candle height" is in map
        if(counts.find(ar[i]) != counts.end()){
            //if it is, incrememnt its value
            counts[ar[i]]++;
        }else{
            //if not, add it, and set its value to 1
            counts[ar[i]] = 1;
        }
    }

    //create iterator for the hashmap to find the largest value in the map
    unordered_map<int, int>::iterator itr;
    //set the value of the number of candles that can be blown to 1
    int countOfTallest = 1;
    for(itr = counts.begin(); itr != counts.end(); itr++){
        if(itr->second > countOfTallest){
            countOfTallest = itr->second;
        }
    }
    //cout << countOfTallest << endl;
    return countOfTallest;
}
