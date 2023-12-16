class A 
{
    public:
       int x;
    protected:
       int y;
    private:
       int z;
};

class B : public A
{
    // x is public
    // y is protected
    // z is not accessible from B
    void f() {
        x = 1;
        y = 1;
        // z = 1; // error
    }
};

class C : protected A
{
    // x is protected
    // y is protected
    // z is not accessible from C
    void f() {
        x = 1;
        y = 1;
        // z = 1; // error
    }
};

class D : private A    // 'private' is default for classes
{
    // x is private
    // y is private
    // z is not accessible from D
    void f() {
        x = 1;
        y = 1;
        // z = 1; // error
    }
};

int main() {
    A a;
    B b;
    C c;

    b.x = 1;
    // b.y = 1; // error

    // c.x = 1; // error
    // c.y = 1; // error

    // d.x = 1; // error
    // d.y = 1; // error
}