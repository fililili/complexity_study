#include <optional>
#include <string>

struct program {
    std::string exe(std::string input) {
        // do some calculation
        return input; // fake return
    }
    std::string _s;
};

// return the result of p with i
// if return {}, means it doesn't stop
std::optional<std::string> god_program(program p, std::string i) {
    // try return p.exe(i)
    return {};
}

std::string paradox_program(program p) {
    auto self_ret = god_program(p, p._s);
    if (self_ret && self_ret.value() == "1")
        return "0";
    else
        return "1";
}

program paradox_program_{std::string{"\
std::string paradox_program(program p) {\
    auto self_ret = god_program(p, p._s);\
    if (self_ret && self_ret.value() == \"1\")\
        return \"0\";\
    else\
    return \"1\";\
}"}};

int main() {
    auto val = paradox_program(paradox_program_);
    // if paradox_program(paradox_program_) = 1,
    // then god_program(paradox_program_, paradox_program_._s) not exist or not equal to 1
    // then paradox_program_.exe(paradox_program_._s) cannot stop or not equal to 1
    
    // if paradox_program(paradox_program_) = 0,
    // then god_program(paradox_program_, paradox_program_._s) = 1
    // then paradox_program_.exe(paradox_program_._s) = 1

    // we can implement exe function, just write a compiler and execute the program.
    // so paradox_program doesn't exist.
    // if god_program exist, paradox_program exist, too.
    // so paradox_program don't exist, too.
}
