    //name ->private accessed by getter and setter
    #include <bits/stdc++.h>
    using namespace std;

    class vehicle
    {
        private:
            string name;
        public :
            string model;
            int nooftyres;

            string getname()
            {
                return this->name;
            }
            vehicle(string name,string model,int nooftyres)
            {
                cout << "i am inside vehicle constructor" << endl;
                this->name=name;
                this->model=model;
                this->nooftyres=nooftyres;
            }

        public:
            void start_engine()
            {
                cout << "Engine is starting " << name << " " << model << endl;
            }
            void stop_engine()
            {
                cout << "Engine is stoping " << name << " " << model << endl;
            }
    };

    class car:public vehicle
    {
        public:
            int noofdoors;
            string transmissiontype;

            car(string name,string model,int nooftyres,int noofdoors,string transmissiontype):vehicle(name,model,nooftyres)
            {
                cout << "i am inside car constructor" << endl;
                this->noofdoors=noofdoors;
                this->transmissiontype=transmissiontype;
            }

            void startAC()
            {
                cout << "AC has started of " << getname() <<endl;
            } 
    };

    int main()
    {
        car A("maruti 800","LXI",4,4,"manual");
        A.start_engine();
        A.startAC();
        A.stop_engine();
        cout << A.getname();
        return 0;
    } 