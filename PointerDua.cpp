#include <iostream>
using namespace std;


class mahasiswa 
{
    public: 
    int nim;
    void ShowNim()
    {
        cout << "No induk: " << nim << endl;
    }
};

int main()
{
    // Mengalokasikan memori di heap
    mahasiswa *mhs = new mahasiswa{1}; 
    
    // Mengakses member menggunakan pointer
    mhs ->nim = 2;
    mhs -> ShowNim(); 
    
    // Membersihkan memori untuk mencegah memory leak
    delete mhs; 
    
    return 0;
}