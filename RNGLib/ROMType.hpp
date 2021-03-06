
#ifndef INCLUDED_ROM_TYPE_HPP
#define INCLUDED_ROM_TYPE_HPP

namespace RNGLib {
namespace ROMType {

    typedef ConstantParameters5Gen<0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0> None;
    typedef ConstantParameters5Gen<0x2215f10, 0x221600c, 0x221600c, 0x2216058, 0x2216058, 0x60, 0x6000000, 0x6, 0xc79, 0xc7a> B1Ja;
    typedef ConstantParameters5Gen<0x2215f30, 0x221602c, 0x221602c, 0x2216078, 0x2216078, 0x60, 0x6000000, 0x6, 0xc68, 0xc69> W1Ja;

} // end ROMType
} // end RNGLib
#endif
