    //upcasting and downcasting
    #include <bits/stdc++.h>
    using namespace std;

    class shape
    {
        public:
            virtual void draw()
            {
                cout << "Generic drawing..." << endl;
            }
    };

    class circle:public shape
    {
        public:
            void draw() override
            {
                cout << "drawing a circle" << endl;
            }
    };

    class square:public shape
    {
        public:
            void draw() override
            {
                cout << "drawing a square" << endl;
            }
    };

    class rectangle:public shape
    {
        public:
            void draw() override
            {
                cout << "drawing a rectangle" << endl;
            }
    };

    class triangle: public shape
    {
        public:
            void draw() override
            {
                cout << "drawing a triangle" << endl;
            }
    };

    void shapedrawing(shape *s)
    {
        s->draw();
    }

    int main()
    {
        //shape without virtul keyword
        shape *s=new shape();
        s->draw();

        //upcasting
        shape *s1=new circle();
        s1->draw();

        //downcasting
        shape *s2=new shape();
        circle *c=(circle *)s2;
        c->draw();
        return 0;
    } 