#include <iostream>
using namespace std;

class  distance {
public:
    void get_distance(int distance_milmetr, int distance_santmetr, int distance_metr);
    void show_distance();
    distance operator+(const distance&distance);
    ~distance();
private:
    int milmetr, santmrtr, metr;
};

void distance::get_distance(int distance_milmetr, int distance_santmetr, int distance_metr) {
    milmetr = distance_milmetr;
    santmrtr = distance_santmetr;
    metr = distance_metr;
}

void distance::show_distance() {
    cout << "distance: " << metr << "m, " << santmrtr << "sm, " << milmetr << "mm" << '\n';
}

class distance distance::operator+(const distance&distance) {
    class distance result;
    result.metr=distance.metr+metr;
    result.santmrtr=distance.santmrtr+ santmrtr;
    result.milmetr=distance.milmetr+milmetr;
    if (result.milmetr >= 10) {
        result.santmrtr+=(result.milmetr/10);
        result.milmetr%=10;
    }
    if (result.santmrtr >= 100) {
        result.metr+=(result.santmrtr/100);
        result.santmrtr%=100;
    }
    return result;
}

distance::~distance(){}

int main() {
    int mm_1, sm_1, m_1, mm_2, sm_2, m_2;
    class distance distance_1;
    class distance distance_2;
    cout << "First distance(mm, sm, m):";
    cin >> mm_1 >> sm_1 >> m_1;
    cout << "First distance(mm, sm, m):";
    cin >> mm_2 >> sm_2 >> m_2;
    distance_1.get_distance(mm_1, sm_1, m_1);
    distance_1.show_distance();
    distance_2.get_distance(mm_2, sm_2, m_2);
    distance_2.show_distance();
    (distance_1+distance_2).show_distance();
    return 0;
}