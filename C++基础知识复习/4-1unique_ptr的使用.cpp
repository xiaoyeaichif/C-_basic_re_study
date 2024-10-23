

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

// 返回unique_ptr对象操作
unique_ptr<Cat> getUniquePtr()
{
    unique_ptr<Cat> temp =  make_unique<Cat>(); 
    return temp; // 触发移动语义---》返回局部对象-----》这部分是编译器来完成
}


// unique_ptr使用

int main()
{
    // 1:普通创建对象---->普通构造函数，使用的是初始值
    std::unique_ptr<Cat> p1(new Cat());
    p1->show();
    std::cout <<"Cat1 name is " << p1->getName() << std::endl;
    std::cout << "p1 address(栈上地址): " << &p1 << " points to(堆上地址): " << p1.get() << std::endl;
    cout << "----------------" << endl;


    // 2: 调用有参构造函数
    std::unique_ptr<Cat> p2 = std::make_unique<Cat>("Yinyue");
    p2->show();
    std::cout <<"Cat2 name is " << p2->getName() << std::endl;
    std::cout << "p2 address(栈上地址): " << &p2 << " points to(堆上地址): " << p2.get() << std::endl;
    cout << "----------------" << endl;

    // 3: 使用new的方式调用
    std::unique_ptr<Cat> p3 (new Cat("kiki"));
    p3->show();
    std::cout <<"Cat3 name is " << p3->getName() << std::endl;
    std::cout << "p1 address(栈上地址): " << &p3 << " points to(堆上地址): " << p3.get() << std::endl;

    cout<<"----------------" << endl;
    //4: 检验赋值函数
    // unique_ptr不允许赋值
    //p1 = p3;

    //5: 移动语义的使用
    // 将p3移动到p1
    // 也就是说p1的指针指向了p3的指针，但是p3的指针为空
    // 在移动操作之前
    std::cout << "Before move: " << std::endl;
    std::cout << "p1 address(栈上地址): " << &p1 << " points to(堆上地址): " << p1.get() << std::endl;
    std::cout << "p3 address(栈上地址): " << &p3 << " points to(堆上地址): " << p3.get() << std::endl;

    // 移动 p3 到 p1
    // p3的指针为空
    // p1的资源会被直接释放,所以此时会调用p1的析构函数
    // 另外p3的堆上资源会被p1接管
    cout<<"----------------" << endl;
    p1 = std::move(p3);
    cout<<"----------------" << endl;
    // p3->show();  -----》p3被置为nullptr，不可以在调用成员函数

    std::cout << "After move: " << std::endl;
    std::cout << "p1 address(栈上地址): " << &p1 << " points to(堆上地址): " << p1.get() << std::endl;
    std::cout << "p3 address(栈上地址): " << &p3 << " points to(堆上地址): " << p3.get() << std::endl;

    cout<<"----------------" << endl;

    // 接收临时变量的返回
    // 返回的值是右值，所以会触发移动构造函数，将返回值的所有权转移给p4
    // 那p4最终能调用对象的成员函数
    unique_ptr<Cat> p4 = getUniquePtr();
    p4->show();
    cout<<"----------------" << endl;
    return 0;
}


//1： 智能指针本身是一个栈对象，出了作用域就会被销毁，销毁的同时也会将智能指针所指向区域的内存资源给释放
//    也就是说只能指针本身在栈上，但指向的内存地址在堆上
//2：智能指针有两个地址，一个地址是栈上地址，一个是指向的内存区域的堆地址