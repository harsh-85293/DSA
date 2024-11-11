    //compile type polymorphism or static polymorphism
    //operator overloading
    #include <bits/stdc++.h>
    using namespace std;

    class Complex
    {
        public:
            int real;
            int imag;
        
            Complex()
            {
                real=imag=-1;
            }
            Complex(int r,int i)
            {
                this->real=r;
                this->imag=i;
            };

            Complex operator+(const Complex &B)
            {
                //this=A
                Complex temp;
                temp.real=this->real+B.real;
                temp.imag=this->imag+B.imag;
                return temp;
            }

            Complex operator-(const Complex &B)
            {
                //this=A
                Complex temp;
                temp.real=this->real-B.real;
                temp.imag=this->imag-B.imag;
                return temp;
            }

            void print()
            {
                printf("%d + (%di)",this->real,this->imag);
                cout << endl;
            }
    };

    int main()
    {
        Complex A(2,5);
        A.print();
        Complex B(2,3);
        B.print();

        Complex C=A+B;
        C.print();

        Complex D=A-B;
        D.print();
        return 0;
    } 