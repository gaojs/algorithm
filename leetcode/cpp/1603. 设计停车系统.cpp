#include <securec.h>
#include <bits/stdc++.h>
using namespace std;

class ParkingSystem {
private:
    int n[3];
public:
    ParkingSystem(int big, int medium, int small)
    {
        n[0] = big;
        n[1] = medium;
        n[2] = small;
    }

    bool addCar(int carType)
    {
        if (carType < 1 || carType>3) {
            return false;
        } else if (n[carType - 1] <= 0) {
            return false;
        } else {
            n[carType - 1]--;
            return true;
        }
    }
};

int main()
{
    return 0;
}