#include <string>
#include <vector>

using namespace std;

struct info {
    info* numExist[10] = { NULL };
    bool terminates = false;
};

info root;

bool operate(string& st) {
    info* curIdx = &root;
    int lenSt = st.length(), curNum;
    
    for (int i = 0; i < lenSt; i++) {
        curNum = st[i] - '0';
        
        if (curIdx -> terminates) return false; //접두사와 일치하는 문자열이 있다.
        
        if (!curIdx -> numExist[curNum]) {
            curIdx -> numExist[curNum] = new info;
        }
         curIdx = curIdx -> numExist[curNum];
    }
    curIdx -> terminates = true;
    
    for (const auto it : curIdx -> numExist) {
        if (it) return false;
    }
    return true;
}

bool solution(vector<string> phone_book) {
    int num_phoneBook = phone_book.size();
    for (int i = 0; i < num_phoneBook; i++) {
        if (!operate(phone_book[i])) {
            return false;
        }
    }
    
    return true;
}