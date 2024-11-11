    //generally used
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
            float *gpa;

            //constructor->default
            Student()
            {
                cout << "mai hu student ka parametrized  constructor" << endl;
            }

            //copy constructor
            Student(const Student &scrobj)//srcobj->A
            {
                cout << "Student copy constructor called" << endl;
                this->id=scrobj.id;
                this->age=scrobj.age;
                this->name=scrobj.name;
                this->nos=scrobj.nos;
            }

            //parametrized constructoe
            Student(int id,int age,string name,int nos,float gpa)
            {
                cout << "mai hu student ka parametrized  constructor" << endl;
                this->id=id;
                this->name=name;
                this->age=age;
                this->nos=nos;
                this->gpa=new float(gpa);
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
                cout << "mai hu " << this->name<<" ka parametrized destructor" << endl;
                delete this->gpa;//delete the dynamic memory allocated
            }
    };

    int main()
    {
        Student A(1,21,"Harsh",6,9.6);
        Student B(2,22,"Rohit",7,9.7);
        Student C(3,23,"Ram",8,9.8);
        // Student D(4,24,"Lala",9);

        cout << A.name <<" "<<A.age << endl;
        B.bunk();
        C.sleeping();

        //copy constructor
        Student Z=A;//1st way
        Student X(A);//2nd way

        cout << "copy constructor name:" << Z.name << " " <<"name from which copy constructor is copied:"<< A.name << endl;
        
        //Dynamic memory allocation
        Student *F=new Student(1,14,"Babbar",7,10);
        cout << F->name << " " << F->age << endl;
        F->study();
        delete F;
        
        return 0;
    }  