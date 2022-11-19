//
// Created by Administrator on 2022/11/12.
//

#ifndef TWOPOINTTHREE_ICONTROLLER_H
#define TWOPOINTTHREE_ICONTROLLER_H
#include <map>
#include <functional>
typedef std::function<void(std::string,std::string)> calFun;
class IController {
public:
    IController(){};
    virtual ~IController() {};
    virtual void setParams(const std::map<std::string,std::string>& params)=0;
    virtual bool start() = 0;
    virtual bool stop() = 0;
    virtual bool isConnect() = 0;
    virtual bool reConnect() = 0;
    virtual bool setCalFun(calFun cal) = 0;
    virtual std::string getParams(const std::string& params) = 0;
};


#endif //TWOPOINTTHREE_ICONTROLLER_H
