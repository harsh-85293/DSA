    //pure virtual function
    #include <bits/stdc++.h>
    using namespace std;
    #if !defined(BIRD_H)
    #define BIRD_H

    class Bird
    {
        public:
            virtual void eat()=0;
            virtual void fly()=0;
            //classes that inherit this class has to inherit compulsary these pure virtual functions
    };

    class sparrow:public Bird
    {
        public:
            void eat() override
            {
                cout << "sparrow is eating" << endl;
            }

            void fly() override
            {
                cout << "sparrow is flying" << endl;
            }
    };

    class eagle:public Bird
    {
        public:
            void eat() override
            {
                cout << "eagle is eating" << endl;
            }

            void fly() override
            {
                cout << "eagle is flying" << endl;
            }
    };
    #endif // MACRO
