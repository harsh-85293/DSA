  #include <iostream>
  #include <unordered_map>
  #include <map>
  using namespace std;

  int main()
  {
    //creation
    unordered_map<int, string>umap;
    map<int, string>omap;

    //insertion
    umap[0] = "harsh";
    umap[1] = "rohit";
    umap[2] = "shivam";
    
    omap[0] = "hello";
    omap[1] = "ji";
    omap[2] = "ki hal chal";
    
    cout << "printing ordered map:" << endl;
    for(auto it:omap){
        cout << it.first << "->" << it.second << " ";
    }cout << endl;

    cout << "printing unordered map:" << endl;
    for(auto it:umap){
        cout << it.first << "->" << it.second << " ";
    }cout << endl;
    return 0;
  }