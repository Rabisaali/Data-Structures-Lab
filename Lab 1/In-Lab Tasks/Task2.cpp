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

        ~Rectangle() {
            delete width;
            width = nullptr;
            delete height;
            height = nullptr;
            cout << "Rectangle Destroyed" << endl;
        }
};

int main () {
    int w, h;
    cout << "Enter width: ";
    cin >> w;
    cout << "Enter height: ";
    cin >> h;
    Rectangle r(w, h);
    r.display();
}