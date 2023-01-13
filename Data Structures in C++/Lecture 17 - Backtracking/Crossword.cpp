/*
#include<bits/stdc++.h>
using namespace std;
bool isValidVertical(char cross[10][10], string word, int row, int col) {
    int k = 0;
    for (int i = row; k < word.length() && i < 10; i++) {
        if (cross[i][col] != '-') {
            if (cross[i][col] == word[k]) {
                break;
            }
            return false;
        }
        k++;
    }
    if (k + 1 == word.length())
        return true;
    return false;
}
bool isValidHorizontal(char cross[10][10], string word, int row, int col) {
    int k = 0;
    for (int j = col; k < word.length() && j < 10; j++) {
        if (cross[row][j] != '-') {
            if (cross[row][j] == word[k]) {
                break;
            }
            return false;
        }
        k++;
    }
    if (k + 1 == word.length())
        return true;
    return false;
}
void setVertical(char cross[10][10], string word, int row, int col, vector<bool> helper) {
    for (int i = row, k = 0; k < word.length(); i++, k++) {
        if (cross[i][col] != '-') {
            helper.push_back(false);
            continue;
        }
        cross[i][col] = word[k];
        helper.push_back(true);
    }
}
void setHorizontal(char cross[10][10], string word, int row, int col, vector<bool> helper) {
    for (int j = col, k = 0; k < word.length(); j++, k++) {
        if (cross[row][j] != '-') {
            helper.push_back(false);
            continue;
        }
        cross[row][j] = word[k];
        helper.push_back(true);
    }
}
void resetVertical(char cross[10][10], vector<bool> helper, int row, int col) {
    for (int i = row, k = 0; k < helper.size(); i++, k++) {
        if (helper[k] == true) {
            cross[i][col] = '-';
        }
    }
}
void resetHorizontal(char cross[10][10], vector<bool> help, int row, int col) {
    for (int i = col, k = 0; k < help.size(); i++, k++) {
        if (help[k] == true) {
            cross[row][i] = '-';
        }
    }
}
void print(char cross[10][10]) {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            cout << cross[i][j];
        }
        cout << endl;
    }
}
bool solveCrossword(char cross[10][10], vector<string> words, int index) {
    if (index == words.size()) {
        print(cross);
        return true;
    }
    for (int row = 0; row < 10; row++) {
        for (int col = 0; col < 10; col++) {
            if (cross[row][col] == '-' || cross[row][col] == words[index][0]) {
                if (isValidVertical(cross, words[index], row, col)) {
                    vector<bool> helper;
                    setVertical(cross, words[index], row, col, helper);
                    if (!solveCrossword(cross, words, index + 1))
                        resetVertical(cross, helper, row, col);
                }
                else if (isValidHorizontal(cross, words[index], row, col)) {
                    vector<bool> helper;
                    setHorizontal(cross, words[index], row, col, helper);
                    if (!solveCrossword(cross, words, index + 1))
                        resetHorizontal(cross, helper, row, col);
                }
            }
        }
    }
    return false;
}
int main() {
    char cross[10][10];
    for (int i = 0; i < 10; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < 10; j++) {
            cross[i][j] = s[j];
        }
    }
    vector<string> words;
    string s;
    cin >> s;
    for (int i = 0, j = 1; s[j] != '\0'; j++) {
        if (s[j] == ';' || s[j + 1] == '\0') {
            words.push_back(s.substr(i, j - i));
            i = j + 1;
        }
    }
    solveCrossword(cross, words, 0);
}
*/
#include <iostream>
using namespace std;
char crossWord[10][10];

bool isValidHorizontal(int row, int col, string word)
{

    if (10 - col < word.length())
        return false;

    for (int i = 0, j = col; i < word.length(); ++i, j++)
    {
        if (crossWord[row][j] != '-' && crossWord[row][j] != word[i])
        {
            return false;
        }
    }

    return true;
}

bool isValidVertical(int row, int col, string word)
{

    if (10 - row < word.length())
        return false;

    for (int i = row, j = 0; j < word.length(); ++i, j++)
    {
        if (crossWord[i][col] != '-' && crossWord[i][col] != word[j])
        {
            return false;
        }
    }

    return true;
}

void setHorizontal(int row, int col, string word, bool state[])
{

    for (int i = 0, j = col; i < word.size(); ++i, j++)
    {
        if (crossWord[row][j] != '+')
        {

            if (crossWord[row][j] == word[i])
                state[i] = false;
            else
                state[i] = true;
            crossWord[row][j] = word[i];
        }
    }
}

void setVertical(int row, int col, string word, bool state[])
{

    for (int i = 0, j = row; i < word.size(); ++i, j++)
    {
        if (crossWord[j][col] != '+')
        {

            if (crossWord[j][col] == word[i])
                state[i] = false;
            else
                state[i] = true;
            crossWord[j][col] = word[i];
        }
    }
}

void resetHorizontal(int row, int col, bool state[], int size)
{

    for (int i = 0, j = col; i < size; ++i, j++)
    {
        if (state[i] == true)
            crossWord[row][j] = '-';
    }
    return;
}

void resetVertical(int row, int col, bool state[], int size)
{

    for (int i = 0, j = row; i < size; ++i, j++)
    {
        if (state[i] == true)
            crossWord[j][col] = '-';
    }
    return;
}

void set_value(bool helper[], int len)
{
    for (int i = 0; i < len; i++)
    {
        helper[i] = false;
    }
}

bool crossWordHelper(string input[], int size, int index)
{

    if (index == size)
    {
        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < 10; j++)
            {

                cout << crossWord[i][j];
            }
            cout << endl;
        }
        return true;
    }

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {

            if (crossWord[i][j] == '-' || crossWord[i][j] == input[index][0])
            {
                int length = input[index].size();
                bool state[length];
                set_value(state, length);

                if (isValidHorizontal(i, j, input[index]))
                {
                    setHorizontal(i, j, input[index], state);
                    if (crossWordHelper(input, size, index + 1))
                    {
                        return true;
                    }
                    resetHorizontal(i, j, state, length);
                }

                if (isValidVertical(i, j, input[index]))
                {
                    setVertical(i, j, input[index], state);
                    if (crossWordHelper(input, size, index + 1))
                    {
                        return true;
                    }
                    resetVertical(i, j, state, length);
                }
            }
        }
    }
    return false;
}

void solveCrossWord(string input[], int size)
{

    bool res = crossWordHelper(input, size, 0);
    return;
}

int main()
{
    string ss;
    for (int i = 0; i < 10; i++)
    {
        cin >> ss;
        for (int j = 0; j < 10; j++)
        {
            crossWord[i][j] = ss[j];
        }
    }

    char s[200];
    cin >> s;

    string input[10];
    char ch;
    string word = "";
    int a = 0;
    for (int i = 0; s[i] != '\0'; ++i)
    {

        if (s[i] == ';')
        {
            input[a++] = word;
            word = "";
        }
        else
        {
            word += s[i];
        }
    }
    input[a++] = word;

    solveCrossWord(input, a);
    return 0;
}