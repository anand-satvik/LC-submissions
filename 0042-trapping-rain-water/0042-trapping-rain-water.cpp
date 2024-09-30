class Solution {
public:
    int trap(vector<int>& arr) {
        int n=arr.size();
        int l=0;int r=n-1;int lmax=0,rmax=0,total=0;
        while(l<r)
        {
            if(arr[l]<=arr[r])
            {
                if(lmax<=arr[l])
                lmax=arr[l];
                else
                total+=lmax-arr[l];
                l++;
            }
            else
            {
                if(rmax<=arr[r])
                rmax=arr[r];
                else
                total+=rmax-arr[r];
                r--;
            }
        }
        return total;
    }
};