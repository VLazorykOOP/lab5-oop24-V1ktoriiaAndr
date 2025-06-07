#include <iostream>
#include <math.h>

using namespace std;

class Triad {
protected:
    double a, b, c;
public:
    Triad(double a = 0, double b = 0, double c = 0) : a(a), b(b), c(c) {}

    void setValues(double a, double b, double c) {
        this->a = a;
        this->b = b;
        this->c = c;
    }

    double sum() const {
        return a + b + c;
    }

    void display() const {
        cout << "Triad: " << a << ", " << b << ", " << c << endl;
    }
};

class Triangle : public Triad {
public:
    Triangle(double a = 1, double b = 1, double c = 1) : Triad(a, b, c) {}

    bool isValid() const {
        return (a + b > c) && (a + c > b) && (b + c > a);
    }

    double area() const {
        if (!isValid()) {
            cout << "Error: The sides do not form a triangle." << endl;
            return -1;
        }
        double s = sum() / 2;
        return sqrt(s * (s - a) * (s - b) * (s - c));
    }

    bool angles(double &A, double &B, double &C) const {
        if (!isValid()) {
            cout << "Error: The sides do not form a triangle." << endl;
            return false;
        }
        A = acos((b*b + c*c - a*a) / (2 * b * c)) * 180 / M_PI;
        B = acos((a*a + c*c - b*b) / (2 * a * c)) * 180 / M_PI;
        C = acos((a*a + b*b - c*c) / (2 * a * b)) * 180 / M_PI;
        return true;
    }

    void display() const {
        cout << "Triangle sides: " << a << ", " << b << ", " << c << endl;
    }
};

int main() {
    Triangle t(3, 4, 5);
    t.display();
    cout << "Sum of sides: " << t.sum() << endl;

    double ar = t.area();
    if (ar != -1) {
        cout << "Area: " << ar << endl;
    }

    double A, B, C;
    if (t.angles(A, B, C)) {
        cout << "Triangle angles: " << endl;
        cout << "A = " << A << " degrees" << endl;
        cout << "B = " << B << " degrees" << endl;
        cout << "C = " << C << " degrees" << endl;
    }

    return 0;
}
