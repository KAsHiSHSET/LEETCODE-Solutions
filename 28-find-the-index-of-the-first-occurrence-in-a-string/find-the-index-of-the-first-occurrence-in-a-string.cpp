#define ll long long int

class Solution {
public:
    const ll radix1 = 26;
    const ll mod1 = 1000000007;
    const ll radix2 = 27;
    const ll mod2 = 1000000033;

    // compute hash of substring of length m
    pair<ll,ll> hashpair(string str, ll m){
        ll hash1 = 0, hash2 = 0;
        ll factor1 = 1, factor2 = 1;

        for(ll i = m-1; i >= 0; i--){
            hash1 = (hash1 + ((str[i]-'a') * factor1) % mod1) % mod1;
            factor1 = (factor1 * radix1) % mod1;

            hash2 = (hash2 + ((str[i]-'a') * factor2) % mod2) % mod2;
            factor2 = (factor2 * radix2) % mod2;
        }
        return {hash1, hash2};
    }

    int strStr(string haystack, string needle) {
        ll n = haystack.length(), m = needle.length();
        if(n < m) return -1;

        // precompute max weights (radix^m)
        ll max_weight1 = 1, max_weight2 = 1;
        for(ll i=0;i<m;i++){
            max_weight1 = (max_weight1 * radix1) % mod1;
            max_weight2 = (max_weight2 * radix2) % mod2;
        }

        // needle hash
        pair<ll,ll> hashneedle = hashpair(needle, m);

        // haystack rolling hash
        pair<ll,ll> hashhay = {0,0};
        for(ll i=0;i<=n-m;i++){
            if(i==0){
                hashhay = hashpair(haystack, m);
            }
            else{
                // remove leftmost, shift, add new char
                hashhay.first = ((hashhay.first * radix1) % mod1 
                                - ((haystack[i-1]-'a') * max_weight1) % mod1 
                                + (haystack[i+m-1]-'a') + mod1) % mod1;

                hashhay.second = ((hashhay.second * radix2) % mod2 
                                - ((haystack[i-1]-'a') * max_weight2) % mod2 
                                + (haystack[i+m-1]-'a') + mod2) % mod2;
            }

            if(hashneedle.first == hashhay.first && hashneedle.second == hashhay.second){
                // verify substring to avoid collision
                if(haystack.substr(i,m) == needle) return i;
            }
        }
        return -1;
    }
};
