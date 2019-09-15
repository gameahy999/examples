#include <folly/futures/Future.h>
#include <iostream>
#include <memory>
#include <thread>

#include "folly_stuff.h"

void sayHello(int v) {
    std::cout << "Hello World!" << std::endl;
    std::cout << "The value is: " << v << std::endl;
}

void test_follyStuff() {
    std::cout << "Have a try on folly::Promise, folly::Future, etc." << std::endl;

    std::shared_ptr<folly::Promise<int>> promisePtr =
        std::make_shared<folly::Promise<int>>();
    promisePtr->getFuture().then(sayHello);

    std::cout << "Have a sleep here." << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(2000));

    promisePtr->setValue(12);
    // promisePtr->setValue(24);
}
