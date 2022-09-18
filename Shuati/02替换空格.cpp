class Solution {
public:
	void replaceSpace(char *str,int length) {
        int ind=0,cnt=count(str,str+length,' '),newl=2*cnt+length-1;
        for(ind=length-1;ind>=0;ind--){
            if(str[ind]==' '){
                strncpy(str+newl-2,"%20",3);
                newl-=3;
            }
            else
                str[newl--]=str[ind];
          }
	}
};
