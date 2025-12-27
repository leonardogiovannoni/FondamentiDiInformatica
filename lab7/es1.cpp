#include <cmath>
#include <iostream>
using namespace std;

struct Point {
    int x;
    int y;
};

Point point_add(Point p1, Point p2) {
    Point result = {};
    result.x = p1.x + p2.x;
    result.y = p1.y + p2.y;
    return result;
}

void point_print(Point me) {
    cout << "(" << me.x << ", " << me.y << ")" << endl;
}

int parte_a() {
    int x = 0;
    int y = 0;
    cin >> x >> y;
    Point p1 = {};
    p1.x = x;
    p1.y = y;

    cin >> x >> y;
    Point p2 = {};
    p2.x = x;
    p2.y = y;
    cout << "p1 = ";
    point_print(p1);

    cout << "p2 = ";
    point_print(p2);

    Point p3 = point_add(p1, p2);

    cout << "p1 + p2 = ";
    point_print(p3);

    return 0;
}

int parte_b() {
    int n = 0;
    cin >> n;
    if (n % 2 != 0) {
        cout << "Errore: il numero di coordinate deve essere pari." << endl;
        return 1;
    }

    int *coords = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> coords[i];
    }

    Point *points = new Point[n / 2];
    for (int i = 0; i < n / 2; i++) {
        int x = coords[2 * i];
        int y = coords[2 * i + 1];

        points[i].x = x;
        points[i].y = y;
    }

    for (int i = 0; i < n / 2; i++) {
        cout << "Point " << i << ": ";
        point_print(points[i]);
    }

    delete[] coords;
    delete[] points;

    return 0;
}

int main() {
//    return parte_a();
     return parte_b();
}
