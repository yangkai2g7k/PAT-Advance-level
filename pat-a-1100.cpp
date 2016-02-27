//
//  main.cpp
//  test
//
//  Created by 杨凯 on 16/2/4.
//  Copyright © 2016年 杨凯. All rights reserved.
//

#include <iostream>
#include <map>
#include <sstream>
using namespace std;
map<int,string> earth,h;
map<string,int> mars,mh;
int atoi(string num){
    int value = 0;
    for(int i = 0;i<num.length();i++)
        value = value*10 + num[i] - '0';
    return value;
}
int itoa(string num){
    char di[4] = "";
    char re[4] = "";
    bool flag = false;
    int result = 0;
    int j = 0;
    for(int i = 0;i<num.length();i++){
        if(num[i] == ' '){
            flag = true;
            di[3] = '\0';
            stringstream ss;
            ss << di;
            result = mh[ss.str()];
            j = 0;
        }
        else{
            if(flag == false)
                di[j++] = num[i];
            else
                re[j++] = num[i];
        }
    }
    if(flag == false)
    {
        di[3] = '\0';
        stringstream ss;
        ss << di;
        result = mars[ss.str()];
    }
    else {
        re[3] = '\0';
        stringstream ss;
        ss << re;
        result = result*13 + mars[ss.str()];
    }
    return result;
}
int main(int argc, const char * argv[]) {
    earth[0] = "tret";
    earth[1] = "jan";
    earth[2] = "feb";
    earth[3] = "mar";
    earth[4] = "apr";
    earth[5] = "may";
    earth[6] = "jun";
    earth[7] = "jly";
    earth[8] = "aug";
    earth[9] = "sep";
    earth[10] = "oct";
    earth[11] = "nov";
    earth[12] = "dec";
    h[0] = "tret";
    h[1] = "tam";
    h[2] = "hel";
    h[3] = "maa";
    h[4] = "huh";
    h[5] = "tou";
    h[6] = "kes";
    h[7] = "hei";
    h[8] = "elo";
    h[9] = "syy";
    h[10] = "lok";
    h[11] = "mer";
    h[12] = "jou";
    mars["tret"] = 0;
    mars["jan"] = 1;
    mars["feb"] = 2;
    mars["mar"] = 3;
    mars["apr"] = 4;
    mars["may"] = 5;
    mars["jun"] = 6;
    mars["jly"] = 7;
    mars["aug"] = 8;
    mars["sep"] = 9;
    mars["oct"] = 10;
    mars["nov"] = 11;
    mars["dec"] = 12;
    mars["tam"] = 13;
    mars["hel"] = 26;
    mars["maa"] = 13*3;
    mars["huh"] = 13*4;
    mars["tou"] = 13*5;
    mars["kes"] = 13*6;
    mars["hei"] = 13*7;
    mars["elo"] = 13*8;
    mars["syy"] = 13*9;
    mars["lok"] = 130;
    mars["mer"] = 13*11;
    mars["jou"] = 13*12;
    mh["tam"] = 1;
    mh["hel"] = 2;
    mh["maa"] = 3;
    mh["huh"] = 4;
    mh["tou"] = 5;
    mh["kes"] = 6;
    mh["hei"] = 7;
    mh["elo"] = 8;
    mh["syy"] = 9;
    mh["lok"] = 10;
    mh["mer"] = 11;
    mh["jou"] = 12;
    int times;
    cin >> times;
    getchar();
    while (times--) {
        string line;
        getline(cin,line);
        if(line.length()&&line[0]>='0'&&line[0]<='9'){
            int value = atoi(line);
            if(value<13){
                cout << earth[value] << endl;
            }
            else {
                int di = value / 13;
                int re = value - di*13;
                if(re)
                    cout << h[di] << ' ' << earth[re] << endl;
                else cout << h[di]<< endl;
            }
        }
        else{
            cout << itoa(line) << endl;
        }
    }
    return 0;
}
