#include <iostream>
using namespace std;
void change(int a [][3], int m, int n) {
    for (int i = 1; i < m; i += 2) {
        for (int j = 0; j < n; j++) {
            a[i][j] = 0;
        }
    }
}

void change(int a[], int n) {
    int start = -1, end = -1;

    for (int i = 0; i < n; i++) {
        if (a[i] == 0) {
            if (start == -1) {
                start = i;
            }
            else {
                end = i;
                break;
            }
        }
    }

    if (start != -1 && end != -1) {
        for (int i = start + 1; i < end; i++) {
            a[i] = 0;
        }

    }
}

int main() {
    const int n = 3, m = 4;
    int a2[m][n] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9},
        {10,11,12}
    };
    for (int i = 0; i < (m); i++) {
        for (int j = 0; j < 3; j++) {
            cout << a2[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    change(a2, m, n);
    for (int i = 0; i < (m - 1); i++) {
        for (int j = 0; j < n; j++) {
            if (a2[i][j] == 0) {
                for (int k = i; k < m; k++) {
                    int c = a2[k][j];
                    a2[k][j] = a2[k + 1][j];
                    a2[k + 1][j] = c;
                }
            }
        }
    }

    for (int i = 0; i < (m / 2); i++) {
        for (int j = 0; j < 3; j++) {
            cout << a2[i][j] << " ";
        }
        cout << endl;
    }

    int a1[] = { 1, 0, 2, 3, 0, 4, 5, 6 };
    const int s = 8;
    cout << endl;
    for (int i = 0; i < s; i++) {
        cout << a1[i] << " ";
    }
    change(a1, s);
    cout << endl;
    for (int i = 0; i < s; i++) {
        cout << a1[i] << " ";
    }
    int p = s;
    for (int i = 0; i < p; i++)
    {
        if (a1[i] == 0)
        {

            for (int j = i; j < p; j++)
            {
                a1[j] = a1[j + 1];
            }
            p--;
            i--;
        }
    }
    cout << endl;
    for (int i = 0; i < p; i++) {
        cout << a1[i] << " ";
    }
    return 0;
}
