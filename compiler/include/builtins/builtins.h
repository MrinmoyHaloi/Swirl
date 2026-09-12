#pragma once
#define SW_BUILTIN_FILE_PATH "/__Sw__9117778/builtins.sw"

#define SW_BUILTIN_SOURCE std::format(R"(
export enum target {{
    windows,
    linux,
    darwin,

    x86,
    x64,
    arm64,
    unknown
}}

export comptime let arch:     target = target::{};
export comptime let platform: target = target::{};

{})",                                                            \
Triple.getArch()   == sw::Target::x86 ? "x86"                    \
: Triple.getArch() == sw::Target::x64 ? "x64"                    \
: Triple.getArch() == sw::Target::ARM64 ? "arm64" : "unknown",   \
                                                                 \
Triple.getOS()   == sw::Target::Windows ? "windows"              \
: Triple.getOS() == sw::Target::Linux ? "linux"                  \
: Triple.getOS() == sw::Target::Darwin ? "darwin" : "unknown",   \
                                                                         \
                                                                         \
R"(export struct str {
    var __Sw_buffer: *char;
    var __Sw_length: i64;

    export fn size(&self):  i64  { return self.__Sw_length; }
    export fn ptr (&self): *char { return self.__Sw_buffer; }

    export fn from_pointer(buf: *char, len: i64) {
        var inst: str;
        inst.__Sw_buffer = buf;
        inst.__Sw_length = len;
        return inst;
    }
})")
