// lightoj 1164 - Horrible Queries

#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#define MAX 100005
#define ll long long

typedef struct info{
    ll sum;
    ll prop;    // propagate
};

info tree[3*MAX];

int t, q, n, l, r, type, value;
int arr[MAX];

void update(int root, int start, int last, int lower, int upper, ll x){
    if(last < lower || upper < start)
        return;
    if( start >= lower && last <= upper){
        tree[root].sum += (last-start+1)*x;     // x added number of leaf node times
        tree[root].prop +=x;
        return;
    }

    int left = root<<1;
    int right = (root<<1)+1;
    int mid = start + ((last-start)>>1);
    update(left,start, mid, lower, upper, x);
    update(right, mid+1, last, lower, upper, x);
    tree[root].sum = tree[left].sum + tree[right].sum + (last-start+1)*tree[root].prop;
}

ll query(int root, int start, int last,int lower, int upper, ll carry){
    if( last < lower || start > upper){
        return 0;
    }
    if( start >= lower && last <= upper){
        return tree[root].sum + (last-start+1)*carry;
    }

    int left = root <<1;
    int right = (root<<1)+1;
    int mid = start + ((last-start)>>1);
    ll s1 = query(left, start, mid, lower, upper,  carry+tree[root].prop);
    ll s2 = query(right, mid+1, last, lower, upper, carry+tree[root].prop);
    return s1+s2;
}

int main(){
    scanf("%d",&t);
    for(int tc=1; tc <= t; tc++){
        scanf("%d %d",&n, &q);
        memset(tree, 0, sizeof tree);
        printf("Case %d:\n",tc);
        for(int i = 0; i < q ; i++ ){
            scanf("%d", &type);

            switch(type){
                case 0:
                    scanf("%d %d %d",&l,&r,&value);
                    update(1,1,n,l+1,r+1,value);
                    break;
                case 1:
                    scanf("%d %d",&l,&r);
                    printf("%lld\n",query(1,1,n,l+1,r+1,0));
            }
        }
    }
    return 0;
}
