// /**
//  * Testing BST - Binary Search Tree functions
//  *
//  * This file has series of tests for BST
//  * Each test is independent and uses assert statements
//  * Test functions are of the form
//  *
//  *      test_netidXX()
//  *
//  * where netid is UW netid and XX is the test number starting from 01
//  *
//  * Test functions can only use the public functions from BST
//  * testBSTAll() is called from main in main.cpp
//  * testBSTAll calls all other functions
//  * @author Multiple
//  * @date ongoing
//  */

#include "bstmap.h"
#include <cassert>
#include <sstream>

using namespace std;

// global value for testing
// NOLINTNEXTLINE
stringstream globalSS;

// need to reset SS before calling this
void printer(const BSTMap::value_type &p) {
  globalSS << "[" << p.first << "=" << p.second << "]";
}

// // Testing == and []
void test01() {
  cout << "Starting test01" << endl;
  cout << "* Testing ==, !=, [] and copy constructor" << endl;
  BSTMap b1;
  auto val = b1["hello"];
  assert(val == 0);
  b1["hello"] = 5;
  val = b1["hello"];
  assert(val == 5);
  b1["world"] = 42;

  BSTMap b2;
  assert(b1 != b2);
  b2["hello"] = 5;
  b2["world"] = 42;
  assert(b1 == b2);

  BSTMap b3(b2);
  cout << b1 << endl;
  cout << b2 << endl;
  cout << b3 << endl;
  assert(b1 == b3);
  cout << "Ending test01" << endl;
}

// Testing traversal
void test02() {
  cout << "Starting test02" << endl;
  cout << "* Testing traversal" << endl;
  BSTMap b;
  b["x"] = 10;
  b["f"] = 5;
  b["b"] = 3;
  b["e"] = 4;
  b["z"] = 50;
  cout << b << endl;

  globalSS.str("");
  b.inorder(printer);
  string order = globalSS.str();
  cout << order << endl;
  assert(order == "[b=3][e=4][f=5][x=10][z=50]");

  globalSS.str("");
  b.preorder(printer);
  order = globalSS.str();
  cout << order << endl;
  assert(order == "[x=10][f=5][b=3][e=4][z=50]");

  globalSS.str("");
  b.postorder(printer);
  order = globalSS.str();
  cout << order << endl;
  cout << b << endl;
  assert(order == "[e=4][b=3][f=5][z=50][x=10]");
  cout << "Ending test02" << endl;
}

// Testing rebalance
void test03() {
  cout << "Starting test03" << endl;
  cout << "* Testing rebalance" << endl;
  BSTMap b;
  b["1"] = 1;
  b["2"] = 2;
  b["3"] = 3;
  b["4"] = 4;
  b["5"] = 5;
  b["6"] = 6;
  assert(b.height() == 6);
  cout << b << endl;
  b.rebalance();
  cout << b << endl;
  assert(b.height() == 3);
  cout << b << endl;
  b.clear();
  assert(b.height() == 0);
  cout << "Ending test03" << endl;
}

void test04() {
  cout << "Starting test04" << endl;
  cout << "* Testing a big vector" << endl;
  vector<BSTMap::value_type> veccy;
  veccy.emplace_back(make_pair("01", 1));
  veccy.emplace_back(make_pair("02", 2));
  veccy.emplace_back(make_pair("03", 3));
  veccy.emplace_back(make_pair("04", 4));
  veccy.emplace_back(make_pair("05", 5));
  veccy.emplace_back(make_pair("06", 6));
  veccy.emplace_back(make_pair("07", 7));
  veccy.emplace_back(make_pair("08", 8));
  veccy.emplace_back(make_pair("09", 9));
  veccy.emplace_back(make_pair("10", 10));
  veccy.emplace_back(make_pair("11", 11));
  veccy.emplace_back(make_pair("12", 12));
  veccy.emplace_back(make_pair("13", 13));
  veccy.emplace_back(make_pair("14", 14));
  veccy.emplace_back(make_pair("15", 15));
  veccy.emplace_back(make_pair("16", 16));
  veccy.emplace_back(make_pair("17", 17));
  veccy.emplace_back(make_pair("18", 18));
  BSTMap b(veccy);
  assert(b.size() == 18);
  b.rebalance();
  assert(b.size() == 18);
  BSTMap cob(b);
  assert(!cob.empty());
  assert(cob.contains("12"));
  assert(cob.count("15") == 1);
  assert(cob.count("19") == 0);
  cout << cob << endl;
  cout << "Ending test04" << endl;
}

void test05() {
  cout << "Starting test05" << endl;
  cout << "* Testing equality" << endl;
  BSTMap b;
  cout << b << endl;
  b["1"] = 1;
  BSTMap d;
  d["1"] = 2;
  assert(b != d);
  cout << "Ending test05" << endl;
}

// // Calling all test functions
void testBSTAll() {
  test01();
  test02();
  test03();
  test04();
  test05();
  // TODO(student) Add more tests
}