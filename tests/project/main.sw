extern "C" fn GetStdHandle(nStdHandle: i64): *char;
extern "C" fn WriteConsoleA(nConsoleOutput: *char, lpBuffer: *char, nNumberOfCharsToWrite: i64, lpNumberOfCharsWritten: *i64): *char;

fn main() {
    var message = "Hello World!\n";
    var bytes_written: i64 = 0;
    var handle: *char = GetStdHandle(-11);
    WriteConsoleA(handle, message.ptr(), message.size(), &bytes_written);
}