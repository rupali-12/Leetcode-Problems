class Fancy {
public:
   typedef long long ll;
     ll add=0;
     ll mult=1;
     ll M = 1e9+7;
     vector<ll>seq;

    //  Binary expontiation for ferma little theorem  =pow(mult, M-2)
    ll power(ll a, ll b){
       if(b==0) return 1;

       ll half = power(a, b/2);
       ll result =(half*half)%M;
       if(b%2 == 1){
        result = (result*a)%M;
       }
       return result;
    }



    Fancy() {
        
    }
    
    void append(int val) {
        ll x = ((val-add)%M + M)*power(mult, M-2)%M;
        seq.push_back(x);
    }
    
    void addAll(int inc) {
        add = (add + inc)%M;
    }
    
    void multAll(int m) {
        add = (add*m)%M;
        mult = (mult*m)%M;
    }
    
    int getIndex(int idx) {
        if(idx >= seq.size())return -1;
        ll x = seq[idx];
        return (x*mult + add)%M;
    }
};

/**
 * Your Fancy object will be instantiated and called as such:
 * Fancy* obj = new Fancy();
 * obj->append(val);
 * obj->addAll(inc);
 * obj->multAll(m);
 * int param_4 = obj->getIndex(idx);
 */