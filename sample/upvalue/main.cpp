#include <iostream>
#include "libscript.h"

int foo(Args& args, Pusher& returns)
{
    UpValue v1 = args.getUpValue(1);
    UpValue v2 = args.getUpValue(2);

    if (!v1.isNoneOrNil())
        std::cout << v1.toInteger() << std::endl;

    if (!v2.isNoneOrNil())
        std::cout << v2.toString() << std::endl;

    return 0;
}

int foo2(RawInterface raw)
{
    UpValue v(raw, 1);
    std::cout << v.toInteger() << std::endl;
    v.reset(v.toInteger() + 1);
    return 0;
}

int main()
{
    Script script;

    script.getGlobalTable().set("foo",
        script.newClosure(foo, /* There is upvalue contents*/"7", 6));

    script.getGlobalTable().set("foo2",
        script.newClosure(foo2, 10));

    script.execString("foo() for i=1, 10 do foo2() end");
}