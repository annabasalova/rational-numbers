#include <iostream>

using namespace std;

int nod(int n, int m) {
    int c;
    if (n < m) {
        c = n;
        n = m;
        m = c;
    }
    while (m > 0) {
        c = n;
        n = m;
        m = c % m;
    }
    return n;
}

class rac {
private: int p, q;
public:
    rac(double p = 0, double q = 1) :p(p/nod(p,q)), q(q/nod(p,q)) {};
    rac operator +(rac b) {
        rac res;
        int a,  c;
        a = p * b.q + b.p * q;
        c = q * b.q;
        res.p = a / nod(a, c);
        res.q = c / nod(a, c);
        return res;
    }
    friend ostream& operator<<(ostream& stream, rac a);
    ~rac() = default;
};

ostream& operator<<(ostream& stream, rac a) {
    stream << a.p << "/" << a.q;
    return stream;
}

int main()
{
    rac a(1, 3);
    rac b(1, 2);
    a = a + b;
    cout << a;
}
