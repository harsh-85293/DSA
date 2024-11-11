    #include <bits/stdc++.h>
    using namespace std;

    class Student
    {
        private:
            //attributes  
            int id;
            int age;
            string name;
            int nos;
            float *gpa;
            string gf;

        public:
            void setgpa(float a)
            {
                *this->gpa=a;
            }

            float getgpa() const
            {
                return *this->gpa;
            }

            int getage() const
            {
                return this->age;
            }
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
        //now A.age or A.gpa or ....etc cannot be called

        cout << A.getgpa() << endl;
        A.setgpa(8.35);
        cout << A.getgpa() << endl;

        cout << A.getage() << endl;
        return 0;
    }  