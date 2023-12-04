#include <iostream>
#include <fstream>
    using namespace std;

struct muchie {
    int x, y, c;
} v[26];


int main() {

    int a1, a2, m, n, i, j, cost, k, l, nr, t[26];
    char nume[20][21] = {"Oala", "Soroca", "Balti", "Drochia", "Rascani", "Sangerei", "Falesti", "Glodeni", "Floresti", "Donduseni", "Edinet"  };
    muchie aux;
    fstream fin("graphin.txt");
    fin  >> n >> m;
    cout << "Graful meu are " << n << " virfuri " << " si " << m << " muchii.\n";

    for (i = 1; i <= m; i++) {
        fin >> v[i].x >> v[i].y >> v[i].c;
        cout << "(" << v[i].x << "; " << v[i].y << ") = " << v[i].c << endl;
    }

    cout << "Arborele de cost minim este" << endl;

    for (i = 1; i <= m - 1; i++) {
        for (j = i + 1; j <= m; j++) {
            if (v[i].c > v[j].c) {
                aux = v[i];
                v[i] = v[j];
                v[j] = aux;
            }
        }
    }

    for (i = 1; i <= n; i++) {
        t[i] = i;
    }

    cost = 0;
    i = 1;
    nr = 0;

    while (nr < n - 1) {
        if (t[v[i].x] != t[v[i].y]) {
            nr++;
            cost += v[i].c;
            //3 cout << v[i].x << " " << v[i].y << endl;
             cout << "(" << nume[v[i].x] << "; " << nume [v[i].y] << ") = " << v[i].c << endl;
            k = t[v[i].x];
            l = t[v[i].y];
            for (j = 1; j <= n; j++) {
                if (t[j] == k) {
                    t[j] = l;
                }
            }
        }
        i++;
    }

    cout << "Cost: " << cost << endl;
    return 0;
}

