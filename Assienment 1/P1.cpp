#include <iostream>

using namespace std;

int main(){
    int num;
    int array[1000005];
    cin >> num;
    // cout << num;
    for (int i=0; i<num; i++){
        cin >> array[i];
    }
    // for (int i=0; i<num; i++){
    //     cout << array[i] << endl;
    // }
    int ans=0;
    if (num == 0 or num == 1){
        ans = 0;
    }
    else if(num == 2){
        ans = 1;
    }
    else{
        for (int i=0; i<num-1; i++){   
            int min = array[i];
            int max = -1;
            for (int j=i+1; j<num; j++){
                if (array[j] >= max and max <= min){
                    max = array[j];
                    ans += 1;
                }
                // else if (array[i] <= min && max <= min ){
                //     ans += 1;
                // }
            }
        // cout << ans << endl;
        }
    }
    cout << ans;
}