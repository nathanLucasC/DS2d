#pragma once

#include <stdio.h>
#include <memory>
#include <map>
#include <vector>
#include <unordered_map>

namespace gb 
{

    template <typename T>
    using unique = std::unique_ptr<T>;

    template <typename T>
    using shared = std::shared_ptr<T>;

    template <typename T>
    using weak = std::weak_ptr<T>;

    template <typename T>
    using List = std::vector<T>;

    template <typename keyType, typename valType, typename Pr = std::less<keyType>>
    using Map = std::map<keyType, valType, Pr>;

    template <typename keyType, typename valType, typename hasher = std::hash<keyType>>
    using Dictionary = std::unordered_map<keyType, valType, hasher>;


    //macro
    #define LOG(M, ...) printf(M "\n", ##__VA_ARGS__)
}