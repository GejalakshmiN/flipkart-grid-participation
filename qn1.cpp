#include <iostream>
#include <vector>
#include <string>
#include<bits/stdc++.h>
using namespace std;

int dx[] = {-1,-1,-1,0,1,1,1,0};
int dy[] = {-1,0,1,1,1,0,-1,-1};

bool isValid(int x, int y, int N) {
    return (x >= 0 && x < N && y >= 0 && y < N);
}

bool searchWord(vector<string>& grid, string& word, int x, int y, int dirX, int dirY) {
    int N = grid.size();
    int len = word.size();
    for (int i = 0; i < len; i++) {
        int nx = x + i * dirX;
        int ny = y + i * dirY;
        if (!isValid(nx, ny, N) || grid[nx][ny] != word[i])
            return false;
    }
    return true;
}

int countOccurrences(vector<string>& grid, string word) {
    int N = grid.size();
    int count = 0;
    string rev = word;
    reverse(rev.begin(), rev.end());

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            for (int d = 0; d < 8; d++) {
                if (searchWord(grid, word, i, j, dx[d], dy[d]))
                    count++;
                if (word != rev && searchWord(grid, rev, i, j, dx[d], dy[d]))
                    count++;
                else if (word == rev && searchWord(grid, rev, i, j, dx[d], dy[d]))
                    count++;  // palindrome: add extra
            }
        }
    }

    return count;
}

int main() {
    int N;
    cin >> N;
    vector<string> grid(N);
    for (int i = 0; i < N; i++) {
        cin >> grid[i];
    }
    string word;
    cin >> word;

    cout << countOccurrences(grid, word) << endl;

    return 0;
}
