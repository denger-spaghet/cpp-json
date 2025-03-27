#include "json.h"

int main() {

    JsonObject obj;
    obj.add("one", JsonValue{ "one" });

    JsonObject inner;
    inner.add("three", JsonValue{ "three" });
    obj.add("two", inner);

    std::string test {obj.toString()};
    std::cout << test << "\n";
    return 0;
}