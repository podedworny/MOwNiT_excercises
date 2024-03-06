#include <iostream>
#include <iomanip>
using namespace std;

template<typename T>
T gen(int k, int c, T* arr, bool isForward) {
    if (arr[k] != 0) return arr[k];
    if (isForward) {
        arr[k] = 10.0 / static_cast<T>(c) * gen(k - 1, c, arr, isForward) - gen(k - 2, c, arr, isForward);
    } else {
        arr[k] = 10.0 / static_cast<T>(c) * gen(k + 1, c, arr, isForward) - gen(k + 2, c, arr, isForward);
    }
    return arr[k];
}

template<typename T>
void generate_values(int c) {
    T t[47] = {};
    T w[47] = {};

    t[0] = static_cast<T>(1.0);
    t[1] = static_cast<T>(1.0) / static_cast<T>(c);

    gen<T>(46, c, t, true);

    cout << fixed << setprecision(10);
    for (auto & i : t) {
        cout <<  i << endl;
    }
    cout << '\n';

    w[46] = t[46];
    w[45] = t[45];

    gen<T>(0, c, w, false);

    for (auto & i : w) {
        cout << i << endl;
    }
    cout << '\n';
}

void generate(int c) {
    cout << "Float:" << endl;
    generate_values<float>(c);

    cout << "Double:" << endl;
    generate_values<double>(c);

    cout << "Long Double:" << endl;
    generate_values<long double>(c);
}

int main() {
    generate(3);
    return 0;
}