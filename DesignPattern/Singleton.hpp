
//
//  temp.hpp
//  Graph_Algorithm
//
//  Created by fxd on 2023/7/13.
//

#ifndef temp_hpp
#define temp_hpp

#include <stdio.h>
#include <iostream>
#include <memory>
#include <mutex>

namespace V1{
class SingletonPattern_V1
{
private:
    SingletonPattern_V1() {
        std::cout << "V1 constructor called!" << std::endl;
    }
    SingletonPattern_V1(SingletonPattern_V1&) = delete;
    SingletonPattern_V1& operator=(const SingletonPattern_V1&) = delete;
    static SingletonPattern_V1* m_pInstance;
 
public:
    ~SingletonPattern_V1() {
//        delete m_pInstance;
        std::cout << "V1 destructor called!" << std::endl;
    }
    //在这里实例化
    static SingletonPattern_V1* Instance() {
        if (!m_pInstance) {
            m_pInstance = new SingletonPattern_V1();
        }
        return m_pInstance;
    }
    void use() const { std::cout << "in use" << std::endl; }
};
 
//在类外初始化静态变量
SingletonPattern_V1* SingletonPattern_V1::m_pInstance = nullptr;


};


namespace V2{
class SingletonPattern_V2{
public:
    ~SingletonPattern_V2(){
        std::cout << "V2 destructor called!\n";
    }
    
    static std::shared_ptr<SingletonPattern_V2> Instance(){
        if(!m_pInstance){
            std::lock_guard<std::mutex> lk(m_mutex);
            if(!m_pInstance){
//                m_pInstance = std::make_shared<SingletonPattern_V2>();
                std::shared_ptr<SingletonPattern_V2>(new SingletonPattern_V2());
            }
        }
        return m_pInstance;
    }
    
    void use() const { std::cout << "in use" << std::endl; }
    
private:
    SingletonPattern_V2() {
        std::cout << "V2 constructor called!" << std::endl;
    }
    SingletonPattern_V2(SingletonPattern_V2&) = delete;
    SingletonPattern_V2& operator=(const SingletonPattern_V2&) = delete;
    static std::shared_ptr<SingletonPattern_V2> m_pInstance;
    static std::mutex m_mutex;
};

std::shared_ptr<SingletonPattern_V2> SingletonPattern_V2::m_pInstance = nullptr;
std::mutex SingletonPattern_V2::m_mutex;
};

namespace V3{
class SingletonPattern_V3{
public:
    ~SingletonPattern_V3(){
        std::cout << "V3 destructor!\n";
    }
    static SingletonPattern_V3& Instance() {
        static SingletonPattern_V3 m_pInstance;
        return m_pInstance;
 
    }
    
private:
    SingletonPattern_V3(){
        std::cout << "V3 constructor!\n";
    }
    SingletonPattern_V3(const SingletonPattern_V3& temp) = delete;
    SingletonPattern_V3& operator=(const SingletonPattern_V3& temp) = delete;
    
};

};

#endif /* temp_hpp */

