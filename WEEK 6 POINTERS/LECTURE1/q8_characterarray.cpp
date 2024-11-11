    #include <bits/stdc++.h>
    using namespace std;

    int main()
    {
        char ch[100]="Babbar";
        char *cptr=ch;

        cout << "ch:" << ch << endl;//Babbar
        cout << "&ch:" << &ch << endl;//104
        cout << "ch[0]:" << ch[0] << endl;//B
        cout << "&cptr:" << &cptr << endl;//420
        cout << "*cptr:" << *cptr << endl;//B
        cout << "*(cptr+3):" << *(cptr+3) << endl;//b
        cout << "cptr:" << cptr << endl;//Babbar
        cout << "cptr+3:"<< cptr+3 << endl;

        //below code is not handlewd by vs code ans is a
        // char ch1='a';
        // char *cpt=&ch1;
        // cout << cpt << endl;
        
        return 0;
    }