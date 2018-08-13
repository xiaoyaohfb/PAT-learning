#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int a[20], n, count1 = 0;
bool HashTable[45] = {false};
void pocket(int sum, int pos){
    
    if(sum == 40){
        count1++;
        return;
    }
    for(int i = pos; i < n; i++){
        if(HashTable[a[i]] == false && sum + a[i] <= 40){
            HashTable[a[i]] = true;
            pocket(sum + a[i], i + 1);
            HashTable[a[i]] = false;
        }
    }
}
int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }
    sort(a, a + n);
    pocket(0, 0);
    printf("%d", count1);
    return 0;
}