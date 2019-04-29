//
// Created by dguco on 19-3-23.
//

#include <iostream>
#include <functional>
#include <utility>      // std::declval
#include <iostream>     // std::cout
#include <memory>

void test()
{
    //    decltype(std::declval<A>().value()) a;  // int a
//    decltype(std::declval<B>().value()) b;  // int b
//    decltype(B(0, 0).value()) c;   // same as above (known constructor)
//    a = b = B(10, 2).value();
//    typedef decltype(std::declval<C>()) type_c;
//    C *ccc = new C;
//    type_c __c = std::move(*ccc);
//    std::cout << a << '\n';
//
//    std::shared_ptr<int> ip1 = std::make_shared<int>(10);
//    int use = ip1.use_count();
//    std::shared_ptr<int> ip2 = ip1;
//    use = ip1.use_count();
//    use = ip2.use_count();
//    std::shared_ptr<int> ip3 = std::move(ip2);
//    use = ip1.use_count();
//    use = ip2.use_count();
//    use = ip3.use_count();
//    ip3.reset();
//    if (ip3) {
//        std::cout << "Ok" << std::endl;
//    }
//    else {
//        std::cout << "failed" << std::endl;
//    }
};
struct A
{              // abstract class
    virtual int value() = 0;
};

struct C
{
    int a;
};

class B
{    // class with specific constructor
    int val_;
public:
    B()
    {
        val_ = 0;
        printf("B default construct\n");
    }
    B(int i, int j)
        : val_(i * j)
    {
        printf("B construct,i = %d,j= %d\n", i, j);
    }
    B(const B &other)
    {
        printf("B copy construct\n");
        this->val_ = other.val_;
    }
    B(const B &&other)
    {
        printf("B move construct\n");
        this->val_ = other.val_;
    }
    B &operator=(const B &b)
    {
        this->val_ = b.val_;
        printf("B operator=\n");
        return *this;
    };

    int value()
    { return val_; }
};

int main()
{
    int a_ = 0;
    B bbb = [&a_]() -> B
    {
        printf("Call func a_ = %d\n", a_);
    }();
    printf("bbb value = %d \n", bbb.value());
    return 0;
}