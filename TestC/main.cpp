#include <map>
#include <string>
#include <iostream>

template <typename M>
void print(const M& m)
{
    std::cout << m.size() << " elements: ";

    for (const auto& p : m)
    {
        std::cout << "(" << p.first << ", " << p.second << ") ";
    }

    std::cout << std::endl;
}

void emplacetest()
{
    std::map<int, std::string> m1;

    auto ret = m1.emplace(10, "ten");

    if  (!ret.second)
    {
        auto pr = *ret.first;
        std::cout << "Emplace failed, element with key 10 already exists."
            << std::endl << "  The existing element is (" << pr.first << ", " << pr.second << ")"
            << std::endl;
        std::cout << "map not modified" << std::endl;
    }
    else
    {
        std::cout << "map modified, now contains ";
        print(m1);
    }
    std::cout << std::endl;

    ret = m1.emplace(10, "one zero");

    if (!ret.second)
    {
        auto pr = *ret.first;
        std::cout << "Emplace failed, element with key 10 already exists."
            << std::endl << "  The existing element is (" << pr.first << ", " << pr.second << ")"
            << std::endl;
    }
    else
    {
        std::cout << "map modified, now contains ";
        print(m1);
    }
    std::cout << std::endl;
}

int main(int argc, char** argv)
{
    printf("Hello World\r\n");
    emplacetest();
    return 0;
}