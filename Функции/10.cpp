#include <iostream>
using namespace std;

int call_count = 0;


void count_calls() {
    call_count++;
    cout << "Ôóíêöèÿ áûëà âûçâàíà " << call_count << " ðàç(à)." << endl;
}

int main() {
    setlocale(LC_ALL, "Rus");
 
    for (int i = 0; i < 10; i++) {
        count_calls();
    }
    return 0;
}
