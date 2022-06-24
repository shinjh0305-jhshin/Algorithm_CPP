#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#define pp pair<string, keyInfo>
using namespace std;

struct keyInfo {
    int sum = 0;
    vector<pair<int, int>> song; //고유번호, 재생횟수
};

unordered_map<string, keyInfo> rawdata; //key-value mapping을 위한 자료구조

bool compareGenre(const pp& a, const pp& b) { //장르의 총 재생 횟수의 합을 기준으로 정렬
    return a.second.sum > b.second.sum;
}

bool compareSong(const pair<int, int>& a, const pair<int, int>& b) { //각 장르 내부의 노래의 재생 횟수를 기준으로 정렬
    return a.second > b.second;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    
    int songs = genres.size();
    for (int i = 0; i < songs; i++) { //해시를 이용한 매핑 진행
        rawdata[genres[i]].song.push_back({i, plays[i]});
        rawdata[genres[i]].sum += plays[i];
    }
    
    vector<pp> newRawdata (rawdata.begin(), rawdata.end()); //정렬을 위해서 vector 자료구조로 이동
    sort(newRawdata.begin(), newRawdata.end(), compareGenre); //장르의 총 재생횟수 기준으로 정렬
    
    int genre = newRawdata.size(); //전체 장르의 개수
    
    for (int i = 0; i < genre; i++) { //각 장르 내부에서 재생 횟수를 기준으로 노래 정렬
        sort(newRawdata[i].second.song.begin(), newRawdata[i].second.song.end(), compareSong);
    }
    
    for (int i = 0; i < genre; i++) {
        auto& currentGenre = newRawdata[i].second.song;  //현재 장르 내부에 속한 노래가 저장된 vector 자료구조
        songs = currentGenre.size();
        
        answer.push_back(currentGenre[0].first);
        if (songs > 1) answer.push_back(currentGenre[1].first); //노래가 2개 이상일 경우에만 두 번째 노래도 넣는다.
    }
   
    return answer;
}