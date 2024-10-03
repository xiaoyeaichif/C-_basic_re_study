#include<iostream>
#include<memory>
#include <string>

using namespace std;

class Cat
{
public:
    Cat() {
        this->name = "yejie";
    };
    // 有参构造函数
    Cat(string name){
        this->name = name;
    };

    // 显示信息
    void show() {
        cout << "name: " << name << endl;
    }

    // 获取name
    string getName() const
    {
        return name;
    }

    // 设置name
    void setName(string name)
    {
        this->name = name;
    }

    // 析构函数的使用
    ~Cat()
    {
        cout << "析构函数 Run !" << endl;
    }
private:
    string name;
};


// shared_ptr智能指针作为值传递
// 智能指针出作用域自动析构,也就是说出作用域之后引用计数变成1
void cat_by_value(shared_ptr<Cat> cat)
{
    // 输出name
    std::cout<<"name: "<< cat->getName()<<endl;
    // 获取引用计数
    std::cout<<"func use count: "<< cat.use_count()<<endl;
}

// 作为引用传递
void cat_by_reference(shared_ptr<Cat> &cat)
{
    // 输出name
    std::cout<<"name: "<< cat->getName()<<endl;
    // 获取引用计数
    std::cout<<"func use count: "<< cat.use_count()<<endl;
}


// shared_ptr智能指针的使用
int main()
{
    std::shared_ptr<Cat>p1 = std::make_shared<Cat>();
    // 统计当前的引用计数个数以及输出
    std::cout<<"name: "<< p1->getName()<<endl;
    std::cout<<"p1 use count: "<<p1.use_count()<<endl;
    cout<<"------------------------------------------------"<<endl;
    cat_by_value(p1);
    cout<<"------------------------------------------------"<<endl;
    cat_by_reference(p1);
    return 0;
}