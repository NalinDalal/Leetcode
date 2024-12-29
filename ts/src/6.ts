// 1639. Number of Ways to Form a Target String Given a Dictionary
/* class Solution {
public:
    static int numWays(vector<string>& words, string& target) {
        const int mod=1e9+7;
        const int m=target.size(), n=words[0].size();
        
        // count freq
        int freq[26][1000]={0};
        for (int i = 0; i<n; i++) {
            for (const auto& w : words) 
                freq[w[i]-'a'][i]++;
        }
        
        //1D DP array for optimization
        int dp[1001]={0};
        dp[0]=1; // Base case
        
        for (int i=0; i<n; i++) {
            // Traverse target from back to front to avoid overwriting
            for (int j=m; j>=1; j--) {
                long long fc=freq[target[j-1]-'a'][i];// avoid of overflowing
                dp[j]=(dp[j]+dp[j-1]*fc) % mod;    
            }
        }
        return dp[m];
    }
};

auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();*/

function numWays(words: string[], target: string): number {
    let mod:number=1e9+7;
    let m:number=target.length, n=words[0.length;

    //count freq
    //let freq:number[26][1000]=[[0]];
    let freq: number[][] = Array.from({ length: 26 }, () => Array(1000).fill(0));

    for(let i =0;i<n;i++){
        for(const w of words){
            freq[w.charCodeAt(i)-'a'.charCodeAt(0)][i]++;
        }
    }

    //let dp:[number]=[0];
    let dp:number[]=Array(m + 1).fill(0);
    dp[0]=1;

    for(let i:number=0;i<n;i++){
        //traverse target from back to front to avoid overwriting
        for(let j=m;j>=1;j--){
            let fc: number = freq[target.charCodeAt(j - 1) - 'a'.charCodeAt(0)][i];//avoid overflow
            //let fc:number=freq[target[j-1]-'a'][i]; //avoid overflow
            dp[j]=(dp[j]+dp[j-1]*fc)%mod;
        }
    }
    return dp[m];
};


/* t.ly/BiOjT */
