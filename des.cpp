#include <iostream>
#include <bitset>
#include <vector>

using namespace std;

// Initial Permutation Table
const int IP[64] = {
    58, 50, 42, 34, 26, 18, 10,  2,
    60, 52, 44, 36, 28, 20, 12,  4,
    62, 54, 46, 38, 30, 22, 14,  6,
    64, 56, 48, 40, 32, 24, 16,  8,
    57, 49, 41, 33, 25, 17,  9,  1,
    59, 51, 43, 35, 27, 19, 11,  3,
    61, 53, 45, 37, 29, 21, 13,  5,
    63, 55, 47, 39, 31, 23, 15,  7
};

// Final Permutation Table
const int FP[64] = {
    40,  8, 48, 16, 56, 24, 64, 32,
    39,  7, 47, 15, 55, 23, 63, 31,
    38,  6, 46, 14, 54, 22, 62, 30,
    37,  5, 45, 13, 53, 21, 61, 29,
    36,  4, 44, 12, 52, 20, 60, 28,
    35,  3, 43, 11, 51, 19, 59, 27,
    34,  2, 42, 10, 50, 18, 58, 26,
    33,  1, 41,  9, 49, 17, 57, 25
};

// Expansion D-box Table
const int E[48] = {
    32,  1,  2,  3,  4,  5,  4,  5,
     6,  7,  8,  9,  8,  9, 10, 11,
    12, 13, 12, 13, 14, 15, 16, 17,
    16, 17, 18, 19, 20, 21, 20, 21,
    22, 23, 24, 25, 24, 25, 26, 27,
    28, 29, 28, 29, 30, 31, 32,  1
};

// S-box Tables
const int S[8][4][16] = {
    {
        {14, 4, 13, 1, 2, 15, 11, 8, 3, 10, 6, 12, 5, 9, 0, 7},
        {0, 15, 7, 4, 14, 2, 13, 1, 10, 6, 12, 11, 9, 5, 3, 8},
        {4, 1, 14, 8, 13, 6, 2, 11, 15, 12, 9, 7, 3, 10, 5, 0},
        {15, 12, 8, 2, 4, 9, 1, 7, 5, 11, 3, 14, 10, 0, 6, 13}
    },
    {
        {15, 1, 8, 14, 6, 11, 3, 4, 9, 7, 2, 13, 12, 0, 5, 10},
        {3, 13, 4, 7, 15, 2, 8, 14, 12, 0, 1, 10, 6, 9, 11, 5},
        {0, 14, 7, 11, 10, 4, 13, 1, 5, 8, 12, 6, 9, 3, 2, 15},
        {13, 8, 10, 1, 3, 15, 4, 2, 11, 6, 7, 12, 0, 5, 14, 9}
    },
    {
        {10, 0, 9, 14, 6, 3, 15, 5, 1, 13, 12, 7, 11, 4, 2, 8},
        {13, 7, 0, 9, 3, 4, 6, 10, 2, 8, 5, 14, 12, 11, 15, 1},
        {13, 6, 4, 9, 8, 15, 3, 0, 11, 1, 2, 12, 5, 10, 14, 7},
        {1, 10, 13, 0, 6, 9, 8, 7, 4, 15, 14, 3, 11, 5, 2, 12}
    },
    {
        {7, 13, 14, 3, 0, 6, 9, 10, 1, 2, 8, 5, 11, 12, 4, 15},
        {13, 8, 11, 5, 6, 15, 0, 3, 4, 7, 2, 12, 1, 10, 14, 9},
        {10, 6, 9, 0, 12, 11, 7, 13, 15, 1, 3, 14, 5, 2, 8, 4},
        {3, 15, 0, 6, 10, 1, 13, 8, 9, 4, 5, 11, 12, 7, 2, 14}
    },
    {
        {2, 12, 4, 1, 7, 10, 11, 6, 8, 5, 3, 15, 13, 0, 14, 9},
        {14, 11, 2, 12, 4, 7, 13, 1, 5, 0, 15, 10, 3, 9, 8, 6},
        {4, 2, 1, 11, 10, 13, 7, 8, 15, 9, 12, 5, 6, 3, 0, 14},
        {11, 8, 12, 7, 1, 14, 2, 13, 6, 15, 0, 9, 10, 4, 5, 3}
    },
    {
        {12, 1, 10, 15, 9, 2, 6, 8, 0, 13, 3, 4, 14, 7, 5, 11},
        {10, 15, 4, 2, 7, 12, 9, 5, 6, 1, 13, 14, 0, 11, 3, 8},
        {9, 14, 15, 5, 2, 8, 12, 3, 7, 0, 4, 10, 1, 13, 11, 6},
        {4, 3, 2, 12, 9, 5, 15, 10, 11, 14, 1, 7, 6, 0, 8, 13}
    },
    {
        {4, 11, 2, 14, 15, 0, 8, 13, 3, 12, 9, 7, 5, 10, 6, 1},
        {13, 0, 11, 7, 4, 9, 1, 10, 14, 3, 5, 12, 2, 15, 8, 6},
        {1, 4, 11, 13, 12, 3, 7, 14, 10, 15, 6, 8, 0, 5, 9, 2},
        {6, 11, 13, 8, 1, 4, 10, 7, 9, 5, 0, 15, 14, 2, 3, 12}
    },
    {
        {13, 2, 8, 4, 6, 15, 11, 1, 10, 9, 3, 14, 5, 0, 12, 7},
        {1, 15, 13, 8, 10, 3, 7, 4, 12, 5, 6, 11, 0, 14, 9, 2},
        {7, 11, 4, 1, 9, 12, 14, 2, 0, 6, 10, 13, 15, 3, 5, 8},
        {2, 1, 14, 7, 4, 10, 8, 13, 15, 12, 9, 0, 3, 5, 6, 11}
    }
};

// Permutation Table
const int P[32] = {
    16,  7, 20, 21,
    29, 12, 28, 17,
     1, 15, 23, 26,
     5, 18, 31, 10,
     2,  8, 24, 14,
    32, 27,  3,  9,
    19, 13, 30,  6,
    22, 11,  4, 25
};

// Left Shifts Table
const int shift_table[16] = {
    1, 1, 2, 2,
    2, 2, 2, 2,
    1, 2, 2, 2,
    2, 2, 2, 1
};

// PC1 Table
const int PC1[56] = {
    57, 49, 41, 33, 25, 17,  9,
     1, 58, 50, 42, 34, 26, 18,
    10,  2, 59, 51, 43, 35, 27,
    19, 11,  3, 60, 52, 44, 36,
    63, 55, 47, 39, 31, 23, 15,
     7, 62, 54, 46, 38, 30, 22,
    14,  6, 61, 53, 45, 37, 29,
    21, 13,  5, 28, 20, 12,  4
};

// PC2 Table
const int PC2[48] = {
    14, 17, 11, 24,  1,  5,
     3, 28, 15,  6, 21, 10,
    23, 19, 12,  4, 26,  8,
    16,  7, 27, 20, 13,  2,
    41, 52, 31, 37, 47, 55,
    30, 40, 51, 45, 33, 48,
    44, 49, 39, 56, 34, 53,
    46, 42, 50, 36, 29, 32
};

bitset<28> left_shift(bitset<28> k, int shifts) {
    bitset<28> tmp = k;
    for (int i = 0; i < 28; i++) {
        k[i] = tmp[(i + shifts) % 28];
    }
    return k;
}

void generate_keys(bitset<64> key, vector<bitset<48>>& round_keys) {
    bitset<56> perm_key;
    bitset<28> left, right;

    for (int i = 0; i < 56; i++) {
        perm_key[55-i] = key[64-PC1[i]];
    }

    for (int i = 28; i < 56; i++) {
        left[i-28] = perm_key[i];
        right[i-28] = perm_key[i-28];
    }

    for (int i = 0; i < 16; i++) {
        left = left_shift(left, shift_table[i]);
        right = left_shift(right, shift_table[i]);

        bitset<56> combined_key;
        for (int j = 28; j < 56; j++) {
            combined_key[j-28] = left[j-28];
            combined_key[j] = right[j-28];
        }

        bitset<48> round_key;
        for (int j = 0; j < 48; j++) {
            round_key[47-j] = combined_key[56-PC2[j]];
        }
        round_keys.push_back(round_key);
    }
}

bitset<32> f(bitset<32> R, bitset<48> K) {
    bitset<48> expanded_R;
    for (int i = 0; i < 48; i++) {
        expanded_R[47-i] = R[32-E[i]];
    }

    expanded_R ^= K;

    bitset<32> output;
    int x = 0;
    for (int i = 0; i < 48; i += 6) {
        int row = expanded_R[47-i]*2 + expanded_R[47-i-5];
        int col = expanded_R[47-i-1]*8 + expanded_R[47-i-2]*4 + expanded_R[47-i-3]*2 + expanded_R[47-i-4];
        int val = S[i/6][row][col];
        bitset<4> binary(val);
        for (int j = 0; j < 4; j++) {
            output[31-x] = binary[3-j];
            x++;
        }
    }

    bitset<32> permuted_output;
    for (int i = 0; i < 32; i++) {
        permuted_output[31-i] = output[32-P[i]];
    }

    return permuted_output;
}

bitset<64> encrypt(bitset<64> plaintext, vector<bitset<48>> round_keys) {
    bitset<64> permuted_plaintext;
    for (int i = 0; i < 64; i++) {
        permuted_plaintext[63-i] = plaintext[64-IP[i]];
    }

    bitset<32> left, right, new_right;
    for (int i = 32; i < 64; i++) {
        left[i-32] = permuted_plaintext[i];
        right[i-32] = permuted_plaintext[i-32];
    }

    for (int i = 0; i < 16; i++) {
        new_right = left ^ f(right, round_keys[i]);
        left = right;
        right = new_right;
    }

    bitset<64> combined;
    for (int i = 0; i < 32; i++) {
        combined[i] = right[i];
        combined[32+i] = left[i];
    }

    bitset<64> ciphertext;
    for (int i = 0; i < 64; i++) {
        ciphertext[63-i] = combined[64-FP[i]];
    }

    return ciphertext;
}

int main() {
    bitset<64> key(0x133457799BBCDFF1);
    bitset<64> plaintext(0x0123456789ABCDEF);

    vector<bitset<48>> round_keys;
    generate_keys(key, round_keys);

    bitset<64> ciphertext = encrypt(plaintext, round_keys);

    cout << "Ciphertext: " << hex << uppercase << ciphertext.to_ullong() << endl;

    return 0;
}
