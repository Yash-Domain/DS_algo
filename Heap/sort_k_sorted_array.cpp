//TC Nlogn better than nmlog(nm)
class Data {
public:
    int val, apos, vpos;
    Data(int v, int ap, int vp) {
        val = v;
        apos = ap;
        vpos = vp;
    }
};

struct mycomp {
    bool operator()(Data &d1, Data &d2) {
        return d1.val > d2.val; // for min-heap
    }
};

class Solution {
public:
    vector<int> mergeArrays(vector<vector<int>> &mat) {
        int n = mat.size();

        vector<int> ans;
        priority_queue<Data, vector<Data>, mycomp> pq;

        // Push first element of each array
        for (int i = 0; i < n; i++) {
            pq.push(Data(mat[i][0], i, 0));
        }

        while (!pq.empty()) {
            Data curr = pq.top();
            pq.pop();
            ans.push_back(curr.val);

            int ap = curr.apos, vp = curr.vpos;
            if (vp + 1 < mat[ap].size()) {
                pq.push(Data(mat[ap][vp + 1], ap, vp + 1));
            }
        }
        return ans;
    }
};