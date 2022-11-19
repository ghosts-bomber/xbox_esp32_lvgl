//
// Created by Administrator on 2022/11/12.
//

#ifndef TWOPOINTTHREE_XBOXCONTROLLER_H
#define TWOPOINTTHREE_XBOXCONTROLLER_H
#include "IController.h"

class XboxController:public IController {
public:
    XboxController();
    ~XboxController();
    void setParams(const std::map<std::string,std::string>& params) override;
    bool start() override;
    bool stop() override;
    bool isConnect() override;
    bool reConnect() override;
    bool setCalFun(calFun cal) override;
    std::string getParams(const std::string& params) override;

private:
};


#endif //TWOPOINTTHREE_XBOXCONTROLLER_H
