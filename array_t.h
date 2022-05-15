#include <iostream>
#include <vector>

class array_t {
 public:
 array_t() {}
 ~array_t(){}

//给定一个n个元素的有序(升序)整型数组和一个目标值target.
//写一个函数搜索nums中的target,如果目标值存在返回下标，否则返回-1.
 int s(std::vector<int>& a, int t) {
     int l = 0;
     int r = a.size() - 1;
     while(l <= r) {
        int m = l + (r - l)/2; //为了防止溢出
        if(a[m] > t) {
            r = m - 1;
        } else if(a[m] < t){
            l = m + 1;
        }else if(a[m] == t){
            return m;
        }
     }
     return -1;
 }
/*主要注意区间的边界是否有效，上面的代码左右区间边界都有效，即[l,r],所以判断条件为l <= r*/

//给定一个数组nums和一个值val,你需要原地的移除所有数值等于val的元素，
//并返回移除后的数组新长度
int s1(std::vector<int> &v, int t) {
    
    int l_prt = 0;
    for(int f_prt = 0; f_prt < v.size(); f_prt++){
        if(v[f_prt] != t) {
            v[l_prt++] = v[f_prt];
        }
    }
    return l_prt;
}

//给定一个递增的数组nums,返回每个数的平方组成新的数组，要求也按递增排序
std::vector<int> s2(std::vector<int>& v){

    int l = 0;
    int r = v.size() - 1;
    int k = v.size() - 1;
    std::vector<int> v2(v.size(),0);
    while(l <= r) {
        int val1 = v[l]*v[l];
        int val2 = v[r]*v[r];
        if(val1 < val2) {
            v2[k--] = val2;
            r--;
        }else {
            v2[k--] = val1;
            l++;
        }
    }
    return v2;
}

//给定一个含有n个正正数的数组和一个正数s,找出该数组中满足其和>=s的长度最小的连续子数组，
//并返回其长度。如果不存在符合条件的子数组，返回0.
int s3(std::vector<int> v, int s){
    
    int l = 0;
    int prt1 = 0;
    int prt2 = 0;
    int sum = 0;

    while(prt2 != v.size() - 1){
        for(int i = prt1; i <= prt2; i++){
           sum = sum + v[i];
        }
       if(sum >= s) {
        if(l > prt2 - prt1 + 1 || l == 0){
            l = prt2 -prt1 + 1; 
        }
        prt1++;
       }else {
        prt2++;     
       }
       sum = 0;
    }
    return l;
}

};















