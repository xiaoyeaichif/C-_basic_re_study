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

// shared_ptr智能指针的使用

int main()
{
    // 1.创建一个shared_ptr对象
    shared_ptr<Cat> p1(new Cat());
    p1->show();
    cout << "name: "<< p1->getName() << endl;
    cout << "p1.use_count(): " << p1.use_count() << endl;
    cout<<"--------------------------"<<endl;

    // 2: 拷贝一个智能指针
    shared_ptr<Cat> p2 = p1;
    cout << "p2.use_count(): " << p2.use_count() << endl;
    cout<<"----------检查p1引用计数有没有变化--------"<<endl;
    cout << "p1.use_count(): " << p1.use_count() << endl;

    cout<<"--------------------------"<<endl;

    // 改变p2的指向,检查引用计数的个数的变化
    p2.reset(new Cat("yejie2"));
    cout << "p2.use_count(): " << p2.use_count() << endl;
    cout << "p1.use_count(): " << p1.use_count() << endl;

    // 将p1的指针置为空,检查p1和p2的计数个数
    cout<<"--------------------------"<<endl;
    std::shared_ptr<Cat> p3 = p1;
    // 表示当前的区域有两个指针p1和p3指向了同一个对象
    cout << "p3.use_count(): " << p3.use_count() << endl;
    // 将p1这个对象置为空，也就是说一个对象的指针被置为空，计数会少一个1
    p1 = nullptr;
    // 将p1置为空之后,p1所指向的对象就会被销毁
    cout << "p1.use_count(): " << p1.use_count() << endl;
    // 输出p2的指向
    cout << "p2.use_count(): " << p2.use_count() << endl;
    cout << "p3.use_count(): " << p3.use_count() << endl;

    // 4： 使用make_shared创建对象
    cout<<"--------------------------"<<endl;
    std::shared_ptr<Cat> p4 = std::make_shared<Cat>("Yinyue");
    // 输出p4的引用计数
    std::cout << "p4.use_count(): "<<p4.use_count()<<std::endl;
    std::shared_ptr<Cat>  p5 = p4;
    std::shared_ptr<Cat>  p6 = p4;
    std::cout << "p4.use_count(): "<<p4.use_count()<<std::endl;
    std::cout << "p5.use_count(): "<<p5.use_count()<<std::endl;
    std::cout << "p6.use_count(): "<<p6.use_count()<<std::endl;
    p4.reset();
    // 没人指向这片区域时才会被销毁
    cout<<"--------------------------"<<endl;
    std::cout << "p4.use_count(): "<<p4.use_count()<<std::endl;
    std::cout << "p5.use_count(): "<<p5.use_count()<<std::endl;
    std::cout << "p6.use_count(): "<<p6.use_count()<<std::endl;

    // 最后的分割符
    cout<<"--------------------------"<<endl;
    return 0;
}