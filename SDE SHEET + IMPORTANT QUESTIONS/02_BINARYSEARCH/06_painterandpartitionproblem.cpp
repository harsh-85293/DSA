
int noofpartition(vector<int>& arr, int maxi){
    int painter = 1;
    int painterpartition = 0;
    int n = arr.size();

    for(int i = 0; i <= n - 1; i++){
        if(painterpartition + arr[i] <= maxi){
            painterpartition += arr[i];
        }

        else{
            painter++;
            painterpartition = arr[i];
        }
    }
    return painter;
}

int findLargestMinDistance(vector<int> &boards, int k)
{
    //    Write your code here.
    int n = boards.size();
    if(k > n){
        return -1;
    }

    int low = *max_element(boards.begin(), boards.end());
    int high = accumulate(boards.begin(), boards.end(), 0);

    while(low <= high){
        int mid = low + (high - low)/2;
        int nps = noofpartition(boards, mid);

        if(nps > k){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    return low;
}