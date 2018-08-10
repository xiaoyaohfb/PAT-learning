#include <cstdio>
#include <cstring>
bool det[128] = {false};
int main() {
    char c1[81], c2[81];
    scanf("%s", c1);
    scanf("%s", c2);
    int len1 = strlen(c1);
    int len2 = strlen(c2);
    for(int i = 0; i < len2; i++){
      if(c2[i] >='a' && c2[i] <= 'z') {
        c2[i] -= 32;
      }
      det[c2[i]] = true;
    }
    for(int i = 0; i < len1; i++){
      if(c1[i] >='a' && c1[i] <= 'z') {
        c1[i] -= 32;
      }
      if(det[c1[i]] == false){
        printf("%c", c1[i]);
        det[c1[i]] = true;
      }
    }
    
}