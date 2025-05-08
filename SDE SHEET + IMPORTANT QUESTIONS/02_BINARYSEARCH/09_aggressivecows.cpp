bool canweplace(vector<int>&arr, int dist, int cows){
    int cntcows = 1;
    int last = arr[0];
    int n = arr.size();
    for(int i = 1; i <= n - 1; i++){
        if(arr[i] - last >= dist){
            cntcows++;
            last = arr[i];
        }
    }

    if(cntcows >= cows){
        return true;
    }

    else{
        return false;
    }
}

int brutels(vector<int> &stalls, int cows){
    sort(stalls.begin(), stalls.end());
    int maxi = *max_element(stalls.begin(), stalls.end());
    int mini = *min_element(stalls.begin(), stalls.end());

    for(int i = 1; i <= maxi - mini; i++){
        if(canweplace(stalls, i, cows) == true){
            continue;
        }
        else{
            return i - 1;
        }
    }
    return maxi - mini;
    
}

int optimalbs(vector<int> &stalls, int cows){
    sort(stalls.begin(), stalls.end());
    int low = 0;
    int high = stalls[stalls.size() - 1] - stalls[0];
    int ans = 0;
    while(low <= high){
        int mid = low + (high - low) / 2;

        if(canweplace(stalls, mid, cows) == true){
            ans =  mid;
            low = mid + 1;
        }

        else{
            high = mid - 1;
        }
    }
    return ans;
}


int aggressiveCows(vector<int> &stalls, int k)
{
    //    Write your code here.
    //return brutels(stalls, k);
    return optimalbs(stalls, k);
}