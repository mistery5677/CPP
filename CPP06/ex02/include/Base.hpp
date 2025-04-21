#pragma once
#include <string>

class Base {
    private:
    public:
        Base();
        virtual ~Base();

        static          Base* generate(void);
        static void     identify(Base* p);
        static void     identify(Base& p);
};