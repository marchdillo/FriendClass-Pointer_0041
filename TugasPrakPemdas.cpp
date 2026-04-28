#include <iostream>
#include <cmath>

using namespace std;

// Forward Declaration agar class LayangLayang mengenali class BelahKetupat
class BelahKetupat;

class LayangLayang {
private:
    double d1, d2, sisiA, sisiB;

public:
    void input() {
        cout << "--- Input Layang-Layang ---" << endl;
        cout << "Diagonal 1: "; cin >> d1;
        cout << "Diagonal 2: "; cin >> d2;
        cout << "Sisi Panjang (a): "; cin >> sisiA;
        cout << "Sisi Pendek (b): "; cin >> sisiB;
    }

    double hitungLuas() {
        return 0.5 * d1 * d2;
    }

    double hitungKeliling() {
        return 2 * (sisiA + sisiB);
    }

    void output() {
        cout << "\n--- Hasil Layang-Layang ---" << endl;
        cout << "Luas: " << hitungLuas() << endl;
        cout << "Keliling: " << hitungKeliling() << endl;
    }

    // Memberikan izin kepada class BelahKetupat untuk mengakses private member
    friend class BelahKetupat;
};

class BelahKetupat {
private:
    double d1, d2, sisi;

public:
    void input() {
        cout << "\n--- Input Belah Ketupat ---" << endl;
        cout << "Diagonal 1: "; cin >> d1;
        cout << "Diagonal 2: "; cin >> d2;
        cout << "Sisi: "; cin >> sisi;
    }

    double hitungLuas() {
        return 0.5 * d1 * d2;
    }

    // Method ini bisa mengakses data LayangLayang jika diperlukan karena status 'friend'
    double hitungKeliling() {
        return 4 * sisi;
    }

    // Contoh penggunaan friend: menghitung keliling Layang-Layang dari dalam class ini
    void hitungKelilingLayang(LayangLayang &l) {
        double kel = 2 * (l.sisiA + l.sisiB);
        cout << "Keliling Layang-Layang (diakses dari Belah Ketupat): " << kel << endl;
    }

    void output() {
        cout << "\n--- Hasil Belah Ketupat ---" << endl;
        cout << "Luas: " << hitungLuas() << endl;
        cout << "Keliling: " << hitungKeliling() << endl;
    }
};

int main() {
    // Akses hanya melalui object
    LayangLayang objLayang;
    BelahKetupat objKetupat;

    objLayang.input();
    objLayang.output();

    objKetupat.input();
    objKetupat.output();

    // Mendemonstrasikan friend class/method
    objKetupat.hitungKelilingLayang(objLayang);

    return 0;
}