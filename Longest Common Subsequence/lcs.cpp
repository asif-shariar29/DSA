#include<iostream>
#include<string>
using namespace std;

int main () {
    string firstString, secondString, LCM = "";
    cout<<"Enter the first string: ";
    cin>>firstString;
    cout<<"Enter the second string: ";
    cin>>secondString;

    int firstStringLength = firstString.length(), secondStringLength = secondString.length();
    int DynamicArr[100][100] = {0};

    for (int i = 1; i <= firstStringLength; i++) {
        for (int j = 1; j <= secondStringLength; j++) {
        if (firstString[i - 1] == secondString[j - 1]) {
                DynamicArr[i][j] = DynamicArr[i - 1][j - 1] + 1;
             }
    else {
    DynamicArr[i][j] = max(DynamicArr[i - 1][j], DynamicArr[i][j - 1]);
}    
    }
        }

int i = firstStringLength, j = secondStringLength;

while (i > 0 && j > 0) {
    if (firstString[i-1] == secondString[j-1]) {
        LCM = firstString[i-1] + LCM;
        i--;
        j--;
    }
  else if (DynamicArr[i-1][j] > DynamicArr[i][j-1]) {
    i--;
  }
  else j--;
}

cout<<"Longest Common Subsequence(LCM): "<<LCM<<endl<<"Length: "<<LCM.length()<<endl;

}