#include <iostream>
#include <cmath>
using namespace std;

class Bod {
private:
    double x, y;

public:
    Bod(double xBod = 0.0, double yBod = 0.0) {
        x = xBod;
        y = yBod;
    }

    void vypis() const {
        cout << "Bod: "<< "(" << x << ", " << y << ")" << endl;
    }

    void posun(double xMove, double yMove) {
        x += xMove;
        y += yMove;
    }

    void otoc(double uhelStupne) {
        double rad1 = M_PI / 180.0;
        double rad2 = uhelStupne * rad1;
        double xRot = x * cos(rad2) - y * sin(rad2);
        double yRot = x * sin(rad2) + y * cos(rad2);
        x = xRot;
        y = yRot;
    }

    void zkosen(double kx, double ky) {
        double xKos = x + kx * y;
        double yKos = y + ky * x;
        x = xKos;
        y = yKos;
    }

    void zrcadli() {
        x = -x;
        y = -y;
    }
};

int main() {
    double x, y;
    cout << "Zadej souradnice bodu X: ";
    cin >> x;
    cout << "Zadej souradnice bodu Y: ";
    cin >> y;

    Bod bod(x, y);

    int volba;
    do {
        cout << "\n--- MENU ---\n";
        bod.vypis();
        cout << "1. Posun bod\n";
        cout << "2. Otoc bod kolem pocatku\n";
        cout << "3. Zkosen bod\n";
        cout << "4. Zrcadli bod\n";
        cout << "0. Konec\n";
        cout << "Vyber: ";
        cin >> volba;

        switch (volba) {
        case 1: {
            double dx, dy;
            cout << "Zadej posun x: ";
            cin >> dx;
            cout << "Zadej posun y: ";
            cin >> dy;
            bod.posun(dx, dy);
            break;
        }
        case 2: {
            double uhel;
            cout << "Zadej uhel ve stupnich: ";
            cin >> uhel;
            bod.otoc(uhel);
            break;
        }
        case 3: {
            double kx, ky;
            cout << "Zadej zkoseni x: ";
            cin >> kx;
            cout << "Zadej zkoseni y: ";
            cin >> ky;
            bod.zkosen(kx, ky);
            break;
        }
        case 4: {
            bod.zrcadli();
            break;
        }
        case 0:
            cout << "Konec programu.\n";
            break;
        default:
            cout << "Neplatna volba.\n";
        }

    } while (volba != 0);

    return 0;
}
