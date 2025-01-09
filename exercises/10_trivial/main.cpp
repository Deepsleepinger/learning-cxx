#include "../exercise.h"
#include <iostream>

// 定义 FibonacciCache 结构体
struct FibonacciCache {
    unsigned long long cache[16];// 缓存数组
    int cached;                  // 缓存的数量
};

// 实现缓存优化的斐波那契计算
static unsigned long long fibonacci(FibonacciCache &cache, int i) {
    // 如果缓存的数量小于 i+1，则需要计算并填充缓存
    while (cache.cached <= i) {
        cache.cache[cache.cached] = cache.cache[cache.cached - 1] + cache.cache[cache.cached - 2];
        cache.cached++;
    }
    return cache.cache[i];
}

int main(int argc, char **argv) {
    // 初始化缓存结构体
    FibonacciCache fib = {
        {0, 1},// 初始化 cache 数组的前两个元素为 0 和 1
        2      // 初始化 cached 为 2，表示前两个元素已经被缓存
    };

    // 测试 fibonacci(10) 是否等于 55
    ASSERT(fibonacci(fib, 10) == 55, "fibonacci(10) should be 55");
    std::cout << "fibonacci(10) = " << fibonacci(fib, 10) << std::endl;

    return 0;
}