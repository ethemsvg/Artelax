//Made by Ethem Mengaaslan for Artelax Internship Application.

#include <iostream>
#include <vector>

using namespace std;

int main(){

// The vector where the values will be stored.
vector<int> dailyValues;

int i=0;
int tempInt;
int size;

// These bools show whether the current point on the iteration is in a rising or a lowering position among the values.
bool isRising;
bool isLowering;

cout << "Please enter how many values you're going to enter." << endl;
cin >> size;

cout << "Please enter "<< size << " positive integer values:" << endl;

for(i=0;i<size;i++){
    
    cin >> tempInt;
    dailyValues.push_back(tempInt);
}

/*

The if block below is to determine whether the values are rising, 
lowering or in a steady state (At the beggining).
The first two values are compared. 

*/

if(dailyValues[0] > dailyValues[1]){
    isLowering = true;
    isRising = false;
}else if(dailyValues[0] < dailyValues[1]){
    isLowering = false;
    isRising = true;
    cout << "Bought at " << dailyValues[0] << endl;
}else if(dailyValues[0] == dailyValues[1]){
    isLowering = false;
    isRising = false;
    cout << "Bought at " << dailyValues[0] << endl;
}

for(i=0;i<size-1;i++){
    /* If the values are in a rising position, this if block checks whether the rising position is ended on that exact value,
       This is done by comparing the current value to the next one.
       If the next value is lower than the current value, it means the current value is the highest point on the current rise,
       and the stock should be sold at that point for maximum profit.
    */
    if(isRising){
        if(dailyValues[i] > dailyValues[i+1]){
            isRising = false;
            isLowering = true;
            cout << "Sold at " << dailyValues[i] << endl;
        }
    }
    /* If the values are in a lowering position, this if block checks whether the lowering position is ended on that exact value,
       This is done by comparing the current value to the next one.
       If the next value is higher than the current value, it means the current value is the lowest point on the current rise,
       and the stock should be bought at that point for maximum profit.
    */
    else if(isLowering){
        if(dailyValues[i] < dailyValues[i+1]){
            isRising = true;
            isLowering = false;
            cout << "Bought at " << dailyValues[i] << endl;
        }
    }
    /* If the values are not in a lowering or rising position,
      (If the past two values were equal), this block checks the next value.
      Comparing the current value to the next value, it determines whether the next
      movement is going to be a rise or a lowering.
      It then sets the bool isLowering and isRising variables, letting the loop continue on working
       on the next iterations.
    */
    else{
        if(dailyValues[i] > dailyValues[i+1]){
            isLowering = true;
            isRising = false;
        }else if(dailyValues[i] < dailyValues[i+1]){
            isLowering = false;
            isRising = true;
        }
    }
}

/* 
   Since the above for loop compares i with i+1, when the last element is compared with i+1, it causes a segmentation error.
   To get over this, we inspect the last value out the for loop as a last step seperately.
*/
if(dailyValues[size-1] > dailyValues[size-2]){
    cout << "Sold at " << dailyValues[size-1] << endl;
}

return 1;

}