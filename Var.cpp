#include <iostream>
#include "Windows.h"
#include <string>

using namespace std;

class Var {
private:
    int varI;
    double varD;
    string varS;
    int type;
public:
    Var(int var) : varI{ var }, varD{ double() }, varS{ string() }, type{ 1 } {}
    Var(double var) : varI{ int() }, varD{ var }, varS{ string() }, type{ 2 } {}
    Var(string var) : varI{ int() }, varD{ double() }, varS{ var }, type{ 3 } {}
    Var() : varI{ int() }, varD{ double() }, varS{ string() }, type{ 0 } {}

    Var operator+(const Var& object) {
        switch (type) {
        case 1:
            switch (object.type) {
            case 1: return Var(varI + object.varI);
            case 2: return Var(varI + int(object.varD));
            case 3: return Var(varI + atoi(object.varS.c_str()));
            }
        case 2:
            switch (object.type) {
            case 1: return Var(varD + double(object.varI));
            case 2: return Var(varD + object.varD);
            case 3: return Var(varD + atof(object.varS.c_str()));
            }
        case 3:
            switch (object.type) {
            case 1: return Var(varS + to_string(object.varI));
            case 2: return Var(varS + to_string(object.varD));
            case 3: return Var(varS + object.varS);
            }
        }
    }

    Var operator-(const Var& object) {
        switch (type) {
        case 1:
            switch (object.type) {
            case 1: return Var(varI - object.varI);
            case 2: return Var(varI - int(object.varD));
            case 3: return Var(varI - atoi(object.varS.c_str()));
            }
        case 2:
            switch (object.type) {
            case 1: return Var(varD - double(object.varI));
            case 2: return Var(varD - object.varD);
            case 3: return Var(varD - atof(object.varS.c_str()));
            }
        }
    }

    Var operator*(const Var& object) {
        switch (type) {
        case 1:
            switch (object.type) {
            case 1: return Var(varI * object.varI);
            case 2: return Var(varI * int(object.varD));
            case 3: return Var(varI * atoi(object.varS.c_str()));
            }
        case 2:
            switch (object.type) {
            case 1: return Var(varD * double(object.varI));
            case 2: return Var(varD * object.varD);
            case 3: return Var(varD * atof(object.varS.c_str()));
            }
        }
    }

    Var operator/(const Var& object) {
        switch (type) {
        case 1:
            switch (object.type) {
            case 1: return object.varI != 0 ? Var(varI / object.varI) : Var();
            case 2: return object.varD != 0 ? Var(varI / int(object.varD)) : Var();
            case 3: return object.varS != "0" ? Var(varI / atoi(object.varS.c_str())) : Var();
            }
        case 2:
            switch (object.type) {
            case 1: return object.varI != 0 ? Var(varD / double(object.varI)) : Var();
            case 2: return object.varD != 0 ? Var(varD / object.varD) : Var();
            case 3: return object.varS != "0" ? Var(varD / atof(object.varS.c_str())) : Var();
            }
        }
    }

    Var& operator+=(const Var& object) {
        *this = *this + object;
        return *this;
    }

    Var& operator-=(const Var& object) {
        *this = *this - object;
        return *this;
    }

    Var& operator*=(const Var& object) {
        *this = *this * object;
        return *this;
    }

    Var& operator/=(const Var& object) {
        *this = *this / object;
        return *this;
    }

    bool operator<(const Var& object) {
        switch (type) {
        case 1:
            switch (object.type) {
            case 1: return varI < object.varI;
            case 2: return varI < int(object.varD);
            case 3: return varI < atoi(object.varS.c_str());
            }
        case 2:
            switch (object.type) {
            case 1: return varD < double(object.varI);
            case 2: return varD < object.varD;
            case 3: return varD < atof(object.varS.c_str());
            }
        }
    }

    bool operator>(const Var& object) {
        return !(*this < object || *this == object);
    }

    bool operator<=(const Var& object) {
        return *this < object || *this == object;
    }

    bool operator>=(const Var& object) {
        return *this > object || *this == object;
    }

    bool operator==(const Var& object) {
        if (type != object.type) {
            return false;
        }
        switch (type) {
        case 1:
            switch (object.type) {
            case 1: return varI == object.varI;
            case 2: return varI == int(object.varD);
            case 3: return varI == atoi(object.varS.c_str());
            }
        case 2:
            switch (object.type) {
            case 1: return varD == double(object.varI);
            case 2: return varD == object.varD;
            case 3: return varD == atof(object.varS.c_str());
            }
        case 3:
            switch (object.type) {
            case 1: return varS == to_string(object.varI);
            case 2: return varS == to_string(object.varD);
            case 3: return varS == object.varS;
            }
        }
    }

    bool operator!=(const Var& object) {
        return !(*this == object);
    }

    void Show() const {
        switch (type) {
        case 1: cout << varI << endl; break;
        case 2: cout << varD << endl; break;
        case 3: cout << varS << endl; break;
        }
    }
};


int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Var var1 = 5;
    Var var2 = 2.5;
    Var var3 = string("8.4");
    Var(var2 + var1).Show();
    var1 -= var2;
    var1.Show();
    Var(var1 * var2).Show();
    Var(var2 / var1).Show();
    if (var1 > var2) cout << ">" << endl;
    if (var1 != var3) cout << "Not Equal" << endl;
}
