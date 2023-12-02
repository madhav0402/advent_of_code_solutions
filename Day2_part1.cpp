#include<iostream>
#include<string>
#include<fstream>
#include<map>
#include<climits>
using namespace std;


int main(){
    int ans=0;
    string s;
    
    ifstream fin;
    fin.open("input.txt");
    while(getline(fin,s)){
        int red=0,green=0,blue=0;
        int id=0,count=0,j=5,flag=0;
        string curr="";
        while(s[j]!=':')
            id=id*10+(s[j++]-'0');

        for(int i=j+2;i<s.length();++i)
        {
            if(s[i]==';'||s[i]==',')
            {
                if(curr=="red")
                    red+=count;
                else if(curr=="green")
                    green+=count;
                else if(curr=="blue")
                    blue+=count;
                if(s[i]==';'){
                    if(red>12||green>13||blue>14){
                        flag=1;
                        break;
                    }
                    else
                        red=0;green=0;blue=0;
                }
                count=0;
            }
            else if(s[i]==' ')
                curr="";
            else if(s[i]-'0'>=0&&s[i]-'0'<=9)
                count=count*10+(s[i]-'0');
            else
                curr+=s[i];
        }
        if(curr=="red")
            red+=count;
        else if(curr=="green")
            green+=count;
        else if(curr=="blue")
            blue+=count;

        if(red>12||green>13||blue>14)
            flag=1;
        if(flag)
            continue;
        else
            ans+=id;
    }
    fin.close();
    cout<<ans<<endl;
    return 0;
}
