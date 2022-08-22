#include <iostream>
using namespace std;
class ComplexNumbers {
    // Complete this class
    private:
    int real, imaginary;
    public:
    ComplexNumbers(int r, int i)
    {
        real = r;
        imaginary = i;
    }
    void plus(ComplexNumbers const &c)
    {
        this -> real = this -> real + c.real;
        this -> imaginary = this -> imaginary + c.imaginary;
    }
    void print()
    {
        cout << this -> real << " + i" << this -> imaginary; 
    }
    void multiply(ComplexNumbers const &c)
    {
        this -> real = (this -> real * c.real) + ((this -> imaginary * c.imaginary) * -1);
        this -> imaginary = (this -> real * c.imaginary) + (this -> imaginary * c.real);
    }
};

int main() {
    int real1, imaginary1, real2, imaginary2;
    
    cin >> real1 >> imaginary1;
    cin >> real2 >> imaginary2;
    
    ComplexNumbers c1(real1, imaginary1);
    ComplexNumbers c2(real2, imaginary2);
    
    int choice;
    cin >> choice;
    
    if(choice == 1) {
        c1.plus(c2);
        c1.print();
    }
    else if(choice == 2) {
        c1.multiply(c2);
        c1.print();
    }
    else {
        return 0;
    }   
}