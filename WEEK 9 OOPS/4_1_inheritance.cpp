    //best way
    //name ->protected
    #include <bits/stdc++.h>
    using namespace std;

    class vehicle
    {
        protected:
            string name;
            string model;
            int nooftyres;

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
        ~vehicle()
        {
            cout << "vehicle destructor is called" << endl;
        }
    };

    class car:public vehicle
    {
        protected:
            int noofdoors;
            string transmissiontype;
        public:
            car(string name,string model,int nooftyres,int noofdoors,string transmissiontype):vehicle(name,model,nooftyres)
            {
                cout << "i am inside car constructor" << endl;
                this->noofdoors=noofdoors;
                this->transmissiontype=transmissiontype;
            }

            void startAC()
            {
                cout << "AC has started of " << name <<endl;
            } 

            ~car()
            {
                cout << "car destructor is called" << endl;
            }
    };
    class motorcycle:public vehicle
    {
        protected:
            string handlebarstyle;
            string suspensiontype;
        public:
            motorcycle(string name,string model,int nooftyres,string handlebarstyle,string suspensiontype):vehicle(name,model,nooftyres)
            {
                cout << "motorcycle constructor is called" << endl;
                this->handlebarstyle=handlebarstyle;
                this->suspensiontype=suspensiontype;
            }
            void wheelie()
            {
                cout << "Wheelie kar rahe hai " << name << endl;
            }
        ~motorcycle()
        {
            cout << "motorcycle destructor is called" << endl;
        }
    };

    int main()
    {
        car A("maruti 800","LXI",4,4,"manual");
        A.start_engine();
        A.startAC();
        A.stop_engine();
        // cout <<A.name(); not accesible
        motorcycle M("BMW","VXI",2,"U","Hard");
        M.wheelie();
        M.stop_engine();
        return 0;
    } 