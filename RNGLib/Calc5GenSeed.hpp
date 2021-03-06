/*
 * Copyright (c) 2014 odan
 * License: MIT License
 */
#ifndef INCLUDED_CALC_5GEN_SEED_HPP
#define INCLUDED_CALC_5GEN_SEED_HPP
#include "Config.hpp"

namespace RNGLib {
class Calc5GenSeed {
private:
    RNGLIB_STATIC_CONSTEXPR_OR_CONST u32 K0 = 0x5a827999;
    RNGLIB_STATIC_CONSTEXPR_OR_CONST u32 K1 = 0x6ed9eba1;
    RNGLIB_STATIC_CONSTEXPR_OR_CONST u32 K2 = 0x8f1bbcdc;
    RNGLIB_STATIC_CONSTEXPR_OR_CONST u32 K3 = 0xca62c1d6;

    RNGLIB_STATIC_CONSTEXPR_OR_CONST u32 H0 = 0x67452301;
    RNGLIB_STATIC_CONSTEXPR_OR_CONST u32 H1 = 0xefcdab89;
    RNGLIB_STATIC_CONSTEXPR_OR_CONST u32 H2 = 0x98badcfe;
    RNGLIB_STATIC_CONSTEXPR_OR_CONST u32 H3 = 0x10325476;
    RNGLIB_STATIC_CONSTEXPR_OR_CONST u32 H4 = 0xc3d2e1f0;
    u32 W[80];

    u32 to_uint32_little_endian(u32 val) const {
        return ((val&0xff)<<24) | (((val>>8)&0xff)<<16) |
            (((val>>16)&0xff)<<8) | ((val>>24)&0xff);
    }

    u32 to_bcd(u32 val) const {
        return ((val/10)<<4) | (val%10);
    }
    u32 sha1_circular_shift(u32 bits, u32 word) const {
        return ((word << bits) | (word >> (32-bits)));
    }
public:
    template<class T>
    u64 operator() (const T& paramers) {
        u64 seed = 0;
        u32 A, B, C, D, E;
        u32 temp;
        u32 t;
        W[0] = to_uint32_little_endian(paramers.get_nazo1());
        W[1] = to_uint32_little_endian(paramers.get_nazo2());
        W[2] = to_uint32_little_endian(paramers.get_nazo3());
        W[3] = to_uint32_little_endian(paramers.get_nazo4());
        W[4] = to_uint32_little_endian(paramers.get_nazo5());
        W[5] = to_uint32_little_endian(
                    (paramers.get_vcount()<<16) | paramers.get_timer0()
                );
        W[6] = (paramers.get_mac_add5() << 8) | paramers.get_mac_add6();
        W[7] = to_uint32_little_endian(
                    paramers.get_gxstat() ^ paramers.get_frame() ^
                    ((paramers.get_mac_add4()<<24) | 
                    (paramers.get_mac_add3()<<16) |
                    (paramers.get_mac_add2()<<8 ) | 
                    (paramers.get_mac_add1()))
                );
        W[8] = (to_bcd(paramers.get_year())  << 24) | 
               (to_bcd(paramers.get_month()) << 16) |
               (to_bcd(paramers.get_day()) << 8) |
                paramers.get_week();
        W[9] = ((to_bcd(paramers.get_hour()) |
               ((12<=paramers.get_hour())<<6)) << 24) |
               (to_bcd(paramers.get_minute()) << 16) |
               (to_bcd(paramers.get_sec()) << 8);
        W[10] = 0x00000000;
        W[11] = 0x00000000;
        W[12] = to_uint32_little_endian(paramers.get_key());
        W[13] = 0x80000000;
        W[14] = 0x00000000;
        W[15] = 0x000001A0;
        for (t = 16; t < 80; t++) {
            W[t] = sha1_circular_shift(1, W[t-3] ^ W[t-8] ^ W[t-14] ^ W[t-16]);
        }

        A = H0;
        B = H1;
        C = H2;
        D = H3;
        E = H4;


        for (t = 0; t < 20; t++) {
            temp =  sha1_circular_shift(5, A) +((B & C) | ((~B) & D)) + E + W[t] + K0;
            E = D;
            D = C;
            C = sha1_circular_shift(30, B);
            B = A;
            A = temp;
        }

        for (t = 20; t < 40; t++) {
            temp = sha1_circular_shift(5, A) + (B ^ C ^ D) + E + W[t] + K1;
            E = D;
            D = C;
            C = sha1_circular_shift(30, B);
            B = A;
            A = temp;
        }

        for (t = 40; t < 60; t++) {
            temp = sha1_circular_shift(5, A) +
                ((B & C) | (B & D) | (C & D)) + E + W[t] + K2;
            E = D;
            D = C;
            C = sha1_circular_shift(30, B);
            B = A;
            A = temp;
        }

        for (t = 60; t < 80; t++) {
            temp = sha1_circular_shift(5, A) + (B ^ C ^ D) + E + W[t] + K3;
            E = D;
            D = C;
            C = sha1_circular_shift(30, B);
            B = A;
            A = temp;
        }

        seed = to_uint32_little_endian(H1+B);
        seed <<= 32;
        seed |= to_uint32_little_endian(H0+A);

        return seed;
    }

};
} // end RNGLib

#endif
