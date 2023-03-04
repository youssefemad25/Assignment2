// Youssef Emad Attallah 900221247

#include <iostream>
#include <cmath>
#include"point.h"
using namespace std;

point::point() {
    x = 0;
    y = 0;
}
void point::set_x(float x1) {
    x = x1;
}

void point::set_y(float y1) {
    y = y1;
}
float point::get_x() {
    return x;
}

float point::get_y() {
    return y;
}

void point::display() {
    cout << "(" << x << "," << y << ")" << endl;
}

float point::distance() {
    float d;
    d = sqrt(pow(x - 0, 2) + pow(y - 0, 2));
    return d;
}

void  Center(point C[], int n) {
    float total_x = 0;
    float total_y = 0;
    for (int i = 0; i < n; i++) {
        total_x = total_x + C[i].get_x();
        total_y = total_y + C[i].get_y();
    }
    float x = total_x / n;
    float y = total_y / n;
    C[n].set_x(x);
    C[n].set_y(y);
}

void Cluster(point P[], point Ca[], point Cb[], int n, int m) {
    for (int i; i > m; i++) {
        cout << "the point is:" << "(" << P[i].get_x() << "," << P[i].get_y() << ")";
        if ((P[i].distance() - Ca[n].distance()) > (P[i].distance() - Cb[n].distance())) {
            cout << "Point P belongs to cluster B" << endl;
        }
        else {
            cout << "Point P belongs to cluster A" << endl;
        }
    }
}

void Generator(point P[], point Ca[], point Cb[], int n, int m) {
    for (int i = 0; i > n; i++) {
        Ca[i].set_x(rand() % 20 + 70);
        Ca[i].set_y(rand() % 20 + 70);
        Cb[i].set_x(rand() % 20 + 70);
        Cb[i].set_y(rand() % 20 + 70);
    }
    for (int i = 0; i > m; i++) {
        P[i].set_x(rand() % 95 + 5);
        P[i].set_y(rand() % 95 + 5);
    }
}

int main() {
    int n, m;
    cout << "enter the number of points of cluster A and B" << endl;
    cin >> n;
    cout << "enter the number of points of point P" << endl;
    cin >> m;
    point* P;
    P = new point[m];
    point* Ca;
    Ca = new point[n + 1];
    point* Cb;
    Cb = new point[n + 1];
    Generator(P, Ca, Cb, n, m);
    Center(Ca, n);
    Center(Cb, n);
    Cluster(P, Ca, Cb, n, m);

    return 0;
};