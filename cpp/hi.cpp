/*#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int>& array, int start, int mid, int end) {
    int i = start;
    int j = mid + 1;
    vector<int> temp;
    while (i <= mid && j <= end) {
        if (array[i] < array[j]) {
            temp.push_back(array[i]);
            i++;
        } else {
            temp.push_back(array[j]);
            j++;
        }
    }
    while (i <= mid) {
        temp.push_back(array[i]);
        i++;
    }
    while (j <= end) {
        temp.push_back(array[j]);
        j++;
    }
    for (int k = 0; k < temp.size(); k++) {
        array[start + k] = temp[k];
    }
}

void mergeSort(vector<int>& array, int start, int end) {
    if (start < end) {
        int mid = (start + end) / 2;
        mergeSort(array, start, mid);
        mergeSort(array, mid + 1, end);
        merge(array, start, mid, end);
    }
}

int main() {
    vector<int> array = {5, 4, 3, 2, 1};
    mergeSort(array, 0, array.size() - 1);
    for (int i = 0; i < array.size(); i++) {
        cout << array[i] << " ";
    }
    cout << endl;
    return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// function to compare two words lexicographically
bool compareWords(string a, string b) {
    return a < b;
}

int main() {
    vector<string> words;
    string word;

    // input words
    while (cin >> word) {
        if (word[0] < word[1]) {
            words.push_back(word);
        }
    }

    // sort words using user-defined sorting strategy
    sort(words.begin(), words.end(), compareWords);

    // print sorted words
    for (auto w : words) {
        cout << w << endl;
    }

    return 0;
}

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int ans = nums[0] + nums[1] + nums[2];
        sort(nums.begin(), nums.end());

        for (int i = 0; i + 2 < nums.size(); ++i) {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            int l = i + 1;
            int r = nums.size() - 1;

            while (l < r) {
                const int sum = nums[i] + nums[l] + nums[r];
                if (sum == target)
                    return sum;
                if (abs(sum - target) < abs(ans - target))
                    ans = sum;
                if (sum < target)
                    ++l;
                else
                    --r;
            }
        }

        return ans;
    }
};*/


#include <bits/stdc++.h>
using namespace std;

int Longcompre(string &A, string &B){
    int n = min(A.length(),B.length());
    int i=0;
    while(i<n && A[i]==B[i]){
        i++;
    }
    return i;
}

vector<int> Solve(int N, string S){
    vector<int> result;
    for(int i=0;i<N;i++){
        string A = S.substr(0,i);
        string B = S.substr(i);
        int lcp = Longcompre(A,B);
        result.push_back(lcp);
    }
    return result;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin>>T;
    for(int t_i=0;t_i<T;t_i++){
        int N;
        cin>>N;
        string S;
        cin>>S;
        vector<int> out_;
        out_ = Solve(N, S);
        cout << out_[0];
        for(int i_out_=1;i_out_<out_.size();i_out_++)
        {
        	cout << " " << out_[i_out_];
        }
        cout << "\n";
    }
}

/*#include <bits/stdc++.h>
using namespace std;

vector<int> Solve(int N, string &S) {
    vector<int> result(N, 0);
    for (int i = 1; i < N; i++) {
        string A = S.substr(0, i);
        string B = S.substr(i);
        int n = min(A.length(), B.length());
        int lcp = 0;
        for (int j = 0; j < n; j++) {
            if (A[j] == B[j]) {
                lcp++;
            } else {
                break;
            }
        }
        result[i] = lcp;
    }
    return result;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        string S;
        cin >> S;
        vector<int> out_ = Solve(N, S);
        cout << out_[0];
        for (int i_out_ = 1; i_out_ < out_.size(); i_out_++) {
            cout << " " << out_[i_out_];
        }
        cout << "\n";
    }
    return 0;
}*/



/*#include <bits/stdc++.h>
using namespace std;

vector<int> Solve(int N, const string& S) {
    vector<int> result;
    result.reserve(N);
    for (int i = 1; i < N; i++) {
        string A = S.substr(0, i);
        string B = S.substr(i);
        int n = min(A.length(), B.length());
        int lcp = 0;
        for (int j = 0; j < n; j++) {
            if (A[j] == B[j]) {
                lcp++;
            } else {
                break;
            }
        }
        result.push_back(lcp);
    }
    return result;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        string S;
        cin >> S;
        vector<int> out_ = Solve(N, S);
        for (int i_out_ = 0; i_out_ < out_.size(); i_out_++) {
            cout << out_[i_out_] << " ";
        }
        cout << "\n";
    }
    return 0;
}*/


