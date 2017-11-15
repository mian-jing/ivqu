#include <string>
#include <iostream>
#include <map>
#include <unordered_map>

template <typename M>
void print(const M& m)
{
    std::cout << m.size() << " elements: ";

    for (const auto& p : m)
    {
        std::cout << "(" << p.first << ", " << p.second << ") ";
    }

    printf("\n");
}

void emplacetest()
{
    std::unordered_map<int, std::string> m1;

    auto ret = m1.emplace(10, "ten");

    if  (!ret.second)
    {
        auto pr = *ret.first;
        std::cout << "Emplace failed, element with key 10 already exists."
            << "\n" << "  The existing element is (" << pr.first << ", " << pr.second << ")"
            << "\n";
        std::cout << "map not modified" << "\n";
    }
    else
    {
        std::cout << "map modified, now contains ";
        print(m1);
    }
    std::cout << "" << "\n";

    ret = m1.emplace(10, "one zero");

    if (!ret.second)
    {
        auto pr = *ret.first;
        std::cout << "Emplace failed, element with key 10 already exists."
            << "\n" << "  The existing element is (" << pr.first << ", " << pr.second << ")"
            << "\n";
    }
    else
    {
        std::cout << "map modified, now contains ";
        print(m1);
    }
    std::cout << "" << "\n";
}

int main(int argc, char** argv)
{
    std::cout << "Hello World\r\n";
    emplacetest();
    return 0;
}