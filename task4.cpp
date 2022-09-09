#include<iostream>
#include<string>
using namespace std;


double mediana(string S) {
	int S0 = 0;
	int S1 = 0;
	for (int i = 0; i < size(S); i++) {
		if (S[i] == '0')S0++;
		else if (S[i] == '1')S1++;
	}
	if (S0 > S1) return 0;
	else if (S1 > S0) return 1;
	else return 0.5;
}
double chartodouble(char a) {
	if (a == '0') return 0;
	else if (a == '1') return 1;
}


string sub(string S, int j, int i) {
	string sub = "";
	for (int k = j; k <= i; k++) {
		sub += S[k];
	}
	return sub;
}
int main() {
	int N;
	cin >> N;
	string S;
	cin >> S;
	bool flag;
	cout << -1 << " ";
	for (int i = 1; i < N; i++) {
		if (i == 1) {
			if (mediana(sub(S,0,1)) == chartodouble(S[i])) cout << 1 << " ";
			else cout << -1 << " ";
		}
		else {
			flag = false;
			for (int j = 0; j < i; j++) {
				if (mediana(sub(S,j,i)) == chartodouble(S[i])) {
					flag = true;
					cout << j + 1 << " ";
					break;
				}
			}
			if(!flag)cout << -1 << " ";
		}
	}
	return 0;
}
