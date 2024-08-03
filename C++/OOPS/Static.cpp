#include<bits/stdc++.h>
using namespace std;

class Base{
    public:
        virtual void display(){
            cout << "display static\n";
        }
        static void display(int x){
            cout << x<<" display static\n";
        }
        void print(){
            cout << "print static\n";
        }
};

class Derived:public Base{
    public:
        void display() override{
            cout << "display derived\n";
        }
        static void display(int x){
            cout << x<<" display derived\n";
        }
};

int main(){
    Derived *b = new Derived();
    b->display();
    b->print();
    Base::display(12);
    return 0;
}