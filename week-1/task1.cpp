#include<stdio.h>
int isVowel (char ch){
  if (ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u' ||
    ch=='A' || ch=='E' || ch=='I' || ch=='O' || ch=='U')
    return 1;
  return 0;
}
int main(){
  char str[100];
  int i, j=0;

  printf("Enter a string= ");
  fgets(str, sizeof(str), stdin);

  for(i=0; str[i]!='\0'; i++){
    if(!isVowel(str[i])){
    str[j]=str[i];
      j++;
    }
  }
  str[j]='\0';

  printf("String without vowels= %s\n",str);
  return 0;
}

