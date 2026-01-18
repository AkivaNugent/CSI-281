//
//  test.cpp
//
//  Tests to prove your code works.
//  You SHOULD modify this file.
//
//  Copyright 2019 David Kopec
//
//  Permission is hereby granted, free of charge, to any person
//  obtaining a copy of this software and associated documentation files
//  (the "Software"), to deal in the Software without restriction,
//  including without limitation the rights to use, copy, modify, merge,
//  publish, distribute, sublicense, and/or sell copies of the Software,
//  and to permit persons to whom the Software is furnished to do so,
//  subject to the following conditions:
//
//  The above copyright notice and this permission notice
//  shall be included in all copies or substantial portions of the Software.
//
//  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
//  OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
//  THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR
//  OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
//  ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
//  OTHER DEALINGS IN THE SOFTWARE.

#include "Queue.h"
#include "Stack.h"
#include "catch.h"
#include <string>

using namespace std;
using namespace csi281;

TEST_CASE( "Queue Tests", "[queue]" ) {
    SECTION( "Queue w/ int tests" ) {
        Queue<int> q1 = Queue<int>();

        cout << "Testing Queue Pop Int" << endl;
        cout << "Pushing [10, 15, 20, 25, 30]..." << endl;

        //PUSh Test
        q1.push(10);
        q1.push(15);
        q1.push(20);
        q1.push(25);
        q1.push(30);

        
        cout << "Expected count: 5" << endl;
        cout << "getcount() returned " << q1.getCount() << "items" << endl;

        CHECK(q1.getCount() == 5);

        //PEEK Test
        cout << "Testing Queue Peek Int" << endl;

        CHECK(q1.peek() == 10);

        //POP test
        cout << "Testing Queue Pop Int" << endl;
        CHECK(q1.pop() == 10);
        CHECK(q1.getCount() == 4);
        CHECK(q1.peek() == 15);

        //Emptying out the Queue Int
        cout << "Emptying Queue Int" << endl;
        CHECK(q1.pop() == 15);
        CHECK(q1.pop() == 20);
        CHECK(q1.pop() == 25);
        CHECK(q1.pop() == 30);
        CHECK(q1.getCount() == 0);

    }
    
    SECTION( "Queue w/ string tests" ) {
        Queue<string> q2 = Queue<string>();

        cout << "Testing Queue Pop String" << endl;
        cout << "Pushing [Hi, my, name, is, Akiva, Nugent]..." << endl;

        //PUSh Test
        q2.push("Hi");
        q2.push("my");
        q2.push("name");
        q2.push("is");
        q2.push("Akiva");
        q2.push("Nugent");


        cout << "Expected count: 6" << endl;
        cout << "getcount() returned " << q2.getCount() << "items" << endl;

        CHECK(q2.getCount() == 6);

        //PEEK Test
        cout << "Testing Queue Peek String" << endl;

        CHECK(q2.peek() == "Hi");

        //POP test
        cout << "Testing Queue Pop String" << endl;
        CHECK(q2.pop() == "Hi");
        CHECK(q2.getCount() == 5);
        CHECK(q2.peek() == "my");

        //Emptying out the Queue String
        cout << "Emptying Queue String" << endl;
        CHECK(q2.pop() == "my");
        CHECK(q2.pop() == "name");
        CHECK(q2.pop() == "is");
        CHECK(q2.pop() == "Akiva");
        CHECK(q2.pop() == "Nugent");
        CHECK(q2.getCount() == 0);

    }
}

TEST_CASE( "Stack Tests", "[stack]" ) {
    SECTION( "Stack w/ int tests" ) {
        Stack<int> s1 = Stack<int>();

        cout << "Testing Queue Pop Int" << endl;
        cout << "Pushing [10, 15, 20, 25, 30]..." << endl;

        //PUSh Test
        s1.push(10);
        s1.push(15);
        s1.push(20);
        s1.push(25);
        s1.push(30);


        cout << "Expected count: 5" << endl;
        cout << "getcount() returned " << s1.getCount() << "items" << endl;

        CHECK(s1.getCount() == 5);

        //PEEK Test
        cout << "Testing Stack Peek Int" << endl;

        CHECK(s1.peek() == 30);

        //POP test
        cout << "Testing Stack Pop Int" << endl;
        CHECK(s1.pop() == 30);
        CHECK(s1.getCount() == 4);
        CHECK(s1.peek() == 25);

        //Emptying out the Queue Test
        cout << "Emptying Stack Int" << endl;
        CHECK(s1.pop() == 25);
        CHECK(s1.pop() == 20);
        CHECK(s1.pop() == 15);
        CHECK(s1.pop() == 10);
        CHECK(s1.getCount() == 0);

    }
    
    SECTION( "Stack w/ string tests" ) {
        Stack<string> s2 = Stack<string>();

        cout << "Testing Queue Pop String" << endl;
        cout << "Pushing [Hi, my, name, is, Akiva, Nugent]..." << endl;

        //PUSh Test
        s2.push("Hi");
        s2.push("my");
        s2.push("name");
        s2.push("is");
        s2.push("Akiva");
        s2.push("Nugent");


        cout << "Expected count: 6" << endl;
        cout << "getcount() returned " << s2.getCount() << "items" << endl;

        CHECK(s2.getCount() == 6);

        //PEEK Test
        cout << "Testing Queue Peek String" << endl;

        CHECK(s2.peek() == "Nugent");

        //POP test
        cout << "Testing Queue Pop String" << endl;
        CHECK(s2.pop() == "Nugent");
        CHECK(s2.getCount() == 5);
        CHECK(s2.peek() == "Akiva");

        //Emptying out the Queue String
        cout << "Emptying Queue String" << endl;
        CHECK(s2.pop() == "Akiva");
        CHECK(s2.pop() == "is");
        CHECK(s2.pop() == "name");
        CHECK(s2.pop() == "my");
        CHECK(s2.pop() == "Hi");
        CHECK(s2.getCount() == 0);

    }
}

