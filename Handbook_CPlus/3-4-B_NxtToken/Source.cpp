#include <iostream>
#include <string>
#include <string_view>

bool NextToken(std::string_view& _sv, const char _delimiter, std::string_view& _token) {
    using namespace std;
    bool trigger = false;
    string res;
    int idx = 0;
    for (auto i : _sv) {
        if (i == _delimiter) {
            _token = res;
            _sv.remove_prefix(idx);
            trigger = true;
            break;
        }
        else {
            res += _sv[idx];
            ++idx;
        }
    }
    if (trigger) { return 1; }
    else { return 0; }
}

int main() {
    std::string_view sv = "Hello world and good bye";

    const char delimiter = ' ';
    std::string_view token;

    // Делим строку на токены по разделителю и перебираем эти токены:
    while (NextToken(sv, delimiter, token)) {
        // обрабатываем очередной token
        // например, печатаем его на экране:
        std::cout << token << "\n";
    }

	return 0;
}