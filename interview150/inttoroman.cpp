/**
 * xiebaoma
 * 2025-07-01
 */

#include <string>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    string intToRoman(int num)
    {
        unordered_map<int, string> gmap;
        gmap[1] = "I";
        gmap[2] = "II";
        gmap[3] = "III";
        gmap[4] = "IV";
        gmap[5] = "V";
        gmap[6] = "VI";
        gmap[7] = "VII";
        gmap[8] = "VIII";
        gmap[9] = "IX";
        unordered_map<int, string> smap;
        smap[1] = "X";
        smap[2] = "XX";
        smap[3] = "XXX";
        smap[4] = "XL";
        smap[5] = "L";
        smap[6] = "LX";
        smap[7] = "LXX";
        smap[8] = "LXXX";
        smap[9] = "XC";
        unordered_map<int, string> bmap;
        bmap[1] = "C";
        bmap[2] = "CC";
        bmap[3] = "CCC";
        bmap[4] = "CD";
        bmap[5] = "D";
        bmap[6] = "DC";
        bmap[7] = "DCC";
        bmap[8] = "DCCC";
        bmap[9] = "CM";
        unordered_map<int, string> qmap;
        qmap[1] = "M";
        qmap[2] = "MM";
        qmap[3] = "MMM";
        string ret = "";
        // ge 3749 9
        int count = num % 10;
        ret = gmap[count] + ret;
        num /= 10;
        // shi 374 4
        if (num <= 0)
        {
            return ret;
        }
        count = num % 10;
        ret = smap[count] + ret;
        num /= 10;
        // bai 37
        if (num <= 0)
        {
            return ret;
        }
        count = num % 10;
        ret = bmap[count] + ret;
        num /= 10;
        // qian 3
        if (num <= 0)
        {
            return ret;
        }
        count = num % 10;
        ret = qmap[count] + ret;

        return ret;
    }
};