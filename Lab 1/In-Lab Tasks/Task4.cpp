#include<iostream>
using namespace std;

class Rectangle {
    private:
        int* width;
        int* height;

    public:
        Rectangle(int w, int h) {
            width = new int;
            height = new int;

            *width = w;
            *height = h;
        }

        int area() const {
            return (*width)*(*height);
        }

        void display() {
            cout << "Width: " << *width << endl;
            cout << "Height: " << *height << endl;
            cout << "Area: " << area() << endl;
        }

        int* width_getter() {
            return width;
        }

        int* height_getter() {
            return height;
        }

        void width_setter(int y) {
            *width = y;
        }

        void height_setter(int x) {
            *height = x;
        }

        Rectangle(const Rectangle &other) {
            width = new int(*other.width);
            height = new int(*other.height);
        }

        ~Rectangle() {
            delete width;
            width = nullptr;
            delete height;
            height = nullptr;
            cout << "Rectangle Destroyed" << endl;
        }
};

int main () {
    Rectangle r1(4, 5);
    Rectangle r2 = r1;

    cout << "Printing r1's width address: " << r1.width_getter() << endl;

    cout << "Printing r2's width address: " << r2.width_getter() << endl;

    cout << "Modifying r2's width pointer by changing the value stored in it to 5" << endl;
    r2.width_setter(5);

    cout << "Displaying the details of r1:" << endl;
    r1.display(); 
    //This time the width wasn't changed when i modified the pointer

    /*when r1 and r2 go out of scope, both of their destructors will try to delete the same dynamically allocated memory(for task 3). To be specific, when r1's destructor is called it will delete the dynamically allocated memory of height and width, but then the call of r2's destructor will try to delete the same memory(if they both share the same address), causing double-deletion problem (undefined behaviour), but after adding a copy constructor of our own, now the value from r1 is copied into a new addresses for r2. Hence, when the destructor is called now, separate memories are deleted without causing double deletion problem*/
}