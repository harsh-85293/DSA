   //creation, insertion and deletion
   #include <bits/stdc++.h>
   using namespace std;

   class Heap{
    public:
        int *arr;
        int capacity;
        int index;
        
        Heap(int n){
            this->capacity = n;
            arr = new int[n];
            index = 0;
            //jab mujhe insert karna hoga tab +1 karke insert kar denge
            for(int i = 0; i < n; i++){
                arr[i] = 0;
            }
        }
        
        void printheap(){
            for(int i = 0; i < capacity; i++){
                cout << arr[i] << " ";
            }cout << endl;
        }

        void insert(int val){
            //if heap is filled completely
            if(index == capacity - 1){
                cout << "overflow" << endl;
                return;
            }
            //agar jagah available hai
            index++;
            arr[index] = val;
            //now put value at right position
            //by comparing with parent node
            //1 b/c 1 has no parent node
            int i = index;
            while(i > 1){
                int parentindex = i/2;

                if(arr[parentindex] < arr[i]){ 
                    swap(arr[parentindex], arr[i]);
                    i = parentindex;
                }
                else{
                    //parent already bada hai no need to do anything
                    break;
                }
            } 
        }

        void deletefromheap(){
            //replacement
            swap(arr[1], arr[index]);    
            //size reduction 
            index--;
            //heapify
            //heapify(arr, index, 1);
        }
        
        //heapify value present at current index
        
    };

    void heapify(int *arr, int n, int currindex){
        //input
        int i = currindex;
        int li = 2*i;
        int ri = 2*i + 1;
        
        int largestindex = i;//assuming i par value hi greatest hai

        //check in left
        if(li < n && arr[li] > arr[largestindex]){
            //left mai badi value mil gayi
            largestindex = li;
        }
        //check in right
        if(ri < n && arr[ri] > arr[largestindex]){
            //right mai badi value mil gayi
            largestindex = ri;
        }

        //jab yaha pahuche tab sabse badei value ka index hoga
        //largest value i vali hi hai
        //agar largest right ya left vali hai to swap kar do
        if(largestindex != i){
            swap(arr[i], arr[largestindex]);
            i = largestindex;
            //baaki recursion sambhal lega
            heapify(arr, n, i);
        }
    }

    void buildheap(int *arr, int n){
        for(int i = n/2; i > 0; i--){
            heapify(arr, n, i); 
        }
    }

    void heapsort(int *arr, int n){
        //n -> size
        while(n != 1){
            //delete root element and swap it with smallest element
            swap(arr[1], arr[n-1]);
            //delete last element
            n--;
            //heapify i index vala element
            heapify(arr, n, 1);//last -> e so size  = e+1
        }
    }

   int main(){
    Heap pq(10);

    int arr[] = {-1, 10, 20, 30, 40, 50};
    int n = 6;

    buildheap(arr, n);
    cout << endl;
    for(int i = 1; i < n; i++){
        cout << arr[i] << " ";
    }cout << endl;

    cout << endl << "printing heap before sort:" << endl;
    for(int k = 1; k < n; k++){ 
        cout << arr[k] << " ";
    }cout << endl;
    
    heapsort(arr, n);

    cout << endl << "printing heap after sort:" << endl;
    for(int k = 1; k < n; k++){ 
        cout << arr[k] << " ";
    }cout << endl;
   }
