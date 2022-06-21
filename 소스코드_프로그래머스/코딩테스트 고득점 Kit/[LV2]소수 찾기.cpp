#include <string>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

bool isPrime[10000000];

void getPrime(string st) {
    sort(st.begin(), st.end(), greater<char>());
    int upperBound = stoi(st);

    memset(isPrime, true, sizeof(isPrime)); 
    isPrime[0] = isPrime[1] = false;

    for (int i = 2; i * i <= upperBound; i++) {
        if (!isPrime[i]) continue;
        for (int j = 2;; j++) {
            if (i * j > upperBound) break;
            isPrime[i * j] = false;
        }
    }
}

int solution(string numbers) {
    int answer = 0;
    int lenNumbers = numbers.length();
    
    getPrime(numbers);
    
    sort(numbers.begin(), numbers.end());
    
    int target;    
    do {
        for (int i = 0; i < lenNumbers; i++) {
            target = stoi(numbers.substr(i));
            if (isPrime[target]) {
                isPrime[target] = false;
                answer++;
            }
        }
    } while (next_permutation(numbers.begin(), numbers.end()));
    
    return answer;
}