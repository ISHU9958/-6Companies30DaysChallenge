string encode(string src)
{     
  string ans;
  int i=0,j=0,n=src.length();
  while(j<n){
      if(src[i]==src[j]){
          j++;
      }
      else{
          ans+=src[i];
          ans+=to_string(j-i);
          i=j;
      }
    }
    ans+=src[i];
    ans+=to_string(j-i);
    return ans;
}     
