#include<iostream>
#include<string>
#include<fstream>
#include<map>
#include<climits>
using namespace std;

int findLast(string str2,string substr){
    int index=-1;
    for(int i=0;i<str2.length();i++){
        if(str2.substr(i,substr.length())==substr)
            index=i;
    }
    return index;
}
int main(){
    long long ans=0; string s;
    map<string,int> mp;
    mp["one"]=1;
    mp["two"]=2;
    mp["three"]=3;
    mp["four"]=4;
    mp["five"]=5;
    mp["six"]=6;
    mp["seven"]=7;
    mp["eight"]=8;
    mp["nine"]=9;

    ifstream fin;
    fin.open("input.txt");
    while(getline(fin,s)){
        int i=0,j=s.length()-1;
        while(i<s.length()&&(s[i]-'0'<0||s[i]-'0'>9))
            i++;
        while(j>=0&&(s[j]-'0'<0||s[j]-'0'>9))
            j--;

        int digit1=-1,digit2=-1;
        int idx1=INT_MAX,idx2=INT_MIN;
        string str1="",str2="";

        str1=s.substr(0,i);

        if(j==s.length()-1)
            str2="";
        else
            str2=s.substr(j+1,s.length()-j-1);
            
        for(auto it:mp)
        {
        
            size_t found1 = str1.find(it.first);
            if(found1!=(string::npos))
                if((int)found1<idx1)
                {
                    idx1=(int)found1;
                    digit1=it.second;
                }
            
            int found2 = findLast(str2,it.first);
            if(found2!=-1)
                if(found2>idx2)
                {
                    idx2=found2;
                    digit2=it.second;
                }
        }
        if(digit1==-1) digit1=(s[i]-'0');
        if(digit2==-1) digit2=(s[j]-'0');

        ans+=(digit1*10+digit2);
    }
    fin.close();
    cout<<ans<<endl;
    return 0;
}
