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

    // 
    void setFriend(shared_ptr<Cat> m_frined)
    {
        this->m_frined = m_frined;
        cout<< "use.count() = " << m_frined.use_count() << endl;
    }

    // 析构函数的使用
    ~Cat()
    {
        cout << "析构函数 Run !" << endl;
    }
private:
    string name;
    //std::shared_ptr<Cat> m_frined;
    // 改为weak_ptr指针，解决循环引用问题
    std::weak_ptr<Cat> m_frined;
};



// weak_ptr智能指针的使用
// 1：解决shared_ptr循环引用的问题
// 2：判断shared_ptr是否为空----->也就是生命周期
// 3：weak_ptr不会改变引用计数值
int main()
{
    //1：weak_ptr不会改变引用计数的值
    shared_ptr<Cat> sp1(new Cat("yejie"));
    weak_ptr<Cat> wp1(sp1);
    cout << "wp1.use_count() = " << wp1.use_count() << endl;
    cout << "sp1.use_count() = " << sp1.use_count() << endl;
    cout<<"-------------------"<<endl;
    //2:判断生命周期是否为空
    // weak_ptr可以观察一个 std::shared_ptr 指向的对象，检查该对象是否还存在或是否已经被销毁。
    sp1.reset();
    if(wp1.lock())
    {
        cout << "wp1.use_count() = " << wp1.use_count() << endl;
    }
    else{
        cout << "wp1 is null" << endl;
    }
    cout<<"-------------------"<<endl;
    // 3: 循环引用
    std::shared_ptr<Cat> sp2(new Cat("yejie"));
    // 相互设置对方为朋友,相当于死锁
    std::shared_ptr<Cat> sp3(new Cat("yinyue"));
    sp2->setFriend(sp3);
    sp3->setFriend(sp2);
    // 检查两者的引用计数
    cout << "sp2.use_count() = " << sp2.use_count() << endl;
    cout << "sp3.use_count() = " << sp3.use_count() << endl;
    cout<<"------yejie---------"<<endl;
    return 0;
}