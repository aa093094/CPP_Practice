#include <future>
#include <iostream>
#include <string>
#include <thread>
using std::string;

void worker(std::promise<string>* p) {
    p->set_value("some data");
}

int main() {
    std::promise<string> p;
    std::future<string> data = p.get_future();

    std::thread t(worker, &p);

    data.wait();

    std::cout << "받은 데이터 : " << data.get() << std::endl;

    t.join();
}
