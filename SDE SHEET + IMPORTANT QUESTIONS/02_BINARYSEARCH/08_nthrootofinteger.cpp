//Brute Approach
int function(int no, int n){
    int ans = 1;

    for(int i = 1; i <= n; i++){
      ans = ans*no;
    }
    
    return ans;
  }

int NthRoot(int n, int m) {
    // Write your code here.
    for(int i = 1; i < m; i++){
      
      if(function(i, n) == m){
        return i;
      }

      else if(function(i, n) > m){
        break;
      }

    }
    
    return -1;
  }

//Optimal Approach
int power(int base, int exp) {
    long long ans = 1;
    while (exp > 0) {
        ans *= base;
        if (ans > 1e9) return 1e9 + 1; // Prevent overflow
        exp--;
    }
    return ans;
}
int power(int base, int n, int m) {
  long long ans = 1;
  while (n > 0) {
      ans *= base;
      if (ans > m) return 2; 
      n--;
  }
  if(ans == m){
    return 1;
  }
  return 0;
}

int optimalusingbs(int n, int m){
  int low = 1;
  int high = m;

  while(low <= high){
    int mid = low + (high - low)/2;
    int midn = power(mid, n, m);
    
    if(midn == 1){
      return mid;
    }

    else if(midn == 0){
      low = mid + 1; 
    }
    
    else{
      high = mid - 1; 
    }
  }
  return -1;
}

int NthRoot(int n, int m) {
  // Write your code here.
  //return brute(n, m);
  return optimalusingbs(n, m);
}
    // Write your code here.
    //return brute(n, m);
    return optimalusingbs(n, m);
}