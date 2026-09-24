// class Solution {
// public:
//     void rotate(vector<int>& nums, int k) {
//         k %= nums.size();

//         reverse(nums.begin(), nums.end());
//         reverse(nums.begin(), nums.begin() + k);
//         reverse(nums.begin() + k, nums.end());
//     }
// };
const size_t BUFFER_SIZE = 0x30000000;
alignas(64) static char buffer[BUFFER_SIZE];
static size_t buffer_pos = 0;

void* operator new(size_t size) {
    size_t aligned_pos = (buffer_pos + 63) & ~63;
    char* ptr = buffer + aligned_pos;
    buffer_pos = aligned_pos + size;
    return ptr;
}
void* operator new[](size_t size) { return operator new(size); }
void operator delete(void*) noexcept {}
void operator delete(void*, size_t) noexcept {}
void operator delete[](void*) noexcept {}
void operator delete[](void*, size_t) noexcept {}

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        if (n == 0) return;
        k %= n;
        if (k == 0) return;

        int g = __gcd(n, k);
        int* a = nums.data();

        for (int i = 0; i < g; i++) {
            int temp = a[i];
            int cur = i;
            while (true) {
                int nxt = cur + k;
                if (nxt >= n) nxt -= n;
                int save = a[nxt];
                a[nxt] = temp;
                if (nxt == i) break;
                temp = save;
                cur = nxt;
            }
        }
    }
};