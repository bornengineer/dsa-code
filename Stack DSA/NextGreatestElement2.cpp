#include <bits/stdc++.h>
using namespace std;

void print(vector<int> &res)
{
    for (int i = 0; i < res.size(); ++i)
    {
        cout << res[i] << " ";
    }
    cout << endl;
}

void nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
{
    // bruteforce O(n^2)
    vector<int> res(nums1.size(), -1);
    for (int i = 0; i < nums1.size(); ++i)
    {
        for (int j = 0; j < nums2.size(); ++j)
        {
            if (nums1[i] == nums2[j])
            {
                for (int k = j + 1; k <= nums2.size(); ++k)
                {
                    if (nums2[k] > nums2[j])
                    {
                        res[i] = nums2[k];
                        break;
                    }
                }
            }
        }
    }
    print(res);
}

int main()
{
    vector<int> v1 = {4, 1, 2};
    vector<int> v2 = {1, 3, 4, 2};
    // vector<int> v1 = {2,4};
    // vector<int> v2 = {1, 2, 3, 4};
    nextGreaterElement(v1, v2);
    return 0;
}