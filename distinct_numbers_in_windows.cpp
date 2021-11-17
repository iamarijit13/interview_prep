#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

vector<int> find_distinct_number(vector<int>, int);

int main () {
    vector<int> ar = {1, 2, 1, 3, 4, 3}, re;
    int window = 3;

    re = find_distinct_number(ar, window);

    for (auto x : re) {
        cout << x << " ";
    }

    return 0;
}

vector<int> find_distinct_number(vector<int> A, int B) {
    auto start = A.begin(), end = A.begin() + B;
    vector<int> slice(B), hash(B + 1), re;
    vector<int> :: iterator it;

    while (end <= A.end()) {
        copy(start, end, slice.begin());
        start++;
        end++;
        sort(slice.begin(), slice.end());
        it = std :: unique(slice.begin(), slice.end());
        slice.resize(distance(slice.begin(), it));
        re.push_back(slice.size());
        slice.resize(distance(slice.begin(), slice.begin() + B));
    }

    return re;
}

// Optimized solution

vector<int> dNums(vector<int> &A, int B) {
    assert(B<=A.size());
    int n=A.size();
    vector<int> ret;
    unordered_map <int, int> m;
    for(int i=0; i<n; i++){
        //increase key
        m[A[i]]++;
        if(i-B+1>=0){

            //decrease key
            ret.push_back(m.size());
            m[A[i-B+1]]--;

            //remove if count becomes 0
            if(m[A[i-B+1]]==0)m.erase(A[i-B+1]);
        }
    }
    return ret;
}
