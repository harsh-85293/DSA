    //default constructor
    #include <bits/stdc++.h>
    using namespace std;

    class Student
    {
        public:
            //attributes  
            int id;
            int age;
            string name;
            int nos;

            //constructor->default
            Student()
            {
                cout << "mai hu student ka default  constructor" << endl;
            }

            //behaviour or method  or function
            void study()
            {
                    cout << this ->name << " is studying." << endl; 
            }

            void sleeping()
            {
                cout << this ->name << " is sleeping." << endl;                
            }

            void bunk()
            {
                cout << this ->name << " is bunking." << endl;
            }

            //destructor->default
            // if you will not declare it compiler will declare it automatically
            ~Student()
            {
                cout << "mai hu " << this->name <<" ka default destructor" << endl;
            }
    };

    int main()
    {
        Student A;
        A.id=15;
        A.name="Harsh";
        A.nos=5;

        A.study();

        Student B;
        B.id=25;
        B.name="Rohit";
        B.nos=6;

        B.bunk();
        return 0;
    }