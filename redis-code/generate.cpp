#include <iostream>
#include <string>
#include <sw/redis++/redis++.h>
#include <unordered_map>
#include <vector>

using std::cout;
using std::endl;
using std::string;
using std::unordered_map;
using std::vector;

void test1(sw::redis::Redis &redis) {
    cout << "get和set的使用" << endl;

    // 清空一下数据库, 避免之前残留的数据有干扰.
    redis.flushall();
    // 使用 set 设置 key
    redis.set("key1", "111");
    redis.set("key2", "222");
    redis.set("key3", "333");

    //使用get获取到key对应的值
    sw::redis::OptionalString value1 = redis.get("key1");
    // OptionalString 可以隐式转成 bool 类型, 可以直接在 if 中判定. 如果是无效元素, 就是返回 false
    if (value1) {
        //.value()方法 可以获取OptionalString对象中的实际值
        cout << "value1=" << value1.value() << endl;
    }

    auto value2 = redis.get("key2");
    if (value2) {
        std::cout << "value2=" << value2.value() << std::endl;
    }

    auto value3 = redis.get("key3");
    if (value3) {
        std::cout << "value3=" << value3.value() << std::endl;
    }

    auto value4 = redis.get("key4");
    if (value4) {
        std::cout << "value4=" << value4.value() << std::endl;
    }
}


int main() {
    sw::redis::Redis redis("tcp://127.0.0.1:6379");
    test1(redis);
    return 0;
}