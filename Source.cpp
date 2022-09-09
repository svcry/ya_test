#include<iostream>
#include<string>
#include<math.h>
using namespace std;

string to_binary_string(int n)
{
    string buffer;
    do
    {
        buffer += char('0' + n % 2);
        n = n / 2;
    } while (n > 0);
    return string(buffer.crbegin(), buffer.crend());
}

int main() {
    int W = 0;
    int n;
    cin >> n;
    int Wi;
    char letter;
    int number;
    string W_S;
    int W_last = W;
    for (int i = 0; i < n; i++) {
        cin >> Wi;
        if (Wi > W_last)W = Wi - W_last;
        else W = W_last - Wi;
        W_S = to_binary_string(W);
        number = size(W_S) - W_S.find_first_of('1');
        if (number == 27) letter = ' ';
        else letter =  96 + number;
        cout << letter;
        W_last = Wi;
    }

    return 0;
}