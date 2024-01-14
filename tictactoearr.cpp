#include <iostream>
using namespace std;

// Fungsi untuk menampilkan papan
void tampilPapan(char papan[3][3]) {
     cout << "-------------\n";
        for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << "| " <<papan[i][j] << " ";
        }
        cout <<  "|\n-------------\n";
    }
}

// Fungsi untuk mengecek kemenangan
bool cekMenang(char papan[3][3], char pemain) {
    // Check baris dan kolom
    for (int i = 0; i < 3; i++) {
        if (papan[i][0] == pemain && papan[i][1] == pemain && papan[i][2] == pemain)
            return true;
        if (papan[0][i] == pemain && papan[1][i] == pemain && papan[2][i] == pemain)
            return true;
    }

    // Check diagonal
    if (papan[0][0] == pemain && papan[1][1] == pemain && papan[2][2] == pemain)
        return true;
    if (papan[0][2] == pemain && papan[1][1] == pemain && papan[2][0] == pemain)
        return true;

    return false;
}

// Fungsi untuk mengecek apakah suatu sel di papan sudah terisi atau belum
bool isCellEmpty(char papan[3][3], int row, int col) {
    return papan[row][col] == ' ';
}

int main() {
    char papan[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
    int row, col;
    char currentPemain = 'X';

    cout << "Selamat datang di Tic Tac Toe!" << endl;

    do {
        // Menampilkan papan
        tampilPapan(papan);

        // Input dari pemain
        cout << "Pemain " << currentPemain << ", masukkan baris (0-2) dan kolom (0-2) yang ingin diisi (pisahkan dengan spasi): ";
        cin >> row >> col;

        // Mengecek validitas input
        if (row < 0 || row >= 3 || col < 0 || col >= 3 || !isCellEmpty(papan, row, col)) {
            cout << "Input tidak valid. Coba lagi." << endl;
            continue;
        }

        // Menyimpan input pemain pada papan
        papan[row][col] = currentPemain;

        // Mengecek kemenangan
        if (cekMenang(papan, currentPemain)) {
            tampilPapan(papan);
            cout << "Player " << currentPemain << " menang!" << endl;
            break;
        }

        // Ganti giliran pemain
        currentPemain = (currentPemain == 'X') ? 'O' : 'X';

    } while (true);

    return 0;
}
