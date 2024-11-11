    #include <bits/stdc++.h>
    #include "bird.h"
    using namespace std;

    void birddosomething(Bird *&bird)
    {
        bird->eat();
        bird->fly();
        bird->eat();
    }

    int main()
    {
        Bird *bird =new eagle();
        birddosomething(bird);
        return 0;
    } 