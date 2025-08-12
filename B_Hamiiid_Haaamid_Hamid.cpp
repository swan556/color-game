#include <bits/stdc++.h>
using namespace std;

int main() {

    int t; cin>>t;
    vector<int> ans;

    for(int ts = 0; ts < t; ts++) {

        int n, h;
        cin>>n>>h;

        int lw = -1, rw = -1;
        int n_wl = 0, n_wr=0;
        string s; cin>>s;
        
        for(int i = 0; i < n; i++) {
            if(s[i]=='#' && i<h) {

                n_wl++;
                lw = i+1;
            }

            if(s[i]=='#' && i>h-1) {
            
                n_wr++;
                if(rw == -1) rw = i+1;
                
            }

        }

        int lc = h-1, rc = n-h;
        char attack;

        if(n_wl==n_wr) {

            if(n_wl==0) {ans.push_back(1); continue;}
            else {

                if(lc<rc) {attack = 'l';}
                else attack = 'r';

            }

        }


        // inflate hamid:
        

    }

    cout<<endl;

}