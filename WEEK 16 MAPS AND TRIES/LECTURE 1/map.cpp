  #include <iostream>
  #include <unordered_map>
  #include <map>
  using namespace std;

  int main()
  {
    //creation
    unordered_map<int, string>u_map;
    map<int, string>o_map;

    //insertion
    u_map[2] = "harsh";
    u_map[3] = "rohit";
    u_map[1] = "shivam";
    
    o_map[2] = "hello";
    o_map[3] = "ji";
    o_map[1] = "ki hal chal";
    
    //accessing elements
    cout << "printing ordered map:" << endl;
    for(auto it:o_map){
        cout << it.first << "->" << it.second << " ";
    }cout << endl;

    cout << "printing unordered map:" << endl;
    for(auto it:u_map){
        cout << it.first << "->" << it.second << " ";
    }cout << endl;

    //search and finding
    //count() and find()
    //1st method -> find()
    if(u_map.find(1) == u_map.end()){
        cout << "1 nahi mila" << endl;
    }
    else{
        cout << "1 mil gaya" << endl;
    }

    //2nd method -> count()
    if(u_map.count(1) == 0){
        cout << "1 nahi mila" << endl;
    }
    else{
        cout << "1 mil gaya" << endl;
    }

    //occurence of elements 
    cout << u_map.count(1) << endl;
    return 0;
  }