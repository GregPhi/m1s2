#include <iostream>
#include <chrono>
#include "mailbox.hpp"

using namespace std;

void prod(Mailbox<int> &mbox)
{
    using namespace std::chrono_literals;

    cout << "I am a producer " << endl;
    for (int i=0; i<50; i++) {
        cout << "Prod: inserting " << i << endl;
        mbox.put(i);
        this_thread::sleep_for( 200ms );
    }
    cout << "Producer terminated" << endl;
}

void cons(Mailbox<int> &mbox)
{
    cout << "I am a consumer" << endl;
    while (true) cout << "Cons: " << mbox.get() << endl;
}

int main()
{
    Mailbox<int> mbox(4);

    thread p1(prod, std::ref(mbox));
    thread p2(prod, std::ref(mbox));
    thread p3(prod, std::ref(mbox));
    thread p4(prod, std::ref(mbox));

    thread c1(cons, std::ref(mbox));
    thread c2(cons, std::ref(mbox));
    c1.detach();
    c2.detach();
    
    p1.join(); p2.join(); p3.join(); p4.join();

    this_thread::sleep_for( chrono::seconds(1) );
}

