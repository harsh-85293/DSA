    //final keyword
    #include <bits/stdc++.h>
    using namespace std;

    class shape final //no child can be created of shape
    {
        public:
            virtual void draw() final
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
        circle c;
        rectangle r;
        square s;
        shapedrawing(&c);
        shapedrawing(&r);         
        triangle *t=new triangle();
        shapedrawing(t);
        delete(t);
        return 0;
    } 