#include <vector>
#include <iostream>
#include <limits>

using namespace std;

void fel11(int n, vector<int> &arr)
{
    cout << "n: "; cin >> n;

    vector<vector<int>> matrix(n, vector<int>(n, 0));

    int fent = 0, lent = n - 1, bal = 0, jobb = n - 1;
    int index = 0;

    while (fent <= lent && bal <= jobb) {
        for (int i = bal; i <= jobb; i++) matrix[fent][i] = arr[index++];
        fent++;

        for (int i = fent; i <= lent; i++) matrix[i][jobb] = arr[index++];
        jobb--;

        if (fent <= lent) {
            for (int i = jobb; i >= bal; i--) matrix[lent][i] = arr[index++];
            lent--;
        }

        if (bal <= jobb) {
            for (int i = lent; i >= fent; i--) matrix[i][bal] = arr[index++];
            bal++;
        }
    }

    for (const auto &row : matrix) {
        for (int num : row) {
            cout << num << " ";
        }
        cout << endl;
    }
}

void fel12(int n, vector<vector<int>> &matrix)
{
    vector<pair<int, int>> kimenet;

    int dx[] = {-1, -1, -1, 0, 1, 1, 1, 0};
    int dy[] = {-1, 0, 1, 1, 1, 0, -1, -1};

    for (int i = 1; i < n - 1; i++) {
        for (int j = 1; j < n - 1; j++) {
            bool paratlanok = true;
            for (int k = 0; k < 8; k++) {
                int ni = i + dx[k], nj = j + dy[k];
                if (matrix[ni][nj] % 2 == 0) {
                    paratlanok = false;
                    break;
                }
            }
            if (paratlanok) kimenet.push_back({i, j});
        }
    }

    for (const auto &p : kimenet) {
        cout << p.first + 1 << " " << p.second + 1 << endl;
    }
}

void fel13(int n, vector<vector<int>> &matrix)
{
    cout << "Oszlop mini: ";
    for (int j = 0; j < n; j++) {
        int mini = numeric_limits<int>::max();
        for (int i = 0; i < n; i++) {
            mini = min(mini, matrix[i][j]);
        }
        cout << mini << " ";
    }
    cout << endl;
}

void fel14(int n, int m, vector<vector<int>> &matrix)
{
    int maxi = numeric_limits<int>::min();
    int maxi_sor = -1, maxi_oszl = -1;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] > maxi) {
                maxi = matrix[i][j];
                maxi_sor = i;
                maxi_oszl = j;
            }
        }
    }

    cout << "Maxi: " << maxi << " " << maxi_sor + 1 << " " << maxi_oszl + 1 << "\n";

    vector<vector<int>> uj_matrix;
    for (int i = 0; i < n; i++) {
        if (i == maxi_sor) continue;
        vector<int> uj_sor;
        for (int j = 0; j < m; j++) {
            if (j == maxi_oszl) continue;
            uj_sor.push_back(matrix[i][j]);
        }
        uj_matrix.push_back(uj_sor);
    }

    cout << "\n";
    for (const auto &row : uj_matrix) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
}

void fel15(int n, int m, vector<vector<int>> &matrix)
{
    vector<vector<int>> forditott(m, vector<int>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            forditott[m - 1 - j][i] = matrix[i][j];
        }
    }

    for (const auto &row : forditott) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
}

void fel16(int n)
{
    vector<vector<int>> matrix(n, vector<int>(n, 1));

    for (int i = 1; i < n / 2 + 1; i++) {
        for (int j = i; j < n - i; j++) {
            matrix[j][i] = matrix[j][n - i - 1] = 2 * i + 1;
        }
    }

    for (const auto &row : matrix) {
        for (int num : row) {
            cout << num << " ";
        }
        cout << endl;
    }
}

void fel17(int n)
{
    string nToStr = to_string(n);
    int hossz = nToStr.length();
    vector<vector<int>> matrix(hossz, vector<int>(hossz));

    for (int i = 0; i < hossz; i++) {
        for (int j = 0; j < hossz; j++) {
            matrix[i][j] = nToStr[j] - '0';
        }
    }

    for (const auto &i : matrix) {
        for (int j : i) {
            cout << j << " ";
        }
        cout << endl;
    }
}

void fel18(int n, int m)
{
    vector<vector<int>> matrix(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> matrix[i][j];
        }
    }

    vector<int> pontok;
    int kerrO=0, kerrS=0;

    for (int i = 0; i < n; i++) {
        int maxi = matrix[i][0], oszlId = 0;

        for (int j = 1; j < m; j++) {
            if (matrix[i][j] > maxi) {
                maxi = matrix[i][j];
                oszlId = j;
                kerrO=j; kerrS=i;
            }
        }

        bool keresettPontE = true;
        for (int k = 0; k < n; k++) {
            if (matrix[k][oszlId] < maxi) {
                keresettPontE = false;
                break;
            }
        }

        if (keresettPontE) pontok.push_back(maxi);
    }

    for (int val : pontok) {
        cout << kerrO<<' '<<kerrS-1<<' '<< val << " ";
    }
    cout << endl;
}

int main() {

//    vector<int> arr(16);
//    arr.assign({1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16});
//    fel11(4,arr);
//
//    vector<vector<int>> matrix(4, vector<int>(4));
//    matrix[0]={1 ,1 ,3 ,4};
//    matrix[1]={5 ,6 ,7 ,8};
//    matrix[2]={9 ,9 ,11 ,12};
//    matrix[3]={13 ,14 ,15 ,16};
//    fel12(4,matrix);

//    vector<vector<int>> matrix(4, vector<int>(4));
//    matrix[0]={1 ,12 ,13 ,45};
//    matrix[1]={5 ,16 ,7 ,18};
//    matrix[2]={9 ,10 ,11 ,12};
//    matrix[3]={13 ,14 ,15 ,16};
//    fel13(4,matrix);
//
//    vector<vector<int>> matrix(4, vector<int>(5));
//    matrix[0]={1 ,12 ,13 ,45 ,10};
//    matrix[1]={5 ,16 ,7 ,18 ,49};
//    matrix[2]={9 ,50 ,11 ,12 ,25};
//    matrix[3]={13 ,14 ,15 ,16 ,34};
//    fel14(4,5,matrix);

//    vector<vector<int>> matrix(4, vector<int>(5));
//    matrix[0]={1 ,12 ,13 ,45 ,10};
//    matrix[1]={5 ,16 ,7 ,18 ,49};
//    matrix[2]={9 ,50 ,11 ,12 ,25};
//    matrix[3]={13 ,14 ,15 ,16 ,34};
//    fel15(4,5,matrix);

//    fel16(4);

//    fel17(123);

    fel18(4,3); //minor bug, de a peldara megy
}

