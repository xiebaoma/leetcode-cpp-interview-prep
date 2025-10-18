#include <bits/stdc++.h>
using namespace std;
using int64 = long long;
const int64 MOD = 1000000009LL;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, K;
    if(!(cin >> N >> K)) return 0;
    vector<int64> A(N);
    for(int i=0;i<N;++i) cin >> A[i];

    // sort indices by abs desc (keep values)
    vector<int> idx(N);
    iota(idx.begin(), idx.end(), 0);
    sort(idx.begin(), idx.end(), [&](int i, int j){
        if (llabs(A[i]) != llabs(A[j])) return llabs(A[i]) > llabs(A[j]);
        return A[i] > A[j]; // tie-breaker arbitrary but stable
    });

    // select first K indices
    vector<int> sel(idx.begin(), idx.begin()+K);
    vector<int> unsel(idx.begin()+K, idx.end());

    // helper to compute product sign and absolute modulo
    auto compute_product_info = [&](const vector<int>& chosen){
        int sign = 1;
        bool hasZero = false;
        int64 absmod = 1;
        for(int id : chosen){
            int64 v = A[id];
            if (v == 0) { hasZero = true; absmod = 0; } 
            if (v < 0) sign *= -1;
            if (!hasZero){
                int64 mult = llabs(v) % MOD;
                __int128 t = (__int128)absmod * mult;
                absmod = (int64)(t % MOD);
            }
        }
        return tuple<int,int64,bool>(sign, absmod, hasZero);
    };

    auto [sign_sel, absmod_sel, zero_sel] = compute_product_info(sel);

    // if any zero in selection -> result 0
    if (zero_sel){
        cout << 0 << "\n";
        return 0;
    }

    // if sign positive -> done
    if (sign_sel == 1){
        cout << (absmod_sel % MOD) << "\n";
        return 0;
    }

    // sign is negative -> try to fix by swapping
    // find candidates:
    // in selected: smallest-abs negative, smallest-abs positive
    int sel_neg = -1, sel_pos = -1;
    for(int id : sel){
        if (A[id] < 0){
            if (sel_neg == -1 || llabs(A[id]) < llabs(A[sel_neg])) sel_neg = id;
        } else {
            if (sel_pos == -1 || llabs(A[id]) < llabs(A[sel_pos])) sel_pos = id;
        }
    }
    // in unselected: largest-abs positive, largest-abs negative
    int unsel_pos = -1, unsel_neg = -1;
    for(int id : unsel){
        if (A[id] > 0){
            if (unsel_pos == -1 || llabs(A[id]) > llabs(A[unsel_pos])) unsel_pos = id;
        } else if (A[id] < 0){
            if (unsel_neg == -1 || llabs(A[id]) > llabs(A[unsel_neg])) unsel_neg = id;
        }
    }

    bool can1 = (sel_neg != -1 && unsel_pos != -1); // swap sel_neg out, unsel_pos in
    bool can2 = (sel_pos != -1 && unsel_neg != -1); // swap sel_pos out, unsel_neg in

    if (can1 || can2){
        // if both possible compare ratios: choose swap that gives larger abs product
        // ratio1 = abs(unsel_pos)/abs(sel_neg)
        // ratio2 = abs(unsel_neg)/abs(sel_pos)
        bool choose1 = false;
        if (can1 && !can2) choose1 = true;
        else if (!can1 && can2) choose1 = false;
        else {
            // both true: compare unsel_pos_abs * sel_pos_abs  vs unsel_neg_abs * sel_neg_abs
            __int128 a1 = (__int128)llabs(A[unsel_pos]) * llabs(A[sel_pos == -1 ? sel_neg : sel_pos]); // placeholder
            // Actually we need compare ratio1 vs ratio2: ratio1 > ratio2 <=> unsel_pos_abs * sel_pos_abs > unsel_neg_abs * sel_neg_abs
            __int128 left  = (__int128)llabs(A[unsel_pos]) * (__int128)llabs(A[sel_pos]);
            __int128 right = (__int128)llabs(A[unsel_neg]) * (__int128)llabs(A[sel_neg]);
            // But sel_pos or sel_neg might be -1 not possible here because can1 && can2 true ensures both exist.
            if (left > right) choose1 = true;
            else choose1 = false;
        }

        if (choose1){
            // perform swap: remove sel_neg, add unsel_pos
            for (int &v : sel) if (v == sel_neg){ v = unsel_pos; break; }
        } else {
            for (int &v : sel) if (v == sel_pos){ v = unsel_neg; break; }
        }

        // recompute product now
        auto [sign2, absmod2, zero2] = compute_product_info(sel);
        if (zero2){
            cout << 0 << "\n";
            return 0;
        }
        if (sign2 == 1){
            cout << (absmod2 % MOD) << "\n";
            return 0;
        }
        // if still negative (shouldn't generally happen), handle below
    }

    // If we reach here, we couldn't make product positive by swapping.
    // If there's any zero in whole array, best is 0 (0 > any negative)
    bool anyZero = false;
    for(int i=0;i<N;++i) if (A[i]==0) { anyZero = true; break; }
    if (anyZero){
        cout << 0 << "\n";
        return 0;
    }

    // Otherwise final product must be negative. To maximize (i.e., get value as large as possible),
    // pick K numbers with smallest absolute values (so magnitude minimized, negative value as large as possible).
    vector<int> idx2(N);
    iota(idx2.begin(), idx2.end(), 0);
    sort(idx2.begin(), idx2.end(), [&](int i, int j){
        if (llabs(A[i]) != llabs(A[j])) return llabs(A[i]) < llabs(A[j]);
        return A[i] > A[j];
    });
    vector<int> chosen(idx2.begin(), idx2.begin()+K);
    auto [sign_final, absmod_final, zero_final] = compute_product_info(chosen);
    if (zero_final){
        cout << 0 << "\n";
        return 0;
    }
    // sign_final should be -1 here
    if (sign_final == 1){
        cout << (absmod_final % MOD) << "\n";
    } else {
        int64 am = absmod_final % MOD;
        if (am == 0) cout << 0 << "\n";
        else cout << "-" << am << "\n";
    }
    return 0;
}
