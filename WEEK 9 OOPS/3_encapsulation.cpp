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

        private:
            float *gpa;
            string gf;

        public:
            //constructor->default
            Student()
            {
                cout << "mai hu student ka parametrized  constructor" << endl;
            }

            //parametrized constructoe
            Student(int id,int age,string name,int nos,float gpa,string gf)
            {
                cout << "mai hu student ka parametrized  constructor" << endl;
                this->id=id;
                this->name=name;
                this->age=age;
                this->nos=nos;
                this->gpa=new float(gpa);
                this->gf=gf;
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
        public:
            //destructor->default
            // if you will not declare it compiler will declare it automatically
            ~Student()
            {
                cout << "mai hu " << this->name<<" ka parametrized destructor" << endl;
                delete this->gpa;//delete the dynamic memory allocated
            }
        private:
            void gfchatting()
            {
                cout << this ->name << " is chatting." << endl;
            }
    };

    int main()
    {
        Student A(1,12,"Ranu",5,7.8,"Menu");
        //A. after dot gfchatting and gpa are not available
        // A.gfchatting();
        return 0;
    }  