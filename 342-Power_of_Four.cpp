class Solution {
public:
    bool isPowerOfFour(int num) {
        return !(num ^ 1)     || !(num ^ 4)     || !(num ^ 4<<2)  || !(num ^ 4<<4)
            || !(num ^ 4<<6)  || !(num ^ 4<<8)  || !(num ^ 4<<10) || !(num ^ 4<<12)
            || !(num ^ 4<<14) || !(num ^ 4<<16) || !(num ^ 4<<18) || !(num ^ 4<<20)
            || !(num ^ 4<<22) || !(num ^ 4<<24) || !(num ^ 4<<26) || !(num ^ 4<<28);
    }
};
